#ifndef DB2FILELOADER
#define DB2FILELOADER

#include <QtCore>
#include "defines.h"
#include "dbcstorage.h"
#include <cassert>

class DB2FileLoader
{
    public:
        DB2FileLoader();
        ~DB2FileLoader();

    bool Load(const char *filename, const char *fmt);

    class Record
    {
    public:
        float getFloat(quint32 field) const
        {
            assert(field < file.fieldCount);
            float val = *reinterpret_cast<float*>(offset+file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        quint32 getUInt(quint32 field) const
        {
            assert(field < file.fieldCount);
            quint32 val = *reinterpret_cast<quint32*>(offset+file.GetOffset(field));
            EndianConvert(val);
            return val;
        }
        quint32 getUInt8(quint32 field) const
        {
            assert(field < file.fieldCount);
            return *reinterpret_cast<quint8*>(offset+file.GetOffset(field));
        }

        const char *getString(size_t field) const
        {
            assert(field < file.fieldCount);
            size_t stringOffset = getUInt(field);
            //assert(stringOffset < file.stringSize);
            return reinterpret_cast<char*>(file.stringTable + stringOffset);
        }

    private:
        Record(DB2FileLoader &file_, unsigned char *offset_): offset(offset_), file(file_) {}
        unsigned char *offset;
        DB2FileLoader &file;

        friend class DB2FileLoader;

    };

    // Get record by id
    Record getRecord(size_t id);
    /// Get begin iterator over records

    quint32 GetNumRows() const { return recordCount;}
    quint32 GetCols() const { return fieldCount; }
    quint32 GetOffset(size_t id) const { return (fieldsOffset != NULL && id < fieldCount) ? fieldsOffset[id] : 0; }
    bool IsLoaded() const { return (data != NULL); }
    char* AutoProduceData(const char* fmt, qint32& count, char**& indexTable);
    char* AutoProduceStringsArrayHolders(const char* fmt, char* dataTable);
    char* AutoProduceStrings(const char* fmt, char* dataTable, LocaleConstant loc);
    static quint32 GetFormatRecordSize(const char * format, qint32 * index_pos = NULL);
    static quint32 GetFormatStringsFields(const char * format);
private:

    quint32 recordSize;
    quint32 recordCount;
    quint32 fieldCount;
    quint32 stringSize;
    quint32 *fieldsOffset;
    unsigned char *data;
    unsigned char *stringTable;

    // WDB2 / WCH2 fields
    quint32 tableHash;    // WDB2
    quint32 build;        // WDB2

    int unk1;            // WDB2 (Unix time in WCH2)
    int unk2;            // WDB2
    int unk3;            // WDB2 (index table)
    int locale;          // WDB2
    int unk5;            // WDB2
};

#endif // DB2FILELOADER

