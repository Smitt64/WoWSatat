TEMPLATE = app

QT += qml quick gui widgets
CONFIG += c++11

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
    dbfiles/spells.cpp
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
    dbfiles/spells.h

