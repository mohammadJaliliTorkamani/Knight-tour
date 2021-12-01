TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    horse.cpp \
    handler.cpp \
    board.cpp \
    element.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    horse.h \
    handler.h \
    board.h \
    element.h

