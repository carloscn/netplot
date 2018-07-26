/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_port_num;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_host_ip;
    QPushButton *pushButton_set;
    QGroupBox *groupBox;
    QCustomPlot *plot;
    QPushButton *pushButton_disconnect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1208, 583);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_port_num = new QLineEdit(centralWidget);
        lineEdit_port_num->setObjectName(QStringLiteral("lineEdit_port_num"));
        lineEdit_port_num->setGeometry(QRect(84, 11, 108, 26));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 11, 57, 18));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(198, 11, 16, 18));
        lineEdit_host_ip = new QLineEdit(centralWidget);
        lineEdit_host_ip->setObjectName(QStringLiteral("lineEdit_host_ip"));
        lineEdit_host_ip->setGeometry(QRect(219, 11, 108, 26));
        lineEdit_host_ip->setReadOnly(true);
        pushButton_set = new QPushButton(centralWidget);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));
        pushButton_set->setGeometry(QRect(333, 11, 80, 26));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 1161, 461));
        plot = new QCustomPlot(groupBox);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(20, 40, 1131, 411));
        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(420, 10, 80, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1208, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_port_num->setText(QApplication::translate("MainWindow", "8322", nullptr));
        label->setText(QApplication::translate("MainWindow", "Port Num:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        pushButton_set->setText(QApplication::translate("MainWindow", "setup", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
