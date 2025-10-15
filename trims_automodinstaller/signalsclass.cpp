#include "signalsclass.h"
#include <QDebug>
#include "downloader.h"

SignalsClass::SignalsClass(QObject *parent)
    : QObject{parent}
{

    d = new downloader(this);

    folderChosen = false;
    remoteChosen = false;

}

void SignalsClass::callMe()
{
    qDebug() << "Opening File Dialog";

}

void SignalsClass::download() {

    if (!folderChosen) {
        qDebug() <<"Folder not chosen!";
        debugChange("Folder not chosen!");
        return;
    }

    if (!remoteChosen) {
        qDebug() <<"Url not chosen!";
        debugChange("Url not chosen!");
        return;
    }

    d->doDownload();
    qDebug() << "Downloading File";

}

void SignalsClass::folderChange(QString folderUrl) {
    folderChosen = true;
    qDebug() << "Folder URL has been changed: " + folderUrl;
    debugChange("Folder URL has been changed: " + folderUrl);
    d->changeFolderUrl(folderUrl);

}

void SignalsClass::remoteChange(QString remoteUrl) {
    remoteChosen = true;
    qDebug() << "Remote URl has been changed: " + remoteUrl;
    debugChange("Remote URL has been changed: " + remoteUrl);
    d->changeRemoteUrl(remoteUrl);
}

void SignalsClass::debugChange(QString debugMsg) {
    debugText = debugMsg;
    emit debugTextChanged();
}
