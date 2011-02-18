CONFIG += mobility
MOBILITY = serviceframework

xml.path = .
xml.files = clockservice.xml
INSTALLS += xml

HEADERS += \
    clockprovider.h

SOURCES += \
    clockprovider.cpp \
    main.cpp
