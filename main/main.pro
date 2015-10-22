TEMPLATE = app

QT += qml quick gui widgets testlib network sql
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
    QmlItems/wowitembase.cpp \
    QmlItems/wowequip.cpp \
    QmlItems/wowequipstat.cpp \
    QmlItems/wowitemsetbonus.cpp \
    dbfiles/db2fileloader.cpp \
    dbfiles/itemsdbc.cpp \
    dbfiles/wdbloader.cpp \
    dbfiles/wdbkeyindex.cpp
RESOURCES += qml.qrc \
    images.qrc \
    sql.qrc

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
    QmlItems/wowitembase.h \
    QmlItems/wowequip.h \
    QmlItems/wowequipstat.h \
    QmlItems/wowitemsetbonus.h \
    dbfiles/itemsdbc.h \
    dbfiles/common.h \
    dbfiles/db2fileloader.h \
    dbfiles/db2store.h \
    dbfiles/wdbloader.h \
    dbfiles/wdbstore.h \
    dbfiles/wdbkeyindex.h

CONFIG(debug, debug|release): {
    TARGET = $$join(TARGET,,,_d)
}

win32-msvc* {
    QMAKE_CXXFLAGS += -openmp
    QMAKE_LFLAGS   += -openmp

    LIBS += -openmp
}
win32-g++ {
    QMAKE_CXXFLAGS += -fopenmp
    QMAKE_LFLAGS   += -fopenmp

    LIBS += -lgomp -lpthread
}
