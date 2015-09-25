import QtQuick 2.5
import WowStat 1.0

Item {
    id: item1
    width: 300
    height: 300
    clip: true

    property int maxdbc: 0

    Image {
        id: image1
        fillMode: Image.Tile
        source: "../images/ui/loadpanel/MacroPopup-TopLeft.png"
        width: sourceSize.width
        height: sourceSize.height
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
    }

    Image {
        id: image2
        fillMode: Image.Tile
        source: "../images/ui/loadpanel/MacroPopup-TopRight.png"
        width: sourceSize.width
        height: sourceSize.height
        anchors.left: image1.right
    }

    Image {
        id: image3
        width: sourceSize.width
        height: sourceSize.height
        anchors.top: image1.bottom
        source: "../images/ui/loadpanel/MacroPopup-BotLeft.png"
    }

    Image {
        id: image4
        x: 0
        y: 256
        source: "../images/ui/loadpanel/MacroPopup-BotRight.png"

        width: sourceSize.width
        height: sourceSize.height
        anchors.left: image3.right
        anchors.leftMargin: 0
    }

    WoWProgressBar {
        id: woWProgressBar1
        value: 0
        max: maxdbc
        indicatorColor: "#8b0000"
        anchors.rightMargin: 19
        anchors.bottomMargin: 245
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 31
    }

    TextEdit {
        id: textEdit1
        color: "#eae7e7"
        text: ""
        anchors.bottomMargin: 44
        anchors.rightMargin: 19
        anchors.leftMargin: 14
        anchors.topMargin: 70
        anchors.fill: parent
        readOnly: true
        font.pixelSize: 12

        font.family: "Emblem"
    }

    Component.onCompleted: {
        woWProgressBar1.max = WowStat.dbcCount()
    }

    function appendToLog(str) {
        textEdit1.append(str)
    }

    function step() {
        woWProgressBar1.step()
    }
}

