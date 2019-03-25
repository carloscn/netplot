/********************************************************************************
** Form generated from reading UI file 'da_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DA_DIALOG_H
#define UI_DA_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QPushButton *pushButton_Send;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QDialogButtonBox *buttonBox;
    QLabel *label_dac_state;

    void setupUi(QDialog *da_dialog)
    {
        if (da_dialog->objectName().isEmpty())
            da_dialog->setObjectName(QStringLiteral("da_dialog"));
        da_dialog->resize(474, 206);
        verticalLayout = new QVBoxLayout(da_dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(da_dialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_path = new QLineEdit(da_dialog);
        lineEdit_path->setObjectName(QStringLiteral("lineEdit_path"));

        horizontalLayout_2->addWidget(lineEdit_path);

        pushButton_load = new QPushButton(da_dialog);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));

        horizontalLayout_2->addWidget(pushButton_load);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(da_dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_freq = new QLineEdit(da_dialog);
        lineEdit_freq->setObjectName(QStringLiteral("lineEdit_freq"));

        horizontalLayout->addWidget(lineEdit_freq);

        label_3 = new QLabel(da_dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_Send = new QPushButton(da_dialog);
        pushButton_Send->setObjectName(QStringLiteral("pushButton_Send"));

        verticalLayout->addWidget(pushButton_Send);

        pushButton_start = new QPushButton(da_dialog);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        verticalLayout->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(da_dialog);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        verticalLayout->addWidget(pushButton_stop);

        buttonBox = new QDialogButtonBox(da_dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        label_dac_state = new QLabel(da_dialog);
        label_dac_state->setObjectName(QStringLiteral("label_dac_state"));

        verticalLayout->addWidget(label_dac_state);


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
        pushButton_Send->setText(QApplication::translate("da_dialog", "Send", nullptr));
        pushButton_start->setText(QApplication::translate("da_dialog", "Start", nullptr));
        pushButton_stop->setText(QApplication::translate("da_dialog", "stop", nullptr));
        label_dac_state->setText(QApplication::translate("da_dialog", "State: DAC Fucntion.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class da_dialog: public Ui_da_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DA_DIALOG_H
