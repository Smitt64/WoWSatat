#include "wowitemsetbonus.h"

WoWItemSetBonus::WoWItemSetBonus(QObject *parent) :
    QObject(parent)
{

}

void WoWItemSetBonus::setDescription(const QString &str)
{
    m_description = str;
}

void WoWItemSetBonus::setThreshold(const quint8 &value)
{
    m_threshold = value;
}
