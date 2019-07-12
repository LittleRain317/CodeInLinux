#ifndef TEXTPROCESSTHREAD_H
#define TEXTPROCESSTHREAD_H

#include <QThread>
#include <QVector>
#include "html.h"

class textProcessThread : public QThread
{
public:
    textProcessThread();
    void getData(QString filePath, qint64 line);

protected:
    void run();

private:
    HTML htmlData;
};

#endif // TEXTPROCESSTHREAD_H
