#include <QCoreApplication>
#include "thread.h"
#include "writethread.h"

int num = 0;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Thread * t1 = new Thread();
    Thread * t2 = new Thread();
    Thread * t3 = new Thread();
    writeThread * w1 = new writeThread();
    writeThread * w2 = new writeThread();
    t1->start();
    t2->start();
    t3->start();
    w1->start();
    w2->start();
    return a.exec();
}
