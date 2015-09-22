var ClassList;

function initApplication() {
    var stat = WowStat.init()

    return stat;
}

/*function loadClassListComponent() {
    mainloader.setSource("StartLoading.qml", {"anchors.fill" : mainwindow, "maxdbc" : WowStat.dbcCount()});

    WowStat.finishLoadDbc.connect(dbcLoadFinish);
    WowStat.loadDBCStores(mainloader.item, "")
    mainwindow.show()
}

function dbcLoadFinish() {
    mainloader.item.destroy()
    mainloader.setSource("ClassList.qml", {"anchors.fill" : mainwindow});
    ClassList = mainloader.item
    ClassList.close.connect(closeApp);
}*/

function closeApp() {
    Qt.quit()
}
