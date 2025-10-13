#ifndef SIGNALSCLASS_H
#define SIGNALSCLASS_H

#include "downloader.h"
#include <QObject>

class SignalsClass : public QObject
{
    Q_OBJECT
public:
    explicit SignalsClass(QObject *parent = nullptr);

signals:

public slots:
    void callMe();
    void download();
    void variableChange();

private:
    downloader* d;
    bool folderChosen;

};

#endif // SIGNALSCLASS_H
