#ifndef DA_DIALOG_H
#define DA_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFileDialog>

namespace Ui {
class da_dialog;
}

class da_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit da_dialog(QWidget *parent = 0);
    ~da_dialog();

signals:

    void da_trans_packet(QByteArray);

private slots:
    void on_pushButton_load_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::da_dialog *ui;
};

#endif // DA_DIALOG_H
