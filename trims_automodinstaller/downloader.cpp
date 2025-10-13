#include "downloader.h"
#include <qobject.h>

downloader::downloader(QObject *parent)
    : QObject{parent}, manager(nullptr)
{
    folderUrl = "";

}

void downloader::doDownload() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &downloader::replyFinished);

    QUrl url("https://cdn.modrinth.com/data/OhduvhIc/versions/lCVEKyxE/veinminer-fabric-2.5.0.jar");
    QNetworkRequest request(url);

    request.setRawHeader("User-Agent", "Mozilla/5.0");
    manager->get(request);

}

void downloader::replyFinished(QNetworkReply* reply) {
    QFile* file = new QFile(folderUrl + "/veinminer.jar");

    if(file->open(QFile::WriteOnly)) {
        file->write(reply->readAll());
        file->flush();
        file->close();
    }
}

void downloader::changeUrl(QString url) {
    folderUrl = url;
    qDebug() << "URL has been changed" + folderUrl;
}
