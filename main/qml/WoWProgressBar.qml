import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: progressbar
    width: 200
    height: 35
    clip: true

    property color indicatorColor: "darkred"
    property real min: 0
    property real max: 100
    property real value: 100

    Image {
        id: indicator
        width: (progressbar.width - anchors.leftMargin * 2) * (value / max)
        anchors.leftMargin: 8
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        source: "../images/ui/BarFill.png"
    }

    BorderImage {
        id: borderImage1
        x: -22
        y: -19
        z: 1
        anchors.rightMargin: -24
        anchors.leftMargin: -24
        anchors.bottomMargin: -20
        anchors.topMargin: -20
        border.bottom: 5
        border.top: 5
        border.right: 5
        border.left: 5
        anchors.fill: parent
        source: "../images/ui/UI-CastingBar-Border.png"
    }

    ColorOverlay {
        color: "#8b0000"
        anchors.fill: indicator
    }

    function step() {
        if(value < max) {
           value = value + 1
        }
    }
}

