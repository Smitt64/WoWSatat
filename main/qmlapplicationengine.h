#ifndef QMLAPPLICATIONENGINE_H
#define QMLAPPLICATIONENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>

class WowStatObject;
class QmlApplicationEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:    
    explicit QmlApplicationEngine(QObject *parent = 0);

signals:

public slots:
    void warnings(const QList<QQmlError> &warnings);

private:
    void reg();
    WowStatObject *wstobj;
};

#endif // QMLAPPLICATIONENGINE_H
