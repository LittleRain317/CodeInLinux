#include "textprocessthread.h"
#include <QDebug>
textProcessThread::textProcessThread()
{

}

void textProcessThread::run()
{
    htmlData.setUrl("http://test.ecutszy.xin");
    htmlData.request();
    qDebug() << "threadID" << QThread::currentThreadId();
}
