#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   // HTML html(NULL, "http://www.baidu.com");

    return a.exec();
}
