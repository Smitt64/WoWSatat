#include "wdbloader.h"
#include <string.h>
#include <vector>
#include <omp.h>

#include "wdbkeyindex.h"

WDBLoader::WDBLoader(const char *format)
{
    dataTable = NULL;
    _format = new char[strlen(format) + 1];

    fmtCount = strlen(format);
    memset(_format, 0, strlen(format) + 1);
    strcpy(_format, format);
    indexField = -1;

    offsets = new int[fmtCount];

    int offset = 0;
    for (int i = 0; i < fmtCount; i++)
    {
        offsets[i] = offset;
        switch (_format[i])
        {
        case 'i':
            offset += sizeof(int);
            break;
        case 'n':
            if (indexField <= 0)
                indexField = i;
            offset += sizeof(int);
            break;
        case 'f':
            offset += sizeof(float);
            break;
        case 'd':
            offset += sizeof(double);
            break;
        case 's':
            offset += sizeof(char*);
            break;
        default:
            offset += sizeof(int);
            break;
        }
    }
    indeces = NULL;
    m_index = new WDBKeyIndex();
}

void WDBLoader::load(const char *file)
{
    FILE *f = NULL;

    fopen_s(&f, file, "rb");

    if (!f)
        return;

    char magic[5] = {0};
    fread(&magic, sizeof(int), 1, f);

    if (strcmp(magic, "WDBC") == 0)
    {
        loadWDBC(f);
    }
    else if (strcmp(magic, "WDB2") == 0)
    {
        loadWDB2(f);
    }
}

void WDBLoader::cookData()
{
    char *ptr = dataTable;
    std::vector<int> strFields;
    for (int j = 0; j < fmtCount; j++)
    {
        if (_format[j] == 's')
        {
            strFields.push_back(j);
        }
    }

    int maxi = 0;
#pragma omp parallel for
    for (int i = 0; i < recordCount; i++)
    {
        std::for_each(strFields.begin(), strFields.end(), [this, &ptr, i](short j){
            int strind = *reinterpret_cast<int*>(ptr + offsets[j]);
            memset(ptr + offsets[j], 0, sizeof(int));
            if (strind >= 0 && strind < stringTableSize)
            {
                char *ptr_to_str = (char*)string_block + strind;
                int p = reinterpret_cast<int>(ptr_to_str);
                memcpy(ptr + offsets[j], &p, sizeof(int));

                if (i == 83447)
                {
                    qDebug() << ptr_to_str << *(int*)(ptr + offsets[j]);
                }
            }
        });

        if (!indeces)
        {
            int ind = *reinterpret_cast<int*>(ptr + offsets[indexField]);
            if (ind > maxi)maxi = ind;
        }

        /*if (indexField >= 0)
        {
            int ind = *reinterpret_cast<int*>(ptr + offsets[indexField]);
            m_index->insert(ind, i * recordSize);
        }*/

        ptr += recordSize;
    }

    if (!indeces)
    {
        indeces = new int[maxi];
        ptr = dataTable;
#pragma omp parallel for
        for (int i = 0; i < recordCount; i++)
        {
            int ind = *reinterpret_cast<int*>(ptr + offsets[indexField]);
            indeces[ind] = i;

            ptr += recordSize;
        }
    }

    strFields.erase(strFields.begin(), strFields.end());
}

void WDBLoader::loadWDB2(FILE *f)
{
    DB2Header header;
    memset(&header, 0, sizeof(DBCHeader));

    fread((char*)&header, sizeof(DB2Header), 1, f);

    fieldCount = header.hdr.field_count;
    recordCount = header.hdr.record_count;
    recordSize = header.hdr.record_size;
    stringTableSize = header.hdr.string_table_size;
    dataLen = recordCount * recordSize;

    if (header.max_id > 0)
    {
        //indeces = new int[header.max_id - header.min_id + 1];
        //fread(indeces, (header.max_id - header.min_id + 1) * sizeof(int), 1, f);
        fseek(f, (header.max_id - header.min_id + 1) * sizeof(int), SEEK_CUR);
        fseek(f, (header.max_id - header.min_id + 1) * sizeof(short), SEEK_CUR);
    }

    dataTable = new char[dataLen];
    fread((char*)dataTable, dataLen, 1, f);

    string_block = new char[header.hdr.string_table_size];
    fread((char*)string_block, header.hdr.string_table_size, 1, f);

    cookData();
}

void WDBLoader::loadWDBC(FILE *f)
{
    DBCHeader header;
    memset(&header, 0, sizeof(DBCHeader));

    fread((char*)&header, sizeof(DBCHeader), 1, f);

    fieldCount = header.field_count;
    recordCount = header.record_count;
    recordSize = header.record_size;
    stringTableSize = header.string_table_size;
    dataLen = recordCount * recordSize;

    dataTable = new char[dataLen];
    fread((char*)dataTable, dataLen, 1, f);

    string_block = new char[header.string_table_size];
    fread((char*)string_block, header.string_table_size, 1, f);

    cookData();
}
