import QtQuick 2.0

Rectangle {
    id: itemDelegate
    property string specimage: ""
    property string specname: ""

    Component.onCompleted: showAnim.start();
    transform:
        Rotation { id:rt; origin.x: width; origin.y: height; axis { x: 0.3; y: 1; z: 0 } angle: 0}//     <--- I like this one more!
    width: parent.width
    height: 50
    color: index % 2 === 0 ? "#EEE" : "#DDD"
    SequentialAnimation {
        id: showAnim
        running: false
        RotationAnimation { target: rt; from: 180; to: 0; duration: 1000; easing.type: Easing.OutBack; property: "angle" }
    }

    Image {
        id: image
        width: image.height
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 2
        anchors.top: parent.top
        anchors.topMargin: 2
        anchors.left: parent.left
        anchors.leftMargin: 2
        source: specimage
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            itemDelegate.state = "hihglight"
        }

        onExited: itemDelegate.state = ""
    }

    Text {
        id: text1
        text: specname
        style: Text.Normal
        textFormat: Text.PlainText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors.top: parent.top
        anchors.topMargin: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 2
        anchors.right: parent.right
        anchors.rightMargin: 2
        anchors.left: image.right
        anchors.leftMargin: 2
        font.pixelSize: 17
    }
    states: [
        State {
            name: "hihglight"

            PropertyChanges {
                target: itemDelegate
                color: "#313545"
            }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "hihglight"
            ColorAnimation { target: itemDelegate; duration: 200; }
        },
        Transition {
            from: "hihglight"
            to: ""
            ColorAnimation { target: itemDelegate; duration: 200; }
        }
    ]

}
