import QtQuick 2.0

Item {
    id: item1
    width: 400
    height: 50

    BorderImage {
        id: borderImage1
        verticalTileMode: BorderImage.Stretch
        anchors.leftMargin: -7
        anchors.topMargin: -2
        anchors.bottomMargin: -8
        horizontalTileMode: BorderImage.Stretch
        anchors.fill: parent
        border.bottom: 10
        border.top: 10
        border.right: 10
        border.left: 100
        source: "../../images/ui/ClassListSel.png"
    }

}

