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
                                                     "Data Document(*.da *.flt)",
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
    is_over_time = true;

    is_over_time = false;
    timer->stop();
    qDebug() << "timer over time";
}

void da_dialog::on_buttonBox_accepted()
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
    quint64 da_freq = ui->lineEdit_freq->text().toInt();
    QString file_name = ui->lineEdit_path->text();
    QByteArray stream_data;
    union {
        qint32 qint32_d;
        struct BITS{
            quint8 B0:4;
            quint8 B1:4;
            quint8 B2:4;
            quint8 B3:4;
        } bit;
    } da_com;
    QFile *filp = new QFile(file_name);
    if ( !filp->open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QMessageBox::warning(this, "Warning","Open File Failed!");
        return;
    }
    quint64 da_len = 0;
    quint64 da_pac_n = 0;
    stream_data = filp->readAll();
    QList<QByteArray> data_sep = stream_data.split(',');
    da_len = data_sep.length();
    qint32 dac_data[da_len + 1];
    for (quint64 i = 0; i < da_len; i ++) {
        dac_data[i] = data_sep.at(i).toInt();
    }
    qDebug() << "the dac length is :" << da_len;
    // data load prepare send to host.
    // 1. judge the number of packet.
    da_pac_n = (quint64) ceil(da_len / 1000.0);
    qDebug() << da_pac_n;

    for (quint64 i = 0; i < da_pac_n; i++) {
        da_packet.clear();
        da_packet.append(0xAD);
        da_packet.append(0xAC);
        da_com.qint32_d = da_freq;
        da_packet.append(da_com.bit.B3);
        da_packet.append(da_com.bit.B2);
        da_packet.append(da_com.bit.B1);
        da_packet.append(da_com.bit.B0);
        if ( i < da_pac_n - 1) {
            da_com.qint32_d = 2000;
        }else {
            da_com.qint32_d = da_len - ((da_pac_n-1) * 1000.0);
        }
        da_packet.append(da_com.bit.B1);
        da_packet.append(da_com.bit.B0);
        for (quint64 j = 0; j < 1000; j ++) {
            da_com.qint32_d = dac_data[j+i*1000];
            da_packet.append(da_com.bit.B3);
            da_packet.append(da_com.bit.B2);
            da_packet.append(da_com.bit.B1);
            da_packet.append(da_com.bit.B0);
        }
        da_packet.append(0xBF);
        da_packet.append(0xBE);
        qDebug() << "send times :" << i << " data.";
        QElapsedTimer t;
        t.start();
        while(t.elapsed() <= 1);
        emit da_trans_packet(da_packet);
    }
    filp->close();
    delete filp;
}

void da_dialog::on_buttonBox_clicked(QAbstractButton *button)
{

}
