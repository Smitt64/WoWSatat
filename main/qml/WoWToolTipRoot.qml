import QtQuick 2.0
import WowStat 1.0
import "WoWEquipToolTip.js" as ToolTip

MouseArea {
    id: toolTipRoot
    width: 200
    height: 200
    hoverEnabled: true

    property WoWEquip equip
    property alias showAfterTime: showTimer.interval
    property bool showed: false

    Timer {
        id: showTimer
        running: false
        repeat: false

        onTriggered: {
            showed = true
            ToolTip.create(equip, toolTipRoot, {})
        }
    }

    onEntered: {
        showTimer.start()
    }

    onExited: {
        if (showed) {
            showed = false
            showTimer.stop()
            ToolTip.destroy()
        }
    }

    onPositionChanged: {
        if (showed) {
            var obj = toolTipRoot.mapToItem(toolTipRoot.parent, mouse.x, mouse.y);
            ToolTip.tooltip.x = obj.x
            ToolTip.tooltip.y = obj.y
            mouse.accepted = true
        }
    }
}

