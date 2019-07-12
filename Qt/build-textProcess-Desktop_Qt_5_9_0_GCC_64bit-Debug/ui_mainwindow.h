/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(655, 545);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionoutput = new QAction(MainWindow);
        actionoutput->setObjectName(QStringLiteral("actionoutput"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DataTable = new QTableView(centralWidget);
        DataTable->setObjectName(QStringLiteral("DataTable"));
        DataTable->setGeometry(QRect(60, 10, 256, 192));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 230, 111, 96));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ProcessLabel = new QLabel(layoutWidget);
        ProcessLabel->setObjectName(QStringLiteral("ProcessLabel"));

        verticalLayout->addWidget(ProcessLabel);

        ProcessTextEdit = new QTextEdit(layoutWidget);
        ProcessTextEdit->setObjectName(QStringLiteral("ProcessTextEdit"));

        verticalLayout->addWidget(ProcessTextEdit);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 230, 121, 96));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SleepLabel = new QLabel(layoutWidget1);
        SleepLabel->setObjectName(QStringLiteral("SleepLabel"));

        verticalLayout_2->addWidget(SleepLabel);

        SleepTextEdit = new QTextEdit(layoutWidget1);
        SleepTextEdit->setObjectName(QStringLiteral("SleepTextEdit"));

        verticalLayout_2->addWidget(SleepTextEdit);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 80, 82, 60));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        StartPushButton = new QPushButton(layoutWidget2);
        StartPushButton->setObjectName(QStringLiteral("StartPushButton"));

        verticalLayout_3->addWidget(StartPushButton);

        EndPushButton = new QPushButton(layoutWidget2);
        EndPushButton->setObjectName(QStringLiteral("EndPushButton"));

        verticalLayout_3->addWidget(EndPushButton);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(270, 230, 141, 96));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        UrlLabel = new QLabel(layoutWidget3);
        UrlLabel->setObjectName(QStringLiteral("UrlLabel"));

        verticalLayout_4->addWidget(UrlLabel);

        UrlTextEdit = new QTextEdit(layoutWidget3);
        UrlTextEdit->setObjectName(QStringLiteral("UrlTextEdit"));

        verticalLayout_4->addWidget(UrlTextEdit);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        DataTable->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 23));
        menuOutput = new QMenu(menuBar);
        menuOutput->setObjectName(QStringLiteral("menuOutput"));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "textProcess", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open(&o)", Q_NULLPTR));
        actionoutput->setText(QApplication::translate("MainWindow", "output", Q_NULLPTR));
        ProcessLabel->setText(QApplication::translate("MainWindow", "NumOfProcess", Q_NULLPTR));
        SleepLabel->setText(QApplication::translate("MainWindow", "Sleep", Q_NULLPTR));
        StartPushButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        EndPushButton->setText(QApplication::translate("MainWindow", "End", Q_NULLPTR));
        UrlLabel->setText(QApplication::translate("MainWindow", "SetURL", Q_NULLPTR));
        menuOutput->setTitle(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        menuFIle->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
