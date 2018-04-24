QT += core testlib
QT -= gui

CONFIG += c++11 console

GTEST_SRCDIR = /usr/src/gtest
GMOCK_SRCDIR = /usr/src/gmock

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))

INCLUDEPATH *= \
$$GTEST_SRCDIR \
$$GTEST_SRCDIR/include \
$$GMOCK_SRCDIR \
$$GMOCK_SRCDIR/include

DEFINES += QT_DEPRECATED_WARNINGS

TARGET = Try_Gtest

TEMPLATE = app

SOURCES += \
main.cpp \
tests.cpp \
somemathfunc.cpp \
$$GTEST_SRCDIR/src/gtest-all.cc \
$$GMOCK_SRCDIR/src/gmock-all.cc

HEADERS += \
    somemathfunc.h

