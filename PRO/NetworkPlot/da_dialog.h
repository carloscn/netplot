#ifndef DA_DIALOG_H
#define DA_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <QElapsedTimer>
#include <QTime>


namespace Ui {
class da_dialog;
}

struct dac_data {
    quint32 *buffer;
    quint64 left_len;
};

class da_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit da_dialog(QWidget *parent = 0);
    ~da_dialog();
    void active_da_state();
    void sleep_da_state();
signals:

    void da_trans_packet(QByteArray);

    void da_trans_array(QByteArray);

private slots:

    void on_pushButton_load_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_timer_over_time();

    void on_net_notify_dac_hand_ok(bool);
    void on_buttonBox_rejected();


    void on_pushButton_Send_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::da_dialog *ui;
    QTimer *timer;
    bool is_over_time;
    quint64 data_counter;

    bool is_dac_hand_ok;
    struct dac_data dac_summay_buffer;
    bool is_stop_pressed;
    void DELAY_MS(int s);

};

#endif // DA_DIALOG_H
