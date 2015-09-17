import QtQuick 2.3
import QtQuick.Window 2.2
import "main.js" as MainJs

Window {
    id: mainwindow
    visible: true

    Loader {
        id: mainloader
        anchors.fill: parent

        onStateChanged: {
            console.log(status)
        }
    }

    Component.onCompleted: {
        MainJs.loadClassListComponent();
    }
}

