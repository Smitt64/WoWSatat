function pumpData(tooltiparam, e) {
    console.log(e)
    tooltiparam.equipItem = e
    tooltiparam.itemName = e.name
    tooltiparam.nameQualityColor = e.qualityColor
    tooltiparam.nameDescription = e.nameDescription
    tooltiparam.inventoryType = e.inventorySlotName
    tooltiparam.armorType = e.itemSubClassName
    tooltiparam.itemLevel = e.itemLevel
    tooltiparam.armor = e.armor
    tooltiparam.maxDurability = e.maxDurability
    tooltiparam.requiredLevel = e.requiredLevel

    tooltiparam.isSetItem = e.isSetItem
    tooltiparam.itemSetCount = e.itemSetCount
    tooltiparam.itemSetName = e.itemSetName
    tooltiparam.sellPrice = e.sellPrice

    for (var i = 0; i < e.stats.length; i = i + 1) {
        tooltiparam.statList.append({"typeName" : e.stats[i].typeName, "amount" : e.stats[i].amount})
    }

    var str = ""
    for (i = 0; i < e.allowableClasses.length; i = i + 1) {
        if (i !== 0) {
            str = str + ", "
        }
        str = str + "<font color='" +WowStat.raidClassColors(e.allowableClasses[i]) + "'>" + WowStat.chrClassName(e.allowableClasses[i]) + "</font>"
    }
    tooltiparam.allowableClasses = str

    str = ""
    for (i = 0; i < e.allowableRaces.length; i = i + 1) {
        if (i !== 0) {
            str = str + ", "
        }
        str = str + WowStat.chrRaceName(e.allowableRaces[i])
    }
    tooltiparam.allowableRaces = str

    str = "\n"
    for (i = 0; i < e.setBonuses.length; i = i + 1) {
        str = str + qsTr("Комплект ") + parseInt(e.setBonuses[i].threshold) + qsTr(" предмета: ") + e.setBonuses[i].description + "\n"
    }
    tooltiparam.itemSetBonuses = str
}

var component = Qt.createComponent("WoWEquipToolTip.qml");
var tooltip
function create(equipItem, parentitm, properties) {
    if (tooltip === null || tooltip === undefined) {
        tooltip = component.createObject(parentitm, properties);

        if (tooltip === null) {
            console.error("error creating tooltip: " + component.errorString());
        }
        else {
            pumpData(tooltip, equipItem)
        }
    }
}

function destroy() {
    if (tooltip !== null && tooltip !== undefined) {
        tooltip.destroy()
        tooltip = null
    }
}
