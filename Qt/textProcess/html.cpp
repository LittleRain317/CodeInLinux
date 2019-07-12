#include "html.h"
#include <QDebug>

HTML::HTML(QObject *parent)
{
    this->setParent(parent);
    manager = new QNetworkAccessManager(this);
    //qDebug() << url;
    connect(manager, &QNetworkAccessManager::finished, this, &HTML::replyFinished);
   // manager->get(QNetworkRequest(QUrl(url)));
}

void HTML::request()
{
    manager->get(QNetworkRequest(url));

}


void HTML::processText()
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(dataSource.toUtf8(), &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isArray())
        {
            QJsonArray array = parse_doucment.array();

            for (auto it : array)
            {
                if(it.isString())
                {
                   qDebug() << it.toString();
                }
            }
        }
    }

}

void HTML::replyFinished(QNetworkReply *reply)
{
    dataSource = reply->readAll();
    qDebug() << dataSource;
    processText();
}
