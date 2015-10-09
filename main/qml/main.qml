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

    WoWItemBase {
        id: base
        width: 64
        height: 64
        fillColor: "#000000"

    }

    Component.onCompleted: {
        /*console.log(wowFont.name)
        var stat = MainJs.initApplication()
        if (stat === 0) {
            MainJs.loadClassListComponent();
        }*/
        base.loadFromUrl("https://yastatic.net/islands/_/uBeuL5reE-5D8m89Ky4i6XNh8yo.svg")
        main.state = "LoadDBC"
    }
}

