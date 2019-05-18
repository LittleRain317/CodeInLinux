/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionoutput;
    QWidget *centralWidget;
    QTableView *DataTable;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ProcessLabel;
    QTextEdit *ProcessTextEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *SleepLabel;
    QTextEdit *SleepTextEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *StartPushButton;
    QPushButton *EndPushButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QLabel *UrlLabel;
    QTextEdit *UrlTextEdit;
    QMenuBar *menuBar;
    QMenu *menuOutput;
    QMenu *menuFIle;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(655, 545);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionoutput = new QAction(MainWindow);
        actionoutput->setObjectName(QString::fromUtf8("actionoutput"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DataTable = new QTableView(centralWidget);
        DataTable->setObjectName(QString::fromUtf8("DataTable"));
        DataTable->setGeometry(QRect(60, 10, 256, 192));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 230, 111, 96));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ProcessLabel = new QLabel(layoutWidget);
        ProcessLabel->setObjectName(QString::fromUtf8("ProcessLabel"));

        verticalLayout->addWidget(ProcessLabel);

        ProcessTextEdit = new QTextEdit(layoutWidget);
        ProcessTextEdit->setObjectName(QString::fromUtf8("ProcessTextEdit"));

        verticalLayout->addWidget(ProcessTextEdit);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 230, 121, 96));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SleepLabel = new QLabel(layoutWidget1);
        SleepLabel->setObjectName(QString::fromUtf8("SleepLabel"));

        verticalLayout_2->addWidget(SleepLabel);

        SleepTextEdit = new QTextEdit(layoutWidget1);
        SleepTextEdit->setObjectName(QString::fromUtf8("SleepTextEdit"));

        verticalLayout_2->addWidget(SleepTextEdit);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 80, 82, 60));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        StartPushButton = new QPushButton(layoutWidget2);
        StartPushButton->setObjectName(QString::fromUtf8("StartPushButton"));

        verticalLayout_3->addWidget(StartPushButton);

        EndPushButton = new QPushButton(layoutWidget2);
        EndPushButton->setObjectName(QString::fromUtf8("EndPushButton"));

        verticalLayout_3->addWidget(EndPushButton);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(270, 230, 141, 96));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        UrlLabel = new QLabel(layoutWidget3);
        UrlLabel->setObjectName(QString::fromUtf8("UrlLabel"));

        verticalLayout_4->addWidget(UrlLabel);

        UrlTextEdit = new QTextEdit(layoutWidget3);
        UrlTextEdit->setObjectName(QString::fromUtf8("UrlTextEdit"));

        verticalLayout_4->addWidget(UrlTextEdit);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        DataTable->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 23));
        menuOutput = new QMenu(menuBar);
        menuOutput->setObjectName(QString::fromUtf8("menuOutput"));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuOutput->menuAction());
        menuOutput->addAction(actionoutput);
        menuFIle->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "textProcess", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open(&o)", nullptr));
        actionoutput->setText(QApplication::translate("MainWindow", "output", nullptr));
        ProcessLabel->setText(QApplication::translate("MainWindow", "NumOfProcess", nullptr));
        SleepLabel->setText(QApplication::translate("MainWindow", "Sleep", nullptr));
        StartPushButton->setText(QApplication::translate("MainWindow", "Start", nullptr));
        EndPushButton->setText(QApplication::translate("MainWindow", "End", nullptr));
        UrlLabel->setText(QApplication::translate("MainWindow", "SetURL", nullptr));
        menuOutput->setTitle(QApplication::translate("MainWindow", "Output", nullptr));
        menuFIle->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
