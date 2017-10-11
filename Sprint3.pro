TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    algorithms.cpp \
    sorter.cpp \
    readandwrite.cpp

HEADERS += \
    algorithms.h \
    dsstring.h \
    sorter.h \
    readandwrite.h
