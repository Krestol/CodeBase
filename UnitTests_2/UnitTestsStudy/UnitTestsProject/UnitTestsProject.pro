include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    tst_testcase.h \
    readermock.h \
    writermock.h \
    errorobservermock.h

SOURCES += \
        main.cpp

unix:!macx: LIBS += -L$$PWD/../../lib/ -lSomeStaticLibrary

INCLUDEPATH += $$PWD/../SomeStaticLibrary
DEPENDPATH += $$PWD/../SomeStaticLibrary

unix:!macx: PRE_TARGETDEPS += $$PWD/../../lib/libSomeStaticLibrary.a

DESTDIR = $$PWD/../../bin
