#include <QtCore>
#include <iostream>

#include "thread.h"

Thread::Thread()
{
    stopped = false;
}

void Thread::setMessage(const QString &message)
{
    messageStr = message;
}

void Thread::run()
{
    forever{
        //qDebug() << stopped << " " << (long)QThread::currentThreadId();
        std::cout << "HELLO";
        sleep(3);
       //mutex.lock();
       if (stopped)
       {
           stopped = false;
         //  mutex.unlock();
           break;
       }
      // std::cerr << qPrintable(messageStr);
       //mutex.unlock();
    }
    std::cerr << std::endl;

}

void Thread::stop()
{
    //mutex.lock();
    stopped = true;
    //mutex.unlock();
}
