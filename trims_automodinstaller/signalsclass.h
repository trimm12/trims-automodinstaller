#ifndef SIGNALSCLASS_H
#define SIGNALSCLASS_H

#include <QObject>

class SignalsClass : public QObject
{
    Q_OBJECT
public:
    explicit SignalsClass(QObject *parent = nullptr);

signals:

public slots:
    void callMe();

};

#endif // SIGNALSCLASS_H
