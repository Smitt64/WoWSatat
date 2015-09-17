import QtQuick 2.0

Image {
    id: itemDelegate
    property string specimage: ""
    property string specname: ""

    Component.onCompleted: showAnim.start();
    transform:
        Rotation { id:rt; origin.x: width; origin.y: height; axis { x: 0.3; y: 1; z: 0 } angle: 0}//     <--- I like this one more!
    width: parent.width
    height: 50
    fillMode: Image.TileHorizontally
    source: "../../images/ui/UI-AuctionPost-Background.png"

    SequentialAnimation {
        id: showAnim
        running: false
        RotationAnimation { target: rt; from: 180; to: 0; duration: 1000; easing.type: Easing.OutBack; property: "angle" }
    }

    Image {
        id: image
        width: image.height
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.left: parent.left
        anchors.leftMargin: 4
        source: specimage
    }

    Text {
        id: text1
        color: "#7d7d90"
        text: specname
        style: Text.Normal
        textFormat: Text.PlainText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors.top: parent.top
        anchors.topMargin: 4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        anchors.right: parent.right
        anchors.rightMargin: 2
        anchors.left: image.right
        anchors.leftMargin: 4
        font.pixelSize: 17
    }

    ClassListSelectDelegate {
        id: selection
        anchors.fill: parent
        opacity: 0.0
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

    states: [
        State {
            name: "hihglight"

            PropertyChanges {
                target: selection
                opacity: 1.0
            }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "hihglight"
            PropertyAnimation {
                properties: "opacity";
            }

            //ColorAnimation { target: itemDelegate; duration: 200; }
        },
        Transition {
            from: "hihglight"
            to: ""
            PropertyAnimation {
                properties: "opacity";
            }
        }
    ]

}
