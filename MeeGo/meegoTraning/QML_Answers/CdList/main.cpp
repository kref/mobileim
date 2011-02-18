#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtDeclarative/QDeclarativeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDeclarativeView v(QUrl("qrc:/CD.qml"));
    v.show();
    return a.exec();
}
