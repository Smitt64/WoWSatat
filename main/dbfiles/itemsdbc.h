#ifndef ITEMSDBC
#define ITEMSDBC

#include <QtCore>
#include "defines.h"

typedef struct
{
    quint32 classID;
    quint32 flags;
    quint32 unused1;
    quint32 unused2;
    float priceModifier;
    DBCString className;
}ItemClass;

typedef struct
{
    quint32 id;
    quint32 itemClass;
    quint32 itemSubClass;
    quint32 unknown1;
    quint32 unknown2;
    quint32 flags;
    quint32 displayFlags;
    quint32 weaponParrySeq;
    quint32 weaponReadySeq;
    quint32 weaponAttackSeq;
    quint32 weaponSwingSize;

    DBCString displayName;
    DBCString verboseName;
} ItemSubClass;

typedef struct {
    int    Id;                                           // 0
    int    Quality;                                      // 1
    int    Flags;                                        // 2
    int    Flags2;
    int    Unk430;
    float  Unk430_1;
    float  Unk430_2;
    int    BuyCount;
    int    BuyPrice;                                     // 4
    int    SellPrice;                                    // 5
    int    InventoryType;                                // 6
    int    AllowableClass;                               // 7
    int    AllowableRace;                                // 8
    int    ItemLevel;                                    // 9
    int    RequiredLevel;                                // 10
    int    RequiredSkill;                                // 11
    int    RequiredSkillRank;                            // 12
    int    RequiredSpell;                                // 13
    int    RequiredHonorRank;                            // 14
    int    RequiredCityRank;                             // 15
    int    RequiredReputationFaction;                    // 16
    int    RequiredReputationRank;                       // 17
    int    MaxCount;                                     // 18
    int    Stackable;                                    // 19
    int    ContainerSlots;                               // 20
    int    ItemStatType1;                                // 21 - 30
    int    ItemStatType2;                                // 21 - 30
    int    ItemStatType3;                                // 21 - 30
    int    ItemStatType4;                                // 21 - 30
    int    ItemStatType5;                                // 21 - 30
    int    ItemStatType6;                                // 21 - 30
    int    ItemStatType7;                                // 21 - 30
    int    ItemStatType8;                                // 21 - 30
    int    ItemStatType9;                                // 21 - 30                              // 21 - 30
    int    ItemStatValue1;                               // 31 - 40
    int    ItemStatValue2;                               // 31 - 40
    int    ItemStatValue3;                               // 31 - 40
    int    ItemStatValue4;                               // 31 - 40
    int    ItemStatValue5;                               // 31 - 40
    int    ItemStatValue6;                               // 31 - 40
    int    ItemStatValue7;                               // 31 - 40
    int    ItemStatValue8;                               // 31 - 40
    int    ItemStatValue9;                               // 31 - 40                             // 31 - 40
    int    ItemStatUnk1_1;
    int    ItemStatUnk1_2;
    int    ItemStatUnk1_3;
    int    ItemStatUnk1_4;
    int    ItemStatUnk1_5;
    int    ItemStatUnk1_6;
    int    ItemStatUnk1_7;
    int    ItemStatUnk1_8;
    int    ItemStatUnk2_1;
    int    ItemStatUnk2_2;
    int    ItemStatUnk2_3;
    int    ItemStatUnk2_4;
    int    ItemStatUnk2_5;
    float    ScalingStatDistribution;                      // 61
    float    DamageType;                                   // 62
    float    Delay;                                        // 63
    float   RangedModRange;
    float   Unk430_3;
    int    SpellId1;
    int    SpellId2;
    int    SpellId3;
    int    SpellId4;
    int    SpellTrigger1;
    int    SpellTrigger2;
    int    SpellTrigger3;
    int    SpellTrigger4;
    float  Bonding;
    int    Unk430_4;
    int    PageText;
    char* Name;                              // 101
    int    LanguageID;                                   // 102
    int    PageMaterial;
    int    StartQuest;                                               // 96                                    // 99
    char* Description;                            // 104
    int    LockID;                                       // 105
    int    Material;                                     // 106
    int    Sheath;                                       // 107
    int    RandomProperty;                               // 108
    int    RandomSuffix;                                 // 109
    int    ItemSet;                                      // 110
    int    Area;                                         // 112
    int    Map;                                          // 113
    int    BagFamily;                                    // 114
    int    TotemCategory;                                // 115
    int    Color1;                                       // 116
    int    Color2;                                       // 117
    int    Color3;                                       // 118
    int    Content1;                                     // 119
    int    Content2;                                     // 120
    int    Content3;                                     // 121
    int    SocketBonus;                                  // 122
    int    GemProperties;
    float  ArmorDamageModifier;                          // 124                                  // 125
    int    ItemLimitCategory;                            // 126
    int    HolidayId;
    int    Unk430_5; // 127
    float  StatScalingFactor;                            // 128
    int    Field130;                                     // 129
    int    Field131;
}ItemSparse;

extern const ItemSparse *const FindItemSparse(const quint32 &itemId);

#endif // ITEMSDBC

