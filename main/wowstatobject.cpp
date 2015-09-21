#include "wowstatobject.h"
#include "dbfiles/dbcfileloader.h"
#include "dbfiles/dbcstorage.h"
#include "dbfiles/dbcstructure.h"

WowStatObject::WowStatObject(QObject *parent)
    : QObject(parent)
{

}

int WowStatObject::init()
{
    return WowStatObject::INIT_NOERROR;
}

void WowStatObject::loadDBCStores(const QString *path)
{
    std::string dbcPath = path->toStdString();

    LocaleNameStr const* defaultLocaleNameStr = NULL;
    quint32 build = ReadDBCBuild(dbcPath,defaultLocaleNameStr);

    StoreProblemList bad_dbc_files;
    LocalData availableDbcLocales(build,defaultLocaleNameStr->locale);

    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellAuraOptionsStore,         dbcPath,"SpellAuraOptions.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellAuraRestrictionsStore,    dbcPath,"SpellAuraRestrictions.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellCastingRequirementsStore, dbcPath,"SpellCastingRequirements.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellCategoriesStore,          dbcPath,"SpellCategories.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellClassOptionsStore,        dbcPath,"SpellClassOptions.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellCooldownsStore,           dbcPath,"SpellCooldowns.dbc");
    LoadDBC(availableDbcLocales,/*bar,*/bad_dbc_files,sSpellEffectStore,              dbcPath,"SpellEffect.dbc");
}
