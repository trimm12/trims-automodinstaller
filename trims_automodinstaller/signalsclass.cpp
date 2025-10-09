#include "signalsclass.h"
#include <QDebug>

SignalsClass::SignalsClass(QObject *parent)
    : QObject{parent}
{}

void SignalsClass::callMe()
{
    qDebug() << "I'm being called!";
}
