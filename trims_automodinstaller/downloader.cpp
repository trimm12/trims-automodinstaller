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
    remoteUrl = "";

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &downloader::replyFinished);

}

void downloader::doDownload() {

    QUrl url(remoteUrl);
    QNetworkRequest request(url);

    request.setRawHeader("User-Agent", "Mozilla/5.0");
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::NoLessSafeRedirectPolicy);
    manager->get(request);

}

void downloader::replyFinished(QNetworkReply* reply) {


    QByteArray data = reply->readAll();

    QString filename = reply->property("saveName").toString();
    if (filename.isEmpty()) {
        filename = "mods.json";
        QFile file(folderUrl + "/" + filename);
        if(file.open(QFile::WriteOnly)) {
            file.write(data);
            file.close();
        }

    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject root = document.object();
    QJsonArray m_list = root.value("mods").toArray();
    int m_len = m_list.size();

    for (int i = 0; i < m_len; i++) {
        QJsonObject m_index = m_list[i].toObject();
        QString m_url = m_index.value("cdn_url").toString();
        QString m_name = m_index.value("jar_name").toString();
        qDebug() << m_url;
        qDebug() << m_name;

        QUrl url(m_url);
        QNetworkRequest request(url);
        request.setRawHeader("User-Agent", "Mozilla/5.0");
        request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::NoLessSafeRedirectPolicy);
        request.setRawHeader("Accept", "*/*");
        request.setRawHeader("Referer", "https://www.curseforge.com/");
        QNetworkReply *reply = manager->get(request);
        reply->setProperty("saveName", m_name);
    }
    } else {
        QFile file(folderUrl + "/" + filename);
        if(file.open(QFile::WriteOnly)) {
            file.write(data);
            file.close();
        }
    }

    reply->deleteLater();
}

void downloader::changeFolderUrl(QString url) {
    folderUrl = url;
    qDebug() << "Received: Folder Url -> " + folderUrl;
}

void downloader::changeRemoteUrl(QString url) {
    remoteUrl = url;
    qDebug() << "Received: Remote Url -> " + remoteUrl;
}
