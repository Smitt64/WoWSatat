#ifndef DBCSTRUCTURE
#define DBCSTRUCTURE

#include "dbcstorage.h"
#include "db2store.h"
#include "spells.h"
#include "itemsdbc.h"
#include "common.h"
#include "wdbstore.h"

/*extern DBCStorage <SpellRadiusEntry>             sSpellRadiusStore;
extern DBCStorage <SpellRangeEntry>              sSpellRangeStore;
extern DBCStorage <SpellRuneCostEntry>           sSpellRuneCostStore;
extern DBCStorage <SpellShapeshiftFormEntry>     sSpellShapeshiftFormStore;*/
extern DBCStorage <SpellEntry>                    sSpellStore;
extern DBCStorage <SpellAuraOptionsEntry>         sSpellAuraOptionsStore;
extern DBCStorage <SpellAuraRestrictionsEntry>    sSpellAuraRestrictionsStore;
extern DBCStorage <SpellCastingRequirementsEntry> sSpellCastingRequirementsStore;
extern DBCStorage <SpellCategoriesEntry>          sSpellCategoriesStore;
extern DBCStorage <SpellClassOptionsEntry>        sSpellClassOptionsStore;
extern DBCStorage <SpellCooldownsEntry>           sSpellCooldownsStore;
extern DBCStorage <SpellEffectEntry>              sSpellEffectStore;
extern DBCStorage <SpellEquippedItemsEntry>       sSpellEquippedItemsStore;
extern DBCStorage <SpellInterruptsEntry>          sSpellInterruptsStore;
extern DBCStorage <SpellLevelsEntry>              sSpellLevelsStore;
extern DBCStorage <SpellPowerEntry>               sSpellPowerStore;
extern DBCStorage <SpellReagentsEntry>            sSpellReagentsStore;
extern DBCStorage <SpellScalingEntry>             sSpellScalingStore;
extern DBCStorage <SpellShapeshiftEntry>          sSpellShapeshiftStore;
extern DBCStorage <SpellTargetRestrictionsEntry>  sSpellTargetRestrictionsStore;
extern DBCStorage <SpellTotemsEntry>              sSpellTotemsStore;
extern DBCStorage <SpellIconEntry>                sSpellIconStore;

extern DBCStorage <ItemClass>                     sItemClass;
extern DBCStorage <ItemSubClass>                  sItemSubClass;
extern DBCStorage <ChrClasses>                    sChrClasses;
extern DBCStorage <ChrRaces>                      sChrRaces;

extern WDBStore <ItemSparse>                      wItemSparse;
extern WDBStore <WChrClasses> wChrClasses;

#endif // DBCSTRUCTURE

