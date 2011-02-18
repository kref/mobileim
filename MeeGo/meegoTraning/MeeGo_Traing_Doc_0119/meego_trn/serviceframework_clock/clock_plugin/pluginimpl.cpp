#include "pluginimpl.h"

#include "clockprovider.h"


PluginImpl::PluginImpl(QObject *parent) :
    QObject(parent)
{
}

QObject* PluginImpl::createInstance(
        const QtMobility::QServiceInterfaceDescriptor &,
        QtMobility::QServiceContext *,
        QtMobility::QAbstractSecuritySession *)
{
    return new ClockProvider(this);
}

Q_EXPORT_PLUGIN2(serviceframework_clock_plugin, PluginImpl)
