#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T08:07:52
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB2Viewer
TEMPLATE = app

DESTDIR = ../bin
OBJECTS_DIR = ../.build_db2
MOC_DIR = ../.build_db2
UI_DIR = ../.build_db2
RCC_DIR = ../.build_db2

SOURCES += main.cpp\
        mainwindow.cpp \
    db2window.cpp \
    db2tablemodel.cpp \
    stringlistdlg.cpp \
    seldefenitiondlg.cpp \
    comboboxdelegate.cpp \
    db2filtersortmodel.cpp

HEADERS  += mainwindow.h \
    db2window.h \
    db2tablemodel.h \
    stringlistdlg.h \
    seldefenitiondlg.h \
    comboboxdelegate.h \
    db2filtersortmodel.h

FORMS    += mainwindow.ui \
    db2window.ui \
    stringlistdlg.ui \
    seldefenitiondlg.ui
