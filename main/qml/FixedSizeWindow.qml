import QtQuick 2.0

Item {
    id: item1
    width: 350
    height: 440
    clip: true

    property string iconname: ""
    signal close()

    CloseButton {
        id: closebutton
        z: 1
        anchors.rightMargin: -4
        anchors.topMargin: 8
        anchors.top: parent.top
        anchors.right: parent.right

        onTriggered: {
            console.log("onClicked")
            item1.close()
        }
    }

    Image {
        id: icon
        x: 0
        y: 0
        width: 71
        height: 70
        source: iconname
    }

    Image {
        id: image1
        width: 256
        height: 256
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        fillMode: Image.Tile
        clip: true
        source: "../images/ui/window/UI-TaxiFrame-TopLeft.png"
    }

    Image {
        id: image2
        height: 256
        anchors.left: image1.right
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: -34
        source: "../images/ui/window/UI-TaxiFrame-TopRight.png"
    }

    Image {
        id: image3
        width: 256
        anchors.top: image1.bottom
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -71
        anchors.left: parent.left
        anchors.leftMargin: 0
        source: "../images/ui/window/UI-TaxiFrame-BotLeft.png"
    }

    Image {
        id: image4
        anchors.left: image3.right
        anchors.top: image2.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -71
        anchors.right: parent.right
        anchors.rightMargin: -34
        source: "../images/ui/window/UI-TaxiFrame-BotRight.png"
    }
}

