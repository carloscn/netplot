/**
 * \brief   This project about NETPLOT.
 *
 * \License  THIS FILE IS PART OF MULTIBEANS PROJECT;
 *           all of the files  - The core part of the project;
 *           THIS PROGRAM IS NOT FREE SOFTWARE, NEED MULTIBEANS ORG LIC;
 *           YOU SHOULD HAVE RECEIVED A COPY OF WTFPL LICENSE UTIL 5/1/2021
 *           OVER THE DATE, ALL FUNCTIONS WILL BE CLOSED. IF NOT, MULTIBEANS
 *           WILL TAKE APPROPRIATE MEASURES.
 *
 *                ________________     ___           _________________
 *               |    __    __    |   |   |         |______     ______|
 *               |   |  |  |  |   |   |   |                |   |
 *               |   |  |__|  |   |   |   |________        |   |
 *               |___|        |___|   |____________|       |___|
 *
 *                               MULTIBEANS ORG.
 *                     Homepage: http://www.mltbns.com/
 *
 *           * You can download the license on our Github. ->
 *           * -> https://github.com/lifimlt  <-
 *           * Copyright (c) 2018 Wei Haochen(Carlos Wei: # whc.mlt@qq.com).
 *           * Copyright (c) 2013-2018 MULTIBEANS ORG. http://www.mltbns.com/
 *
 *  \note    void.
 ****************************************************************************/
#include "da_dialog.h"
#include "ui_da_dialog.h"

da_dialog::da_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::da_dialog)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(on_timer_over_time()));
    is_over_time = false;
    is_dac_hand_ok = false;
    data_counter = 0;
    is_stop_pressed = false;
    this->cycle_num = 0;
}

da_dialog::~da_dialog()
{
    delete ui;
}

void da_dialog::on_pushButton_load_clicked()
{

    QByteArray Doc;
    QString file_name = QFileDialog::getOpenFileName(this,
                                                     tr("Open File"),
                                                     "/usr/data",
                                                     "Data Document(*.da *.flt *)",
                                                     0);
    if (!file_name.isNull()) {
        qDebug() << file_name ;
    }else{
        qDebug() << "cancel " ;
        return;
    }
    ui->lineEdit_path->setText(file_name);

}

void da_dialog::on_timer_over_time()
{
    if (this->cycle_num < 0) {
        timer->stop();
    }else{
        this->cycle_num = ui->lineEdit_cycle_num->text().toUInt();
        run_da_out();
    }

}

void da_dialog::on_buttonBox_accepted()
{

}

void da_dialog::active_da_state()
{
    QByteArray array;

    array.append(0xAD);
    array.append(0xAC);

    emit da_trans_packet(array);
}

void da_dialog::sleep_da_state()
{
    QByteArray array;

    array.append(0x55);
    array.append(0xFF);
    qDebug() << "stop";
    emit da_trans_packet(array);
}

void da_dialog::on_net_notify_dac_hand_ok(bool state)
{
    uint64_t cycle_num;
    QByteArray da_packet;
    is_stop_pressed = false;
    union {
        qint32 qint32_d;
        struct BITS{
            quint8 B0:8;
            quint8 B1:8;
            quint8 B2:8;
            quint8 B3:8;
        } bit;
    } da_com;
    //    DELAY_MS(10);
    if (dac_summay_buffer.left_len > 1 ) {
        is_dac_hand_ok = state;
        if (dac_summay_buffer.left_len > 256 )
            cycle_num = 256;
        else if (dac_summay_buffer.left_len <= 256)
            cycle_num = dac_summay_buffer.left_len;
        qDebug() << cycle_num;
        da_packet.clear();
        for (quint64 j = 0; j < cycle_num; j ++) {
            da_com.qint32_d = dac_summay_buffer.buffer[ 256 * data_counter + j];
            da_packet.append(da_com.bit.B3);
            da_packet.append(da_com.bit.B2);
            da_packet.append(da_com.bit.B1);
            da_packet.append(da_com.bit.B0);
            //            qDebug("B0: 0x%x", da_com.bit.B0);
            //            qDebug("B1: 0x%x", da_com.bit.B1);
            //            qDebug("B2: 0x%x", da_com.bit.B2);
            //            qDebug("B3: 0x%x", da_com.bit.B3);
            dac_summay_buffer.left_len--;
        }
        data_counter++;
        qDebug() << "send data packet number is :" << data_counter << "| left:" << dac_summay_buffer.left_len;
        emit da_trans_packet(da_packet);
        da_packet.clear();
        if (dac_summay_buffer.left_len == 1) {
            sleep_da_state();
            free(dac_summay_buffer.buffer);
            data_counter = 0;
            ui->label_dac_state->setText("State: Send seelp cmd to host.");
        }
    }else {
        qDebug() << "recived stop ack.";

    }
}

void da_dialog::on_buttonBox_clicked(QAbstractButton *button)
{

}

void da_dialog::on_buttonBox_rejected()
{
    sleep_da_state();
    ui->label_dac_state->setText("State: Send seelp cmd to host.");
    timer->stop();
}

void da_dialog::on_pushButton_Send_clicked()
{

    if ( ui->lineEdit_path->text().isEmpty()) {
        QMessageBox::warning(this, "Warning","No file selected.");
        qDebug() << "empty path";
        this->show();
        return;
    }
    if ( ui->lineEdit_freq->text().isEmpty() ) {
        QMessageBox::warning(this, "Warning","DA freqency not set.");
        qDebug() << "empty freq";
        this->show();
        return;
    }
    cycle_num = ui->lineEdit_cycle_num->text().toUInt();
    run_da_out();
    timer->start(1000);

}

void da_dialog::run_da_out()
{
    QString file_name = ui->lineEdit_path->text();
    QByteArray stream_data;
    stream_data.clear();
    QFile *filp = new QFile(file_name);
    if ( !filp->open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QMessageBox::warning(this, "Warning","Open File Failed!");
        return;
    }
    quint64 da_len = 0;
    stream_data = filp->readAll();
    QList<QByteArray> data_sep = stream_data.split(',');

    dac_summay_buffer.left_len = da_len = data_sep.length();
    qDebug() << "read file data length: " << da_len;
    dac_summay_buffer.buffer = (quint32*)malloc(sizeof(quint32) * da_len * 4);
    data_counter = 0;
    for (quint64 i = 0; i < da_len; i ++) {
        dac_summay_buffer.buffer[i] = data_sep.at(i).toUInt();
    }
    qDebug() << "the dac length is :" << da_len;

    filp->close();
    delete filp;

    active_da_state();
    this->cycle_num--;
    ui->label_dac_state->setText("State: Send time: " + QString::number(this->cycle_num) + " to host.");
}

void da_dialog::on_pushButton_start_clicked()
{
    active_da_state();
    ui->label_dac_state->setText("State: Send active cmd to host.");
}

void da_dialog::DELAY_MS(int s)
{
    QTime dieTime = QTime::currentTime().addMSecs(s);
    while (QTime::currentTime()<dieTime);
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void da_dialog::on_pushButton_stop_clicked()
{
    sleep_da_state();
    dac_summay_buffer.left_len = 0;
    ui->label_dac_state->setText("State: Send sleep cmd to host.");
    timer->stop();
}
