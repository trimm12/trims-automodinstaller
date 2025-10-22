#ifndef SIGNALSCLASS_H
#define SIGNALSCLASS_H

#include "downloader.h"
#include <QObject>

class SignalsClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString debugText READ getDebugText NOTIFY debugTextChanged)
    Q_PROPERTY(QString modListText READ getModListText NOTIFY modListTextChanged)

public:
    explicit SignalsClass(QObject *parent = nullptr);
    QString getDebugText() const {return debugText;}
    QString getModListText() const {return modListText;}

signals:
    void debugTextChanged();
    void modListTextChanged();

public slots:
    void callMe();
    void download();
    void folderChange(QString folderUrl);
    void remoteChange(QString remoteURL);
    void debugChange(QString debugMsg);
    void modListChange(QString modMsg);

private:
    downloader* d;
    bool folderChosen;
    bool remoteChosen;
    QString debugText;
    QString modListText;

};

#endif // SIGNALSCLASS_H
