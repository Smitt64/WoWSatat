#include "wowstatobject.h"
#include "dbfiles/dbcfileloader.h"
#include "dbfiles/dbcstorage.h"
#include "dbfiles/dbcstructure.h"
#include <QThreadPool>

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

    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellAuraOptionsStore,         dbcPath,"SpellAuraOptions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellAuraRestrictionsStore,    dbcPath,"SpellAuraRestrictions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCastingRequirementsStore, dbcPath,"SpellCastingRequirements.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCategoriesStore,          dbcPath,"SpellCategories.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellClassOptionsStore,        dbcPath,"SpellClassOptions.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellCooldownsStore,           dbcPath,"SpellCooldowns.dbc");
    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellEffectStore,              dbcPath,"SpellEffect.dbc");

    LoadDBC(availableDbcLocales,_bar,bad_dbc_files,sSpellIconStore,              dbcPath,"SpellIcon.dbc");

    emit finished();
}

// -------------------------------------------------------

WowStatObject::WowStatObject(QObject *parent)
    : QObject(parent)
{

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
    return 7;
}
