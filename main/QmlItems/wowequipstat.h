#ifndef WOWEQUIPSTAT_H
#define WOWEQUIPSTAT_H

#include <QObject>

class WoWEquipStat : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 type READ type)
    Q_PROPERTY(quint16 amount READ amount)
public:
    explicit WoWEquipStat(QObject *parent = 0);

    quint8 type() const { return m_stat; }
    quint16 amount() const { return m_amount; }

private:
    quint8 m_stat;
    quint16 m_amount;
};

#endif // WOWEQUIPSTAT_H
