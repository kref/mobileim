#ifndef PLUGINIMPL_H
#define PLUGINIMPL_H

#include <QObject>
#include <QServicePluginInterface>


class PluginImpl : public QObject, public QtMobility::QServicePluginInterface
{
    Q_OBJECT
    Q_INTERFACES(QtMobility::QServicePluginInterface)

public:
    explicit PluginImpl(QObject *parent = 0);

    QObject* createInstance(
            const QtMobility::QServiceInterfaceDescriptor &descriptor,
            QtMobility::QServiceContext *context,
            QtMobility::QAbstractSecuritySession *session);
};

#endif // PLUGINIMPL_H
