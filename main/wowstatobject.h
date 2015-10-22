#ifndef WOWSTATOBJECT_H
#define WOWSTATOBJECT_H

#include <QtQml>
#include <QObject>
#include <QRunnable>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector3D>
#include <QElapsedTimer>

template <class Function>
quint64 time_call(Function&& f)
{
   QElapsedTimer timer;
   timer.start();
   f();
   return timer.elapsed();
}

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
    Q_ENUMS(InitErrors)
    Q_ENUMS(CharacterClasses)
public:
    enum InitErrors
    {
        INIT_NOERROR = 0,
        INIT_DBC_NOTFOUND
    };

    enum CharacterClasses
    {
        Warrior = 1,
        Paladin,
        Hunter,
        Rogue,
        Priest,
        DeathKnight,
        Shaman,
        Mage,
        Warlock,
        Druid,
        Monk
    };

    explicit WowStatObject(QObject *parent = 0);

    void getCachedIcon(const QString &key, QByteArray *data);
    void checkCacheTable(const QString &table);
    QSqlQuery makeCacheQuery();

signals:
    void finishLoadDbc();

public slots:
    Q_INVOKABLE int init();
    Q_INVOKABLE int dbcCount();
    Q_INVOKABLE void loadDBCStores(QObject *bar, const QString path);

    Q_INVOKABLE QString chrClassName(const quint8 &chrclass);
    Q_INVOKABLE QString raidClassColors(const quint8 &chrclass) const;
    Q_INVOKABLE QString chrRaceName(const quint8 &race) const;

    Q_INVOKABLE QVector3D convertToMoney(const quint32 &copper);

private:
    QSqlDatabase db;
};

QML_DECLARE_TYPE(WowStatObject)

#endif // WOWSTATOBJECT_H
