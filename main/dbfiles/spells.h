#ifndef SPELLS
#define SPELLS

#include "dbcstorage.h"

enum SpellFamily
{
    SPELLFAMILY_GENERIC     = 0,
    SPELLFAMILY_UNK1        = 1,                            // events, holidays
    // 2 - unused
    SPELLFAMILY_MAGE        = 3,
    SPELLFAMILY_WARRIOR     = 4,
    SPELLFAMILY_WARLOCK     = 5,
    SPELLFAMILY_PRIEST      = 6,
    SPELLFAMILY_DRUID       = 7,
    SPELLFAMILY_ROGUE       = 8,
    SPELLFAMILY_HUNTER      = 9,
    SPELLFAMILY_PALADIN     = 10,
    SPELLFAMILY_SHAMAN      = 11,
    SPELLFAMILY_UNK2        = 12,                           // 2 spells (silence resistance)
    SPELLFAMILY_POTION      = 13,
    // 14 - unused
    SPELLFAMILY_DEATHKNIGHT = 15,
    // 16 - unused
    SPELLFAMILY_PET         = 17
};

enum SpellEffectIndex
{
    EFFECT_INDEX_0     = 0,
    EFFECT_INDEX_1     = 1,
    EFFECT_INDEX_2     = 2
};

enum SpellEffects
{
    SPELL_EFFECT_NONE                      = 0,
    SPELL_EFFECT_INSTAKILL                 = 1,
    SPELL_EFFECT_SCHOOL_DAMAGE             = 2,
    SPELL_EFFECT_DUMMY                     = 3,
    SPELL_EFFECT_PORTAL_TELEPORT           = 4,
    SPELL_EFFECT_TELEPORT_UNITS            = 5,
    SPELL_EFFECT_APPLY_AURA                = 6,
    SPELL_EFFECT_ENVIRONMENTAL_DAMAGE      = 7,
    SPELL_EFFECT_POWER_DRAIN               = 8,
    SPELL_EFFECT_HEALTH_LEECH              = 9,
    SPELL_EFFECT_HEAL                      = 10,
    SPELL_EFFECT_BIND                      = 11,
    SPELL_EFFECT_PORTAL                    = 12,
    SPELL_EFFECT_RITUAL_BASE               = 13,
    SPELL_EFFECT_RITUAL_SPECIALIZE         = 14,
    SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL    = 15,
    SPELL_EFFECT_QUEST_COMPLETE            = 16,
    SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL    = 17,
    SPELL_EFFECT_RESURRECT                 = 18,
    SPELL_EFFECT_ADD_EXTRA_ATTACKS         = 19,
    SPELL_EFFECT_DODGE                     = 20,
    SPELL_EFFECT_EVADE                     = 21,
    SPELL_EFFECT_PARRY                     = 22,
    SPELL_EFFECT_BLOCK                     = 23,
    SPELL_EFFECT_CREATE_ITEM               = 24,
    SPELL_EFFECT_WEAPON                    = 25,
    SPELL_EFFECT_DEFENSE                   = 26,
    SPELL_EFFECT_PERSISTENT_AREA_AURA      = 27,
    SPELL_EFFECT_SUMMON                    = 28,
    SPELL_EFFECT_LEAP                      = 29,
    SPELL_EFFECT_ENERGIZE                  = 30,
    SPELL_EFFECT_WEAPON_PERCENT_DAMAGE     = 31,
    SPELL_EFFECT_TRIGGER_MISSILE           = 32,
    SPELL_EFFECT_OPEN_LOCK                 = 33,
    SPELL_EFFECT_SUMMON_CHANGE_ITEM        = 34,
    SPELL_EFFECT_APPLY_AREA_AURA_PARTY     = 35,
    SPELL_EFFECT_LEARN_SPELL               = 36,
    SPELL_EFFECT_SPELL_DEFENSE             = 37,
    SPELL_EFFECT_DISPEL                    = 38,
    SPELL_EFFECT_LANGUAGE                  = 39,
    SPELL_EFFECT_DUAL_WIELD                = 40,
    SPELL_EFFECT_JUMP                      = 41,
    SPELL_EFFECT_JUMP2                     = 42,
    SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER = 43,
    SPELL_EFFECT_SKILL_STEP                = 44,
    SPELL_EFFECT_PLAY_MOVIE                = 45,
    SPELL_EFFECT_SPAWN                     = 46,
    SPELL_EFFECT_TRADE_SKILL               = 47,
    SPELL_EFFECT_STEALTH                   = 48,
    SPELL_EFFECT_DETECT                    = 49,
    SPELL_EFFECT_TRANS_DOOR                = 50,
    SPELL_EFFECT_FORCE_CRITICAL_HIT        = 51,
    SPELL_EFFECT_GUARANTEE_HIT             = 52,
    SPELL_EFFECT_ENCHANT_ITEM              = 53,
    SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY    = 54,
    SPELL_EFFECT_TAMECREATURE              = 55,
    SPELL_EFFECT_SUMMON_PET                = 56,
    SPELL_EFFECT_LEARN_PET_SPELL           = 57,
    SPELL_EFFECT_WEAPON_DAMAGE             = 58,
    SPELL_EFFECT_CREATE_RANDOM_ITEM        = 59,
    SPELL_EFFECT_PROFICIENCY               = 60,
    SPELL_EFFECT_SEND_EVENT                = 61,
    SPELL_EFFECT_POWER_BURN                = 62,
    SPELL_EFFECT_THREAT                    = 63,
    SPELL_EFFECT_TRIGGER_SPELL             = 64,
    SPELL_EFFECT_APPLY_AREA_AURA_RAID      = 65,
    SPELL_EFFECT_RESTORE_ITEM_CHARGES      = 66,
    SPELL_EFFECT_HEAL_MAX_HEALTH           = 67,
    SPELL_EFFECT_INTERRUPT_CAST            = 68,
    SPELL_EFFECT_DISTRACT                  = 69,
    SPELL_EFFECT_PULL                      = 70,
    SPELL_EFFECT_PICKPOCKET                = 71,
    SPELL_EFFECT_ADD_FARSIGHT              = 72,
    SPELL_EFFECT_UNTRAIN_TALENTS           = 73,
    SPELL_EFFECT_APPLY_GLYPH               = 74,
    SPELL_EFFECT_HEAL_MECHANICAL           = 75,
    SPELL_EFFECT_SUMMON_OBJECT_WILD        = 76,
    SPELL_EFFECT_SCRIPT_EFFECT             = 77,
    SPELL_EFFECT_ATTACK                    = 78,
    SPELL_EFFECT_SANCTUARY                 = 79,
    SPELL_EFFECT_ADD_COMBO_POINTS          = 80,
    SPELL_EFFECT_CREATE_HOUSE              = 81,
    SPELL_EFFECT_BIND_SIGHT                = 82,
    SPELL_EFFECT_DUEL                      = 83,
    SPELL_EFFECT_STUCK                     = 84,
    SPELL_EFFECT_SUMMON_PLAYER             = 85,
    SPELL_EFFECT_ACTIVATE_OBJECT           = 86,
    SPELL_EFFECT_WMO_DAMAGE                = 87,
    SPELL_EFFECT_WMO_REPAIR                = 88,
    SPELL_EFFECT_WMO_CHANGE                = 89,
    SPELL_EFFECT_KILL_CREDIT_PERSONAL      = 90,
    SPELL_EFFECT_THREAT_ALL                = 91,
    SPELL_EFFECT_ENCHANT_HELD_ITEM         = 92,
    SPELL_EFFECT_BREAK_PLAYER_TARGETING    = 93,
    SPELL_EFFECT_SELF_RESURRECT            = 94,
    SPELL_EFFECT_SKINNING                  = 95,
    SPELL_EFFECT_CHARGE                    = 96,
    SPELL_EFFECT_SUMMON_ALL_TOTEMS         = 97,
    SPELL_EFFECT_KNOCK_BACK                = 98,
    SPELL_EFFECT_DISENCHANT                = 99,
    SPELL_EFFECT_INEBRIATE                 = 100,
    SPELL_EFFECT_FEED_PET                  = 101,
    SPELL_EFFECT_DISMISS_PET               = 102,
    SPELL_EFFECT_REPUTATION                = 103,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT        = 104,
    SPELL_EFFECT_SURVEY                    = 105,
    SPELL_EFFECT_SUMMON_RAID_MARKER        = 106,
    SPELL_EFFECT_LOOT_CORPSE               = 107,
    SPELL_EFFECT_DISPEL_MECHANIC           = 108,
    SPELL_EFFECT_SUMMON_DEAD_PET           = 109,
    SPELL_EFFECT_DESTROY_ALL_TOTEMS        = 110,
    SPELL_EFFECT_DURABILITY_DAMAGE         = 111,
    SPELL_EFFECT_112                       = 112,           // old SPELL_EFFECT_SUMMON_DEMON
    SPELL_EFFECT_RESURRECT_NEW             = 113,
    SPELL_EFFECT_ATTACK_ME                 = 114,
    SPELL_EFFECT_DURABILITY_DAMAGE_PCT     = 115,
    SPELL_EFFECT_SKIN_PLAYER_CORPSE        = 116,
    SPELL_EFFECT_SPIRIT_HEAL               = 117,
    SPELL_EFFECT_SKILL                     = 118,
    SPELL_EFFECT_APPLY_AREA_AURA_PET       = 119,
    SPELL_EFFECT_TELEPORT_GRAVEYARD        = 120,
    SPELL_EFFECT_NORMALIZED_WEAPON_DMG     = 121,
    SPELL_EFFECT_122                       = 122,
    SPELL_EFFECT_SEND_TAXI                 = 123,
    SPELL_EFFECT_PLAYER_PULL               = 124,
    SPELL_EFFECT_MODIFY_THREAT_PERCENT     = 125,
    SPELL_EFFECT_STEAL_BENEFICIAL_BUFF     = 126,
    SPELL_EFFECT_PROSPECTING               = 127,
    SPELL_EFFECT_APPLY_AREA_AURA_FRIEND    = 128,
    SPELL_EFFECT_APPLY_AREA_AURA_ENEMY     = 129,
    SPELL_EFFECT_REDIRECT_THREAT           = 130,
    SPELL_EFFECT_PLAY_SOUND                = 131,
    SPELL_EFFECT_PLAY_MUSIC                = 132,
    SPELL_EFFECT_UNLEARN_SPECIALIZATION    = 133,
    SPELL_EFFECT_KILL_CREDIT_GROUP         = 134,
    SPELL_EFFECT_CALL_PET                  = 135,
    SPELL_EFFECT_HEAL_PCT                  = 136,
    SPELL_EFFECT_ENERGIZE_PCT              = 137,
    SPELL_EFFECT_LEAP_BACK                 = 138,
    SPELL_EFFECT_CLEAR_QUEST               = 139,
    SPELL_EFFECT_FORCE_CAST                = 140,
    SPELL_EFFECT_FORCE_CAST_WITH_VALUE     = 141,
    SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE  = 142,
    SPELL_EFFECT_APPLY_AREA_AURA_OWNER     = 143,
    SPELL_EFFECT_KNOCKBACK_FROM_POSITION   = 144,
    SPELL_EFFECT_145                       = 145,
    SPELL_EFFECT_ACTIVATE_RUNE             = 146,
    SPELL_EFFECT_QUEST_FAIL                = 147,
    SPELL_EFFECT_148                       = 148,
    SPELL_EFFECT_CHARGE2                   = 149,
    SPELL_EFFECT_QUEST_OFFER               = 150,
    SPELL_EFFECT_TRIGGER_SPELL_2           = 151,
    SPELL_EFFECT_152                       = 152,
    SPELL_EFFECT_CREATE_PET                = 153,
    SPELL_EFFECT_TEACH_TAXI_NODE           = 154,
    SPELL_EFFECT_TITAN_GRIP                = 155,
    SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC    = 156,
    SPELL_EFFECT_CREATE_ITEM_2             = 157,
    SPELL_EFFECT_MILLING                   = 158,
    SPELL_EFFECT_ALLOW_RENAME_PET          = 159,
    SPELL_EFFECT_160                       = 160,
    SPELL_EFFECT_TALENT_SPEC_COUNT         = 161,
    SPELL_EFFECT_TALENT_SPEC_SELECT        = 162,
    SPELL_EFFECT_163                       = 163,
    SPELL_EFFECT_CANCEL_AURA               = 164,
    SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT= 165,
    SPELL_EFFECT_REWARD_CURRENCY           = 166,
    SPELL_EFFECT_167                       = 167,
    SPELL_EFFECT_168                       = 168,
    SPELL_EFFECT_DESTROY_ITEM              = 169,
    SPELL_EFFECT_170                       = 170,
    SPELL_EFFECT_171                       = 171,
    SPELL_EFFECT_MASS_RESSURECTION         = 172,
    SPELL_EFFECT_BUY_GUILD_BANKSLOT        = 173,
    SPELL_EFFECT_174                       = 174,
    SPELL_EFFECT_175                       = 175,
    SPELL_EFFECT_SANCTUARY_2               = 176,
    SPELL_EFFECT_177                       = 177,
    SPELL_EFFECT_178                       = 178,
    SPELL_EFFECT_179                       = 179,
    SPELL_EFFECT_180                       = 180,
    SPELL_EFFECT_181                       = 181,
    SPELL_EFFECT_182                       = 182,
    TOTAL_SPELL_EFFECTS                    = 183,
};

enum Targets
{
    TARGET_NONE                        = 0,
    TARGET_SELF                        = 1,
    TARGET_RANDOM_ENEMY_CHAIN_IN_AREA  = 2,                 // only one spell has that, but regardless, it's a target type after all
    TARGET_RANDOM_FRIEND_CHAIN_IN_AREA = 3,
    TARGET_4                           = 4,                 // some plague spells that are infectious - maybe targets not-infected friends inrange
    TARGET_PET                         = 5,
    TARGET_CHAIN_DAMAGE                = 6,
    TARGET_AREAEFFECT_INSTANT          = 7,                 // targets around provided destination point
    TARGET_AREAEFFECT_CUSTOM           = 8,
    TARGET_INNKEEPER_COORDINATES       = 9,                 // uses in teleport to innkeeper spells
    TARGET_11                          = 11,                // used by spell 4 'Word of Recall Other'
    TARGET_ALL_ENEMY_IN_AREA           = 15,
    TARGET_ALL_ENEMY_IN_AREA_INSTANT   = 16,
    TARGET_TABLE_X_Y_Z_COORDINATES     = 17,                // uses in teleport spells and some other
    TARGET_EFFECT_SELECT               = 18,                // highly depends on the spell effect
    TARGET_ALL_PARTY_AROUND_CASTER     = 20,
    TARGET_SINGLE_FRIEND               = 21,
    TARGET_CASTER_COORDINATES          = 22,                // used only in TargetA, target selection dependent from TargetB
    TARGET_GAMEOBJECT                  = 23,
    TARGET_IN_FRONT_OF_CASTER          = 24,
    TARGET_DUELVSPLAYER                = 25,
    TARGET_GAMEOBJECT_ITEM             = 26,
    TARGET_MASTER                      = 27,
    TARGET_ALL_ENEMY_IN_AREA_CHANNELED = 28,
    TARGET_29                          = 29,
    TARGET_ALL_FRIENDLY_UNITS_AROUND_CASTER = 30,           // select friendly for caster object faction (in different original caster faction) in TargetB used only with TARGET_ALL_AROUND_CASTER and in self casting range in TargetA
    TARGET_ALL_FRIENDLY_UNITS_IN_AREA  = 31,
    TARGET_MINION                      = 32,
    TARGET_ALL_PARTY                   = 33,
    TARGET_ALL_PARTY_AROUND_CASTER_2   = 34,                // used in Tranquility
    TARGET_SINGLE_PARTY                = 35,
    TARGET_ALL_HOSTILE_UNITS_AROUND_CASTER = 36,
    TARGET_AREAEFFECT_PARTY            = 37,
    TARGET_SCRIPT                      = 38,
    TARGET_SELF_FISHING                = 39,
    TARGET_FOCUS_OR_SCRIPTED_GAMEOBJECT = 40,
    TARGET_TOTEM_EARTH                 = 41,
    TARGET_TOTEM_WATER                 = 42,
    TARGET_TOTEM_AIR                   = 43,
    TARGET_TOTEM_FIRE                  = 44,
    TARGET_CHAIN_HEAL                  = 45,
    TARGET_SCRIPT_COORDINATES          = 46,
    TARGET_DYNAMIC_OBJECT_FRONT        = 47,
    TARGET_DYNAMIC_OBJECT_BEHIND       = 48,
    TARGET_DYNAMIC_OBJECT_LEFT_SIDE    = 49,
    TARGET_DYNAMIC_OBJECT_RIGHT_SIDE   = 50,
    TARGET_AREAEFFECT_GO_AROUND_SOURCE = 51,
    TARGET_AREAEFFECT_GO_AROUND_DEST   = 52,                // gameobject around destination, select by spell_script_target
    TARGET_CURRENT_ENEMY_COORDINATES   = 53,                // set unit coordinates as dest, only 16 target B imlemented
    TARGET_LARGE_FRONTAL_CONE          = 54,
    TARGET_ALL_RAID_AROUND_CASTER      = 56,
    TARGET_SINGLE_FRIEND_2             = 57,
    TARGET_58                          = 58,
    TARGET_59                          = 59,
    TARGET_NARROW_FRONTAL_CONE         = 60,
    TARGET_AREAEFFECT_PARTY_AND_CLASS  = 61,
    TARGET_DUELVSPLAYER_COORDINATES    = 63,
    TARGET_INFRONT_OF_VICTIM           = 64,
    TARGET_BEHIND_VICTIM               = 65,                // used in teleport behind spells, caster/target dependent from spell effect
    TARGET_RIGHT_FROM_VICTIM           = 66,
    TARGET_LEFT_FROM_VICTIM            = 67,
    TARGET_68                          = 68,
    TARGET_69                          = 69,
    TARGET_70                          = 70,
    TARGET_RANDOM_NEARBY_LOC           = 72,                // used in teleport onto nearby locations
    TARGET_RANDOM_CIRCUMFERENCE_POINT  = 73,
    TARGET_74                          = 74,
    TARGET_75                          = 75,
    TARGET_DYNAMIC_OBJECT_COORDINATES  = 76,
    TARGET_SINGLE_ENEMY                = 77,
    TARGET_POINT_AT_NORTH              = 78,                // 78-85 possible _COORDINATES at radius with pi/4 step around target in unknown order, N?
    TARGET_POINT_AT_SOUTH              = 79,                // S?
    TARGET_POINT_AT_EAST               = 80,                // 80/81 must be symmetric from line caster->target, E (base at 82/83, 84/85 order) ?
    TARGET_POINT_AT_WEST               = 81,                // 80/81 must be symmetric from line caster->target, W (base at 82/83, 84/85 order) ?
    TARGET_POINT_AT_NE                 = 82,                // from spell desc: "(NE)"
    TARGET_POINT_AT_NW                 = 83,                // from spell desc: "(NW)"
    TARGET_POINT_AT_SE                 = 84,                // from spell desc: "(SE)"
    TARGET_POINT_AT_SW                 = 85,                // from spell desc: "(SW)"
    TARGET_RANDOM_NEARBY_DEST          = 86,                // "Test Nearby Dest Random" - random around selected destination
    TARGET_SELF2                       = 87,
    TARGET_88                          = 88,                // Smoke Flare(s) and Hurricane
    TARGET_DIRECTLY_FORWARD            = 89,
    TARGET_NONCOMBAT_PET               = 90,
    TARGET_91                          = 91,
    TARGET_SUMMONER                    = 92,
    TARGET_CONTROLLED_VEHICLE          = 94,
    TARGET_95                          = 95,
    TARGET_VEHICLE_PASSENGER_0         = 96,
    TARGET_VEHICLE_PASSENGER_1         = 97,
    TARGET_VEHICLE_PASSENGER_2         = 98,
    TARGET_VEHICLE_PASSENGER_3         = 99,
    TARGET_VEHICLE_PASSENGER_4         = 100,
    TARGET_VEHICLE_PASSENGER_5         = 101,
    TARGET_VEHICLE_PASSENGER_6         = 102,
    TARGET_VEHICLE_PASSENGER_7         = 103,
    TARGET_IN_FRONT_OF_CASTER_30       = 104,
    TARGET_105                         = 105,
    TARGET_106                         = 106,
    TARGET_107                         = 107,               // possible TARGET_WMO(GO?)_IN_FRONT_OF_CASTER(_30 ?) TODO: Verify the angle!
    TARGET_GO_IN_FRONT_OF_CASTER_90    = 108,
    TARGET_109                         = 109,               // spell 89008
    TARGET_110                         = 110,               // front enemy aoe
    TARGET_111                         = 111,               // not used
    TARGET_112                         = 112,               // spell 89549
    TARGET_113                         = 113,               // not used
    TARGET_114                         = 114,               // not used
    TARGET_115                         = 115,               // not used
    TARGET_116                         = 116,               // not used
    TARGET_117                         = 117,               // test spell 83658
    TARGET_118                         = 118,               // test spell 79579
    TARGET_119                         = 119,               // mass ressurection 83968
    TARGET_120                         = 120,
    TARGET_121                         = 121,               // spell 95750
    TARGET_122                         = 122,               // spell 100661
    TARGET_123                         = 123,
    TARGET_124                         = 124,
    TARGET_125                         = 125,
    TARGET_126                         = 126,
    TARGET_127                         = 127,
};

#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2
#define MAX_SPELL_TOTEM_CATEGORIES 2

enum SpellAttributes
{
    SPELL_ATTR_UNK0                            = 0x00000001,// 0
    SPELL_ATTR_RANGED                          = 0x00000002,// 1 All ranged abilites have this flag
    SPELL_ATTR_ON_NEXT_SWING_1                 = 0x00000004,// 2 on next swing
    SPELL_ATTR_UNK3                            = 0x00000008,// 3 not set in 3.0.3
    SPELL_ATTR_UNK4                            = 0x00000010,// 4 isAbility
    SPELL_ATTR_TRADESPELL                      = 0x00000020,// 5 trade spells, will be added by client to a sublist of profession spell
    SPELL_ATTR_PASSIVE                         = 0x00000040,// 6 Passive spell
    SPELL_ATTR_UNK7                            = 0x00000080,// 7 can't be linked in chat?
    SPELL_ATTR_UNK8                            = 0x00000100,// 8 hide created item in tooltip (for effect=24)
    SPELL_ATTR_UNK9                            = 0x00000200,// 9
    SPELL_ATTR_ON_NEXT_SWING_2                 = 0x00000400,// 10 on next swing 2
    SPELL_ATTR_UNK11                           = 0x00000800,// 11
    SPELL_ATTR_DAYTIME_ONLY                    = 0x00001000,// 12 only useable at daytime, not set in 2.4.2
    SPELL_ATTR_NIGHT_ONLY                      = 0x00002000,// 13 only useable at night, not set in 2.4.2
    SPELL_ATTR_INDOORS_ONLY                    = 0x00004000,// 14 only useable indoors, not set in 2.4.2
    SPELL_ATTR_OUTDOORS_ONLY                   = 0x00008000,// 15 Only useable outdoors.
    SPELL_ATTR_NOT_SHAPESHIFT                  = 0x00010000,// 16 Not while shapeshifted
    SPELL_ATTR_ONLY_STEALTHED                  = 0x00020000,// 17 Must be in stealth
    SPELL_ATTR_UNK18                           = 0x00040000,// 18
    SPELL_ATTR_LEVEL_DAMAGE_CALCULATION        = 0x00080000,// 19 spelldamage depends on caster level
    SPELL_ATTR_STOP_ATTACK_TARGET              = 0x00100000,// 20 Stop attack after use this spell (and not begin attack if use)
    SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK    = 0x00200000,// 21 Cannot be dodged/parried/blocked
    SPELL_ATTR_SET_TRACKING_TARGET             = 0x00400000,// 22 SetTrackingTarget
    SPELL_ATTR_UNK23                           = 0x00800000,// 23 castable while dead?
    SPELL_ATTR_CASTABLE_WHILE_MOUNTED          = 0x01000000,// 24 castable while mounted
    SPELL_ATTR_DISABLED_WHILE_ACTIVE           = 0x02000000,// 25 Activate and start cooldown after aura fade or remove summoned creature or go
    SPELL_ATTR_UNK26                           = 0x04000000,// 26
    SPELL_ATTR_CASTABLE_WHILE_SITTING          = 0x08000000,// 27 castable while sitting
    SPELL_ATTR_CANT_USED_IN_COMBAT             = 0x10000000,// 28 Cannot be used in combat
    SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY   = 0x20000000,// 29 unaffected by invulnerability (hmm possible not...)
    SPELL_ATTR_UNK30                           = 0x40000000,// 30 breakable by damage?
    SPELL_ATTR_CANT_CANCEL                     = 0x80000000,// 31 positive aura can't be canceled
};

enum SpellAttributesEx
{
    SPELL_ATTR_EX_UNK0                         = 0x00000001,// 0
    SPELL_ATTR_EX_DRAIN_ALL_POWER              = 0x00000002,// 1 use all power (Only paladin Lay of Hands and Bunyanize)
    SPELL_ATTR_EX_CHANNELED_1                  = 0x00000004,// 2 channeled 1
    SPELL_ATTR_EX_CANT_REFLECTED               = 0x00000008,// 3 used for detect can or not spell reflected
    SPELL_ATTR_EX_UNK4                         = 0x00000010,// 4
    SPELL_ATTR_EX_NOT_BREAK_STEALTH            = 0x00000020,// 5 Not break stealth
    SPELL_ATTR_EX_CHANNELED_2                  = 0x00000040,// 6 channeled 2
    SPELL_ATTR_EX_NEGATIVE                     = 0x00000080,// 7
    SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET         = 0x00000100,// 8 Spell req target not to be in combat state
    SPELL_ATTR_EX_UNK9                         = 0x00000200,// 9
    SPELL_ATTR_EX_NO_THREAT                    = 0x00000400,// 10 no generates threat on cast 100%
    SPELL_ATTR_EX_UNK11                        = 0x00000800,// 11
    SPELL_ATTR_EX_UNK12                        = 0x00001000,// 12
    SPELL_ATTR_EX_FARSIGHT                     = 0x00002000,// 13 related to farsight
    SPELL_ATTR_EX_UNK14                        = 0x00004000,// 14
    SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY     = 0x00008000,// 15 remove auras on immunity
    SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE  = 0x00010000,// 16 unaffected by school immunity
    SPELL_ATTR_EX_UNK17                        = 0x00020000,// 17 for auras SPELL_AURA_TRACK_CREATURES, SPELL_AURA_TRACK_RESOURCES and SPELL_AURA_TRACK_STEALTHED select non-stacking tracking spells
    SPELL_ATTR_EX_UNK18                        = 0x00040000,// 18
    SPELL_ATTR_EX_UNK19                        = 0x00080000,// 19
    SPELL_ATTR_EX_REQ_TARGET_COMBO_POINTS      = 0x00100000,// 20 Req combo points on target
    SPELL_ATTR_EX_UNK21                        = 0x00200000,// 21
    SPELL_ATTR_EX_REQ_COMBO_POINTS             = 0x00400000,// 22 Use combo points
    SPELL_ATTR_EX_UNK23                        = 0x00800000,// 23
    SPELL_ATTR_EX_UNK24                        = 0x01000000,// 24 Req fishing pole??
    SPELL_ATTR_EX_UNK25                        = 0x02000000,// 25
    SPELL_ATTR_EX_UNK26                        = 0x04000000,// 26
    SPELL_ATTR_EX_UNK27                        = 0x08000000,// 27
    SPELL_ATTR_EX_UNK28                        = 0x10000000,// 28
    SPELL_ATTR_EX_UNK29                        = 0x20000000,// 29
    SPELL_ATTR_EX_UNK30                        = 0x40000000,// 30 overpower
    SPELL_ATTR_EX_UNK31                        = 0x80000000,// 31
};

enum SpellAttributesEx2
{
    SPELL_ATTR_EX2_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX2_UNK1                        = 0x00000002,// 1
    SPELL_ATTR_EX2_IGNORE_LOS                  = 0x00000004,// 2 do not need LOS (e.g. 18220 since 3.3.3) // changed meaning from ? used for detect can or not spell reflected
    SPELL_ATTR_EX2_UNK3                        = 0x00000008,// 3 auto targeting? (e.g. fishing skill enhancement items since 3.3.3)
    SPELL_ATTR_EX2_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX2_AUTOREPEAT_FLAG             = 0x00000020,// 5
    SPELL_ATTR_EX2_UNK6                        = 0x00000040,// 6 only usable on tabbed by yourself
    SPELL_ATTR_EX2_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX2_UNK8                        = 0x00000100,// 8 not set in 3.0.3
    SPELL_ATTR_EX2_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX2_UNK10                       = 0x00000400,// 10
    SPELL_ATTR_EX2_HEALTH_FUNNEL               = 0x00000800,// 11
    SPELL_ATTR_EX2_UNK12                       = 0x00001000,// 12
    SPELL_ATTR_EX2_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX2_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX2_UNK15                       = 0x00008000,// 15 not set in 3.0.3
    SPELL_ATTR_EX2_UNK16                       = 0x00010000,// 16
    SPELL_ATTR_EX2_UNK17                       = 0x00020000,// 17 suspend weapon timer instead of resetting it, (?Hunters Shot and Stings only have this flag?)
    SPELL_ATTR_EX2_UNK18                       = 0x00040000,// 18 Only Revive pet - possible req dead pet
    SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT         = 0x00080000,// 19 does not necessarly need shapeshift
    SPELL_ATTR_EX2_UNK20                       = 0x00100000,// 20
    SPELL_ATTR_EX2_DAMAGE_REDUCED_SHIELD       = 0x00200000,// 21 for ice blocks, pala immunity buffs, priest absorb shields, but used also for other spells -> not sure!
    SPELL_ATTR_EX2_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX2_UNK23                       = 0x00800000,// 23 Only mage Arcane Concentration have this flag
    SPELL_ATTR_EX2_UNK24                       = 0x01000000,// 24
    SPELL_ATTR_EX2_UNK25                       = 0x02000000,// 25
    SPELL_ATTR_EX2_UNK26                       = 0x04000000,// 26 unaffected by school immunity
    SPELL_ATTR_EX2_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX2_UNK28                       = 0x10000000,// 28 no breaks stealth if it fails??
    SPELL_ATTR_EX2_CANT_CRIT                   = 0x20000000,// 29 Spell can't crit
    SPELL_ATTR_EX2_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX2_FOOD_BUFF                   = 0x80000000,// 31 Food or Drink Buff (like Well Fed)
};

enum SpellAttributesEx3
{
    SPELL_ATTR_EX3_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX3_UNK1                        = 0x00000002,// 1
    SPELL_ATTR_EX3_UNK2                        = 0x00000004,// 2
    SPELL_ATTR_EX3_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX3_UNK4                        = 0x00000010,// 4 Druid Rebirth only this spell have this flag
    SPELL_ATTR_EX3_UNK5                        = 0x00000020,// 5
    SPELL_ATTR_EX3_UNK6                        = 0x00000040,// 6
    SPELL_ATTR_EX3_UNK7                        = 0x00000080,// 7 create a separate (de)buff stack for each caster
    SPELL_ATTR_EX3_TARGET_ONLY_PLAYER          = 0x00000100,// 8 Can target only player
    SPELL_ATTR_EX3_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX3_MAIN_HAND                   = 0x00000400,// 10 Main hand weapon required
    SPELL_ATTR_EX3_BATTLEGROUND                = 0x00000800,// 11 Can casted only on battleground
    SPELL_ATTR_EX3_CAST_ON_DEAD                = 0x00001000,// 12 target is a dead player (not every spell has this flag)
    SPELL_ATTR_EX3_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX3_UNK14                       = 0x00004000,// 14 "Honorless Target" only this spells have this flag
    SPELL_ATTR_EX3_UNK15                       = 0x00008000,// 15 Auto Shoot, Shoot, Throw,  - this is autoshot flag
    SPELL_ATTR_EX3_UNK16                       = 0x00010000,// 16 no triggers effects that trigger on casting a spell??
    SPELL_ATTR_EX3_NO_INITIAL_AGGRO            = 0x00020000,// 17 Causes no aggro if not missed
    SPELL_ATTR_EX3_CANT_MISS                   = 0x00040000,// 18 Spell should always hit its target
    SPELL_ATTR_EX3_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX3_DEATH_PERSISTENT            = 0x00100000,// 20 Death persistent spells
    SPELL_ATTR_EX3_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX3_REQ_WAND                    = 0x00400000,// 22 Req wand
    SPELL_ATTR_EX3_UNK23                       = 0x00800000,// 23
    SPELL_ATTR_EX3_REQ_OFFHAND                 = 0x01000000,// 24 Req offhand weapon
    SPELL_ATTR_EX3_UNK25                       = 0x02000000,// 25 no cause spell pushback ?
    SPELL_ATTR_EX3_UNK26                       = 0x04000000,// 26
    SPELL_ATTR_EX3_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX3_UNK28                       = 0x10000000,// 28
    SPELL_ATTR_EX3_UNK29                       = 0x20000000,// 29
    SPELL_ATTR_EX3_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX3_UNK31                       = 0x80000000,// 31
};

enum SpellAttributesEx4
{
    SPELL_ATTR_EX4_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX4_UNK1                        = 0x00000002,// 1 proc on finishing move?
    SPELL_ATTR_EX4_UNK2                        = 0x00000004,// 2
    SPELL_ATTR_EX4_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX4_UNK4                        = 0x00000010,// 4 This will no longer cause guards to attack on use??
    SPELL_ATTR_EX4_UNK5                        = 0x00000020,// 5
    SPELL_ATTR_EX4_NOT_STEALABLE               = 0x00000040,// 6 although such auras might be dispellable, they cannot be stolen
    SPELL_ATTR_EX4_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX4_STACK_DOT_MODIFIER          = 0x00000100,// 8 no effect on non DoTs?
    SPELL_ATTR_EX4_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX4_SPELL_VS_EXTEND_COST        = 0x00000400,// 10 Rogue Shiv have this flag
    SPELL_ATTR_EX4_UNK11                       = 0x00000800,// 11
    SPELL_ATTR_EX4_UNK12                       = 0x00001000,// 12
    SPELL_ATTR_EX4_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX4_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX4_UNK15                       = 0x00008000,// 15
    SPELL_ATTR_EX4_NOT_USABLE_IN_ARENA         = 0x00010000,// 16 not usable in arena
    SPELL_ATTR_EX4_USABLE_IN_ARENA             = 0x00020000,// 17 usable in arena
    SPELL_ATTR_EX4_UNK18                       = 0x00040000,// 18
    SPELL_ATTR_EX4_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX4_UNK20                       = 0x00100000,// 20 do not give "more powerful spell" error message
    SPELL_ATTR_EX4_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX4_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX4_UNK23                       = 0x00800000,// 23
    SPELL_ATTR_EX4_UNK24                       = 0x01000000,// 24
    SPELL_ATTR_EX4_UNK25                       = 0x02000000,// 25 pet scaling auras
    SPELL_ATTR_EX4_CAST_ONLY_IN_OUTLAND        = 0x04000000,// 26 Can only be used in Outland.
    SPELL_ATTR_EX4_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX4_UNK28                       = 0x10000000,// 28
    SPELL_ATTR_EX4_UNK29                       = 0x20000000,// 29
    SPELL_ATTR_EX4_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX4_UNK31                       = 0x80000000,// 31
};

enum SpellAttributesEx5
{
    SPELL_ATTR_EX5_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX5_NO_REAGENT_WHILE_PREP       = 0x00000002,// 1 not need reagents if UNIT_FLAG_PREPARATION
    SPELL_ATTR_EX5_UNK2                        = 0x00000004,// 2 removed at enter arena (e.g. 31850 since 3.3.3)
    SPELL_ATTR_EX5_USABLE_WHILE_STUNNED        = 0x00000008,// 3 usable while stunned
    SPELL_ATTR_EX5_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX5_SINGLE_TARGET_SPELL         = 0x00000020,// 5 Only one target can be apply at a time
    SPELL_ATTR_EX5_UNK6                        = 0x00000040,// 6
    SPELL_ATTR_EX5_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX5_UNK8                        = 0x00000100,// 8
    SPELL_ATTR_EX5_START_PERIODIC_AT_APPLY     = 0x00000200,// 9  begin periodic tick at aura apply
    SPELL_ATTR_EX5_HIDE_DURATION               = 0x00000400,// 10
    SPELL_ATTR_EX5_UNK11                       = 0x00000800,// 11
    SPELL_ATTR_EX5_UNK12                       = 0x00001000,// 12
    SPELL_ATTR_EX5_UNK13                       = 0x00002000,// 13 haste affects duration (e.g. 8050 since 3.3.3)
    SPELL_ATTR_EX5_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX5_UNK15                       = 0x00008000,// 15
    SPELL_ATTR_EX5_UNK16                       = 0x00010000,// 16
    SPELL_ATTR_EX5_USABLE_WHILE_FEARED         = 0x00020000,// 17 usable while feared
    SPELL_ATTR_EX5_USABLE_WHILE_CONFUSED       = 0x00040000,// 18 usable while confused
    SPELL_ATTR_EX5_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX5_UNK20                       = 0x00100000,// 20
    SPELL_ATTR_EX5_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX5_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX5_UNK23                       = 0x00800000,// 23
    SPELL_ATTR_EX5_UNK24                       = 0x01000000,// 24
    SPELL_ATTR_EX5_UNK25                       = 0x02000000,// 25
    SPELL_ATTR_EX5_UNK26                       = 0x04000000,// 26
    SPELL_ATTR_EX5_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX5_UNK28                       = 0x10000000,// 28
    SPELL_ATTR_EX5_UNK29                       = 0x20000000,// 29
    SPELL_ATTR_EX5_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX5_UNK31                       = 0x80000000,// 31 Forces all nearby enemies to focus attacks caster
};

enum SpellAttributesEx6
{
    SPELL_ATTR_EX6_UNK0                        = 0x00000001,// 0 Only Move spell have this flag
    SPELL_ATTR_EX6_ONLY_IN_ARENA               = 0x00000002,// 1 only usable in arena, not used in 3.2.0a and early
    SPELL_ATTR_EX6_UNK2                        = 0x00000004,// 2
    SPELL_ATTR_EX6_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX6_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX6_UNK5                        = 0x00000020,// 5
    SPELL_ATTR_EX6_UNK6                        = 0x00000040,// 6
    SPELL_ATTR_EX6_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX6_UNK8                        = 0x00000100,// 8
    SPELL_ATTR_EX6_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX6_UNK10                       = 0x00000400,// 10
    SPELL_ATTR_EX6_NOT_IN_RAID_INSTANCE        = 0x00000800,// 11 not usable in raid instance
    SPELL_ATTR_EX6_UNK12                       = 0x00001000,// 12 for auras SPELL_AURA_TRACK_CREATURES, SPELL_AURA_TRACK_RESOURCES and SPELL_AURA_TRACK_STEALTHED select non-stacking tracking spells
    SPELL_ATTR_EX6_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX6_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX6_UNK15                       = 0x00008000,// 15 not set in 3.0.3
    SPELL_ATTR_EX6_UNK16                       = 0x00010000,// 16
    SPELL_ATTR_EX6_UNK17                       = 0x00020000,// 17
    SPELL_ATTR_EX6_UNK18                       = 0x00040000,// 18
    SPELL_ATTR_EX6_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX6_UNK20                       = 0x00100000,// 20
    SPELL_ATTR_EX6_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX6_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX6_UNK23                       = 0x00800000,// 23 not set in 3.0.3
    SPELL_ATTR_EX6_UNK24                       = 0x01000000,// 24 not set in 3.0.3
    SPELL_ATTR_EX6_UNK25                       = 0x02000000,// 25 not set in 3.0.3
    SPELL_ATTR_EX6_UNK26                       = 0x04000000,// 26 not set in 3.0.3
    SPELL_ATTR_EX6_UNK27                       = 0x08000000,// 27 not set in 3.0.3
    SPELL_ATTR_EX6_UNK28                       = 0x10000000,// 28 not set in 3.0.3
    SPELL_ATTR_EX6_NO_DMG_MODS                 = 0x20000000,// 29 do not apply damage mods (usually in cases where it has already been applied)
    SPELL_ATTR_EX6_UNK30                       = 0x40000000,// 30 not set in 3.0.3
    SPELL_ATTR_EX6_UNK31                       = 0x80000000,// 31 not set in 3.0.3
};

enum SpellAttributesEx7
{
    SPELL_ATTR_EX7_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX7_UNK1                        = 0x00000002,// 1
    SPELL_ATTR_EX7_PALADIN_AURA                = 0x00000004,// 2
    SPELL_ATTR_EX7_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX7_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX7_TOTEM_SPELL                 = 0x00000020,// 5  shaman summon totem spells
    SPELL_ATTR_EX7_UNK6                        = 0x00000040,// 6
    SPELL_ATTR_EX7_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX7_UNK8                        = 0x00000100,// 8
    SPELL_ATTR_EX7_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX7_UNK10                       = 0x00000400,// 10
    SPELL_ATTR_EX7_UNK11                       = 0x00000800,// 11
    SPELL_ATTR_EX7_UNK12                       = 0x00001000,// 12
    SPELL_ATTR_EX7_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX7_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX7_UNK15                       = 0x00008000,// 15
    SPELL_ATTR_EX7_UNK16                       = 0x00010000,// 16
    SPELL_ATTR_EX7_UNK17                       = 0x00020000,// 17
    SPELL_ATTR_EX7_UNK18                       = 0x00040000,// 18
    SPELL_ATTR_EX7_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX7_UNK20                       = 0x00100000,// 20
    SPELL_ATTR_EX7_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX7_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX7_UNK23                       = 0x00800000,// 23
    SPELL_ATTR_EX7_UNK24                       = 0x01000000,// 24
    SPELL_ATTR_EX7_UNK25                       = 0x02000000,// 25
    SPELL_ATTR_EX7_UNK26                       = 0x04000000,// 26
    SPELL_ATTR_EX7_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX7_UNK28                       = 0x10000000,// 28
    SPELL_ATTR_EX7_UNK29                       = 0x20000000,// 29
    SPELL_ATTR_EX7_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX7_UNK31                       = 0x80000000,// 31
};

enum SpellAttributesEx8
{
    SPELL_ATTR_EX8_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX8_UNK1                        = 0x00000002,// 1 Single spell Summon Fire (94655)
    SPELL_ATTR_EX8_UNK2                        = 0x00000004,// 2 Luck of the Draw and Whirling Blades
    SPELL_ATTR_EX8_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX8_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX8_UNK5                        = 0x00000020,// 5
    SPELL_ATTR_EX8_UNK6                        = 0x00000040,// 6 Rune Strike, [DND] Falling, Altered Form
    SPELL_ATTR_EX8_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX8_UNK8                        = 0x00000100,// 8 some raid-wide buffs
    SPELL_ATTR_EX8_UNK9                        = 0x00000200,// 9 some dot/hot spells
    SPELL_ATTR_EX8_UNK10                       = 0x00000400,// 10 some transformation spells
    SPELL_ATTR_EX8_UNK11                       = 0x00000800,// 11 Phase 2 Intro Aura (80224)
    SPELL_ATTR_EX8_AURA_SENDS_AMOUNT           = 0x00001000,// 12
    SPELL_ATTR_EX8_UNK13                       = 0x00002000,// 13
    SPELL_ATTR_EX8_UNK14                       = 0x00004000,// 14 Focus Magic, Honor Among Thieves, Turn the Tables
    SPELL_ATTR_EX8_UNK15                       = 0x00008000,// 15 River Boat (76203)
    SPELL_ATTR_EX8_UNK16                       = 0x00010000,// 16
    SPELL_ATTR_EX8_UNK17                       = 0x00020000,// 17
    SPELL_ATTR_EX8_UNK18                       = 0x00040000,// 18 Dark Simulacrum, Soul Swap
    SPELL_ATTR_EX8_IGNORE_TARGET_FOR_COMBO_POINTS = 0x00080000,// 19 Slice and Dice, Savage Roar, Recuperate
    SPELL_ATTR_EX8_ARMOR_SPECIALIZATION        = 0x00100000,// 20
    SPELL_ATTR_EX8_UNK21                       = 0x00200000,// 21 some spells that summon smth
    SPELL_ATTR_EX8_UNK22                       = 0x00400000,// 22 some health-affecting spells
    SPELL_ATTR_EX8_UNK23                       = 0x00800000,// 23 spells that show revive player and show messagebox
    SPELL_ATTR_EX8_UNK24                       = 0x01000000,// 24 some healing spells
    SPELL_ATTR_EX8_UNK25                       = 0x02000000,// 25 mostly druid and mostly feral spells
    SPELL_ATTR_EX8_RAID_MARKER                 = 0x04000000,// 26 probably spell doesn't need to be learned to cast. Raid markers + Juggle Torch (Catch)
    SPELL_ATTR_EX8_UNK27                       = 0x08000000,// 27
    SPELL_ATTR_EX8_GUILD_PERKS                 = 0x10000000,// 28
    SPELL_ATTR_EX8_MASTERY                     = 0x20000000,// 29
    SPELL_ATTR_EX8_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX8_UNK31                       = 0x80000000,// 31
};

enum SpellAttributesEx9
{
    SPELL_ATTR_EX9_UNK0                        = 0x00000001,// 0
    SPELL_ATTR_EX9_UNK1                        = 0x00000002,// 1
    SPELL_ATTR_EX9_UNK2                        = 0x00000004,// 2 some sort of invisibility
    SPELL_ATTR_EX9_UNK3                        = 0x00000008,// 3
    SPELL_ATTR_EX9_UNK4                        = 0x00000010,// 4
    SPELL_ATTR_EX9_UNK5                        = 0x00000020,// 5 some totem spells
    SPELL_ATTR_EX9_UNK6                        = 0x00000040,// 6
    SPELL_ATTR_EX9_UNK7                        = 0x00000080,// 7
    SPELL_ATTR_EX9_UNK8                        = 0x00000100,// 8 Aimed Shot (19434) and Aimed Shot! (82928)
    SPELL_ATTR_EX9_UNK9                        = 0x00000200,// 9
    SPELL_ATTR_EX9_UNK10                       = 0x00000400,// 10 Ice Storm 88239
    SPELL_ATTR_EX9_UNK11                       = 0x00000800,// 11
    SPELL_ATTR_EX9_UNK12                       = 0x00001000,// 12 Feral Charge 49376
    SPELL_ATTR_EX9_UNK13                       = 0x00002000,// 13 Slam 1464, used in cast time calculation
    SPELL_ATTR_EX9_UNK14                       = 0x00004000,// 14
    SPELL_ATTR_EX9_UNK15                       = 0x00008000,// 15 not used
    SPELL_ATTR_EX9_UNK16                       = 0x00010000,// 16 Aimed Shot 19434, Steady Shot 56641, Cobra Shot 77767
    SPELL_ATTR_EX9_UNK17                       = 0x00020000,// 17 not used
    SPELL_ATTR_EX9_UNK18                       = 0x00040000,// 18
    SPELL_ATTR_EX9_UNK19                       = 0x00080000,// 19
    SPELL_ATTR_EX9_UNK20                       = 0x00100000,// 20
    SPELL_ATTR_EX9_UNK21                       = 0x00200000,// 21
    SPELL_ATTR_EX9_UNK22                       = 0x00400000,// 22
    SPELL_ATTR_EX9_UNK23                       = 0x00800000,// 23 Asira Dismount 103720
    SPELL_ATTR_EX9_UNK24                       = 0x01000000,// 24 not used
    SPELL_ATTR_EX9_UNK25                       = 0x02000000,// 25 not used
    SPELL_ATTR_EX9_UNK26                       = 0x04000000,// 26 Item - Mage T12 4P Bonus 99064
    SPELL_ATTR_EX9_UNK27                       = 0x08000000,// 27 20707 Soulstone Resurrection, Quest Invis 9 102370
    SPELL_ATTR_EX9_UNK28                       = 0x10000000,// 28 Decimate, Unholy Frenzy, Spirit Link: all aoe reduce health
    SPELL_ATTR_EX9_UNK29                       = 0x20000000,// 29 passive raid-wide auras
    SPELL_ATTR_EX9_UNK30                       = 0x40000000,// 30
    SPELL_ATTR_EX9_UNK31                       = 0x80000000,// 31 In Chains 88791
};

enum SpellAttributesEx10
{
    SPELL_ATTR_EX10_UNK0                       = 0x00000001,// 0 Deep Wounds, Ignite, Blood Plague, Frost Fever, Ebon Plague, Scarlet Fever, Brittle Bones, Asira Dismount
    SPELL_ATTR_EX10_UNK1                       = 0x00000002,// 1 Combustion, Hemorrhage
    SPELL_ATTR_EX10_UNK2                       = 0x00000004,// 2 Throw Spear, Unholy Shot, Crack Shot!, Throw Knife, Ice Arrow
    SPELL_ATTR_EX10_UNK3                       = 0x00000008,// 3 Spirit Bond, Fel Armor
    SPELL_ATTR_EX10_UNK4                       = 0x00000010,// 4 Water Spout 58873
    SPELL_ATTR_EX10_UNK5                       = 0x00000020,// 5 Immolate, Concussive Stomp
    SPELL_ATTR_EX10_UNK6                       = 0x00000040,// 6 Teleport Player, Teleport Player to NEXUS LEGENDARY
    SPELL_ATTR_EX10_UNK7                       = 0x00000080,// 7
    SPELL_ATTR_EX10_UNK8                       = 0x00000100,// 8 Shadowflame, Furious Swipe
    SPELL_ATTR_EX10_UNK9                       = 0x00000200,// 9 relocation spells
    SPELL_ATTR_EX10_UNK10                      = 0x00000400,// 10 Omar's Seal of Approval, Spellweaving
    SPELL_ATTR_EX10_UNK11                      = 0x00000800,// 11 Herb Gathering, Mining
    SPELL_ATTR_EX10_UNK12                      = 0x00001000,// 12 not used
    SPELL_ATTR_EX10_UNK13                      = 0x00002000,// 13 not used
    SPELL_ATTR_EX10_UNK14                      = 0x00004000,// 14 not used
    SPELL_ATTR_EX10_UNK15                      = 0x00008000,// 15 not used
    SPELL_ATTR_EX10_UNK16                      = 0x00010000,// 16 not used
    SPELL_ATTR_EX10_UNK17                      = 0x00020000,// 17 not used
    SPELL_ATTR_EX10_UNK18                      = 0x00040000,// 18 not used
    SPELL_ATTR_EX10_UNK19                      = 0x00080000,// 19 not used
    SPELL_ATTR_EX10_UNK20                      = 0x00100000,// 20 not used
    SPELL_ATTR_EX10_UNK21                      = 0x00200000,// 21 not used
    SPELL_ATTR_EX10_UNK22                      = 0x00400000,// 22 not used
    SPELL_ATTR_EX10_UNK23                      = 0x00800000,// 23 not used
    SPELL_ATTR_EX10_UNK24                      = 0x01000000,// 24 not used
    SPELL_ATTR_EX10_UNK25                      = 0x02000000,// 25 not used
    SPELL_ATTR_EX10_UNK26                      = 0x04000000,// 26 not used
    SPELL_ATTR_EX10_UNK27                      = 0x08000000,// 27 not used
    SPELL_ATTR_EX10_UNK28                      = 0x10000000,// 28 not used
    SPELL_ATTR_EX10_UNK29                      = 0x20000000,// 29 not used
    SPELL_ATTR_EX10_UNK30                      = 0x40000000,// 30 not used
    SPELL_ATTR_EX10_UNK31                      = 0x80000000,// 31 not used
};

struct ClassFamilyMask
{
    quint64 Flags;
    quint32 Flags2;

    ClassFamilyMask() : Flags(0), Flags2(0) {}
    explicit ClassFamilyMask(quint64 familyFlags, quint32 familyFlags2 = 0) : Flags(familyFlags), Flags2(familyFlags2) {}

    bool Empty() const { return Flags == 0 && Flags2 == 0; }
    bool operator! () const { return Empty(); }
    operator void const* () const { return Empty() ? NULL : this; }// for allow normal use in if(mask)

    bool IsFitToFamilyMask(quint64 familyFlags, quint32 familyFlags2 = 0) const
    {
        return (Flags & familyFlags) || (Flags2 & familyFlags2);
    }

    bool IsFitToFamilyMask(ClassFamilyMask const& mask) const
    {
        return (Flags & mask.Flags) || (Flags2 & mask.Flags2);
    }

    quint64 operator& (quint64 mask) const                     // possible will removed at finish convertion code use IsFitToFamilyMask
    {
        return Flags & mask;
    }

    ClassFamilyMask& operator|= (ClassFamilyMask const& mask)
    {
        Flags |= mask.Flags;
        Flags2 |= mask.Flags2;
        return *this;
    }
};

// SpellAuraOptions.dbc
struct SpellAuraOptionsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    StackAmount;                                  // 51       m_cumulativeAura
    quint32    procChance;                                   // 38       m_procChance
    quint32    procCharges;                                  // 39       m_procCharges
    quint32    procFlags;                                    // 37       m_procTypeMask
};

// SpellAuraRestrictions.dbc
struct SpellAuraRestrictionsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    CasterAuraState;                              // 21       m_casterAuraState
    quint32    TargetAuraState;                              // 22       m_targetAuraState
    quint32    CasterAuraStateNot;                           // 23       m_excludeCasterAuraState
    quint32    TargetAuraStateNot;                           // 24       m_excludeTargetAuraState
    quint32    casterAuraSpell;                              // 25       m_casterAuraSpell
    quint32    targetAuraSpell;                              // 26       m_targetAuraSpell
    quint32    excludeCasterAuraSpell;                       // 27       m_excludeCasterAuraSpell
    quint32    excludeTargetAuraSpell;                       // 28       m_excludeTargetAuraSpell
};

// SpellCastingRequirements.dbc
struct SpellCastingRequirementsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    FacingCasterFlags;                            // 20       m_facingCasterFlags
    //uint32    MinFactionId;                               // 159      m_minFactionID not used
    //uint32    MinReputation;                              // 160      m_minReputation not used
    qint32     AreaGroupId;                                  // 164      m_requiredAreaGroupId
    //uint32    RequiredAuraVision;                         // 161      m_requiredAuraVision not used
    quint32    RequiresSpellFocus;                           // 19       m_requiresSpellFocus
};

// SpellCategories.dbc
struct SpellCategoriesEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    Category;                                     // 1        m_category
    quint32    DmgClass;                                     // 153      m_defenseType
    quint32    Dispel;                                       // 2        m_dispelType
    quint32    Mechanic;                                     // 3        m_mechanic
    quint32    PreventionType;                               // 154      m_preventionType
    quint32    StartRecoveryCategory;                        // 145      m_startRecoveryCategory
};

// SpellClassOptions.dbc
struct SpellClassOptionsEntry
{
    //uint32    Id;                                         // 0        m_ID
    //uint32    modalNextSpell;                             // 50       m_modalNextSpell not used
    ClassFamilyMask SpellFamilyFlags;                       // 149-151  m_spellClassMask NOTE: size is 12 bytes!!!
    quint32    SpellFamilyName;                              // 148      m_spellClassSet
    //char*   Description;                                  // 6 4.0.0

    // helpers

    bool IsFitToFamilyMask(quint64 familyFlags, quint32 familyFlags2 = 0) const
    {
        return SpellFamilyFlags.IsFitToFamilyMask(familyFlags, familyFlags2);
    }

    bool IsFitToFamily(SpellFamily family, quint64 familyFlags, quint32 familyFlags2 = 0) const
    {
        return SpellFamily(SpellFamilyName) == family && IsFitToFamilyMask(familyFlags, familyFlags2);
    }

    bool IsFitToFamilyMask(ClassFamilyMask const& mask) const
    {
        return SpellFamilyFlags.IsFitToFamilyMask(mask);
    }

    bool IsFitToFamily(SpellFamily family, ClassFamilyMask const& mask) const
    {
        return SpellFamily(SpellFamilyName) == family && IsFitToFamilyMask(mask);
    }

    private:
        // catch wrong uses
        template<typename T>
        bool IsFitToFamilyMask(SpellFamily family, T t) const;
};

// SpellCooldowns.dbc
struct SpellCooldownsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    CategoryRecoveryTime;                         // 31       m_categoryRecoveryTime
    quint32    RecoveryTime;                                 // 30       m_recoveryTime
    quint32    StartRecoveryTime;                            // 146      m_startRecoveryTime
};

// SpellEffect.dbc
struct SpellEffectEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    Effect;                                       // 73-75    m_effect
    float     EffectMultipleValue;                          // 106-108  m_effectAmplitude
    quint32    EffectApplyAuraName;                          // 100-102  m_effectAura
    quint32    EffectAmplitude;                              // 103-105  m_effectAuraPeriod
    qint32     EffectBasePoints;                             // 82-84    m_effectBasePoints (don't must be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    //float   unk_320_4;                                    // 169-171  3.2.0
    float     DmgMultiplier;                                // 156-158  m_effectChainAmplitude
    quint32    EffectChainTarget;                            // 109-111  m_effectChainTargets
    qint32     EffectDieSides;                               // 76-78    m_effectDieSides
    quint32    EffectItemType;                               // 112-114  m_effectItemType
    quint32    EffectMechanic;                               // 85-87    m_effectMechanic
    qint32     EffectMiscValue;                              // 115-117  m_effectMiscValue
    qint32     EffectMiscValueB;                             // 118-120  m_effectMiscValueB
    float     EffectPointsPerComboPoint;                    // 124-126  m_effectPointsPerCombo
    quint32    EffectRadiusIndex;                            // 94-96    m_effectRadiusIndex - spellradius.dbc
    quint32    EffectRadiusMaxIndex;                         // 97-99    4.0.0
    float     EffectRealPointsPerLevel;                     // 79-81    m_effectRealPointsPerLevel
    ClassFamilyMask EffectSpellClassMask;                   // 127-129  m_effectSpellClassMask
    quint32    EffectTriggerSpell;                           // 121-123  m_effectTriggerSpell
    quint32    EffectImplicitTargetA;                        // 88-90    m_implicitTargetA
    quint32    EffectImplicitTargetB;                        // 91-93    m_implicitTargetB
    quint32    EffectSpellId;                                // new 4.0.0
    quint32    EffectIndex;                                  // new 4.0.0
    //uint32 unk;                                           // 24 - 4.2.0

    // helpers

    qint32 CalculateSimpleValue() const { return EffectBasePoints; }

    quint32 GetRadiusIndex() const
    {
        if (EffectRadiusIndex != 0)
            return EffectRadiusIndex;

        return EffectRadiusMaxIndex;
    }
};

// SpellEquippedItems.dbc
struct SpellEquippedItemsEntry
{
    //uint32    Id;                                           // 0        m_ID
    qint32     EquippedItemClass;                            // 70       m_equippedItemClass (value)
    qint32     EquippedItemInventoryTypeMask;                // 72       m_equippedItemInvTypes (mask)
    qint32     EquippedItemSubClassMask;                     // 71       m_equippedItemSubclass (mask)
};

// SpellInterrupts.dbc
struct SpellInterruptsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    AuraInterruptFlags;                           // 33       m_auraInterruptFlags
    //uint32                                                // 34       4.0.0
    quint32    ChannelInterruptFlags;                        // 35       m_channelInterruptFlags
    //uint32                                                // 36       4.0.0
    quint32    InterruptFlags;                               // 32       m_interruptFlags
};

// SpellLevels.dbc
struct SpellLevelsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    baseLevel;                                    // 41       m_baseLevel
    quint32    maxLevel;                                     // 40       m_maxLevel
    quint32    spellLevel;                                   // 42       m_spellLevel
};

// SpellPower.dbc
struct SpellPowerEntry
{
    //uint32    Id;                                           // 0 - m_ID
    quint32    manaCost;                                     // 1 - m_manaCost
    quint32    manaCostPerlevel;                             // 2 - m_manaCostPerLevel
    quint32    ManaCostPercentage;                           // 3 - m_manaCostPct
    quint32    manaPerSecond;                                // 4 - m_manaPerSecond
    //uint32  PowerDisplayId;                               // 5 - m_powerDisplayID - id from PowerDisplay.dbc, new in 3.1
    //uint32  unk1;                                         // 6 - 4.0.0
    //unk                                                   // 7 - 4.3.0
};

// SpellReagents.dbc
struct SpellReagentsEntry
{
    //uint32    Id;                                           // 0        m_ID
    qint32     Reagent[MAX_SPELL_REAGENTS];                  // 54-61    m_reagent
    quint32    ReagentCount[MAX_SPELL_REAGENTS];             // 62-69    m_reagentCount
};

// SpellScaling.dbc
struct SpellScalingEntry
{
    //uint32    Id;                                         // 0        m_ID
    qint32     castTimeMin;                                  // 1
    qint32     castTimeMax;                                  // 2
    qint32     castScalingMaxLevel;                          // 3
    qint32     playerClass;                                  // 4        (index * 100) + charLevel => gtSpellScaling.dbc
    float     coeff1[3];                                    // 5-7
    float     coeff2[3];                                    // 8-10
    float     coeff3[3];                                    // 11-13
    float     coefBase;                                     // 14       some coefficient, mostly 1.0f
    qint32     coefLevelBase;                                // 15       some level

    bool IsScalableEffect(SpellEffectIndex i) const { return coeff1[i] != 0.0f; }
};

// SpellShapeshift.dbc
struct SpellShapeshiftEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    StancesNot;                                   // 13       m_shapeshiftMask
    // uint32 unk_320_2;                                    // 14       3.2.0
    quint32    Stances;                                      // 15       m_shapeshiftExclude
    // uint32 unk_320_3;                                    // 16       3.2.0
    // uint32    StanceBarOrder;                            // 155      m_stanceBarOrder not used
};

// SpellTargetRestrictions.dbc
struct SpellTargetRestrictionsEntry
{
    //uint32    Id;                                           // 0        m_ID
    float     MaxTargetRadius;                              // 1 - m_maxTargetRadius
    quint32    MaxAffectedTargets;                           // 1 - m_maxTargets
    quint32    MaxTargetLevel;                               // 2 - m_maxTargetLevel
    quint32    TargetCreatureType;                           // 3 - m_targetCreatureType
    quint32    Targets;                                      // 4 - m_targets
};

// SpellTotems.dbc
struct SpellTotemsEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    TotemCategory[MAX_SPELL_TOTEM_CATEGORIES];    // 162-163  m_requiredTotemCategoryID
    quint32    Totem[MAX_SPELL_TOTEMS];                      // 52-53    m_totem
};

// Spell.dbc
struct SpellEntry
{
    quint32    Id;                                           // 0        m_ID
    quint32    Attributes;                                   // 1        m_attribute
    quint32    AttributesEx;                                 // 2        m_attributesEx
    quint32    AttributesEx2;                                // 3        m_attributesExB
    quint32    AttributesEx3;                                // 4        m_attributesExC
    quint32    AttributesEx4;                                // 5        m_attributesExD
    quint32    AttributesEx5;                                // 6        m_attributesExE
    quint32    AttributesEx6;                                // 7        m_attributesExF
    quint32    AttributesEx7;                                // 8        m_attributesExG (0x20 - totems, 0x4 - paladin auras, etc...)
    quint32    AttributesEx8;                                // 9        m_attributesExH
    quint32    AttributesEx9;                                // 10       m_attributesExI
    quint32    AttributesEx10;                               // 11       m_attributesExJ
    quint32    CastingTimeIndex;                             // 12       m_castingTimeIndex
    quint32    DurationIndex;                                // 13       m_durationIndex
    quint32    powerType;                                    // 14       m_powerType
    quint32    rangeIndex;                                   // 15       m_rangeIndex
    float     speed;                                        // 16       m_speed
    quint32    SpellVisual[2];                               // 17-18    m_spellVisualID
    quint32    SpellIconID;                                  // 19       m_spellIconID
    quint32    activeIconID;                                 // 20       m_activeIconID
    DBCString SpellName;                                    // 21       m_name_lang
    DBCString Rank;                                         // 22       m_nameSubtext_lang
    //DBCString Description;                                // 23       m_description_lang not used
    //DBCString ToolTip;                                    // 24       m_auraDescription_lang not used
    quint32    SchoolMask;                                   // 25       m_schoolMask
    quint32    runeCostID;                                   // 26       m_runeCostID
    //quint32    spellMissileID;                             // 27       m_spellMissileID not used
    //quint32  spellDescriptionVariableID;                   // 28       m_spellDescriptionVariableID, 3.2.0
    quint32  SpellDifficultyId;                              // 29       m_spellDifficultyID - id from SpellDifficulty.dbc
    //float unk_f1;                                         // 30
    quint32 SpellScalingId;                                  // 31       SpellScaling.dbc
    quint32 SpellAuraOptionsId;                              // 32       SpellAuraOptions.dbc
    quint32 SpellAuraRestrictionsId;                         // 33       SpellAuraRestrictions.dbc
    quint32 SpellCastingRequirementsId;                      // 34       SpellCastingRequirements.dbc
    quint32 SpellCategoriesId;                               // 35       SpellCategories.dbc
    quint32 SpellClassOptionsId;                             // 36       SpellClassOptions.dbc
    quint32 SpellCooldownsId;                                // 37       SpellCooldowns.dbc
    //quint32 unkIndex7;                                     // 38       all zeros...
    quint32 SpellEquippedItemsId;                            // 39       SpellEquippedItems.dbc
    quint32 SpellInterruptsId;                               // 40       SpellInterrupts.dbc
    quint32 SpellLevelsId;                                   // 41       SpellLevels.dbc
    quint32 SpellPowerId;                                    // 42       SpellPower.dbc
    quint32 SpellReagentsId;                                 // 43       SpellReagents.dbc
    quint32 SpellShapeshiftId;                               // 44       SpellShapeshift.dbc
    quint32 SpellTargetRestrictionsId;                       // 45       SpellTargetRestrictions.dbc
    quint32 SpellTotemsId;                                   // 46       SpellTotems.dbc
    //quint32 ResearchProject;                               // 47       ResearchProject.dbc

    // helpers
    qint32 CalculateSimpleValue(SpellEffectIndex eff) const;
    ClassFamilyMask const& GetEffectSpellClassMask(SpellEffectIndex eff) const;

    // struct access functions
    SpellAuraOptionsEntry const* GetSpellAuraOptions() const;
    SpellAuraRestrictionsEntry const* GetSpellAuraRestrictions() const;
    SpellCastingRequirementsEntry const* GetSpellCastingRequirements() const;
    SpellCategoriesEntry const* GetSpellCategories() const;
    SpellClassOptionsEntry const* GetSpellClassOptions() const;
    SpellCooldownsEntry const* GetSpellCooldowns() const;
    SpellEffectEntry const* GetSpellEffect(SpellEffectIndex eff) const;
    SpellEquippedItemsEntry const* GetSpellEquippedItems() const;
    SpellInterruptsEntry const* GetSpellInterrupts() const;
    SpellLevelsEntry const* GetSpellLevels() const;
    SpellPowerEntry const* GetSpellPower() const;
    SpellReagentsEntry const* GetSpellReagents() const;
    SpellScalingEntry const* GetSpellScaling() const;
    SpellShapeshiftEntry const* GetSpellShapeshift() const;
    SpellTargetRestrictionsEntry const* GetSpellTargetRestrictions() const;
    SpellTotemsEntry const* GetSpellTotems() const;

    // single fields
    quint32 GetManaCost() const;
    quint32 GetPreventionType() const;
    quint32 GetCategory() const;
    quint32 GetStartRecoveryTime() const;
    quint32 GetMechanic() const;
    quint32 GetRecoveryTime() const;
    quint32 GetCategoryRecoveryTime() const;
    quint32 GetStartRecoveryCategory() const;
    quint32 GetSpellLevel() const;
    qint32 GetEquippedItemClass() const;
    SpellFamily GetSpellFamilyName() const;
    quint32 GetDmgClass() const;
    quint32 GetDispel() const;
    quint32 GetMaxAffectedTargets() const;
    quint32 GetStackAmount() const;
    quint32 GetManaCostPercentage() const;
    quint32 GetProcCharges() const;
    quint32 GetProcChance() const;
    quint32 GetMaxLevel() const;
    quint32 GetTargetAuraState() const;
    quint32 GetManaPerSecond() const;
    quint32 GetRequiresSpellFocus() const;
    quint32 GetSpellEffectIdByIndex(SpellEffectIndex index) const;
    quint32 GetAuraInterruptFlags() const;
    quint32 GetEffectImplicitTargetAByIndex(SpellEffectIndex index) const;
    qint32 GetAreaGroupId() const;
    quint32 GetFacingCasterFlags() const;
    quint32 GetBaseLevel() const;
    quint32 GetInterruptFlags() const;
    quint32 GetTargetCreatureType() const;
    qint32 GetEffectMiscValue(SpellEffectIndex index) const;
    quint32 GetStances() const;
    quint32 GetStancesNot() const;
    quint32 GetProcFlags() const;
    quint32 GetChannelInterruptFlags() const;
    quint32 GetManaCostPerLevel() const;
    quint32 GetCasterAuraState() const;
    quint32 GetTargets() const;
    quint32 GetEffectApplyAuraNameByIndex(SpellEffectIndex index) const;

    bool IsFitToFamilyMask(quint64 familyFlags, quint32 familyFlags2 = 0) const
    {
        SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
        return classOpt && classOpt->IsFitToFamilyMask(familyFlags, familyFlags2);
    }

    bool IsFitToFamily(SpellFamily family, quint64 familyFlags, quint32 familyFlags2 = 0) const
    {
        SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
        return classOpt && classOpt->IsFitToFamily(family, familyFlags, familyFlags2);
    }

    bool IsFitToFamilyMask(ClassFamilyMask const& mask) const
    {
        SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
        return classOpt && classOpt->IsFitToFamilyMask(mask);
    }

    bool IsFitToFamily(SpellFamily family, ClassFamilyMask const& mask) const
    {
        SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
        return classOpt && classOpt->IsFitToFamily(family, mask);
    }

    inline bool HasAttribute(SpellAttributes attribute) const { return Attributes & attribute; }
    inline bool HasAttribute(SpellAttributesEx attribute) const { return AttributesEx & attribute; }
    inline bool HasAttribute(SpellAttributesEx2 attribute) const { return AttributesEx2 & attribute; }
    inline bool HasAttribute(SpellAttributesEx3 attribute) const { return AttributesEx3 & attribute; }
    inline bool HasAttribute(SpellAttributesEx4 attribute) const { return AttributesEx4 & attribute; }
    inline bool HasAttribute(SpellAttributesEx5 attribute) const { return AttributesEx5 & attribute; }
    inline bool HasAttribute(SpellAttributesEx6 attribute) const { return AttributesEx6 & attribute; }
    inline bool HasAttribute(SpellAttributesEx7 attribute) const { return AttributesEx7 & attribute; }
    inline bool HasAttribute(SpellAttributesEx8 attribute) const { return AttributesEx8 & attribute; }
    inline bool HasAttribute(SpellAttributesEx9 attribute) const { return AttributesEx9 & attribute; }
    inline bool HasAttribute(SpellAttributesEx10 attribute) const { return AttributesEx10 & attribute; }

private:
    // prevent creating custom entries (copy data from original in fact)
    SpellEntry(SpellEntry const&);                      // DON'T must have implementation

    // catch wrong uses
    template<typename T>
    bool IsFitToFamilyMask(SpellFamily family, T t) const;
};

struct SpellEffect
{
    SpellEffect()
    {
        effects[0] = NULL;
        effects[1] = NULL;
        effects[2] = NULL;
    }
    SpellEffectEntry const* effects[3];
};

// SpellTotems.dbc
struct SpellIconEntry
{
    //uint32    Id;                                           // 0        m_ID
    quint32    IconID;    // 162-163  m_requiredTotemCategoryID
    DBCString  IconPath;                      // 52-53    m_totem
};

typedef std::map<quint32, SpellEffect> SpellEffectMap;
extern SpellEffectMap sSpellEffectMap;

#endif // SPELLS

