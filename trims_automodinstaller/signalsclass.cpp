#include "signalsclass.h"
#include <QDebug>
#include "downloader.h"

SignalsClass::SignalsClass(QObject *parent)
    : QObject{parent}
{

    d = new downloader(this);

    folderChosen = false;

}

void SignalsClass::callMe()
{
    qDebug() << "Opening File Dialog";

}

void SignalsClass::download() {

    if (!folderChosen) {
        qDebug() <<"Folder not chosen!";
        return;
    }
    d->doDownload();
    qDebug() << "Downloading File";

}

void SignalsClass::variableChange(QString url) {
    folderChosen = true;
    qDebug() << "variable has been changed" + url;
    d->changeUrl(url);

}
