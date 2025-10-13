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

private:
    QNetworkAccessManager* manager;

signals:
};

#endif // DOWNLOADER_H
