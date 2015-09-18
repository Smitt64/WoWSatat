import QtQuick 2.3
import QtQml 2.2
import "delegate"
import "template"
import "ClassList.js" as ClassListJs

FixedSizeWindow {
    id:classwindow

    CloseButton {
        id: closebutton
        anchors.rightMargin: -4
        anchors.topMargin: 8
        anchors.top: parent.top
        anchors.right: parent.right
    }

    ListView {
        id: list
        clip: true
        anchors.bottomMargin: 16
        anchors.rightMargin: 15
        anchors.leftMargin: 24
        anchors.topMargin: 78
        anchors.fill: parent
        cacheBuffer: 10

        ClassModelTemplate {
            id: model
        }

        model: ListModel {
            id: listmodel
        }

        delegate: ClassListItemDelegate {
            id: delegate
            specimage: ("qrc:/" + specicon)
            specname: spec

            width: list.width
        }

        section.delegate: ClassListSectionDelegate {
            id: sectiondelegate
            specimage: ("qrc:/" + list.findClassImage(section))
            specname: section
            width: list.width
            clip: true
        }
        section.criteria: ViewSection.FullString
        section.property: "classname"

        Component.onCompleted: {
            ClassListJs.addToModel()
            addtimer.start()
        }

        Timer {
            id: addtimer
            repeat: true
            interval: 50

            onTriggered: ClassListJs.addToModel()
        }

        function findClassImage(str) {
            for (var i = 0; i < list.model.count; i++) {
                if (list.model.get(i).classname === str) {
                    return list.model.get(i).nameicon;
                }
            }

            return "";
        }
    }

    Text {
        id: text1
        height: 14
        color: "#f4f4f4"
        text: qsTr("Select specialization")
        anchors.leftMargin: 80
        anchors.left: parent.left
        anchors.right: closebutton.left
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.topMargin: 17
        font.pixelSize: 12
    }
}
