#include "wowequipstat.h"

WoWEquipStat::WoWEquipStat(QObject *parent) : QObject(parent)
{

}

QString WoWEquipStat::typeName() const
{
    QString st;

    switch(m_stat)
    {
    case Mana:
        st = tr("Мана");
        break;
    case Health:
        st = tr("Здоровье");
        break;
    case Agility:
        st = tr("Ловкость");
        break;
    case Strength:
        st = tr("Сила");
        break;
    case Intellect:
        st = tr("Интеллект");
        break;
    case Spirit:
        st = tr("Дух");
        break;
    case Stamina:
        st = tr("Выносливость");
        break;
    case Defense:
        st = tr("Защита");
        break;
    case Dodge:
        st = tr("Уклонение");
        break;
    case Parry:
        st = tr("Парирование");
        break;
    case Block:
        st = tr("Блок");
        break;
    case HitMelee:
        st = tr("Меткость (ближнего)");
        break;
    case HitRanged:
        st = tr("Меткость (Дальний)");
        break;
    case HitSpell:
        st = tr("Меткость (заклинаний)");
        break;
    case CriticalStrikeMelee:
        st = tr("Критический удар (ближнего)");
        break;
    case CriticalStrikeRanged:
        st = tr("Критический удар (Дальний)");
        break;
    case CriticalStrikeSpell:
        st = tr("Критический удар (заклинаний)");
        break;
    case HitAvoidanceRanged:
        st = tr("Избегание (Дальний)");
        break;
    case HitAvoidanceSpell:
        st = tr("Избегание (ближнего)");
        break;
    case CriticalStrikeAvoidanceMelee:
        st = tr("Критический Удар Избегание (ближнего)");
        break;
    case CriticalStrikeAvoidanceRanged:
        st = tr("Критический Удар Избегание (Дальний)");
        break;
    case CriticalStrikeAvoidanceSpell:
        st = tr("Критический Удар Избежание (Spell)");
        break;
    case HasteMelee:
        st = tr("Мана");
        break;
    case HasteRanged:
        st = tr("Скорость (ближнего)");
        break;
    case HasteSpell:
        st = tr("Скорость (заклинаний)");
        break;
    case Hit:
        st = tr("Меткость");
        break;
    case CriticalStrike:
        st = tr("Критический удар");
        break;
    case HitAvoidance:
        st = tr("Хит Предотвращение");
        break;
    case CriticalStrikeAvoidance:
        st = tr("Критический Удар Избегание");
        break;
    case PvPResilience:
        st = tr("PvP Устойчивость");
        break;
    case Haste:
        st = tr("Скорость");
        break;
    case Expertise:
        st = tr("Экспертиза");
        break;
    case AttackPower:
        st = tr("Сила атаки");
        break;
    case RangedAttackPower:
        st = tr("Сила атаки дальнего боя");
        break;
    case Versatility:
        st = tr("Униврсальность");
        break;
    case BonusHealing:
        st = tr("Бонус Исцеление");
        break;
    case BonusDamage:
        st = tr("Бонус Урон");
        break;
    case ManaRegeneration:
        st = tr("Восстановление маны");
        break;
    case ArmorPenetration:
        st = tr("Бонус к броне");
        break;
    case SpellPower:
        st = tr("Восстановление маны");
        break;
    case HealthPer5Sec:
        st = tr("Здоровья каждые 5 секунд.");
        break;
    case SpellPenetration:
        st = tr("Проникновение Заклинания");
        break;
    case BlockValue:
        st = tr("Блок Значение");
        break;
    case Mastery:
        st = tr("Искусности");
        break;
    case BonusArmor:
        st = tr("Бонус брони");
        break;
    case FireResistance:
        st = tr("Огнестойкость");
        break;
    case FrostResistance:
        st = tr("Морозостойкость");
        break;
    case HolyResistance:
        st = tr("Святой Сопротивление");
        break;
    case ShadowResistance:
        st = tr("Сопротивление темной магии");
        break;
    case NatureResistance:
        st = tr("Сопротивление силам природы");
        break;
    case ArcaneResistance:
        st = tr("Сопротивление тайной магии");
        break;
    case PvPPower:
        st = tr("PvP сила");
        break;
    case Amplify:
        st = tr("Усиливать");
        break;
    case Multistrike:
        st = tr("Многократная атака");
        break;
    case Readiness:
        st = tr("Готовность");
        break;
    case Speed:
        st = tr("Скорость");
        break;
    case Leech:
        st = tr("Похищение жизни");
        break;
    case Avoidance:
        st = tr("Уклонение");
        break;
    case Indestructible:
        st = tr("Нерушимый");
        break;
    case Cleave:
        st = tr("Рассекание");
        break;
    case Versatility2:
        st = tr("Универсальность");
        break;
    case Unused7:
    case Unused10:
    case Unused11:
    case Unused12:
    default:
        st = tr("Неизвестная характеристика");
    }

    return st;
}
