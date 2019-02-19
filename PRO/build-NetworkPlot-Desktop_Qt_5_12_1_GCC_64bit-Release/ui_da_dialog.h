/********************************************************************************
** Form generated from reading UI file 'da_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
#include <math.h>

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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *da_dialog)
    {
        if (da_dialog->objectName().isEmpty())
            da_dialog->setObjectName(QString::fromUtf8("da_dialog"));
        da_dialog->resize(474, 102);
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

        buttonBox = new QDialogButtonBox(da_dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(da_dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), da_dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), da_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(da_dialog);
    } // setupUi

    void retranslateUi(QDialog *da_dialog)
    {
        da_dialog->setWindowTitle(QApplication::translate("da_dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("da_dialog", "Load:", nullptr));
        pushButton_load->setText(QApplication::translate("da_dialog", "...", nullptr));
        label_2->setText(QApplication::translate("da_dialog", "Freq:", nullptr));
        lineEdit_freq->setText(QApplication::translate("da_dialog", "100000", nullptr));
        label_3->setText(QApplication::translate("da_dialog", "Hz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class da_dialog: public Ui_da_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DA_DIALOG_H
