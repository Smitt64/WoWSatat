#ifndef DBCSTRUCTURE
#define DBCSTRUCTURE

#include "dbcstorage.h"

struct SpellAuraOptionsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    StackAmount;                                  // 51       m_cumulativeAura
    quint32    procChance;                                   // 38       m_procChance
    quint32    procCharges;                                  // 39       m_procCharges
    quint32    procFlags;                                    // 37       m_procTypeMask
};

extern DBCStorage<SpellAuraOptionsEntry> sSpellAuraOptionsEntry;

#endif // DBCSTRUCTURE

