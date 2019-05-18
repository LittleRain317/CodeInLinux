#ifndef THREAD_H
#define THREAD_H


#include <QThread>
#include <iostream>

class Thread : public QThread
{
public:
    Thread();
    void read();
    //void scanf();
protected:
    void run();
    //void run(int);
private:
    //int num;
    //static int numStatic;
};

#endif // THREAD_H
