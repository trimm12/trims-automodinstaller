#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = nullptr);
    void doDownload();

public slots:
    void replyFinished(QNetworkReply*);
    void changeFolderUrl(QString url);
    void changeRemoteUrl(QString url);
    void updateModList();

private:
    QNetworkAccessManager* manager;
    QString folderUrl;
    QString remoteUrl;
    int completedCount;

signals:
    void debugTextChanged(QString msg);
    void modListTextChanged(QString text);
};

#endif // DOWNLOADER_H
