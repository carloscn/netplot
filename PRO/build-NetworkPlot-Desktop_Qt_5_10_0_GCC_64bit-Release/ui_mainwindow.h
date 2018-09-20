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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QCustomPlot *plot;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_host_ip;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_server_ip;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_port_num;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_set;
    QPushButton *pushButton_disconnect;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_close_remote;
    QPushButton *pushButton_close_test;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_freq;
    QPushButton *pushButton_freq_set;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_gain;
    QPushButton *pushButton_gain_set;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_fs;
    QPushButton *pushButton_fs_set;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1208, 665);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(300, 10, 891, 581));
        plot = new QCustomPlot(groupBox);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(12, 33, 887, 541));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 12, 282, 588));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_host_ip = new QLineEdit(groupBox_2);
        lineEdit_host_ip->setObjectName(QStringLiteral("lineEdit_host_ip"));
        lineEdit_host_ip->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_host_ip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_server_ip = new QLineEdit(groupBox_2);
        lineEdit_server_ip->setObjectName(QStringLiteral("lineEdit_server_ip"));
        lineEdit_server_ip->setReadOnly(false);

        horizontalLayout_2->addWidget(lineEdit_server_ip);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_port_num = new QLineEdit(groupBox_2);
        lineEdit_port_num->setObjectName(QStringLiteral("lineEdit_port_num"));

        horizontalLayout_3->addWidget(lineEdit_port_num);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_set = new QPushButton(groupBox_2);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));

        horizontalLayout_4->addWidget(pushButton_set);

        pushButton_disconnect = new QPushButton(groupBox_2);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_4->addWidget(pushButton_disconnect);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_close_remote = new QPushButton(groupBox_2);
        pushButton_close_remote->setObjectName(QStringLiteral("pushButton_close_remote"));

        horizontalLayout_5->addWidget(pushButton_close_remote);

        pushButton_close_test = new QPushButton(groupBox_2);
        pushButton_close_test->setObjectName(QStringLiteral("pushButton_close_test"));

        horizontalLayout_5->addWidget(pushButton_close_test);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_freq = new QLineEdit(groupBox_3);
        lineEdit_freq->setObjectName(QStringLiteral("lineEdit_freq"));
        lineEdit_freq->setReadOnly(false);

        horizontalLayout_7->addWidget(lineEdit_freq);

        pushButton_freq_set = new QPushButton(groupBox_3);
        pushButton_freq_set->setObjectName(QStringLiteral("pushButton_freq_set"));

        horizontalLayout_7->addWidget(pushButton_freq_set);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_gain = new QLineEdit(groupBox_3);
        lineEdit_gain->setObjectName(QStringLiteral("lineEdit_gain"));
        lineEdit_gain->setReadOnly(false);

        horizontalLayout_6->addWidget(lineEdit_gain);

        pushButton_gain_set = new QPushButton(groupBox_3);
        pushButton_gain_set->setObjectName(QStringLiteral("pushButton_gain_set"));

        horizontalLayout_6->addWidget(pushButton_gain_set);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_fs = new QLineEdit(groupBox_3);
        lineEdit_fs->setObjectName(QStringLiteral("lineEdit_fs"));
        lineEdit_fs->setReadOnly(false);

        horizontalLayout_8->addWidget(lineEdit_fs);

        pushButton_fs_set = new QPushButton(groupBox_3);
        pushButton_fs_set->setObjectName(QStringLiteral("pushButton_fs_set"));

        horizontalLayout_8->addWidget(pushButton_fs_set);


        verticalLayout_2->addLayout(horizontalLayout_8);

        textBrowser = new QTextBrowser(groupBox_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        pushButton_clear = new QPushButton(groupBox_3);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        verticalLayout_2->addWidget(pushButton_clear);


        verticalLayout_3->addWidget(groupBox_3);

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
        QWidget::setTabOrder(pushButton_disconnect, pushButton_set);
        QWidget::setTabOrder(pushButton_set, lineEdit_host_ip);
        QWidget::setTabOrder(lineEdit_host_ip, lineEdit_port_num);
        QWidget::setTabOrder(lineEdit_port_num, lineEdit_server_ip);
        QWidget::setTabOrder(lineEdit_server_ip, textBrowser);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\273\230\345\233\276\345\214\272\345\237\237", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\275\221\347\273\234\351\205\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260IP\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        lineEdit_server_ip->setText(QApplication::translate("MainWindow", "192.168.1.176", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEdit_port_num->setText(QApplication::translate("MainWindow", "8322", nullptr));
        pushButton_set->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButton_close_remote->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\350\277\234\347\250\213\346\234\215\345\212\241", nullptr));
        pushButton_close_test->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\344\277\241\346\201\257\351\205\215\347\275\256", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\351\242\221\347\216\207(KHz):", nullptr));
        lineEdit_freq->setText(QApplication::translate("MainWindow", "50", nullptr));
        pushButton_freq_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212\357\274\232", nullptr));
        lineEdit_gain->setText(QApplication::translate("MainWindow", "40", nullptr));
        pushButton_gain_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\347\216\207kHz):", nullptr));
        lineEdit_fs->setText(QApplication::translate("MainWindow", "100", nullptr));
        pushButton_fs_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
