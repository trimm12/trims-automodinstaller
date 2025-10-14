#include "downloader.h"
#include <qobject.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>

downloader::downloader(QObject *parent)
    : QObject{parent}, manager(nullptr)
{
    folderUrl = "";

}

void downloader::doDownload() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &downloader::replyFinished);

    QUrl url("https://gist.githubusercontent.com/trimm12/ab8de37dc23e638fc0727c6e8b4a73ec/raw/3653f2ec0585fba11aac54f3e116cef9c9a56cad/modsurls.json");
    QNetworkRequest request(url);

    request.setRawHeader("User-Agent", "Mozilla/5.0");
    manager->get(request);

}

void downloader::replyFinished(QNetworkReply* reply) {
    // QFile* file = new QFile(folderUrl + "/veinminer.json");

    // if(file->open(QFile::WriteOnly)) {
    //     file->write(reply->readAll());
    //     file->flush();
    //     file->close();
    // }

    QByteArray data = reply->readAll();

    QFile file(folderUrl + "/veinminer.json");
    if(file.open(QFile::WriteOnly)) {
        file.write(data);
        file.close();
    }

    QJsonDocument document = QJsonDocument::fromJson(data);
    qDebug() << document;
    QJsonObject root = document.object();
    QJsonArray m_list = root.value("mods").toArray();
    int m_len = m_list.size();

    for (int i = 0; i < m_len; i++) {
        QJsonObject m_index = m_list[i].toObject();
        QJsonValue m_url = m_index.value("url");
        qDebug() << m_url;
    }

    reply->deleteLater();
}

void downloader::changeUrl(QString url) {
    folderUrl = url;
    qDebug() << "URL has been changed" + folderUrl;
}
