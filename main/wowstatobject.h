#ifndef WOWSTATOBJECT_H
#define WOWSTATOBJECT_H

#include <QtQml>
#include <QObject>
#include <QRunnable>

class WoWDbcLoaderRunable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    WoWDbcLoaderRunable(const QString path, QObject *bar);

    void run();

signals:
    void finished();

private:
    QObject *_bar;
    QString _path;
};

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
    void finishLoadDbc();

public slots:
    Q_INVOKABLE int init();
    Q_INVOKABLE int dbcCount();
    Q_INVOKABLE void loadDBCStores(QObject *bar, const QString path);
};

QML_DECLARE_TYPE(WowStatObject)

#endif // WOWSTATOBJECT_H
