TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    algorithms.cpp \
    readinandparse.cpp

HEADERS += \
    algorithms.h \
    dsstring.h \
    dsvector.h \
    readinandparse.h
