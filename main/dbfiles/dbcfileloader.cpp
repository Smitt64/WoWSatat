#include "dbcfileloader.h"
#include <stdlib.h>
#include <string.h>

LocaleNameStr const fullLocaleNameList[] =
{
    { "enUS", LOCALE_enUS },
    { "enGB", LOCALE_enUS },
    { "koKR", LOCALE_koKR },
    { "frFR", LOCALE_frFR },
    { "deDE", LOCALE_deDE },
    { "zhCN", LOCALE_zhCN },
    { "zhTW", LOCALE_zhTW },
    { "esES", LOCALE_esES },
    { "esMX", LOCALE_esMX },
    { "ruRU", LOCALE_ruRU },
    { NULL,   LOCALE_enUS }
};

DBCFileLoader::DBCFileLoader()
{
    data = NULL;
    fieldsOffset = NULL;
}

bool DBCFileLoader::Load(const char* filename, const char* fmt)
{
    quint32 header;
    delete[] data;

    FILE* f = fopen(filename, "rb");
    if (!f)return false;

    if (fread(&header, 4, 1, f) != 1)                       // Number of records
        return false;

    EndianConvert(header);
    if (header != 0x43424457)
        return false;                                       //'WDBC'

    if (fread(&recordCount, 4, 1, f) != 1)                  // Number of records
        return false;

    EndianConvert(recordCount);

    if (fread(&fieldCount, 4, 1, f) != 1)                   // Number of fields
        return false;

    EndianConvert(fieldCount);

    if (fread(&recordSize, 4, 1, f) != 1)                   // Size of a record
        return false;

    EndianConvert(recordSize);

    if (fread(&stringSize, 4, 1, f) != 1)                   // String size
        return false;

    EndianConvert(stringSize);

    fieldsOffset = new quint32[fieldCount];
    fieldsOffset[0] = 0;
    for (quint32 i = 1; i < fieldCount; ++i)
    {
        fieldsOffset[i] = fieldsOffset[i - 1];
        if (fmt[i - 1] == 'b' || fmt[i - 1] == 'X')         // byte fields
            fieldsOffset[i] += 1;
        else                                                // 4 byte fields (int32/float/strings)
            fieldsOffset[i] += 4;
    }

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize * recordCount;

    if (fread(data, recordSize * recordCount + stringSize, 1, f) != 1)
        return false;

    fclose(f);
    return true;
}

DBCFileLoader::~DBCFileLoader()
{
    delete[] data;
    delete[] fieldsOffset;
}

DBCFileLoader::Record DBCFileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id * recordSize);
}

quint32 DBCFileLoader::GetFormatRecordSize(const char* format, qint32* index_pos)
{
    quint32 recordsize = 0;
    qint32 i = -1;
    for (quint32 x = 0; format[x]; ++ x)
    {
        switch (format[x])
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
            i = x;
            break;
        case FT_IND:
            i = x;
            recordsize += sizeof(quint32);
            break;
        case FT_BYTE:
            recordsize += sizeof(quint8);
            break;
        case FT_LOGIC:
            assert(false && "DBC files not have logic field type");
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

quint32 DBCFileLoader::GetFormatStringsFields(const char * format)
{
    quint32 stringfields = 0;
    for(quint32 x=0; format[x];++x)
        if (format[x] == FT_STRING)
            ++stringfields;

    return stringfields;
}

char* DBCFileLoader::AutoProduceData(const char* format, quint32& records, char**& indexTable)
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

    typedef char* ptr;
    if (strlen(format) != fieldCount)
        return NULL;

    // get struct size and index pos
    qint32 i;
    quint32 recordsize = GetFormatRecordSize(format, &i);

    if (i >= 0)
    {
        quint32 maxi = 0;
        // find max index
        for (quint32 y = 0; y < recordCount; ++y)
        {
            quint32 ind = getRecord(y).getUInt(i);
            if (ind > maxi)maxi = ind;
        }

        ++maxi;
        records = maxi;
        indexTable = new ptr[maxi];
        memset(indexTable, 0, maxi * sizeof(ptr));
    }
    else
    {
        records = recordCount;
        indexTable = new ptr[recordCount];
    }

    char* dataTable = new char[recordCount * recordsize];

    quint32 offset = 0;

    for (quint32 y = 0; y < recordCount; ++y)
    {
        if (i >= 0)
        {
            indexTable[getRecord(y).getUInt(i)] = &dataTable[offset];
        }
        else
            indexTable[y] = &dataTable[offset];

        for (quint32 x = 0; x < fieldCount; ++x)
        {
            switch (format[x])
            {
            case FT_FLOAT:
                *((float*)(&dataTable[offset])) = getRecord(y).getFloat(x);
                offset += sizeof(float);
                break;
            case FT_IND:
            case FT_INT:
                *((quint32*)(&dataTable[offset])) = getRecord(y).getUInt(x);
                offset += sizeof(quint32);
                break;
            case FT_BYTE:
                *((quint8*)(&dataTable[offset])) = getRecord(y).getUInt8(x);
                offset += sizeof(quint8);
                break;
            case FT_STRING:
                *((char**)(&dataTable[offset])) = NULL; // will be replaces non-empty or "" strings in AutoProduceStrings
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

char* DBCFileLoader::AutoProduceStringsArrayHolders(const char* format, char* dataTable)
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

char* DBCFileLoader::AutoProduceStrings(const char* format, char* dataTable, LocaleConstant loc)
{
    if (strlen(format) != fieldCount)
        return NULL;

    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * MAX_LOCALE;

    char* stringPool= new char[stringSize];
    memcpy(stringPool,stringTable,stringSize);

    quint32 offset = 0;

    for (quint32 y = 0; y < recordCount; ++y)
    {
        for (quint32 x = 0; x < fieldCount; ++x)
        {
            switch (format[x])
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
                    const char* st = getRecord(y).getString(x);
                    *slot = stringPool + (st - (const char*)stringTable);
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


bool ReadDBCBuildFileText(const std::string& dbc_path, char const* localeName, std::string& text)
{
    std::string filename  = dbc_path + "component.wow-" + localeName + ".txt";

    if(FILE* file = fopen(filename.c_str(),"rb"))
    {
        char buf[100];
        fread(buf,1,100-1,file);
        fclose(file);

        text = &buf[0];
        return true;
    }
    else
        return false;
}

quint32 ReadDBCBuild(const std::string& dbc_path, LocaleNameStr const*&localeNameStr)
{
    std::string text;

    if (!localeNameStr)
    {
        for(LocaleNameStr const* itr = &fullLocaleNameList[0]; itr->name; ++itr)
        {
            if (ReadDBCBuildFileText(dbc_path,itr->name,text))
            {
                localeNameStr = itr;
                break;
            }
        }
    }
    else
        ReadDBCBuildFileText(dbc_path,localeNameStr->name,text);

    if (text.empty())
        return 0;

    size_t pos = text.find("version=\"");
    size_t pos1 = pos + strlen("version=\"");
    size_t pos2 = text.find("\"",pos1);
    if (pos == text.npos || pos2 == text.npos || pos1 >= pos2)
        return 0;

    std::string build_str = text.substr(pos1,pos2-pos1);

    int build = atoi(build_str.c_str());
    if (build <= 0)
        return 0;

    return build;
}
