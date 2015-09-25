import QtQuick 2.0

Item {
    width: 75
    height: 20
    clip: true

    property string caption: "text"

    Image {
        id: image1
        anchors.bottomMargin: -8
        anchors.fill: parent
        source: "../images/ui/buttons/UI-DialogBox-Button-Up.png"
    }

    Image {
        id: image2
        x: -4
        y: 4
        opacity: 0
        anchors.bottomMargin: -8
        source: "../images/ui/buttons/UI-DialogBox-Button-Down.png"
        anchors.fill: parent
    }

    Text {
        id: text1
        x: 26
        y: 7
        color: "#fdfdfd"
        text: caption
        anchors.verticalCenterOffset: -1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
        font.family: "Emblem"
    }

    states: [
        State {
            name: "pressed"

            PropertyChanges {
                target: image2
                anchors.bottomMargin: -8
                opacity: 1
            }

            PropertyChanges {
                target: image1
                opacity: 0
            }

            PropertyChanges {
                target: text1
                anchors.horizontalCenterOffset: 1
                anchors.verticalCenterOffset: 1
            }
        }
    ]
}

