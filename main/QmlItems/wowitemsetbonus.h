#ifndef WOWITEMSETBONUS_H
#define WOWITEMSETBONUS_H

#include <QObject>

class WoWEquip;
class WoWItemSetBonus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString description READ description)
    Q_PROPERTY(quint16 threshold READ threshold)

    friend class WoWEquip;
public:
    explicit WoWItemSetBonus(QObject *parent = 0);

    const quint16 &threshold() const { return m_threshold; }
    const QString &description() const { return m_description; }

protected:
    void setDescription(const QString &str);
    void setThreshold(const quint8 &value);

private:
    QString m_description;
    quint16 m_threshold;
};

#endif // WOWITEMSETBONUS_H
