TARGET = serviceframework_clock_plugin
TEMPLATE = lib
CONFIG += plugin mobility
PLUGIN_TYPE=serviceframework
MOBILITY = serviceframework

HEADERS += \
    pluginimpl.h clockprovider.h

SOURCES += \
    pluginimpl.cpp clockprovider.cpp

