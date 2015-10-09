#include "wowitembase.h"
#include <QPainter>
#include <QDebug>

WoWItemBase::WoWItemBase(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    reply(NULL)
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

void WoWItemBase::resetImage()
{
    qDebug() << m_icon.load(":/images/ui/items/WoWUnknownItem01.png");
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

    update();

    delete rp;
}
