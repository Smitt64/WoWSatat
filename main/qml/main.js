var ClassList;

function initApplication() {
    var stat = WowStat.init()

    if(stat == WowStat.INIT_NOERROR) {

    }

    return stat;
}

function loadClassListComponent() {
    mainloader.setSource("ClassList.qml", {"anchors.fill" : mainwindow});
    ClassList = mainloader.item
    ClassList.close.connect(closeApp);
    /*mainwindow.width  = 240
    mainwindow.height = 320*/
    mainwindow.show()
}

function closeApp() {
    console.log("dffgh")
    Qt.quit()
}
