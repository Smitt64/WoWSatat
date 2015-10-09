#include "wowequip.h"

WoWEquip::WoWEquip(QQuickPaintedItem *parent) :
    WoWItemBase(parent)
{

}

void WoWEquip::setItemId(const quint32 &id)
{
    m_itemId = id;
}
