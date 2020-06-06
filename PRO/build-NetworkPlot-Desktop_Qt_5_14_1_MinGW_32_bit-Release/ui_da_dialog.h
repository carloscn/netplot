/********************************************************************************
** Form generated from reading UI file 'da_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DA_DIALOG_H
#define UI_DA_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_da_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_load;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_freq;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_cycle_num;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_dac_state;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *da_dialog)
    {
        if (da_dialog->objectName().isEmpty())
            da_dialog->setObjectName(QString::fromUtf8("da_dialog"));
        da_dialog->resize(511, 168);
        verticalLayout = new QVBoxLayout(da_dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(da_dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_path = new QLineEdit(da_dialog);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));

        horizontalLayout_2->addWidget(lineEdit_path);

        pushButton_load = new QPushButton(da_dialog);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        horizontalLayout_2->addWidget(pushButton_load);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(da_dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_freq = new QLineEdit(da_dialog);
        lineEdit_freq->setObjectName(QString::fromUtf8("lineEdit_freq"));

        horizontalLayout->addWidget(lineEdit_freq);

        label_3 = new QLabel(da_dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(da_dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_cycle_num = new QLineEdit(da_dialog);
        lineEdit_cycle_num->setObjectName(QString::fromUtf8("lineEdit_cycle_num"));

        horizontalLayout_4->addWidget(lineEdit_cycle_num);

        label_5 = new QLabel(da_dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_Send = new QPushButton(da_dialog);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));

        horizontalLayout_3->addWidget(pushButton_Send);

        pushButton_start = new QPushButton(da_dialog);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        horizontalLayout_3->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(da_dialog);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        horizontalLayout_3->addWidget(pushButton_stop);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_dac_state = new QLabel(da_dialog);
        label_dac_state->setObjectName(QString::fromUtf8("label_dac_state"));

        horizontalLayout_5->addWidget(label_dac_state);

        buttonBox = new QDialogButtonBox(da_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_5->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(da_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), da_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), da_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(da_dialog);
    } // setupUi

    void retranslateUi(QDialog *da_dialog)
    {
        da_dialog->setWindowTitle(QCoreApplication::translate("da_dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("da_dialog", "\345\212\240\350\275\275\346\226\207\344\273\266\357\274\232", nullptr));
        pushButton_load->setText(QCoreApplication::translate("da_dialog", "...", nullptr));
        label_2->setText(QCoreApplication::translate("da_dialog", "\346\263\242\345\275\242\351\242\221\347\216\207\357\274\232", nullptr));
        lineEdit_freq->setText(QCoreApplication::translate("da_dialog", "100000", nullptr));
        label_3->setText(QCoreApplication::translate("da_dialog", "Hz", nullptr));
        label_4->setText(QCoreApplication::translate("da_dialog", "\345\276\252\347\216\257\346\254\241\346\225\260\357\274\232", nullptr));
        lineEdit_cycle_num->setText(QCoreApplication::translate("da_dialog", "50", nullptr));
        label_5->setText(QCoreApplication::translate("da_dialog", "\346\254\241", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("da_dialog", "\345\217\221\351\200\201", nullptr));
        pushButton_start->setText(QCoreApplication::translate("da_dialog", "\345\274\200\345\247\213\344\277\241\345\217\267", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("da_dialog", "\345\201\234\346\255\242\344\277\241\345\217\267", nullptr));
        label_dac_state->setText(QCoreApplication::translate("da_dialog", "State: DAC Fucntion.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class da_dialog: public Ui_da_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DA_DIALOG_H
