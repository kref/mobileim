#include <QApplication>
#include <QLabel>
#include <QPushButton>

//#include <QRemoteServiceRegister>
#include <qremoteserviceregister.h>
#include <qservicemanager.h>
//#include <QServiceManager>

#include <QDebug>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel label;
    QPushButton* button = new QPushButton("request", &label);
    label.show();

    const QString interfaceName("com.digia.qt.example.clock_service");

    QtMobility::QServiceManager manager;
    QObject* service = manager.loadInterface(interfaceName);
    Q_ASSERT(service);

    QObject::connect(button, SIGNAL(clicked()), service, SLOT(requestTime()));
    QObject::connect(service, SIGNAL(hereItComes(QString)), &label, SLOT(setText(QString)));

    const int result = QApplication::exec();

    return result;
}

