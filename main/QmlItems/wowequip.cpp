#include "wowequip.h"
#include "wowitemsetbonus.h"
#include "dbfiles/dbcstructure.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <algorithm>
#include "wowstatobject.h"
#include "dbfiles/dbcstructure.h"

bool EquipStatLessThen(const WoWEquipStat *s1, const WoWEquipStat *s2)
{
    return s1->m_stat < s2->m_stat;
}

WoWEquip::WoWEquip(QQuickPaintedItem *parent) :
    WoWItemBase(parent)
{

}

WoWEquip::~WoWEquip()
{
    foreach (WoWItemSetBonus *item, m_setBonuses) {
        delete item;
    }

    foreach (WoWEquipStat *stat, m_stats) {
        delete stat;
    }


    m_setBonuses.clear();
    m_setItems.clear();
}

void WoWEquip::setItemId(const quint32 &id)
{
    m_itemId = id;
    QUrl url(QString("https://eu.api.battle.net/wow/item/%1?locale=%2&apikey=t3t28turs87zgaq9rpvdxts8h8tvq3mn")
             .arg(id)
             .arg("ru_RU"));
    jSonReply = am->get(QNetworkRequest(url));
    connect(jSonReply, SIGNAL(finished()), SLOT(onItemIdDownloadFinished()));
}

void WoWEquip::onItemIdDownloadFinished()
{
    qDebug() << "onItemIdDownloadFinished";
    fromJson(jSonReply->readAll());
}

void WoWEquip::fromJson(const QByteArray &data)
{
    QString val = data;
    QJsonParseError jerror;
    QJsonDocument docum = QJsonDocument::fromJson(val.toUtf8(), &jerror);

    if (jerror.error != QJsonParseError::NoError)
    {
        qDebug() << jerror.errorString();
    }
    fromJsonObject(docum.object());
}

QString WoWEquip::qualityColor(const Quality &q)
{
    QString s;
    switch(q)
    {
    case Common:
        s = "#fff1ca";
        break;
    case Uncommon:
        s = "#27f100";
        break;
    case Rare:
        s = "#1770ff";
        break;
    case Epic:
        s = "#8835ee";
        break;
    case Legendary:
        s = "#dd8000";
        break;
    case Artifact:
        s = "#c8cc80";
        break;
    case Heirloom:
        s = "#b7c280";
        break;

    case Poor:
    default:
        s = "#819d8e";
    }
    return s;
}

QString WoWEquip::inventorySlotName() const
{
    QString s;
    switch(m_inventoryType)
    {
    case None:
        break;
    case Head:
        s = tr("Голова");
        break;
    case Neck:
        s = tr("Шея");
        break;
    case Shoulders:
        s = tr("Плечи");
        break;
    case Shirt:
        s = tr("Рубашка");
        break;
    case Vest:
        s = tr("Грудь");
        break;
    case Waist:
        s = tr("Пояс");
        break;
    case Legs:
        s = tr("Ноги");
        break;
    case Feet:
        s = tr("Ступни");
        break;
    case Wrist:
        s = tr("Запястье");
        break;
    case Hands:
        s = tr("Кисти");
        break;
    case Ring:
        s = tr("Кольцо");
        break;
    case Trinket:
        s = tr("Аксесуар");
        break;
    case OneHand:
        s = tr("Одноручное");
        break;
    case Shield:
        s = tr("Щит");
        break;
    case Bow:
        s = tr("лук");
        break;
    case Back:
        s = tr("Спина");
        break;
    case TwoHand:
        s = tr("Двуручное");
        break;
    case Bag:
        s = tr("Сумка");
        break;
    case Tabbard:
    case Robe:
        s = tr("Накидка");
        break;
    case MainHand:
        s = tr("Основная рука");
        break;
    case OffHand:
    case Held:
    case Ammo:
    case Thrown:
    case Ranged:
    case Quiver:
    case Relic:
    default:
        s = "";
    }
    return s;
}

QColor WoWEquip::qualityColor() const
{
    return QColor(qualityColor((WoWEquip::Quality)m_quality).toLocal8Bit().data());
}

void WoWEquip::fromJsonObject(const QJsonObject obj)
{
    if (!obj["id"].isUndefined()) m_itemId = obj["id"].toInt();
    if (!obj["description"].isUndefined()) m_description = obj["description"].toString();

    if (!obj["name"].isUndefined()) m_name = obj["name"].toString();
    if (!obj["nameDescription"].isUndefined()) m_nameDescription = obj["nameDescription"].toString();
    if (!obj["nameDescriptionColor"].isUndefined()) m_nameDescriptionColor = obj["nameDescriptionColor"].toString();

    if (!obj["inventoryType"].isUndefined()) m_inventoryType = obj["inventoryType"].toInt();
    if (!obj["itemLevel"].isUndefined()) m_itemLevel = obj["itemLevel"].toInt();
    if (!obj["quality"].isUndefined()) m_quality = obj["quality"].toInt();
    if (!obj["sellPrice"].isUndefined()) m_sellPrice = obj["sellPrice"].toInt();

    if (!obj["armor"].isUndefined()) m_armor = obj["armor"].toInt();
    if (!obj["baseArmor"].isUndefined()) m_baseArmor = obj["baseArmor"].toInt();
    if (!obj["hasSockets"].isUndefined()) fhasSockets = obj["hasSockets"].toBool();

    if (!obj["itemClass"].isUndefined()) m_itemClass = (WoWItemBase::ItemClassEnum)obj["itemClass"].toInt();
    if (!obj["itemSubClass"].isUndefined()) m_itemSubClass = obj["itemSubClass"].toInt();
    if (!obj["maxDurability"].isUndefined()) m_maxDurability = obj["maxDurability"].toInt();
    if (!obj["requiredLevel"].isUndefined()) m_requiredLevel = obj["requiredLevel"].toInt();

    //http://wow.zamimg.com/images/wow/icons/large/inv_shoulder_plate_raiddeathknight_p_01.jpg
    loadFromUrl(QUrl(QString("http://wow.zamimg.com/images/wow/icons/large/%1.jpg").arg(obj["icon"].toString())));

    if (!obj["bonusStats"].isUndefined() && obj["bonusStats"].isArray())
    {
        QJsonArray &bonuses = obj["bonusStats"].toArray();
        foreach (QJsonValue bonusItem, bonuses) {
            if (!bonusItem.isUndefined())
            {
                QJsonObject bonus = bonusItem.toObject();
                WoWEquipStat *s = new WoWEquipStat(this);
                s->m_amount = bonus["amount"].toInt();
                s->m_stat = (WoWEquipStat::Stat)bonus["stat"].toInt();
                m_stats.append(s);
            }
        }
    }

    qSort(m_stats.begin(), m_stats.end(), EquipStatLessThen);

    if (!obj["itemSet"].isUndefined() && obj["itemSet"].isObject())
    {
        QJsonObject setObj = obj["itemSet"].toObject();

        if (!setObj["id"].isUndefined()) m_itemSetId = setObj["id"].toInt();
        if (!setObj["name"].isUndefined()) m_itemSetName = setObj["name"].toString();

        if (!setObj["setBonuses"].isUndefined() && setObj["setBonuses"].isArray())
        {
            QJsonArray &bonuses = setObj["setBonuses"].toArray();

            foreach (QJsonValue bonusItem, bonuses) {
                if (!bonusItem.isUndefined())
                {
                    QJsonObject bonus = bonusItem.toObject();
                    WoWItemSetBonus *item = new WoWItemSetBonus(this);
                    item->setDescription(bonus["description"].toString());
                    item->setThreshold(bonus["threshold"].toInt());

                    m_setBonuses.append(item);
                }
            }
        }

        QJsonArray setitems = setObj["items"].toArray();
        foreach (QJsonValue sitems, setitems) {
            m_setItems.append(sitems.toInt());
        }
    }

    if (!obj["allowableClasses"].isUndefined() && obj["allowableClasses"].isArray()) {
        QJsonArray &classes = obj["allowableClasses"].toArray();

        foreach (QJsonValue c, classes) {
            m_allowableClasses.append(c.toInt());
        }
    }

    if (!obj["allowableRaces"].isUndefined() && obj["allowableRaces"].isArray()) {
        QJsonArray &races = obj["allowableRaces"].toArray();

        foreach (QJsonValue c, races) {
            m_allowableRaces.append(c.toInt());
        }
    }

    std::sort(m_allowableRaces.begin(), m_allowableRaces.end());
    m_allowableRaces.erase(std::unique(m_allowableRaces.begin(), m_allowableRaces.end()), m_allowableRaces.end());
}
