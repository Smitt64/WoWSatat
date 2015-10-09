#ifndef WOWITEMBASE_H
#define WOWITEMBASE_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>

class WoWItemBase : public QQuickPaintedItem
{
    Q_OBJECT
public:
    WoWItemBase(QQuickItem *parent = NULL);
    void paint(QPainter *painter);

    Q_INVOKABLE void resetImage();

signals:

public slots:

protected:
    QImage m_icon;
};

#endif // WOWITEMBASE_H
