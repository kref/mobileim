TEMPLATE = app
TARGET = BroadcastSeachServer 

QT        += core \
    gui \
    network 

HEADERS   += BroadcastSeachServer.h
SOURCES   += BroadcastSeachServer_reg.rss \
    main.cpp \
    BroadcastSeachServer.cpp
FORMS	  += BroadcastSeachServer.ui
RESOURCES +=

symbian:TARGET.UID3 = 0xEC226B9E
