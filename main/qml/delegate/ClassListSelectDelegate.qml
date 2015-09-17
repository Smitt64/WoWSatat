import QtQuick 2.0

Item {
    id: item1
    width: 200
    height: 50

    BorderImage {
        id: borderImage1
        width: 20
        anchors.leftMargin: -2
        anchors.bottomMargin: -4
        border.left: -120
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.topMargin: -4
        anchors.left: parent.left
        source: "../../images/ui/UI-AuctionPost-Endcaps.png"
    }

    BorderImage {
        id: borderImage2
        x: 8
        y: 8
        width: 20
        anchors.bottomMargin: -4
        anchors.rightMargin: 1
        anchors.right: parent.right
        anchors.topMargin: -4
        anchors.top: parent.top
        border.left: 120
        anchors.bottom: parent.bottom
        source: "../../images/ui/UI-AuctionPost-Endcaps.png"
    }

    BorderImage {
        id: borderImage3
        anchors.bottomMargin: -4
        anchors.topMargin: -4
        border.bottom: 0
        border.top: 0
        border.left: 0
        anchors.left: borderImage1.right
        anchors.right: borderImage2.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        source: "../../images/ui/UI-AuctionPost-Middle.png"
    }

}

