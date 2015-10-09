#ifndef WOWEQUIP_H
#define WOWEQUIP_H

#include <QObject>
#include <QQuickItem>
#include <QQmlListProperty>
#include "wowitembase.h"
#include "wowequipstat.h"

class WoWEquip : public WoWItemBase
{
    Q_OBJECT
    Q_PROPERTY(quint32 itemId READ itemId WRITE setItemId NOTIFY itemIdChanged)
    Q_PROPERTY(QString iconName READ iconName NOTIFY iconNameChanged)
    Q_PROPERTY(QQmlListProperty<WoWEquipStat> stats READ stats)
public:
    WoWEquip(QQuickPaintedItem *parent = 0);
    
    quint32 itemId() const { return m_itemId; }
    void setItemId(const quint32 &id);

    QString iconName() const { return m_iconName; }
    QQmlListProperty<WoWEquipStat> stats() { return QQmlListProperty<WoWEquipStat>((QObject*)this, m_stats); }

signals:
    void itemIdChanged();
    void iconNameChanged();

public slots:
    
private:
    quint32 m_itemId;
    QString m_iconName;

    QList<WoWEquipStat*> m_stats;
};

#endif // WOWEQUIP_H
