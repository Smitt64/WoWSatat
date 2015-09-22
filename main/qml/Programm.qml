import QtQuick 2.0
import WowStat 1.0

Item {
    id: main
    width: 640
    height: 480

    Loader {
        id: mainloader
        active: true
        asynchronous: true
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        onLoaded: {
            if (main.state == "LoadDBC") {
                WowStat.finishLoadDbc.connect(dbcLoadFinish);
                WowStat.loadDBCStores(mainloader.item, "")
            }

            if (main.state == "ClassSelect") {
                /*ClassList = mainloader.item*/
                /*ClassList*/mainloader.item.close.connect(closeApp);
            }
        }
    }

    states: [
        State {
            name: "LoadDBC"

            PropertyChanges {
                target: mainloader
                source: "StartLoading.qml"
            }
        },
        State {
            name: "ClassSelect"
            PropertyChanges {
                target: mainloader
                source: "ClassList.qml"
            }
        }
    ]

    function dbcLoadFinish() {
        main.state = "ClassSelect"
    }

    function closeApp() {
        Qt.quit()
    }

}

