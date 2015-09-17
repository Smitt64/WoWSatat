import QtQuick 2.3
import QtQml 2.2
import "delegate"
import "template"
import "ClassList.js" as ClassListJs

ListView {
    id: list
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
    }

    section.delegate: ClassListSectionDelegate {
        id: sectiondelegate
        specimage: ("qrc:/" + findClassImage(section))
        specname: section
    }
    section.criteria: ViewSection.FullString
    section.property: "classname"

    /*add: Transition {
        RotationAnimation { target: delegate; from: 180; to: 0; duration: 1000; easing.type: Easing.OutBack; property: "angle" }
    }*/

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

