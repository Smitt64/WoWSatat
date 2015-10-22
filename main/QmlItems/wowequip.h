#ifndef WOWEQUIP_H
#define WOWEQUIP_H

#include <QObject>
#include <QQuickItem>
#include <QQmlListProperty>
#include "wowitembase.h"
#include "wowequipstat.h"

class QJsonObject;
class WoWItemSetBonus;
class WoWEquip : public WoWItemBase
{
    Q_OBJECT
    Q_PROPERTY(quint32 itemId READ itemId WRITE setItemId NOTIFY itemIdChanged)
    Q_PROPERTY(QString description READ description)

    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QString nameDescription READ nameDescription)
    Q_PROPERTY(QColor nameDescriptionColor READ nameDescriptionColor)

    Q_PROPERTY(quint8 inventoryType READ inventoryType)
    Q_PROPERTY(QString inventorySlotName READ inventorySlotName)
    Q_PROPERTY(quint16 itemLevel READ itemLevel)

    Q_PROPERTY(quint8 quality READ quality)
    Q_PROPERTY(QColor qualityColor READ qualityColor)

    Q_PROPERTY(quint32 sellPrice READ sellPrice)
    Q_PROPERTY(quint16 requiredLevel READ requiredLevel)

    Q_PROPERTY(quint16 armor READ armor)
    Q_PROPERTY(quint16 baseArmor READ baseArmor)

    Q_PROPERTY(QString itemSetName READ itemSetName)
    Q_PROPERTY(quint16 itemSetCount READ itemSetCount)
    Q_PROPERTY(QString itemSetId READ itemSetId)

    Q_PROPERTY(bool hasSockets READ hasSockets)
    Q_PROPERTY(bool isSetItem READ isSetItem)

    Q_PROPERTY(quint16 maxDurability READ maxDurability)

    Q_PROPERTY(QList<qint32> allowableClasses READ allowableClasses)
    Q_PROPERTY(QList<qint32> allowableRaces READ allowableRaces)
    Q_PROPERTY(QQmlListProperty<WoWEquipStat> stats READ stats NOTIFY statsChanged)
    Q_PROPERTY(QQmlListProperty<WoWItemSetBonus> setBonuses READ setBonuses)

    Q_ENUMS(Quality)
public:
    enum Quality
    {
        Poor = 0, // серый (#819D8E)
        Common,   // белый (#FFF1CA)
        Uncommon, // зеленый (#27F100)
        Rare,     // синий (#1770FF)
        Epic,     // фиолетовый (#8835EE)
        Legendary,// оранжевый (#DD8000)
        Artifact, // артифакт (#C8CC80)
        Heirloom  // (#B7C280)
    };

    WoWEquip(QQuickPaintedItem *parent = 0);
    virtual ~WoWEquip();
    
    const quint32 &itemId() const { return m_itemId; }
    void setItemId(const quint32 &id);

    QQmlListProperty<WoWEquipStat> stats() { return QQmlListProperty<WoWEquipStat>((QObject*)this, m_stats); }
    QQmlListProperty<WoWItemSetBonus> setBonuses() { return QQmlListProperty<WoWItemSetBonus>((QObject*)this, m_setBonuses); }

    void fromJsonObject(QJsonObject obj);
    void fromJson(const QByteArray &data);

    const QString &description() const { return m_description; }

    const QString &name() const { return m_name; }
    const QString &nameDescription() const { return m_nameDescription; }
    const QColor &nameDescriptionColor() const { return m_nameDescriptionColor; }

    const quint8 &inventoryType() const { return m_inventoryType; }
    const quint16 &itemLevel() const { return m_itemLevel; }
    const quint16 &requiredLevel() const { return m_requiredLevel; }

    QColor qualityColor() const;
    const quint8 &quality() const { return m_quality; }

    const quint32 &sellPrice() const { return m_sellPrice; }

    const quint16 &armor() const  { return m_armor; }
    const quint16 &baseArmor() const { return m_baseArmor; }
    const quint16 &maxDurability() const { return m_maxDurability; }

    const QString &itemSetName() const { return m_itemSetName; }
    const quint32 &itemSetId() const { return m_itemSetId; }
    quint16 itemSetCount() const { return m_setItems.size(); }
    const bool isSetItem() const { return !m_itemSetName.isEmpty(); }

    const bool &hasSockets() const { return fhasSockets; }

    Q_INVOKABLE static QString qualityColor(const Quality &q);
    QString inventorySlotName() const;

    const QList<qint32> allowableClasses() const { return m_allowableClasses; }
    const QList<qint32> allowableRaces() const { return m_allowableRaces; }
signals:
    void itemIdChanged();
    void iconNameChanged();
    void statsChanged();

private slots:
    void onItemIdDownloadFinished();
    
private:
    quint32 m_itemId;
    QString m_description, m_name;
    quint8 m_inventoryType, m_quality;
    quint16 m_itemLevel, m_requiredLevel;
    quint32 m_sellPrice;

    quint16 m_armor, m_baseArmor, m_maxDurability;
    bool fhasSockets;

    QString m_itemSetName, m_nameDescription;
    QString m_nameDescriptionColor;
    quint32 m_itemSetId;

    QList<WoWEquipStat*> m_stats;
    QList<WoWItemSetBonus*> m_setBonuses;
    QList<quint16> m_setItems;

    QList<qint32> m_allowableClasses;
    QList<qint32> m_allowableRaces;

    QNetworkReply *jSonReply;
};

#endif // WOWEQUIP_H
