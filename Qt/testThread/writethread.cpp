#include "writethread.h"
#include <QDebug>
extern int num;
writeThread::writeThread()
{

}

void writeThread::write()
{
    qDebug() << "write threadId:" << QThread::currentThreadId()
   << "num = " << num;
    ++num;

}

void writeThread::run()
{
    while(true){
        write();
        sleep(2);
    }
}
