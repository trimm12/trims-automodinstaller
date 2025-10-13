#include "downloader.h"
#include <qobject.h>

downloader::downloader(QObject *parent)
    : QObject{parent}, manager(nullptr)
{}

void downloader::doDownload() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &downloader::replyFinished);

    QUrl url("https://www.curseforge.com/minecraft/mc-mods/veinminer/download/2528295");
    QNetworkRequest request(url);

    request.setRawHeader("User-Agent", "Mozilla/5.0");
    manager->get(request);

}

void downloader::replyFinished(QNetworkReply* reply) {
    QFile* file = new QFile("C:/Users/trim/AppData/Roaming/.minecraft/mods/veinminer-fabric-2.5.0.jar");

    if(file->open(QFile::WriteOnly)) {
        file->write(reply->readAll());
        file->flush();
        file->close();
    }
}
