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
    void folderChange(QString folderUrl);
    void remoteChange(QString remoteURL);

private:
    downloader* d;
    bool folderChosen;
    bool remoteChosen;

};

#endif // SIGNALSCLASS_H
