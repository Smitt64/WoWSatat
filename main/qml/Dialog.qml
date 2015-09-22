import QtQuick 2.0

Item {
    width: 300
    height: 100
    clip: true

    Image {
        id: image1
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.fill: parent
        source: "images/ui/UI-DialogBox-Background.png"
    }

    BorderImage {
        id: borderImage1
        border.bottom: 20
        border.top: 20
        border.right: 20
        border.left: 20
        anchors.fill: parent
        source: "images/ui/DialogFrame-Corners.png"


    }

    Text {
        id: text1
        x: 23
        y: 20
        text: qsTr("Text")
        font.pixelSize: 12
    }
}

