import QtQuick 2.0

Image {
    id: itemDelegate
    property string specimage: ""
    property string specname: ""

    Component.onCompleted: showAnim.start();
    transform:
        Rotation { id:rt; origin.x: width; origin.y: height; axis { x: 0.3; y: 1; z: 0 } angle: 0}//     <--- I like this one more!
    fillMode: Image.TileHorizontally
    source: "../../images/ui/WorldStateFinalScoreFrame-TopBackground.png"

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

    Text {
        id: text1
        color: "#cec8c8"
        text: "Text"
        styleColor: "#79786f"
        style: Text.Raised
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
}
