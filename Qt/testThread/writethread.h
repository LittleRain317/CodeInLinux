#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>

class writeThread : public QThread
{
public:
    writeThread();
    void write();
protected:
    void run();
private:

};

#endif // WRITETHREAD_H
