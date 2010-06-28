#include <QtCore/QCoreApplication>

#include "CIMServer.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"begin my app"<<endl;
            CIMServer myServer;
    return a.exec();
}
