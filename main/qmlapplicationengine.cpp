#include "qmlapplicationengine.h"
#include <QtQml>
#include <QMessageBox>
#include "wowstatobject.h"
#include "QmlItems/wowequip.h"
#include "QmlItems/wowequipstat.h"
#include "QmlItems/wowitembase.h"

QmlApplicationEngine::QmlApplicationEngine(QObject *parent) : QQmlApplicationEngine(parent)
{
    wstobj = new WowStatObject(this);
    reg();
    rootContext()->setContextProperty("WowStat", wstobj);

    connect(this, SIGNAL(warnings(QList<QQmlError>)), SLOT(warnings(QList<QQmlError>)));
}

void QmlApplicationEngine::warnings(const QList<QQmlError> &warnings)
{
    QString str;
    foreach (const QQmlError &err, warnings) {
        str += err.toString() + "\n";
    }
    QMessageBox::warning(NULL, "Error", str);
}

void QmlApplicationEngine::reg()
{
    qmlRegisterUncreatableType<WowStatObject>("WowStat", 1, 0, "WowStatApp", "");
    qmlRegisterType<WoWItemBase>("WowStat", 1, 0, "WoWItemBase");
    qmlRegisterType<WoWEquip>("WowStat", 1, 0, "WoWEquip");
    qmlRegisterType<WoWEquipStat>("WowStat", 1, 0, "WoWEquipStat");
}
