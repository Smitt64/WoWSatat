import QtQuick 2.0

Image {
    id: item1
    width: 640
    height: 480
    source: "../images/ui/UI-DialogBox-Background.png"
    anchors.fill: parent

    Image {
        id: image1
        x: 270
        y: 185
        width: 391
        height: 135
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        source: "../images/ui/UI-DialogBox-Background-Dark.png"

        BorderImage {
            id: borderImage1
            anchors.rightMargin: -8
            anchors.leftMargin: -8
            anchors.bottomMargin: -8
            anchors.topMargin: -8
            border.bottom: 20
            border.top: 20
            border.right: 20
            border.left: 20
            anchors.fill: parent
            source: "../images/ui/DialogFrame-Corners.png"
        }

        Text {
            id: text1
            height: 72
            color: "#cfcfcf"
            text: qsTr("Text")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            font.pixelSize: 12
            font.family: "Emblem"
        }

        Row {
            id: row1
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 7
            anchors.top: text1.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            WoWButton {
                id: woWButton1
                width: 77
                height: 25
                anchors.verticalCenter: borderImage1.verticalCenter
            }
        }


    }

    Connections {
        target: woWButton1
    }
}

