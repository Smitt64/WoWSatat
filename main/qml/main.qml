import QtQuick 2.3
import QtQuick.Window 2.2
import WowStat 1.0
import "main.js" as MainJs
import "Global.js" as Globals

Window {
    id: mainwindow
    visible: true
    width: 800
    height: 600

    FontLoader {
        id: wowFont
        source: "../fonts/defaultwowfont.ttf"
    }

    Image {
        fillMode: Image.Tile
        source: "../images/ui/UI-AuctionPost-Background.png"
        anchors.fill: parent
    }

    /*Loader {
        id: mainloader
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onStateChanged: {
            console.log(status)
        }
    }*/
    Programm {
        id: main
        anchors.fill: parent
    }

    WoWEquip {
        id: base
        width: 64
        height: 64
        itemId: 125194

        WoWToolTipRoot {
            anchors.fill: parent
            equip: base
            showAfterTime: 1000
        }
    }

    Component.onCompleted: {
        /*console.log(wowFont.name)
        var stat = MainJs.initApplication()
        if (stat === 0) {
            MainJs.loadClassListComponent();
        }*/
        main.state = "LoadDBC"
    }
}
