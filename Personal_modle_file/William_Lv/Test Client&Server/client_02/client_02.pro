#-------------------------------------------------
#
# Project created by QtCreator 2010-06-11T15:03:03
#
#-------------------------------------------------

QT       += core gui \
            network \
            sql \
            xml \
            xmlpatterns \
            multimedia
TARGET = client_02
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpServer.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    tcpServer.h \
    dialog.h \
    ui_dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe6cb1139
    TARGET.CAPABILITY += NetworkServices \
    NetworkControl
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    client_02_0xe6cb1139.mmp
