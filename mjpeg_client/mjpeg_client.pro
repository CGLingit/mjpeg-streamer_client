#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T21:12:45
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mjpeg_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camclient.cpp

HEADERS  += mainwindow.h \
    camclient.h

FORMS    += mainwindow.ui
