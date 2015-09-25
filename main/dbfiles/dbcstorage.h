#ifndef DBCSTORAGE
#define DBCSTORAGE

#include "DBCFileLoader.h"
#include <QDebug>
#include <QObject>
#include <QtTest/QTest>

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

struct LocalData
{
    LocalData(quint32 build, LocaleConstant loc)
        : main_build(build), defaultLocale(loc), availableDbcLocales(0xFFFFFFFF),checkedDbcLocaleBuilds(0) {}

    quint32 main_build;
    LocaleConstant defaultLocale;

    // bitmasks for index of fullLocaleNameList
    quint32 availableDbcLocales;
    quint32 checkedDbcLocaleBuilds;
};

typedef std::list<std::string> StoreProblemList;

template<class T>
inline void LoadDBC(LocalData& localeData, QObject *bar, StoreProblemList& errlist, DBCStorage<T>& storage, const std::string& dbc_path, const std::string& filename)
{
    // compatibility format and C++ structure sizes
    //MANGOS_ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T) || LoadDBC_assert_print(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()),sizeof(T),filename));

    std::string dbc_filename = dbc_path + "dbc/" + filename;
    if(storage.Load(dbc_filename.c_str(),localeData.defaultLocale))
    {
        QMetaObject::invokeMethod(bar, "step");
        QMetaObject::invokeMethod(bar, "appendToLog", Q_ARG(QVariant, QObject::tr("Loading [%1]").arg(filename.c_str())));

        for(quint8 i = 0; fullLocaleNameList[i].name; ++i)
        {
            if (!(localeData.availableDbcLocales & (1 << i)))
                continue;

            LocaleNameStr const* localStr = &fullLocaleNameList[i];

            std::string dbc_dir_loc = dbc_path + localStr->name + "/";

            if (!(localeData.checkedDbcLocaleBuilds & (1 << i)))
            {
                localeData.checkedDbcLocaleBuilds |= (1<<i);// mark as checked for speedup next checks

                quint32 build_loc = ReadDBCBuild(dbc_dir_loc,localStr);
                if(localeData.main_build != build_loc)
                {
                    localeData.availableDbcLocales &= ~(1<<i);  // mark as not available for speedup next checks

                    // exist but wrong build
                    if (build_loc)
                    {
                        std::string dbc_filename_loc = dbc_path + localStr->name + "/" + filename;
                        char buf[200];
                        snprintf(buf,200," (exist, but DBC locale subdir %s have DBCs for build %u instead expected build %u, it and other DBC from subdir skipped)",localStr->name,build_loc,localeData.main_build);
                        errlist.push_back(dbc_filename_loc + buf);

                        QMetaObject::invokeMethod(bar, "appendToLog", Q_ARG(QString, QString::fromStdString(dbc_filename_loc + buf)));
                    }

                    continue;
                }
            }

            std::string dbc_filename_loc = dbc_path + localStr->name + "/" + filename;
            if(!storage.LoadStringsFrom(dbc_filename_loc.c_str(),localStr->locale))
                localeData.availableDbcLocales &= ~(1<<i);  // mark as not available for speedup next checks
        }
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) nonexistent
        FILE * f=fopen(dbc_filename.c_str(),"rb");
        if(f)
        {
            char buf[100];
            snprintf(buf, 100, " (exist, but have %u fields instead \"%u\") Wrong client version DBC file?", storage.GetFieldCount(), strlen(storage.GetFormat()));
            errlist.push_back(dbc_filename + buf);
            QMetaObject::invokeMethod(bar, "appendToLog", Q_ARG(QString, QString::fromStdString(dbc_filename + buf)));
            fclose(f);
        }
        else
            errlist.push_back(dbc_filename);
    }
     QTest::qWait(1000);
}

#endif // DBCSTORAGE

