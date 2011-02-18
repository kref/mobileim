#include "clockprovider.h"

#include <QDateTime>


ClockProvider::ClockProvider(QObject *parent) :
    QObject(parent)
{
}

void ClockProvider::requestTime()
{
    emit hereItComes(QDateTime::currentDateTime().toString());
}
