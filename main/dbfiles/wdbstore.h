#ifndef WDBSTORE
#define WDBSTORE

#include "wdbloader.h"
#include "wdbkeyindex.h"
template<class T>
class WDBStore : public WDBLoader
{
public:
    class WDBRecord
    {
        friend class WDBStore;
    public:
        char fldType(const short fld) const
        {
            return _parent->_format[fld];
        }

        int getOffset(const short &field)
        {
            return _parent->offsets[field];
        }

        T *const operator ->() const
        {
            return (T*)recordOffset;
        }

        int getInt(const short &field)
        {
            return *reinterpret_cast<int*>(offset + getOffset(field));
        }

        int getFloat(const short &field)
        {
            return *reinterpret_cast<float*>(offset + getOffset(field));
        }

    private:
        WDBRecord(const WDBStore * const parent, int recordNum)
        {
            recordOffset = (T*)(parent->dataTable + recordNum * parent->recordSize);
            _parent = parent;
        }

        WDBStore *_parent;
        T *recordOffset;
    };

    WDBStore(const char *format) :
        WDBLoader(format)
    {
        //static_assert(sizeof(T) == recordSize, "WDB size not equal struct size");
    }

    WDBRecord GetRecord(const int &record)
    {
        return WDBRecord(this, record);
    }

    T const* LookupEntry(int id)
    {
        /*int _index = index()->search(id);

        if (_index < 0)
            return NULL;

        return (T*)(dataTable + _index);*/
        qDebug() << id << indeces[id];
        return GetRecordStruct(indeces[id]);
    }

    const T * const GetRecordStruct(const int &record) const
    {
        return (T*)(dataTable + record * recordSize);
    }

private:

};

#endif // WDBSTORE

