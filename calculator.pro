#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T15:37:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    help.cpp

HEADERS  += calculator.h \
    stack.h \
    help.h

FORMS    += calculator.ui \
    help.ui

RESOURCES +=
