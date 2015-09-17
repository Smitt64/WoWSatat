var ClassList;

function initApplication() {
    var stat = WowStat.init()

    if(stat == WowStat.INIT_NOERROR) {

    }

    return stat;
}

function loadClassListComponent() {
    ClassList = mainloader.setSource("ClassList.qml", {"anchors.fill" : mainwindow});

    mainwindow.width  = 240
    mainwindow.height = 320
    mainwindow.show()
}
