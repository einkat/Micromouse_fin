TEMPLATE = app
QT += core
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += \
        appengine.cpp \
        controller.cpp \
        czujnik.cpp \
        drive.cpp \
        gmap.cpp \
        grobot.cpp \
        labirynt.cpp \
        main.cpp \
        mwalls.cpp \
        object.cpp \
        robot.cpp \
        robotcore.cpp \
        wall.cpp

HEADERS += \
    appengine.h \
    controller.h \
    czujnik.h \
    drive.h \
    gmap.h \
    grobot.h \
    labirynt.h \
    mwalls.h \
    object.h \
    robot.h \
    robotcore.h \
    wall.h

DISTFILES +=

RESOURCES += \
    resource.qrc
