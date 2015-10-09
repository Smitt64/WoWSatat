#include "wowitembase.h"
#include <QPainter>
#include <QDebug>

WoWItemBase::WoWItemBase(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    resetImage();
    setOpaquePainting(true);
}

void WoWItemBase::paint(QPainter *painter)
{
    QRectF rc = boundingRect();//.adjusted(1, 1, -1, -1);
    painter->fillRect(rc, Qt::transparent);
    painter->drawImage(rc, m_icon, m_icon.rect());
}

void WoWItemBase::resetImage()
{
    qDebug() << m_icon.load(":/images/ui/items/WoWUnknownItem01.png");
}
