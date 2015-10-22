#include "wowstatobject.h"
#include "dbfiles/dbcfileloader.h"
#include "dbfiles/dbcstorage.h"
#include "dbfiles/dbcstructure.h"
#include "dbfiles/itemsdbc.h"
#include <QThreadPool>
#include <QSqlQuery>
#include <QList>
#include <initializer_list>

WoWDbcLoaderRunable::WoWDbcLoaderRunable(const QString path, QObject *bar)
{
    _bar = bar;
    _path = path;
    setAutoDelete(true);
}

void WoWDbcLoaderRunable::run()
{
    std::string dbcPath = _path.toStdString();

    LocaleNameStr const* defaultLocaleNameStr = &fullLocaleNameList[0];
    quint32 build = ReadDBCBuild(dbcPath,defaultLocaleNameStr);

    StoreProblemList bad_dbc_files;
    LocalData availableDbcLocales(build,defaultLocaleNameStr->locale);
    LocalDB2Data availableDb2Locales(LocaleConstant(0));

    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellAuraOptionsStore,         dbcPath,"SpellAuraOptions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellAuraRestrictionsStore,    dbcPath,"SpellAuraRestrictions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCastingRequirementsStore, dbcPath,"SpellCastingRequirements.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCategoriesStore,          dbcPath,"SpellCategories.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellClassOptionsStore,        dbcPath,"SpellClassOptions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCooldownsStore,           dbcPath,"SpellCooldowns.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellEffectStore,              dbcPath,"SpellEffect.dbc");

    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellIconStore,                dbcPath,"SpellIcon.dbc");

    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sItemClass,                     dbcPath,"ItemClass.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sItemSubClass,                  dbcPath,"ItemSubClass.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sChrClasses,                    dbcPath,"ChrClasses.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sChrRaces,                      dbcPath,"ChrRaces.dbc");

    // ==========================================================================================================================
    //LoadDB2(availableDb2Locales,_bar,bad_dbc_files,sItemSparse,                    dbcPath,"Item-sparse.db2");

    qDebug() << "load time ChrClasses: " << time_call([]()
    {
        wChrClasses.load("dbc/ChrClasses.dbc");
    });

    qDebug() << "load time Item-sparse: " << time_call([]()
    {
        wItemSparse.load("db2/Item-sparse.db2");
    });

    const ItemSparse *item = NULL;
    qDebug() << "Found time: " << time_call([&item]()
    {
        item = wItemSparse.LookupEntry(125194);
    });

    emit finished();
}

// -------------------------------------------------------

WowStatObject::WowStatObject(QObject *parent)
    : QObject(parent)
{
    /*QDir d = QDir::current();
    db = QSqlDatabase::addDatabase("QSQLITE", "cache");
    db.setDatabaseName(d.absoluteFilePath("wowstatcache.db"));

    if (db.open())
    {
    }*/
}

int WowStatObject::init()
{
    return WowStatObject::INIT_NOERROR;
}

void WowStatObject::loadDBCStores(QObject *bar, const QString path)
{
    WoWDbcLoaderRunable *r = new WoWDbcLoaderRunable(path, bar);
    connect(r, SIGNAL(finished()), SIGNAL(finishLoadDbc()));
    QThreadPool::globalInstance()->start(r);
}

int WowStatObject::dbcCount()
{
    return 12;
}

void WowStatObject::checkCacheTable(const QString &table)
{
    /*if (!db.tables().contains(table))
    {
        QFile f(QString("qrc:/sql/%1.sql").arg(table));

        if (f.open(QIODevice::ReadOnly))
        {
            QSqlQuery q;
            q.exec(f.readAll());
            f.close();
        }
    }*/
}

QSqlQuery WowStatObject::makeCacheQuery()
{
    return QSqlQuery(db);
}

QString WowStatObject::chrClassName(const quint8 &chrclass)
{
    ///const ChrClasses *item =  sChrClasses.LookupEntry((quint32)chrclass);
    const WChrClasses *item = wChrClasses.LookupEntry(chrclass);

    if (!item)
        return QString("");

    return QString(item->name);
}

QString WowStatObject::chrRaceName(const quint8 &race) const
{
    const ChrRaces *item =  sChrRaces.LookupEntry((quint32)race);

    if (!item)
        return QString("");

    return QString(*item->name_lang);
}

QVector3D WowStatObject::convertToMoney(const quint32 &m)
{
    QVector3D result;

    int copper = m % 100;
    int m2 = (m - copper) / 100;
    int silver = m2 % 100;
    int gold = (m2 - silver) / 100;
    result[0] = copper;
    result[1] = silver;
    result[2] = gold;
    return result;
}

QString WowStatObject::raidClassColors(const quint8 &chrclass) const
{
    QString s;

    switch (chrclass)
    {
    case Warrior:
        s = "#ffc79c6e";
        break;
    case Paladin:
        s = "#fff58cba";
        break;
    case Hunter:
        s = "#ffabd473";
        break;
    case Rogue:
        s = "#fffff569";
        break;
    case Priest:
        s = "#ffffffff";
        break;
    case DeathKnight:
        s = "#ffc41f3b";
        break;
    case Shaman:
        s = "#ff0070de";
        break;
    case Mage:
        s = "#ff69ccf0";
        break;
    case Warlock:
        s = "#ff9482c9";
        break;
    case Druid:
        s = "#ffff7d0a";
        break;
    case Monk:
        s = "#ff00ff96";
        break;
    }

    return s;
}
