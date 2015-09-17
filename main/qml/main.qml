import QtQuick 2.3
import QtQuick.Window 2.2
import WowStat 1.0
import "main.js" as MainJs

Window {
    id: mainwindow
    visible: true
    width: 800
    height: 600

    Image {
        fillMode: Image.Tile
        source: "../images/ui/UI-AuctionPost-Background.png"
        anchors.fill: parent

    }

    Loader {
        id: mainloader
        anchors.fill: parent

        onStateChanged: {
            console.log(status)
        }
    }

    Component.onCompleted: {
        var stat = MainJs.initApplication()
        if (stat === 0) {
            MainJs.loadClassListComponent();
        }
    }
}

