import QtQuick 2.0
import WowStat 1.0

Item {
    id: item1
    width: row1.width
        //height * 4 + row1.spacing * 4 + copperText.contentWidth + (silverText.visible ? silverText.contentWidth : 0) + (goldText.visible ? goldText.contentWidth : 0)
    height: 25

    property int money: 0
    property color textColor: "black"

    Row {
        id: row1
        spacing: 6
        height: parent.height
        layoutDirection: Qt.RightToLeft

        Image {
            id: image1
            width: row1.height
            height: row1.height
            source: "../images/ui/money/money-copper.png"
        }

        Text {
            id: copperText
            text: "0"
            color: textColor
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            font.pixelSize: row1.height
        }

        Image {
            id: image2
            width: row1.height
            height: row1.height
            source: "../images/ui/money/money-silver.png"
        }

        Text {
            id: silverText
            text: "0"
            color: textColor
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            font.pixelSize: row1.height
        }

        Image {
            id: image3
            width: row1.height
            height: row1.height
            source: "../images/ui/money/money-gold.png"
        }

        Text {
            id: goldText
            text: "0"
            color: textColor
            anchors.topMargin: 0
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            font.pixelSize: row1.height
        }
    }

    onMoneyChanged: {
        updateFromMoney()
    }

    Component.onCompleted: {
        updateFromMoney()
    }

    function updateFromMoney() {
        var g = WowStat.convertToMoney(money)

        image2.visible = true
        silverText.visible = true
        image3.visible = true
        goldText.visible = true

        if (g.y === 0) { // silver
            image2.visible = false
            silverText.visible = false
            image3.visible = false
            goldText.visible = false
        }

        if (g.z === 0) { //goldText
            image3.visible = false
            goldText.visible = false
        }

        copperText.text = g.x
        silverText.text = g.y
        goldText.text = g.z
    }
}

