import QtQuick 2.0

Item {
    id: btn
    width: 75
    height: 20
    clip: true

    property string caption: "text"
    property bool enabled: true

    signal clicked

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

    Image {
        id: image3
        opacity: 0
        anchors.fill: parent
        anchors.bottomMargin: -8
        source: "../images/ui/buttons/UI-DialogBox-Button-Disabled.png"
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

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        //hoverEnabled: true

        onPressed: {
            btn.state = "pressed"
        }

        onReleased: {
            btn.state = ""
        }

        onClicked: btn.clicked()
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
        },
        State {
            name: "disabled"

            PropertyChanges {
                target: image2
                opacity: 0
            }

            PropertyChanges {
                target: image1
                opacity: 0
            }

            PropertyChanges {
                target: image3
                opacity: 1
            }

            PropertyChanges {
                target: text1
                color: "#a99b9b"
            }
        }
    ]

    function disable() {
        btn.state = "disabled"
        mouseArea1.visible = false
    }

    function enable() {
        btn.state = ""
        mouseArea1.visible = true
    }

    Component.onCompleted: {
        if (!btn.enabled) {
            disable()
        }
    }

    onEnabledChanged: {
        if (!btn.enabled) {
            disable()
        } else {
            enable()
        }
    }
}

