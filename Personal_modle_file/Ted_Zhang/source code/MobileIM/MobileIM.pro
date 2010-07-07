TEMPLATE = app
TARGET = MobileIM
QT += core \
    gui
HEADERS += chat.h \
    MobileIM.loc \
    MobileIM.h
SOURCES += chat.cpp \
    MobileIM.rss \
    MobileIM_reg.rss \
    main.cpp \
    MobileIM.cpp
FORMS += Chat.ui \
    MobileIM.ui
RESOURCES += chat.qrc \
    tubiao.qrc

