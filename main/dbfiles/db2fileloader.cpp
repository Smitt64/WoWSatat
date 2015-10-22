#include <stdlib.h>
#include <string.h>
#include "db2fileloader.h"

DB2FileLoader::DB2FileLoader()
{
    data = NULL;
    fieldsOffset = NULL;
}

bool DB2FileLoader::Load(const char *filename, const char *fmt)
{
    quint32 header = 48;
    if(data)
    {
        delete [] data;
        data=NULL;
    }

    FILE * f = fopen(filename, "rb");
    if(!f)return false;

    if(fread(&header, 4, 1, f) != 1)                        // Signature
    {
        fclose(f);
        return false;
    }

    EndianConvert(header);

    if(header != 0x32424457)
    {
        fclose(f);
        return false;                                       //'WDB2'
    }

    if(fread(&recordCount,4,1,f)!=1)                        // Number of records
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordCount);

    if(fread(&fieldCount,4,1,f)!=1)                         // Number of fields
    {
        fclose(f);
        return false;
    }

    EndianConvert(fieldCount);

    if(fread(&recordSize,4,1,f)!=1)                         // Size of a record
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordSize);

    if(fread(&stringSize,4,1,f)!=1)                         // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(stringSize);

    /* NEW WDB2 FIELDS*/
    if(fread(&tableHash,4,1,f)!=1)                          // Table hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(tableHash);

    if(fread(&build,4,1,f)!=1)                              // Build
    {
        fclose(f);
        return false;
    }

    EndianConvert(build);

    if(fread(&unk1,4,1,f)!=1)                               // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk1);

    if(fread(&unk2,4,1,f)!=1)                               // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk2);

    if(fread(&unk3,4,1,f)!=1)                               // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk3);

    if(fread(&locale,4,1,f)!=1)                             // Locales
    {
        fclose(f);
        return false;
    }

    EndianConvert(locale);

    if(fread(&unk5,4,1,f)!=1)                               // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk5);

    fieldsOffset = new quint32[fieldCount];
    fieldsOffset[0] = 0;
    for(quint32 i = 1; i < fieldCount; i++)
    {
        fieldsOffset[i] = fieldsOffset[i - 1];
        if (fmt[i - 1] == 'b' || fmt[i - 1] == 'X')         // byte fields
            fieldsOffset[i] += 1;
        else                                                // 4 byte fields (int32/float/strings)
            fieldsOffset[i] += 4;
    }

    data = new unsigned char[recordSize*recordCount+stringSize];
    stringTable = data + recordSize*recordCount;

    if(fread(data, recordSize * recordCount + stringSize, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

DB2FileLoader::~DB2FileLoader()
{
    if(data)
        delete [] data;
    if(fieldsOffset)
        delete [] fieldsOffset;
}

DB2FileLoader::Record DB2FileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id*recordSize);
}

quint32 DB2FileLoader::GetFormatRecordSize(const char * format,qint32* index_pos)
{
    quint32 recordsize = 0;
    qint32 i = -1;
    for(quint32 x = 0; format[x]; ++ x)
    {
        switch(format[x])
        {
        case FT_FLOAT:
            recordsize += sizeof(float);
            break;
        case FT_INT:
            recordsize += sizeof(quint32);
            break;
        case FT_STRING:
            recordsize += sizeof(char*);
            break;
        case FT_SORT:
            i=x;
            break;
        case FT_IND:
            i=x;
            recordsize += sizeof(quint32);
            break;
        case FT_BYTE:
            recordsize += sizeof(quint8);
            break;
        case FT_LOGIC:
            assert(false && "2 files not have logic field type");
            break;
        case FT_NA:
        case FT_NA_BYTE:
            break;
        default:
            assert(false && "unknown format character");
            break;
        }
    }

    if (index_pos)
        *index_pos = i;

    return recordsize;
}

quint32 DB2FileLoader::GetFormatStringsFields(const char * format)
{
    quint32 stringfields = 0;
    for(quint32 x=0; format[x];++x)
        if (format[x] == FT_STRING)
            ++stringfields;

    return stringfields;
}

char* DB2FileLoader::AutoProduceData(const char* format, qint32& records, char**& indexTable)
{
    /*
    format STRING, NA, FLOAT,NA,INT <=>
    struct{
    char* field0,
    float field1,
    int field2
    }entry;

    this func will generate  entry[rows] data;
    */

    typedef char * ptr;
    if(strlen(format)!=fieldCount)
        return NULL;

    //get struct size and index pos
    qint32 i;
    quint32 recordsize=GetFormatRecordSize(format,&i);

    if(i>=0)
    {
        quint32 maxi=0;
        //find max index
        for(quint32 y=0;y<recordCount;y++)
        {
            quint32 ind=getRecord(y).getUInt (i);
            if(ind>maxi)maxi=ind;
        }

        ++maxi;
        records=maxi;
        indexTable=new ptr[maxi];
        memset(indexTable,0,maxi*sizeof(ptr));
    }
    else
    {
        records = recordCount;
        indexTable = new ptr[recordCount];
    }

    char* dataTable= new char[recordCount*recordsize];

    quint32 offset=0;

    for(quint32 y =0; y < recordCount; ++y)
    {
        if (i >= 0)
        {
            indexTable[getRecord(y).getUInt(i)]=&dataTable[offset];
        }
        else
            indexTable[y]=&dataTable[offset];

        for(quint32 x = 0; x < fieldCount; ++x)
        {
            switch(format[x])
            {
            case FT_FLOAT:
                *((float*)(&dataTable[offset]))=getRecord(y).getFloat(x);
                offset += sizeof(float);
                break;
            case FT_IND:
            case FT_INT:
                *((quint32*)(&dataTable[offset]))=getRecord(y).getUInt(x);
                offset += sizeof(quint32);
                break;
            case FT_BYTE:
                *((quint8*)(&dataTable[offset]))=getRecord(y).getUInt8(x);
                offset += sizeof(quint8);
                break;
            case FT_STRING:
                *((char**)(&dataTable[offset]))=NULL;   // will be replaces non-empty or "" strings in AutoProduceStrings
                offset += sizeof(char*);
                break;
            case FT_LOGIC:
                assert(false && "DBC files not have logic field type");
                break;
            case FT_NA:
            case FT_NA_BYTE:
            case FT_SORT:
                break;
            default:
                assert(false && "unknown format character");
                break;
            }
        }
    }

    return dataTable;
}

static char const* const nullStr = "";

char* DB2FileLoader::AutoProduceStringsArrayHolders(const char* format, char* dataTable)
{
    if(strlen(format)!=fieldCount)
        return NULL;

    // we store flat holders pool as single memory block
    size_t stringFields = GetFormatStringsFields(format);
    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * MAX_LOCALE;
    size_t stringHoldersRecordPoolSize = stringFields * stringHolderSize;
    size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * recordCount;

    char* stringHoldersPool= new char[stringHoldersPoolSize];

    // dbc strings expected to have at least empty string
    for(size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    quint32 offset=0;

    // assign string holders to string field slots
    for(quint32 y =0;y<recordCount;y++)
    {
        quint32 stringFieldNum = 0;

        for(quint32 x=0;x<fieldCount;x++)
            switch(format[x])
            {
            case FT_FLOAT:
            case FT_IND:
            case FT_INT:
                offset+=4;
                break;
            case FT_BYTE:
                offset+=1;
                break;
            case FT_STRING:
            {
                // init dbc string field slots by pointers to string holders
                char const*** slot = (char const***)(&dataTable[offset]);
                *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * y + stringHolderSize*stringFieldNum]);

                ++stringFieldNum;
                offset+=sizeof(char*);
                break;
            }
            case FT_NA:
            case FT_NA_BYTE:
            case FT_SORT:
                break;
            default:
                assert(false && "unknown format character");
            }
    }

    //send as char* for store in char* pool list for free at unload
    return stringHoldersPool;
}

char* DB2FileLoader::AutoProduceStrings(const char* format, char* dataTable, LocaleConstant loc)
{
    if(strlen(format)!=fieldCount)
        return NULL;

    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * MAX_LOCALE;

    char* stringPool= new char[stringSize];
    memcpy(stringPool,stringTable,stringSize);

    quint32 offset=0;

    for(quint32 y =0; y < recordCount; ++y)
    {
        for(quint32 x = 0; x < fieldCount; ++x)
        {
            switch(format[x])
            {
            case FT_FLOAT:
                offset += sizeof(float);
                break;
            case FT_IND:
            case FT_INT:
                offset += sizeof(quint32);
                break;
            case FT_BYTE:
                offset += sizeof(quint8);
                break;
            case FT_STRING:
            {
                char** holder = *((char***)(&dataTable[offset]));
                char** slot = &holder[loc];

                // fill only not filled entries
                if (*slot == nullStr)
                {
                    const char * st = getRecord(y).getString(x);
                    *slot=stringPool+(st-(const char*)stringTable);
                }

                offset+=sizeof(char*);
                break;
            }
            case FT_LOGIC:
                assert(false && "DBC files not have logic field type");
                break;
            case FT_NA:
            case FT_NA_BYTE:
            case FT_SORT:
                break;
            default:
                assert(false && "unknown format character");
                break;
            }
        }
    }

    return stringPool;
}
