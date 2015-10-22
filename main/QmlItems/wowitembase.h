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
    Q_PROPERTY(QVariant icon READ icon NOTIFY iconChanged)
    Q_PROPERTY(ItemClassEnum itemClass READ itemClass)
    Q_PROPERTY(quint8 itemSubClass READ itemSubClass)
    Q_PROPERTY(QString itemClassName READ itemClassName)
    Q_PROPERTY(QString itemSubClassName READ itemSubClassName)    

    Q_ENUMS(InventorySlot)
    Q_ENUMS(ItemClassEnum)
public:
    enum InventorySlot{
        None = 0,
        Head, // Голова
        Neck, // Шея
        Shoulders, // Плечи
        Shirt, // Рубашка
        Vest, // Грудь
        Waist, // Пояс
        Legs, // Ноги
        Feet, // Ступни
        Wrist,// Запястье
        Hands, // Кисти
        Ring, // Кольцо
        Trinket, // Аксесуар
        OneHand, // Одноручное
        Shield, // Щит
        Bow, // лук
        Back, // Спина
        TwoHand, // Двуручное
        Bag, // Сумка
        Tabbard, //
        Robe, // Накидка
        MainHand, // Основная рука
        OffHand,
        Held,
        Ammo,
        Thrown,
        Ranged,
        Quiver,
        Relic
    };

    enum ItemClassEnum
    {
        Consumable = 0,
        Container,
        Weapon,
        Gem,
        Armor,
        Reagent,
        Projectile,
        TradeGoods,
        Generic,
        Book,
        Money,
        QuiverItem,
        Quest,
        Key,
        Permanent,
        Junk,
        Glyph
    };

    WoWItemBase(QQuickItem *parent = NULL);
    virtual ~WoWItemBase();
    void paint(QPainter *painter);

    Q_INVOKABLE void resetImage();
    Q_INVOKABLE void loadFromUrl(const QUrl &url);
    Q_INVOKABLE void loadFromId(const quint32 &id);
    
    QVariant icon() const { return m_iconName; }
    void setIcon(const QVariant &icn);

    const ItemClassEnum &itemClass() const { return m_itemClass; }

    QString itemClassName() const;
    QString itemSubClassName() const;
    const quint8 &itemSubClass() const { return m_itemSubClass; }

signals:
    void imageFinished();
    void iconChanged();

private slots:
    void finished();

protected:
    void setItemClass(const ItemClassEnum &itemclass);
    void setItemSubClass(const quint8 &subclass);
    QImage m_icon;
    ItemClassEnum m_itemClass;
    quint8 m_itemSubClass;

    QVariant m_iconName;
    QNetworkAccessManager *am;
    QNetworkReply *reply;
};

#endif // WOWITEMBASE_H
