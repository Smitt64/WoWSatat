import QtQuick 2.0
import WowStat 1.0
import "WoWEquipToolTip.js" as ToolTip

Item {
    id: tooltip
    width: 300
    height: column1.height + 12

    property string itemName: qsTr("Item Name")
    property color nameQualityColor: "#8835ee"
    property string nameDescription: qsTr("Name Description")
    property string inventoryType: qsTr("inventoryType")
    property string armorType: qsTr("armorType")
    property string allowableClasses: ""
    property int itemLevel: 0
    property int armor: 0
    property int maxDurability: 0
    property int requiredLevel: 0
    property string allowableRaces: qsTr("allowableRaces")
    property string itemSetName: ""
    property int itemSetCount: 0
    property string itemSetBonuses: ""
    property int sellPrice: 0

    property bool showClasses: true
    property bool isSetItem: false

    property WoWEquip equipItem

    property ListModel statList: ListModel {

    }

    Image {
        id: image1
        anchors.rightMargin: 2
        anchors.leftMargin: 2
        anchors.bottomMargin: 2
        anchors.topMargin: 2
        anchors.fill: parent
        source: "../images/ui/UI-DialogBox-Background.png"

        Column {
            id: column1
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.rightMargin: 4
            anchors.leftMargin: 4
            anchors.topMargin: 4

            Text {
                id: nameText
                text: itemName
                anchors.left: parent.left
                anchors.right: parent.right
                wrapMode: Text.WordWrap
                font.bold: true
                font.pixelSize: 12
                height: contentHeight
                color: nameQualityColor
            }

            Text {
                id: nameDescriptionText
                color: "#0fff04"
                text: nameDescription
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                wrapMode: Text.WordWrap
                font.pixelSize: 11
            }

            Text {
                id: itemLevelText
                color: "#ffd100"
                text: qsTr("Уровень предмета: ")
                font.pixelSize: 12
            }

            Item {
                id: row1
                height: inventoryText.contentHeight
                anchors.rightMargin: -1
                anchors.left: parent.left
                anchors.leftMargin: -1
                anchors.right: parent.right

                Text {
                    id: inventoryText
                    color: "#e7e5e5"
                    text: inventoryType
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    font.pixelSize: 12
                }

                Text {
                    id: armorTypeText
                    color: "#e7e5e5"
                    text: armorType
                    anchors.rightMargin: 4
                    anchors.right: parent.right
                    font.pixelSize: 12
                }
            }

            Text {
                id: armorText
                color: "#e7e5e5"
                text: qsTr("Броня: ")
                font.pixelSize: 12
            }

            Repeater {
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.leftMargin: 0
                model: statList

                Text {
                    anchors.left: parent.left
                    anchors.right: parent.right

                    text: "+ " + model.amount + " " + model.typeName
                    font.pixelSize: 12

                    color: "#e7e5e5"
                }
            }

            Text {
                id: maxDurabilityText
                text: qsTr("Прочность: ")
                color: "#e7e5e5"
                font.pixelSize: 12
            }

            Text {
                id: classText
                text: qsTr("Классы:")
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                wrapMode: Text.WordWrap
                textFormat: Text.RichText
                color: "#e7e5e5"
                font.pixelSize: 12
            }

            Text {
                id: racesText
                text: qsTr("Расы: ")
                wrapMode: Text.WordWrap
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                font.pixelSize: 12
                color: "#e7e5e5"
            }

            Text {
                id: requiredLevelText
                text: qsTr("Требуется уровень: ")
                font.pixelSize: 12
                color: "#e7e5e5"
            }

            Column {
                id: itemSetColumn
                visible: isSetItem
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right

                Text {
                    id: itemSetNameText
                    color: "#ffd100"
                    text: "itemSetName"
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: parent.right
                    anchors.topMargin: 12
                    font.pixelSize: 12
                }

                Text {
                    id: itemSetItemsText
                    color: "#9d9d9d"
                    text: qsTr("Временно недоступно")
                    visible: true
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    anchors.leftMargin: 12
                    anchors.right: parent.right
                    font.pixelSize: 12
                }

                Text {
                    id: itemSetBonusesText
                    color: "#9d9d9d"
                    text: itemSetBonuses
                    anchors.right: parent.right
                    wrapMode: Text.WordWrap
                    anchors.left: parent.left
                    font.pixelSize: 12
                }
            }

            Row {
                spacing: 8
                Text {
                    id: costText
                    text: qsTr("Цена продажи:")
                    font.pixelSize: 12
                    color: "#e7e5e5"
                }

                WoWMoneyWidget {
                    id: costWidget
                    money: sellPrice
                    textColor: "#e7e5e5"
                    height: costText.contentHeight
                }
            }
        }
    }

    BorderImage {
        id: borderImage1
        border.bottom: 10
        border.top: 10
        border.right: 10
        border.left: 10
        anchors.fill: parent
        source: "../images/ui/tooltip/ToolTip_Borderd.png"
    }

    onItemLevelChanged: {
        itemLevelText.text = qsTr("Уровень предмета: ") + itemLevel
    }

    onArmorChanged: {
        armorText.text = qsTr("Броня: ") + armor
    }

    onMaxDurabilityChanged: {
        maxDurabilityText.text = qsTr("Прочность: ") + maxDurability + " / " + maxDurability
    }

    onAllowableClassesChanged: {
        classText.text = qsTr("Классы: ") + allowableClasses
    }

    onAllowableRacesChanged: {
        racesText.text = qsTr("Расы: ") + allowableRaces
    }

    onRequiredLevelChanged: {
        requiredLevelText.text = qsTr("Требуется уровень: ") + requiredLevel
    }

    onItemSetNameChanged: {
        itemSetNameText.text = "\n" + itemSetName + " (0/" + itemSetCount + ")"
    }

    function pump(equipItem) {
        tooltip.equipItem = equipItem
        ToolTip.pumpData(equipItem)
    }
}

