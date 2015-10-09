#ifndef WOWITEMBASE_H
#define WOWITEMBASE_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WoWItemBase : public QQuickPaintedItem
{
    Q_OBJECT
public:
    WoWItemBase(QQuickItem *parent = NULL);
    virtual ~WoWItemBase();
    void paint(QPainter *painter);

    Q_INVOKABLE void resetImage();
    Q_INVOKABLE void loadFromUrl(const QUrl &url);

signals:
    void imageFinished();

private slots:
    void finished();

protected:
    QImage m_icon;
    QNetworkAccessManager *am;
    QNetworkReply *reply;
};

#endif // WOWITEMBASE_H
