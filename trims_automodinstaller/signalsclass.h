#ifndef SIGNALSCLASS_H
#define SIGNALSCLASS_H

#include "downloader.h"
#include <QObject>

class SignalsClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString debugText READ getDebugText NOTIFY debugTextChanged)

public:
    explicit SignalsClass(QObject *parent = nullptr);
    QString getDebugText() const {return debugText;}

signals:
    void debugTextChanged();

public slots:
    void callMe();
    void download();
    void folderChange(QString folderUrl);
    void remoteChange(QString remoteURL);
    void debugChange(QString debugMsg);

private:
    downloader* d;
    bool folderChosen;
    bool remoteChosen;
    QString debugText;

};

#endif // SIGNALSCLASS_H
