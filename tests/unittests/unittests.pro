QT       += testlib qml

TARGET = unittests
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES +=     main.cpp    

DEFINES += SRCDIR=\\\"$$PWD/\\\"
DEFINES += QUICK_TEST_SOURCE_DIR=\\\"$$PWD/qmltests\\\"

ROOTDIR = $$PWD/../../

include($$ROOTDIR/xbacktrace.pri)

HEADERS +=    

linux {
    QMAKE_LFLAGS+= -rdynamic
}

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DISTFILES += ../../.travis.yml \
    ../../appveyor.yml
