#-------------------------------------------------
#
# Project created by QtCreator 2018-06-27T09:24:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = croppingTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    picturedisplay.cpp \
    json.cpp \
    newmodel.cpp

HEADERS  += mainwindow.h \
    picturedisplay.h \
    json.h \
    newmodel.h

FORMS    += mainwindow.ui \
    newmodel.ui
