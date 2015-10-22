#ifndef WOWEQUIPSTAT_H
#define WOWEQUIPSTAT_H

#include <QObject>

class WoWEquipStat : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Stat type READ type)
    Q_PROPERTY(quint16 amount READ amount)
    Q_PROPERTY(QString typeName READ typeName)

    Q_ENUMS(Stat)
    friend class WoWEquip;
    friend bool EquipStatLessThen(const WoWEquipStat *s1, const WoWEquipStat *s2);
public:
    enum Stat {
        Mana = 0,
        Health = 1,
        Agility = 3,
        Strength = 4,
        Intellect = 5,
        Spirit = 6,
        Stamina = 7,
        Defense = 12,
        Dodge = 13,
        Parry = 14,
        Block = 15,
        HitMelee = 16,
        HitRanged = 17,
        HitSpell = 18,
        CriticalStrikeMelee = 19,
        CriticalStrikeRanged = 20,
        CriticalStrikeSpell = 21,
        HitAvoidanceRanged = 23,
        HitAvoidanceSpell = 24,
        CriticalStrikeAvoidanceMelee = 25,
        CriticalStrikeAvoidanceRanged = 26,
        CriticalStrikeAvoidanceSpell = 27,
        HasteMelee = 28,
        HasteRanged = 29,
        HasteSpell = 30,
        Hit = 31,
        CriticalStrike = 32,
        HitAvoidance = 33,
        CriticalStrikeAvoidance = 34,
        PvPResilience = 35,
        Haste = 36,
        Expertise = 37,
        AttackPower = 38,
        RangedAttackPower = 39,
        Versatility = 40,
        BonusHealing = 41,
        BonusDamage = 42,
        ManaRegeneration = 43,
        ArmorPenetration = 44,
        SpellPower = 45,
        HealthPer5Sec = 46,
        SpellPenetration = 47,
        BlockValue = 48,
        Mastery = 49,
        BonusArmor = 50,
        FireResistance = 51,
        FrostResistance = 52,
        HolyResistance = 53,
        ShadowResistance = 54,
        NatureResistance = 55,
        ArcaneResistance = 56,
        PvPPower = 57,
        Amplify = 58,
        Multistrike = 59,
        Readiness = 60,
        Speed = 61,
        Leech = 62,
        Avoidance = 63,
        Indestructible = 64,
        Unused7 = 65,
        Cleave = 66,
        Versatility2 = 67,
        Unused10 = 68,
        Unused11 = 69,
        Unused12 = 70
    };

    explicit WoWEquipStat(QObject *parent = 0);

    Stat type() const { return m_stat; }
    quint16 amount() const { return m_amount; }

    QString typeName() const;

private:
    Stat m_stat;
    quint16 m_amount;
};

#endif // WOWEQUIPSTAT_H
