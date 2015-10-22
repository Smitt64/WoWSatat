#include "wowitembase.h"
#include "dbfiles/dbcstructure.h"
#include <QTextCodec>
#include <QPainter>
#include <QDebug>

WoWItemBase::WoWItemBase(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    reply(NULL),
    m_itemClass(WoWItemBase::Consumable),
    m_itemSubClass(0)
{
    resetImage();
    setOpaquePainting(true);

    am = new QNetworkAccessManager(this);
}

WoWItemBase::~WoWItemBase()
{
    delete am;
}

void WoWItemBase::paint(QPainter *painter)
{
    QRectF rc = boundingRect();//.adjusted(1, 1, -1, -1);
    painter->fillRect(rc, Qt::transparent);
    painter->drawImage(rc, m_icon, m_icon.rect());
}

void WoWItemBase::loadFromId(const quint32 &id)
{
}

void WoWItemBase::resetImage()
{
    qDebug() << m_icon.load(":/images/ui/items/WoWUnknownItem01.png");
}

void WoWItemBase::setIcon(const QVariant &i)
{
    if (i.canConvert(QVariant::Int))
    {

    }
}

void WoWItemBase::loadFromUrl(const QUrl &url)
{
    reply = am->get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()), SLOT(finished()));
}

void WoWItemBase::finished()
{
    QNetworkReply *rp = (QNetworkReply*)sender();
    m_icon.loadFromData(rp->readAll());
    emit iconChanged();
    update();

    delete rp;
}

QString WoWItemBase::itemClassName() const
{
    if (m_itemClass >= 0)
    {
        const ItemClass *item = sItemClass.LookupEntry((quint32)m_itemClass);

        if (item)
        {
            return QString::fromLocal8Bit(*item->className);
        }
    }

    return QString();
}

QString WoWItemBase::itemSubClassName() const
{
    quint32 itemCount = sItemSubClass.GetNumRows();

    const ItemSubClass *item = NULL;
    for (quint32 i = 0; i < itemCount; i++)
    {
        item = sItemSubClass.LookupEntry(i);

        if (item->itemClass == m_itemClass && item->itemSubClass == m_itemSubClass)
        {
            break;
        }
    }

    if (!item)
        return tr("Unknown");

    //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    return QString(*item->displayName);
}

void WoWItemBase::setItemClass(const ItemClassEnum &itemclass)
{
    m_itemClass = itemclass;
}

void WoWItemBase::setItemSubClass(const quint8 &subclass)
{
    m_itemSubClass = subclass;
}
