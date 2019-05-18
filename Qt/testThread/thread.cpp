#include "thread.h"
#include <QDebug>
extern int num;
Thread::Thread()
{
    // num = 0;
}

void Thread::read()
{

    qDebug() << "read threadId:" << QThread::currentThreadId();
    qDebug() << "num = " << num;

}

void Thread::run()
{
    //qDebug() << "hello" << QString::number((long)QThread::currentThreadId());
    while(1){
  //      print();
        read();
        //qDebug() << "Thread id:" << (long)QThread::currentThreadId();
        //print();
        //qDebug() << "HELLO " << "WORLD" << QString::number((long)QThread::currentThreadId());
        sleep(1);
//        scanf();
        // qDebug() << "hhhhhh";
        //std::cout << "hello" << "world";
    //std::cout << std::endl;
    }
}


//void Thread::print()
//{
//    qDebug() << "num:" << num;
//}

//void Thread::scanf()
//{
//    ++num;
//}
