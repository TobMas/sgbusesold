#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T12:34:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BusCSOpti
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    csvreaderdialog.cpp \
    csvreader.cpp \
    bus.cpp \
    busmodel.cpp \
    busservice.cpp \
    busstop.cpp

HEADERS  += mainwindow.h \
    csvreaderdialog.h \
    csvreader.h \
    bus.h \
    busmodel.h \
    busservice.h \
    busstop.h

FORMS    += mainwindow.ui \
    csvreaderdialog.ui
