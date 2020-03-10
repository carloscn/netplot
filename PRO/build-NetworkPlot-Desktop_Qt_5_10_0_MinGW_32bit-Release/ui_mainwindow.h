/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexit;
    QAction *actionclear_all;
    QAction *actionDA_Back;
    QAction *actionlcok;
    QAction *action_2;
    QAction *action_3;
    QAction *action_5;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_8;
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
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_10;
    QLabel *label_11;
    QLineEdit *lineEdit_set_ip;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLineEdit *lineEdit_set_mask;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_14;
    QLineEdit *lineEdit_set_gate;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *lineEdit_set_port;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_set_to_server;
    QPushButton *pushButton_set_clear;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushButton_set_to_time;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_reboot;
    QTextBrowser *textBrowser_server;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QTextBrowser *textBrowser;
    QLabel *label_7;
    QPushButton *pushButton_clear;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_sample;
    QPushButton *pushButton_close_sample;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_freq;
    QPushButton *pushButton_freq_set;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_gain_1;
    QComboBox *comboBox_gain2;
    QPushButton *pushButton_gain_set;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QComboBox *comboBox_sample_rate;
    QPushButton *pushButton_fs_set;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_ch1_time;
    QCheckBox *checkBox_ch2_time;
    QCheckBox *checkBox_ch3_time;
    QCheckBox *checkBox_ch4_time;
    QSpacerItem *horizontalSpacer;
    QwtPlot *qwt_ch;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox_ch1_fft;
    QCheckBox *checkBox_ch2_fft;
    QCheckBox *checkBox_ch3_fft;
    QCheckBox *checkBox_ch4_fft;
    QSpacerItem *horizontalSpacer_2;
    QwtPlot *qwt_fft;
    QHBoxLayout *horizontalLayout_13;
    QSpinBox *spinBox;
    QSlider *horizontalSlider_do;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *storge_size;
    QComboBox *storge_unit;
    QComboBox *storge_type;
    QPushButton *storge_confirm;
    QLabel *label_9;
    QLineEdit *display_storge_size;
    QLabel *label_8;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1249, 858);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionclear_all = new QAction(MainWindow);
        actionclear_all->setObjectName(QStringLiteral("actionclear_all"));
        actionDA_Back = new QAction(MainWindow);
        actionDA_Back->setObjectName(QStringLiteral("actionDA_Back"));
        actionlcok = new QAction(MainWindow);
        actionlcok->setObjectName(QStringLiteral("actionlcok"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(260, 190));
        groupBox_2->setMaximumSize(QSize(300, 190));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_host_ip = new QLineEdit(groupBox_2);
        lineEdit_host_ip->setObjectName(QStringLiteral("lineEdit_host_ip"));
        lineEdit_host_ip->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_host_ip, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_8, 0, 0, 1, 1);

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


        gridLayout_7->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_port_num = new QLineEdit(groupBox_2);
        lineEdit_port_num->setObjectName(QStringLiteral("lineEdit_port_num"));

        horizontalLayout_3->addWidget(lineEdit_port_num);


        gridLayout_7->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_set = new QPushButton(groupBox_2);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));
        pushButton_set->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton_set);

        pushButton_disconnect = new QPushButton(groupBox_2);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_4->addWidget(pushButton_disconnect);


        gridLayout_7->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_close_remote = new QPushButton(groupBox_2);
        pushButton_close_remote->setObjectName(QStringLiteral("pushButton_close_remote"));

        horizontalLayout_5->addWidget(pushButton_close_remote);

        pushButton_close_test = new QPushButton(groupBox_2);
        pushButton_close_test->setObjectName(QStringLiteral("pushButton_close_test"));

        horizontalLayout_5->addWidget(pushButton_close_test);


        gridLayout_7->addLayout(horizontalLayout_5, 4, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(260, 0));
        tabWidget->setMaximumSize(QSize(300, 16777215));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        groupBox_6->setMinimumSize(QSize(260, 190));
        groupBox_6->setMaximumSize(QSize(300, 190));
        verticalLayout_7 = new QVBoxLayout(groupBox_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_10->addWidget(label_11, 0, 0, 1, 1);

        lineEdit_set_ip = new QLineEdit(groupBox_6);
        lineEdit_set_ip->setObjectName(QStringLiteral("lineEdit_set_ip"));
        lineEdit_set_ip->setReadOnly(false);

        gridLayout_10->addWidget(lineEdit_set_ip, 0, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);

        lineEdit_set_mask = new QLineEdit(groupBox_6);
        lineEdit_set_mask->setObjectName(QStringLiteral("lineEdit_set_mask"));
        lineEdit_set_mask->setReadOnly(false);

        horizontalLayout_8->addWidget(lineEdit_set_mask);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_17->addWidget(label_14);

        lineEdit_set_gate = new QLineEdit(groupBox_6);
        lineEdit_set_gate->setObjectName(QStringLiteral("lineEdit_set_gate"));
        lineEdit_set_gate->setReadOnly(false);

        horizontalLayout_17->addWidget(lineEdit_set_gate);


        verticalLayout_7->addLayout(horizontalLayout_17);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_12->addWidget(label_13);

        lineEdit_set_port = new QLineEdit(groupBox_6);
        lineEdit_set_port->setObjectName(QStringLiteral("lineEdit_set_port"));

        horizontalLayout_12->addWidget(lineEdit_set_port);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        pushButton_set_to_server = new QPushButton(groupBox_6);
        pushButton_set_to_server->setObjectName(QStringLiteral("pushButton_set_to_server"));
        pushButton_set_to_server->setStyleSheet(QStringLiteral(""));

        horizontalLayout_14->addWidget(pushButton_set_to_server);

        pushButton_set_clear = new QPushButton(groupBox_6);
        pushButton_set_clear->setObjectName(QStringLiteral("pushButton_set_clear"));

        horizontalLayout_14->addWidget(pushButton_set_clear);


        verticalLayout_7->addLayout(horizontalLayout_14);


        verticalLayout_3->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dateTimeEdit = new QDateTimeEdit(groupBox_7);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setDate(QDate(2020, 4, 20));
        dateTimeEdit->setTime(QTime(0, 0, 0));
        dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);

        verticalLayout->addWidget(dateTimeEdit);

        pushButton_set_to_time = new QPushButton(groupBox_7);
        pushButton_set_to_time->setObjectName(QStringLiteral("pushButton_set_to_time"));
        pushButton_set_to_time->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton_set_to_time);


        verticalLayout_3->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        verticalLayout_2 = new QVBoxLayout(groupBox_8);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_reboot = new QPushButton(groupBox_8);
        pushButton_reboot->setObjectName(QStringLiteral("pushButton_reboot"));

        verticalLayout_2->addWidget(pushButton_reboot);


        verticalLayout_3->addWidget(groupBox_8);

        textBrowser_server = new QTextBrowser(tab_2);
        textBrowser_server->setObjectName(QStringLiteral("textBrowser_server"));

        verticalLayout_3->addWidget(textBrowser_server);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(260, 400));
        groupBox_3->setMaximumSize(QSize(260, 1200));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textBrowser = new QTextBrowser(groupBox_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(textBrowser, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_7, 2, 0, 1, 1);

        pushButton_clear = new QPushButton(groupBox_3);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        sizePolicy2.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_clear, 6, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetNoConstraint);
        pushButton_sample = new QPushButton(groupBox_3);
        pushButton_sample->setObjectName(QStringLiteral("pushButton_sample"));
        sizePolicy2.setHeightForWidth(pushButton_sample->sizePolicy().hasHeightForWidth());
        pushButton_sample->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_sample);

        pushButton_close_sample = new QPushButton(groupBox_3);
        pushButton_close_sample->setObjectName(QStringLiteral("pushButton_close_sample"));
        sizePolicy2.setHeightForWidth(pushButton_close_sample->sizePolicy().hasHeightForWidth());
        pushButton_close_sample->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_close_sample);


        gridLayout_4->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_5);

        lineEdit_freq = new QLineEdit(groupBox_3);
        lineEdit_freq->setObjectName(QStringLiteral("lineEdit_freq"));
        lineEdit_freq->setEnabled(false);
        sizePolicy2.setHeightForWidth(lineEdit_freq->sizePolicy().hasHeightForWidth());
        lineEdit_freq->setSizePolicy(sizePolicy2);
        lineEdit_freq->setReadOnly(false);

        horizontalLayout_7->addWidget(lineEdit_freq);

        pushButton_freq_set = new QPushButton(groupBox_3);
        pushButton_freq_set->setObjectName(QStringLiteral("pushButton_freq_set"));
        pushButton_freq_set->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_freq_set->sizePolicy().hasHeightForWidth());
        pushButton_freq_set->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(pushButton_freq_set);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_4);

        lineEdit_gain_1 = new QLineEdit(groupBox_3);
        lineEdit_gain_1->setObjectName(QStringLiteral("lineEdit_gain_1"));
        lineEdit_gain_1->setEnabled(false);
        lineEdit_gain_1->setMinimumSize(QSize(50, 0));
        lineEdit_gain_1->setMaximumSize(QSize(50, 16777215));
        lineEdit_gain_1->setReadOnly(false);

        horizontalLayout_6->addWidget(lineEdit_gain_1);

        comboBox_gain2 = new QComboBox(groupBox_3);
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->addItem(QString());
        comboBox_gain2->setObjectName(QStringLiteral("comboBox_gain2"));
        comboBox_gain2->setEnabled(false);
        comboBox_gain2->setMinimumSize(QSize(50, 0));
        comboBox_gain2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(comboBox_gain2);

        pushButton_gain_set = new QPushButton(groupBox_3);
        pushButton_gain_set->setObjectName(QStringLiteral("pushButton_gain_set"));
        pushButton_gain_set->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_gain_set->sizePolicy().hasHeightForWidth());
        pushButton_gain_set->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(pushButton_gain_set);


        gridLayout_4->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        comboBox_sample_rate = new QComboBox(groupBox_3);
        comboBox_sample_rate->addItem(QString());
        comboBox_sample_rate->addItem(QString());
        comboBox_sample_rate->addItem(QString());
        comboBox_sample_rate->addItem(QString());
        comboBox_sample_rate->addItem(QString());
        comboBox_sample_rate->setObjectName(QStringLiteral("comboBox_sample_rate"));

        gridLayout_2->addWidget(comboBox_sample_rate, 0, 1, 1, 1);

        pushButton_fs_set = new QPushButton(groupBox_3);
        pushButton_fs_set->setObjectName(QStringLiteral("pushButton_fs_set"));
        sizePolicy2.setHeightForWidth(pushButton_fs_set->sizePolicy().hasHeightForWidth());
        pushButton_fs_set->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(pushButton_fs_set, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_6, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBox_ch1_time = new QCheckBox(groupBox);
        checkBox_ch1_time->setObjectName(QStringLiteral("checkBox_ch1_time"));
        checkBox_ch1_time->setChecked(true);

        horizontalLayout_10->addWidget(checkBox_ch1_time);

        checkBox_ch2_time = new QCheckBox(groupBox);
        checkBox_ch2_time->setObjectName(QStringLiteral("checkBox_ch2_time"));
        checkBox_ch2_time->setEnabled(false);
        checkBox_ch2_time->setChecked(false);

        horizontalLayout_10->addWidget(checkBox_ch2_time);

        checkBox_ch3_time = new QCheckBox(groupBox);
        checkBox_ch3_time->setObjectName(QStringLiteral("checkBox_ch3_time"));
        checkBox_ch3_time->setEnabled(false);
        checkBox_ch3_time->setChecked(false);

        horizontalLayout_10->addWidget(checkBox_ch3_time);

        checkBox_ch4_time = new QCheckBox(groupBox);
        checkBox_ch4_time->setObjectName(QStringLiteral("checkBox_ch4_time"));
        checkBox_ch4_time->setEnabled(false);
        checkBox_ch4_time->setChecked(false);

        horizontalLayout_10->addWidget(checkBox_ch4_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_10);

        qwt_ch = new QwtPlot(groupBox);
        qwt_ch->setObjectName(QStringLiteral("qwt_ch"));
        sizePolicy3.setHeightForWidth(qwt_ch->sizePolicy().hasHeightForWidth());
        qwt_ch->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(qwt_ch);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        checkBox_ch1_fft = new QCheckBox(groupBox);
        checkBox_ch1_fft->setObjectName(QStringLiteral("checkBox_ch1_fft"));
        checkBox_ch1_fft->setChecked(true);

        horizontalLayout_11->addWidget(checkBox_ch1_fft);

        checkBox_ch2_fft = new QCheckBox(groupBox);
        checkBox_ch2_fft->setObjectName(QStringLiteral("checkBox_ch2_fft"));
        checkBox_ch2_fft->setEnabled(false);
        checkBox_ch2_fft->setChecked(false);

        horizontalLayout_11->addWidget(checkBox_ch2_fft);

        checkBox_ch3_fft = new QCheckBox(groupBox);
        checkBox_ch3_fft->setObjectName(QStringLiteral("checkBox_ch3_fft"));
        checkBox_ch3_fft->setEnabled(false);
        checkBox_ch3_fft->setChecked(false);

        horizontalLayout_11->addWidget(checkBox_ch3_fft);

        checkBox_ch4_fft = new QCheckBox(groupBox);
        checkBox_ch4_fft->setObjectName(QStringLiteral("checkBox_ch4_fft"));
        checkBox_ch4_fft->setEnabled(false);
        checkBox_ch4_fft->setChecked(false);

        horizontalLayout_11->addWidget(checkBox_ch4_fft);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_11);

        qwt_fft = new QwtPlot(groupBox);
        qwt_fft->setObjectName(QStringLiteral("qwt_fft"));
        qwt_fft->setEnabled(true);
        sizePolicy3.setHeightForWidth(qwt_fft->sizePolicy().hasHeightForWidth());
        qwt_fft->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(qwt_fft);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_13->addWidget(spinBox);

        horizontalSlider_do = new QSlider(groupBox);
        horizontalSlider_do->setObjectName(QStringLiteral("horizontalSlider_do"));
        horizontalSlider_do->setMaximum(100);
        horizontalSlider_do->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(horizontalSlider_do);


        verticalLayout_6->addLayout(horizontalLayout_13);


        gridLayout_5->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy4);
        groupBox_4->setMinimumSize(QSize(260, 0));
        groupBox_4->setMaximumSize(QSize(200, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setMinimumSize(QSize(0, 13));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        storge_size = new QLineEdit(groupBox_5);
        storge_size->setObjectName(QStringLiteral("storge_size"));

        horizontalLayout_15->addWidget(storge_size);

        storge_unit = new QComboBox(groupBox_5);
        storge_unit->addItem(QString());
        storge_unit->addItem(QString());
        storge_unit->addItem(QString());
        storge_unit->setObjectName(QStringLiteral("storge_unit"));

        horizontalLayout_15->addWidget(storge_unit);

        storge_type = new QComboBox(groupBox_5);
        storge_type->addItem(QString());
        storge_type->addItem(QString());
        storge_type->setObjectName(QStringLiteral("storge_type"));

        horizontalLayout_15->addWidget(storge_type);

        storge_confirm = new QPushButton(groupBox_5);
        storge_confirm->setObjectName(QStringLiteral("storge_confirm"));
        storge_confirm->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(storge_confirm->sizePolicy().hasHeightForWidth());
        storge_confirm->setSizePolicy(sizePolicy5);

        horizontalLayout_15->addWidget(storge_confirm);


        verticalLayout_4->addLayout(horizontalLayout_15);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        display_storge_size = new QLineEdit(groupBox_5);
        display_storge_size->setObjectName(QStringLiteral("display_storge_size"));

        verticalLayout_4->addWidget(display_storge_size);


        verticalLayout_5->addWidget(groupBox_5);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(label_8);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_5->addLayout(gridLayout);

        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_5->addWidget(progressBar);


        gridLayout_5->addWidget(groupBox_4, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName(QStringLiteral("menu_4"));
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

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionexit);
        menu->addAction(actionclear_all);
        menu->addAction(actionlcok);
        menu_2->addAction(actionDA_Back);
        menu_3->addSeparator();
        menu_3->addAction(action_2);
        menu_3->addAction(action_3);
        menu_3->addAction(menu_4->menuAction());
        menu_4->addAction(action_5);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\350\275\257\344\273\266", nullptr));
        actionclear_all->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\347\274\223\345\255\230", nullptr));
        actionDA_Back->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\260\203\345\210\266\345\233\236\346\224\276", nullptr));
        actionlcok->setText(QApplication::translate("MainWindow", "lcok", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\350\257\245\350\275\257\344\273\266", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\256\270\345\217\257\350\257\264\346\230\216", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "\342\210\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TCP Connection", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260IP\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        lineEdit_server_ip->setText(QApplication::translate("MainWindow", "192.168.1.176", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEdit_port_num->setText(QApplication::translate("MainWindow", "8322", nullptr));
        pushButton_set->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButton_close_remote->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\347\275\221\347\273\234", nullptr));
        pushButton_close_test->setText(QApplication::translate("MainWindow", "\344\275\277\350\203\275\345\255\230\345\202\250", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "TCP Config", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        lineEdit_set_ip->setText(QApplication::translate("MainWindow", "192.168.1.156", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Mask:", nullptr));
        lineEdit_set_mask->setText(QApplication::translate("MainWindow", "255.255.255.0", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Gate:", nullptr));
        lineEdit_set_gate->setText(QApplication::translate("MainWindow", "192.168.1.1", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        lineEdit_set_port->setText(QApplication::translate("MainWindow", "1585", nullptr));
        pushButton_set_to_server->setText(QApplication::translate("MainWindow", "Set", nullptr));
        pushButton_set_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Time Config", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "yy/MM/dd/ hh:mm:ss", nullptr));
        pushButton_set_to_time->setText(QApplication::translate("MainWindow", "Set", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "System Config", nullptr));
        pushButton_reboot->setText(QApplication::translate("MainWindow", "reboot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Net-Config", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266\344\277\241\346\201\257\351\205\215\347\275\256", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "@ \345\242\236\347\233\212\345\210\206\344\270\272\344\270\200\347\272\247\345\242\236\347\233\212\345\222\214\344\272\214\347\272\247\345\242\236\347\233\212.", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        pushButton_sample->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\351\207\207\346\240\267", nullptr));
        pushButton_close_sample->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\351\207\207\346\240\267", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\344\275\216\351\200\232\351\242\221\347\216\207(KHz):", nullptr));
        lineEdit_freq->setText(QApplication::translate("MainWindow", "50", nullptr));
        pushButton_freq_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212: ", nullptr));
        lineEdit_gain_1->setText(QApplication::translate("MainWindow", "1", nullptr));
        comboBox_gain2->setItemText(0, QApplication::translate("MainWindow", "2", nullptr));
        comboBox_gain2->setItemText(1, QApplication::translate("MainWindow", "5", nullptr));
        comboBox_gain2->setItemText(2, QApplication::translate("MainWindow", "10", nullptr));
        comboBox_gain2->setItemText(3, QApplication::translate("MainWindow", "20", nullptr));
        comboBox_gain2->setItemText(4, QApplication::translate("MainWindow", "30", nullptr));
        comboBox_gain2->setItemText(5, QApplication::translate("MainWindow", "50", nullptr));
        comboBox_gain2->setItemText(6, QApplication::translate("MainWindow", "100", nullptr));

        pushButton_gain_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\347\216\207Hz):", nullptr));
        comboBox_sample_rate->setItemText(0, QApplication::translate("MainWindow", "10KHz", nullptr));
        comboBox_sample_rate->setItemText(1, QApplication::translate("MainWindow", "50KHz", nullptr));
        comboBox_sample_rate->setItemText(2, QApplication::translate("MainWindow", "100KHz", nullptr));
        comboBox_sample_rate->setItemText(3, QApplication::translate("MainWindow", "150KHz", nullptr));
        comboBox_sample_rate->setItemText(4, QApplication::translate("MainWindow", "200KHz", nullptr));

        pushButton_fs_set->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ADC-Config", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\347\273\230\345\210\266", nullptr));
        checkBox_ch1_time->setText(QApplication::translate("MainWindow", "CH1", nullptr));
        checkBox_ch2_time->setText(QApplication::translate("MainWindow", "CH2", nullptr));
        checkBox_ch3_time->setText(QApplication::translate("MainWindow", "CH3", nullptr));
        checkBox_ch4_time->setText(QApplication::translate("MainWindow", "CH4", nullptr));
        checkBox_ch1_fft->setText(QApplication::translate("MainWindow", "CH1 FFT", nullptr));
        checkBox_ch2_fft->setText(QApplication::translate("MainWindow", "CH2 FFT", nullptr));
        checkBox_ch3_fft->setText(QApplication::translate("MainWindow", "CH3 FFT", nullptr));
        checkBox_ch4_fft->setText(QApplication::translate("MainWindow", "CH4 FFT", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\210\227\350\241\250", nullptr));
        groupBox_5->setTitle(QString());
        label_10->setText(QApplication::translate("MainWindow", "Setting Size", nullptr));
        storge_unit->setItemText(0, QApplication::translate("MainWindow", "GB", nullptr));
        storge_unit->setItemText(1, QApplication::translate("MainWindow", "MB", nullptr));
        storge_unit->setItemText(2, QApplication::translate("MainWindow", "KB", nullptr));

        storge_type->setItemText(0, QApplication::translate("MainWindow", "Split", nullptr));
        storge_type->setItemText(1, QApplication::translate("MainWindow", "Def", nullptr));

        storge_confirm->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Current Size", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232/usr/data", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\201\224\347\263\273\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
