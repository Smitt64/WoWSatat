#ifndef WDBLOADER_H
#define WDBLOADER_H

#include <stdio.h>
#include <map>
class WDBKeyIndex;
class WDBLoader
{
    typedef struct
    {
      //int magic; // always 'WDBC'
      int record_count;
      int field_count;
      int record_size;
      int string_table_size;
    }DBCHeader;

    typedef struct
    {
        DBCHeader hdr;

        int table_hash;
        int build;
        int timestamp_last_written;                              // set to time(0); when writing in WowClientDB2_Base::Save()
        int min_id;
        int max_id;
        int locale;                                              // as seen in TextWowEnum
        int unk2;
    } DB2Header;
public:
    WDBLoader(const char *formt);

    virtual void load(const char *file);
    int GetNumRows() const { return recordCount; }
    int GetFieldCount() const { return fieldCount; }
    int GetIndexField() const { return indexField; }

    WDBKeyIndex *index() { return m_index; }

protected:
    char *_format;
    int fmtCount;

    void loadWDBC(FILE *f);
    void loadWDB2(FILE *f);
    void cookData();
    int fieldCount;
    int recordCount;
    int recordSize;
    int stringTableSize;
    int dataLen;

    char *dataTable;
    char *string_block;

    int *offsets;
    int *indeces;
    int indexField;
    WDBKeyIndex *m_index;
};

#endif // WDBLOADER_H
