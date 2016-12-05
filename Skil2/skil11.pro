QT += core
QT -= gui

CONFIG += c++11

TARGET = skil11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    person.cpp \
    personservice.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    personservice.h \
    person.h
