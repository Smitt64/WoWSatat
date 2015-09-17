var ClassList;
function loadClassListComponent()
{
    ClassList = mainloader.setSource("ClassList.qml", {"anchors.fill" : mainwindow});

    mainwindow.width  = 240
    mainwindow.height = 320
    mainwindow.showNormal()
}
