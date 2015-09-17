#include "qmlapplicationengine.h"
#include <QtQml>
#include <QMessageBox>
#include "wowstatobject.h"

QmlApplicationEngine::QmlApplicationEngine(QObject *parent) : QQmlApplicationEngine(parent)
{
    wstobj = new WowStatObject(this);

    qmlRegisterUncreatableType<WowStatObject>("WowStat", 1, 0, "WowStatApp", "");
    //qmlRegisterUncreatableType<WowStatObject::InitErrors>("WowStat", 1, 0, "InitError", "");

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
