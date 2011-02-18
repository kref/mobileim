#include <QCoreApplication>

#include "clockprovider.h"

//#include <QRemoteServiceRegister>
#include <qremoteserviceregister.h>
//#include <QServiceManager>
#include <qservicemanager.h>


int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    const QString serviceName("ClockService");
    const QString interfaceName("com.digia.qt.example.clock_service");
    const QString serviceVersion("1.0");

    QtMobility::QServiceManager manager;
    (void)manager.removeService(serviceName);
    bool addServiceOk(manager.addService("clockservice.xml"));
    Q_ASSERT(addServiceOk);

    QtMobility::QRemoteServiceRegister serviceRegister;

    //serviceName, interfaceName and serviceVersion are all
    //defined in the clockservice.xml
    QtMobility::QRemoteServiceRegister::Entry entry = serviceRegister.createEntry<ClockProvider>(serviceName, interfaceName, serviceVersion);

    serviceRegister.publishEntries("clock_service");
    serviceRegister.setQuitOnLastInstanceClosed(true);

    const int result = QCoreApplication::exec();

    return result;
}
