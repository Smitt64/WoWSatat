#include <QApplication>
#include "qmlapplicationengine.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}

