TEMPLATE = app

QT += qml quick gui widgets testlib
CONFIG += c++11 plugin static

TARGET = WoWStat
#TARGET = $$qtLibraryTarget(WoWStat)

DESTDIR = ../bin
OBJECTS_DIR = ../.build
MOC_DIR = ../.build
UI_DIR = ../.build
RCC_DIR = ../.build

SOURCES += main.cpp \
    qmlapplicationengine.cpp \
    wowstatobject.cpp \
    dbfiles/dbcfileloader.cpp \
    dbfiles/dbcstructure.cpp \
    dbfiles/spells.cpp \
    networkimageprovider.cpp \
    QmlItems/wowitembase.cpp
RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    qmlapplicationengine.h \
    wowstatobject.h \
    dbfiles/dbcfileloader.h \
    defines.h \
    dbfiles/dbcstorage.h \
    dbfiles/dbcstructure.h \
    dbfiles/dbcfmt.h \
    dbfiles/spells.h \
    networkimageprovider.h \
    QmlItems/wowitembase.h

CONFIG(debug, debug|release): {
    TARGET = $$join(TARGET,,,_d)
}
