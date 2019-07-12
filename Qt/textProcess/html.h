#ifndef HTML_H
#define HTML_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonDocument>
class HTML : public QObject
{
    Q_OBJECT
public:
    explicit HTML(QObject * parent = nullptr);
    HTML(const HTML & t): url(t.url), dataSource(t.dataSource), name(t.name){}
    void operator = (const HTML & t)
    {
        url = t.url;
        dataSource = t.dataSource;
        name = t.name;
    }

    const QString getUrl(){
        return url;
    }

    void setUrl(QString m_url)
    {
        url = m_url;
    }

    void setDataSource(const QString m_dataSource)
    {
        dataSource  = m_dataSource;
    }

    const QString getData()
    {
        return dataSource;
    }

    void setName(QStringList m_name)
    {
        name = m_name;
    }

    const QStringList getName()
    {
        return name;
    }

    void request();

    void processText();
signals:

public slots:

    void replyFinished(QNetworkReply * reply);

private:
    QString url;
    QString dataSource;
    QStringList name;
    QNetworkAccessManager * manager;
};

#endif // HTML_H
