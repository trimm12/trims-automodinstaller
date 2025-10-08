#include "someclass.h"
#include <QDebug>

SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{}

void SomeClass::callMe()
{
    qDebug() << "I'm being called!";
}
