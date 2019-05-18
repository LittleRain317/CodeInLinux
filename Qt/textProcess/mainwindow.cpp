#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

const QString MainWindow::getFilePath()
{
    QString  FilePath = QFileDialog::getOpenFileName(this,
                                                     tr("Open File"),
                                                     "/home/littlerain/Desktop",
                                                     tr("text File(*.txt)"));
    return FilePath;
}

void MainWindow::saveData(const QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString text(line);
            QStringList everyData= text.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
            QString url = ui->UrlTextEdit->toPlainText();
            if (url == "")
            {
                QMessageBox::information(this, "NO", "Please first!");
                ui->UrlTextEdit->setFocus();
                return;
            }

        }
        file.close();
    }
}

void MainWindow::on_actionOpen_triggered()
{
   QString filePath =  getFilePath();
   if (filePath == "")
   {
        QMessageBox::information(this, "NO!", "Cancle!");
        return;
   }
   saveData(filePath);
}



void MainWindow::on_actionoutput_triggered()
{
    //    thread.start();
    QThread * thread = new QThread();
    html.moveToThread(thread);
    html.setUrl("http://test.ecutszy.xin");
    html.request();
    thread->start();
    qDebug() << "threadId:" << QThread::currentThread();
}
