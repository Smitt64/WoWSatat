#ifndef WOWSTATOBJECT_H
#define WOWSTATOBJECT_H

#include <QtQml>
#include <QObject>

class WowStatObject : public QObject
{
    Q_OBJECT

public:
    enum InitErrors
    {
        INIT_NOERROR = 0,
        INIT_DBC_NOTFOUND
    };
    Q_ENUMS(InitErrors)
    explicit WowStatObject(QObject *parent = 0);

signals:

public slots:
    Q_INVOKABLE int init();
};

QML_DECLARE_TYPE(WowStatObject)

#endif // WOWSTATOBJECT_H
