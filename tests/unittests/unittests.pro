QT       += testlib qml

TARGET = unittests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES +=     main.cpp    

DEFINES += SRCDIR=\\\"$$PWD/\\\"
DEFINES += QUICK_TEST_SOURCE_DIR=\\\"$$PWD/qmltests\\\"

ROOTDIR = $$PWD/../../

include($$ROOTDIR/crossdebug.pri)

HEADERS +=    

!win32 {
    QMAKE_CXXFLAGS += -Werror
}

DISTFILES += ../../.travis.yml \
    ../../appveyor.yml
