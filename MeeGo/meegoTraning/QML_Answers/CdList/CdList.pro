#-------------------------------------------------
#
# Project created by QtCreator 2010-10-04T22:33:54
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = CdList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe78df6b8
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES += \
    cdlist.qrc
