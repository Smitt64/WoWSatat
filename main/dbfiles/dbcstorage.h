#ifndef DBCSTORAGE
#define DBCSTORAGE

#include "DBCFileLoader.h"

template<class T>
class DBCStorage
{
    typedef std::list<char*> StringPoolList;
public:
    explicit DBCStorage(const char* f) : nCount(0), fieldCount(0), fmt(f), indexTable(NULL), m_dataTable(NULL) { }
    ~DBCStorage() { Clear(); }

    T const* LookupEntry(quint32 id) const { return (id >= nCount) ? NULL : indexTable[id]; }
    quint32  GetNumRows() const { return nCount; }
    char const* GetFormat() const { return fmt; }
    quint32 GetFieldCount() const { return fieldCount; }

    bool Load(char const* fn, LocaleConstant loc)
    {
        DBCFileLoader dbc;
        // Check if load was sucessful, only then continue
        if (!dbc.Load(fn, fmt))
            return false;

        fieldCount = dbc.GetCols();

        // load raw non-string data
        m_dataTable = (T*)dbc.AutoProduceData(fmt, nCount, (char**&)indexTable);

        // create string holders for loaded string fields
        m_stringPoolList.push_back(dbc.AutoProduceStringsArrayHolders(fmt,(char*)m_dataTable));

        // load strings from dbc data
        m_stringPoolList.push_back(dbc.AutoProduceStrings(fmt,(char*)m_dataTable,loc));

        // error in dbc file at loading if NULL
        return indexTable != NULL;
    }

    bool LoadStringsFrom(char const* fn, LocaleConstant loc)
    {
        // DBC must be already loaded using Load
        if (!indexTable)
            return false;

        DBCFileLoader dbc;
        // Check if load was successful, only then continue
        if (!dbc.Load(fn, fmt))
            return false;

        // load strings from another locale dbc data
        m_stringPoolList.push_back(dbc.AutoProduceStrings(fmt,(char*)m_dataTable,loc));

        return true;
    }

    void Clear()
    {
        if (!indexTable)
            return;

        delete[]((char*)indexTable);
        indexTable = NULL;
        delete[]((char*)m_dataTable);
        m_dataTable = NULL;

        while (!m_stringPoolList.empty())
        {
            delete[] m_stringPoolList.front();
            m_stringPoolList.pop_front();
        }
        nCount = 0;
    }

    void EraseEntry(quint32 id) { assert(id < nCount && "To be erased entry must be in bounds!") ; indexTable[id] = NULL; }
    void InsertEntry(T* entry, quint32 id) { assert(id < nCount && "To be inserted entry must be in bounds!"); indexTable[id] = entry; }

private:
    quint32 nCount;
    quint32 fieldCount;
    char const* fmt;
    T** indexTable;
    T* m_dataTable;
    StringPoolList m_stringPoolList;
};

#endif // DBCSTORAGE

