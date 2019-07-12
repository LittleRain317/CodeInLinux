#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include "textprocessthread.h"
#include "html.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    const QString getFilePath();
    void saveData(const QString filePath);

private slots:
    void on_actionOpen_triggered();

  //  void on_actionOpen_FIle_triggered();

    void on_actionoutput_triggered();

private:
    Ui::MainWindow *ui;
    HTML html;
    textProcessThread thread;
};

#endif // MAINWINDOW_H
