import QtQuick 2.0

Image {
    id: button
    width: 32
    height: 32

    signal triggered
    states: [
        State {
            name: "pressed"

            PropertyChanges {
                target: button
                source: "../images/ui/buttons/UI-Panel-MinimizeButton-Down.png"
            }
        },
        State {
            name: "disbled"
            PropertyChanges {
                target: button
                source: "../images/ui/buttons/UI-Panel-MinimizeButton-Disabled.png"
            }
        }
    ]
    source: "../images/ui/buttons/UI-Panel-MinimizeButton-Up.png"

    MouseArea {
        id: mouseArea1
        anchors.fill: parent

        onPressed: {
            button.state = "pressed"
        }

        onReleased: {
            button.state = ""
        }

        onClicked: {
            button.triggered()
        }
    }

}

