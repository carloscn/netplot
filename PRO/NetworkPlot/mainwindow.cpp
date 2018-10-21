/**
 * \brief   This project about ds18b20 on common channels DS18B20 .
 *
 * \License  THIS FILE IS PART OF MULTIBEANS PROJECT;
 *           all of the files  - The core part of the project;
 *           THIS PROGRAM IS NOT FREE SOFTWARE, NEED MULTIBEANS ORG LIC;
 *           YOU SHOULD HAVE RECEIVED A COPY OF WTFPL LICENSE UTIL 5/1/2020
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
 *           * Copyright (c) 2013-2018 MULTIBEANS ORG. http://www.mltbns.com/
 *           * Copyright (c) 2018 Wei Haochen(Carlos Wei: # whc.mlt@qq.com).
 *
 *  \note    void.
 ****************************************************************************/
/*                                                                          */
/*  @File       : main.c                                                    */
/*  @Revision   : Ver 1.0.                                                  */
/*  @Date       : 2018.09.xx Realse.                                        */
/*  @Belong     : PROJECT.                                                  */
/*  @GitHub     :                                                           */
/*  @ASCII : (GBK/GB2312) in Linux amd64. AC6                               */
/****************************************************************************/
/*  @Attention:                                                             */
/*  ---------------------------------------------------------------------   */
/*  |    Data    |  Behavior |     Offer     |          Content         |   */
/*  |------------|-----------|---------------|--------------------------|   */
/*  | 2018.08.09 |   create  |Carlos Wei(M)  | add all device driver.   |   */
/*  ---------------------------------------------------------------------   */
/*                                                            MULTIBEANS.   */
/****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define             SERVER_IP       "192.168.1.176"
#define             SERVER_PORT     8322
#define             CUSTOM_PLOT     0
#define             QWT_PLOT        1
#define             N               1024
double ss[N];
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Network Plot");
    /*
    *  init the values of class
    */
    this->plot_count  = 0;
    this->max_value =   -999.0;
    this->min_value =   999.0;
    xcount = 0;
    xrange = 1024;
    this->byte_nums = 0;
    /*
     *  init network
    */
    this->net_socket = new NetClientThread( ui->lineEdit_server_ip->text(), ui->lineEdit_port_num->text().toInt() );
    connect( (QObject*)this->net_socket, SIGNAL( data_prepared(float*,uint) ), this, SLOT( on_double_data_prepared(float*,uint) ));
    connect( (QObject*)this->net_socket, SIGNAL(data_plot(double*)),this,SLOT(on_plot_picture(double*)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_ready(char*,quint32)),this,SLOT(on_net_data_read(char*,quint32)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_ready(QByteArray)),this,SLOT(on_net_data_read(QByteArray)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_plot(quint32*,quint32) ),this,SLOT(on_net_plot_read(quint32*,quint32)));
    connect( (QObject*)this->net_socket, SIGNAL(net_close_file() ),this,SLOT(on_net_close_file()));
    /*
    * Init qwt plugin.
    */
    this->init_qwt();

    this->ch01_file = new QFile(this->get_doc_name());
    this->ch02_file = new QFile(this->get_doc_name());
    this->ch03_file = new QFile(this->get_doc_name());
    this->ch03_file = new QFile(this->get_doc_name());
    ui->lineEdit_host_ip->setText( this->get_local_ip() );

    /*
     * ui state.
     **/
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_close_remote->setEnabled(false);
    ui->pushButton_close_sample->setEnabled(false);
    ui->pushButton_close_test->setEnabled(true);
    ui->pushButton_freq_set->setEnabled(false);
    ui->pushButton_fs_set->setEnabled(false);
    ui->pushButton_gain_set->setEnabled(false);
    ui->pushButton_sample->setEnabled(false);
}

MainWindow::~MainWindow()
{
    on_pushButton_disconnect_clicked();
    this->net_socket->stop();
    free(this->net_socket);
    emit net_close_file();
    delete ui;
}

void MainWindow::init_qwt()
{
    QwtText title;
    QFont font;
    double sin_table[1024];
    QBrush brush2(QColor(128,128,128));
    QwtPlotGrid* grid_ch1 = new QwtPlotGrid();
    QwtPlotGrid* grid_ch2 = new QwtPlotGrid();
    QwtPlotGrid* grid_ch3 = new QwtPlotGrid();
    QwtPlotGrid* grid_ch4 = new QwtPlotGrid();
    QwtPlotGrid* grid_ch1_fft = new QwtPlotGrid();
    QwtPlotGrid* grid_ch2_fft = new QwtPlotGrid();
    QwtPlotGrid* grid_ch3_fft = new QwtPlotGrid();
    QwtPlotGrid* grid_ch4_fft = new QwtPlotGrid();

    brush2.setStyle(Qt::NoBrush);
    font.setBold(true);
    font.setItalic(false);
    title.setFont(font);
    title.setColor(QColor(25,25,112));
    title.setText("Channel 1");
    ui->qwt_ch1->setTitle(title);
    title.setText("Channel 2");
    ui->qwt_ch2->setTitle(title);
    title.setText("Channel 3");
    ui->qwt_ch3->setTitle(title);
    title.setText("Channel 4");
    ui->qwt_ch4->setTitle(title);
    ui->qwt_ch1_fft->setTitle("ch01 fft");
    ui->qwt_ch2_fft->setTitle("ch02 fft");
    ui->qwt_ch3_fft->setTitle("ch03 fft");
    ui->qwt_ch4_fft->setTitle("ch04 fft");
    ui->qwt_ch1->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch1->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch1_fft->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch1_fft->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch2->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch2->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch2_fft->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch2_fft->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch3->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch3->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch3_fft->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch3_fft->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch4->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch4->enableAxis(QwtPlot::xTop,true);
    ui->qwt_ch4_fft->enableAxis(QwtPlot::yRight,true);
    ui->qwt_ch4_fft->enableAxis(QwtPlot::xTop,true);
    this->qwt_curve1_ch1 = new QwtPlotCurve("Curve 1");
    this->qwt_curve1_ch2 = new QwtPlotCurve("Curve 2");
    this->qwt_curve1_ch3 = new QwtPlotCurve("Curve 3");
    this->qwt_curve1_ch4 = new QwtPlotCurve("Curve 4");
    this->qwt_curve1_ch1_fft = new QwtPlotCurve("Curve FFT1");
    this->qwt_curve1_ch2_fft = new QwtPlotCurve("Curve FFT2");
    this->qwt_curve1_ch3_fft = new QwtPlotCurve("Curve FFT3");
    this->qwt_curve1_ch4_fft = new QwtPlotCurve("Curve FFT4");
    this->qwt_curve1_ch1->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch1_fft->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch2->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch2_fft->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch3->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch3_fft->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch4->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch4_fft->setPen(QColor(0,0,128),2,Qt::SolidLine);
    this->qwt_curve1_ch1->setBrush(brush2);
    this->qwt_curve1_ch2->setBrush(brush2);
    this->qwt_curve1_ch3->setBrush(brush2);
    this->qwt_curve1_ch4->setBrush(brush2);
    this->qwt_curve1_ch1_fft->setBrush(brush2);
    this->qwt_curve1_ch2_fft->setBrush(brush2);
    this->qwt_curve1_ch3_fft->setBrush(brush2);
    this->qwt_curve1_ch4_fft->setBrush(brush2);
    this->qwt_curve1_ch1->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch2->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch3->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch4->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch1_fft->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch2_fft->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch3_fft->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch4_fft->setCurveAttribute(QwtPlotCurve::Fitted, true);
    this->qwt_curve1_ch1->attach(ui->qwt_ch1);
    this->qwt_curve1_ch2->attach(ui->qwt_ch2);
    this->qwt_curve1_ch3->attach(ui->qwt_ch3);
    this->qwt_curve1_ch4->attach(ui->qwt_ch4);
    this->qwt_curve1_ch1_fft->attach(ui->qwt_ch1_fft);
    this->qwt_curve1_ch2_fft->attach(ui->qwt_ch2_fft);
    this->qwt_curve1_ch3_fft->attach(ui->qwt_ch3_fft);
    this->qwt_curve1_ch4_fft->attach(ui->qwt_ch4_fft);
    grid_ch1->setPen(QColor(222,222,222),1);
    grid_ch2->setPen(QColor(222,222,222),1);
    grid_ch3->setPen(QColor(222,222,222),1);
    grid_ch4->setPen(QColor(222,222,222),1);
    grid_ch1_fft->setPen(QColor(222,222,222),1);
    grid_ch2_fft->setPen(QColor(222,222,222),1);
    grid_ch3_fft->setPen(QColor(222,222,222),1);
    grid_ch4_fft->setPen(QColor(222,222,222),1);
    grid_ch1->attach(ui->qwt_ch1);
    grid_ch2->attach(ui->qwt_ch2);
    grid_ch3->attach(ui->qwt_ch3);
    grid_ch4->attach(ui->qwt_ch4);
    grid_ch1_fft->attach(ui->qwt_ch1_fft);
    grid_ch2_fft->attach(ui->qwt_ch2_fft);
    grid_ch3_fft->attach(ui->qwt_ch3_fft);
    grid_ch4_fft->attach(ui->qwt_ch4_fft);
    for( int i = 0; i < N; i ++ )
        sin_table[i] = 50* sin(2*M_PI*(5.0/N)*i) + 20 * cos(2*M_PI*(10.0/N)*i) + 60 * cos(2*M_PI*(15.0/N)*i);
    qwt_plot_wave(CHANNEL_0,sin_table,N);
    qwt_plot_fft(CHANNEL_0, sin_table, N);
    for( int i = 0; i < N; i ++ )
        sin_table[i] = 50* sin(2*M_PI*(2/N)*i + (M_PI)/4.0);
    qwt_plot_wave(CHANNEL_1,sin_table,N);
    qwt_plot_fft(CHANNEL_1, sin_table, N);
    for( int i = 0; i < N; i ++ )
        sin_table[i] = 50* sin(2*M_PI*(2/N)*i + (2*M_PI)/4.0);
    qwt_plot_wave(CHANNEL_2,sin_table,N);
    qwt_plot_fft(CHANNEL_2, sin_table, N);
    for( int i = 0; i < N; i ++ )
        sin_table[i] = 50* sin(2*M_PI*(2/N)*i + (3*M_PI)/4.0);
    qwt_plot_wave(CHANNEL_3,sin_table,N);
    qwt_plot_fft(CHANNEL_3, sin_table, N);

    ui->tabWidget->setCurrentIndex(0);
}
QString MainWindow::get_doc_name()
{
    QString name;
    name.clear();
    this->current_time = QDateTime::currentDateTime();
    name = this->current_time.toString("MM-dd-hh-mm-ss");
    name.append(".hex");
    return name;
}
void MainWindow::qwt_plot_wave(unsigned int channel, double *data, unsigned long length)
{

    QVector<QPointF> vector;
    for( quint64 i = 0; i < length ; i++ ){
        QPointF point;
        point.setX( i );
        point.setY( data[i] );
        vector.append(point);
    }
    QwtPointSeriesData* series = new QwtPointSeriesData(vector);

    switch (channel) {

    case CHANNEL_0:
        this->qwt_curve1_ch1->setData(series);
        ui->qwt_ch1->replot();
        ui->qwt_ch1->show();
        break;
    case CHANNEL_1:
        this->qwt_curve1_ch2->setData(series);
        ui->qwt_ch2->replot();
        ui->qwt_ch2->show();
        break;
    case CHANNEL_2:
        this->qwt_curve1_ch3->setData(series);
        ui->qwt_ch3->replot();
        ui->qwt_ch3->show();
        break;
    case CHANNEL_3:
        this->qwt_curve1_ch4->setData(series);
        ui->qwt_ch4->replot();
        ui->qwt_ch4->show();
        break;

    default:

        break;
    }

}

void MainWindow::on_pushButton_set_clicked()
{
    bool ret;

    ret = net_socket->set_connect( ui->lineEdit_server_ip->text(), ui->lineEdit_port_num->text().toInt());
    if( !ret ) {
        qDebug("socket Connection failed!!");
        QMessageBox::warning(this,"Info","Remote server connected failed.");
        ui->pushButton_set->setEnabled(true);
        ui->pushButton_disconnect->setEnabled(false);
    }else {
        qDebug("socket conncetion succussful.");
        QMessageBox::information(this,"Info","Remote server connected.");
        ui->pushButton_set->setEnabled(false);
        ui->pushButton_disconnect->setEnabled(true);
    }
    ui->pushButton_close_remote->setEnabled(true);
    ui->pushButton_close_sample->setEnabled(true);
    ui->pushButton_close_test->setEnabled(true);
    ui->pushButton_freq_set->setEnabled(true);
    ui->pushButton_fs_set->setEnabled(true);
    ui->pushButton_gain_set->setEnabled(true);
    ui->pushButton_sample->setEnabled(true);

}

void MainWindow::on_pushButton_disconnect_clicked()
{
    qDebug() << "listener has been closed!\n";
    this->net_socket->set_disconnet();
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_set->setEnabled(true);
    //file->close();
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_close_remote->setEnabled(false);
    ui->pushButton_close_sample->setEnabled(false);
    ui->pushButton_close_test->setEnabled(true);
    ui->pushButton_freq_set->setEnabled(false);
    ui->pushButton_fs_set->setEnabled(false);
    ui->pushButton_gain_set->setEnabled(false);
    ui->pushButton_sample->setEnabled(false);
}

void MainWindow::on_pushButton_close_remote_clicked()
{

}

void MainWindow::on_double_data_prepared( float* array_datas, uint length)
{
    this->mutex.lock();
    //qDebug() << "MainWindow@on_double_data_prepared() :> data_prepared...";
    this->file->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out( this->file );
    for( int i = 0; i < length; i ++ ) {
        out << QString::number(*(array_datas + i)) << ',';
    }
    out << '&' << endl;
    this->file->close();
    byte_nums = byte_nums + length;
    qDebug() <<  "write: " << length << " double datas to hard disk.";
    ui->textBrowser->append("recv double data :" + QString::number(byte_nums));
    this->mutex.unlock();
}

void MainWindow::on_net_data_read(QByteArray block)
{
    int ret;
    QFile *file = new QFile("../adc.hex");
    QDataStream out(&block, QIODevice::ReadWrite);
    QDataStream in(file);
    ret = file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    qDebug() << "write size : " << block.size();
    if (!ret) {
        qDebug() << "Open failed\n";
        return;
    }
    in << block;
    file->close();
}

void MainWindow::on_net_data_read(char *block, quint32 length)
{

    int ret;
    QFile *file = new QFile("../adc.hex");
    QDataStream in(file);

    ret = file->open(QIODevice::WriteOnly | QIODevice::Append);
    if (!ret) {
        qDebug() << "Open failed\n";
        return;
    }
    for (int i = 0; i < length - 4; i ++) {
        in << *(block + i);
    }
    file->close();
}

void MainWindow::on_plot_picture(double *array_datas)
{

}
QString MainWindow::get_local_ip()
{
    QString host_ip;
    QList<QHostAddress> AddressList = QNetworkInterface::allAddresses();
    foreach(QHostAddress address, AddressList){
        if(address.protocol() == QAbstractSocket::IPv4Protocol &&
                address != QHostAddress::Null &&
                address != QHostAddress::LocalHost){
            if (address.toString().contains("127.0.")){
                continue;
            }
            host_ip = address.toString();
            break;
        }
    }
    return host_ip;
}

void MainWindow::on_pushButton_close_test_clicked()
{

    float data = 155.6f;
    float res = 0.0;
    uint8_t test[4];

    this->net_socket->bcdCode.fd = 66.12f;
    res = this->net_socket->bcd_decoding(&this->net_socket->bcdCode.bcdSperUint8.bit24_32);
    qDebug() << "data is " << res;

}

/*  | header1 | header2 | length | cmd_type | cmd_high_8 bits | cmd_low_8 bits | checksum |

    all of uint8 type.

    for example:
    cmd 8-bits serial:
    "\xAA\xBB\x04\xA0\xFF\xFB\xB1"
    header1  : 0xAA
    header2  : 0xBB
    length   : 0x04
    cmd_type : 0xA0
    cmd_h_8  : 0xFF
    cmd_l_8  : 0xFB
    check_sum: 0xB1

*/
void MainWindow::on_pushButton_freq_set_clicked()
{
    QString lineStr;
    uint8_t   cmd[5];

    lineStr = ui->lineEdit_freq->text();
    cmd[0] = CMD_SET_FREQ;
    cmd[1] = lineStr.toUInt();
    this->net_socket->send_cmd_to_remote( cmd , 2);
}

void MainWindow::on_pushButton_gain_set_clicked()
{
    QString lineStr1;
    QString lineStr2;
    uint8_t   cmd[5];
    uint8_t gain1, gain2;

    lineStr1 = ui->lineEdit_gain_1->text();
    lineStr2 = ui->lineEdit_gain_2->text();
    gain1 = lineStr1.toUInt();
    gain2 = lineStr2.toUInt();
    cmd[0] = CMD_SET_GAIN;
    cmd[1] = gain1;
    cmd[2] = gain2;
    qDebug("Gain1 : 0x%x, Gain2: 0x%x", gain1, gain2);
    this->net_socket->send_cmd_to_remote( cmd , 3);
}

void MainWindow::on_pushButton_fs_set_clicked()
{
    QString lineStr;
    uint8_t   cmd[5];
    union {
        struct {
            uint8_t bit0_8;
            uint8_t bit8_16;
        } serper;
        uint16_t data;
    } kHzFreq;

    lineStr = ui->lineEdit_fs->text();
    kHzFreq.data = lineStr.toUInt();
    cmd[0] = CMD_SET_FS;
    cmd[1] = kHzFreq.serper.bit8_16;
    cmd[2] = kHzFreq.serper.bit0_8;
    this->net_socket->send_cmd_to_remote( cmd , 3);
}

void MainWindow::on_pushButton_sample_clicked()
{
    uint8_t   cmd[5];

    cmd[0] = CMD_ALL_START;
    this->net_socket->send_cmd_to_remote( cmd , 1);
}

void MainWindow::on_pushButton_close_sample_clicked()
{
    uint8_t   cmd[5];
    cmd[0] = CMD_ALL_STOP;
    this->net_socket->send_cmd_to_remote( cmd , 1);
    emit net_close_file();
}

void MainWindow::on_net_plot_read(quint32 *block, quint32 length)
{
    qint32 channel_a[500];
    qint32 channel_b[500];
    qint32 channel_c[500];
    qint32 channel_d[500];
    qDebug() << "slot plot!";

    for (quint32 i = 0; i < 500; i ++) {
#if 0
        channel_a[i] = ((qint32)(~block[i] + 1) & (0xFFFFFF)) * (((block[i] & 0x800000) >> 23)?1:-1);
        channel_b[i] = ((qint32)(~block[500+i] + 1) & (0xFFFFFF)) * (((block[500+i] & 0x800000) >> 23)?1:-1);
        channel_c[i] = ((qint32)(~block[2*500+i] + 1) & (0xFFFFFF))* (((block[2*500+i] & 0x800000) >> 23)?1:-1);
        channel_d[i] = ((qint32)(~block[3*500+i] + 1) & (0xFFFFFF))* (((block[3*500+i] & 0x800000) >> 23)?1:-1);
#elif 0
        channel_a[i] = (qint32) (~(block[i] - 1))      ^(1<<23);// & (0xFFFFFF)) * (((block[i] & 0x800000) >> 23)?1:-1);
        channel_b[i] = (qint32) (~(block[500+i] - 1))  ^(1<<23);// & (0xFFFFFF)) * (((block[500+i] & 0x800000) >> 23)?1:-1);
        channel_c[i] = (qint32) (~(block[2*500+i] - 1))^(1<<23);// & (0xFFFFFF))* (((block[2*500+i] & 0x800000) >> 23)?1:-1);
        channel_d[i] = (qint32) (~(block[3*500+i] - 1))^(1<<23);// & (0xFFFFFF))* (((block[3*500+i] & 0x800000) >> 23)?1:-1);
#endif
        channel_a[i] = (qint32) block[i] << 8;// & (0xFFFFFF)) * (((block[i] & 0x800000) >> 23)?1:-1);
        channel_b[i] = (qint32) block[500+i] << 8;// & (0xFFFFFF)) * (((block[500+i] & 0x800000) >> 23)?1:-1);
        channel_c[i] = (qint32) block[2*500+i] << 8;// & (0xFFFFFF))* (((block[2*500+i] & 0x800000) >> 23)?1:-1);
        channel_d[i] = (qint32) block[3*500+i] << 8;// & (0xFFFFFF))* (((block[3*500+i] & 0x800000) >> 23)?1:-1);
    }

    double channel_a_d[500];
    double channel_b_d[500];
    double channel_c_d[500];
    double channel_d_d[500];

    for (quint32 i = 0; i < 500; i ++) {

        channel_a_d[i] = channel_a[i] / 100000;
        channel_b_d[i] = channel_b[i] / 100000;
        channel_c_d[i] = channel_c[i] / 100000;
        channel_d_d[i] = channel_d[i] / 100000;
        //qDebug() << "sample: " << channel_a_d[i];
    }

    qwt_plot_wave(CHANNEL_0, channel_a_d, 500);
    qwt_plot_fft(CHANNEL_0, channel_a_d, 500);
    qwt_plot_wave(CHANNEL_1, channel_b_d, 500);
    qwt_plot_fft(CHANNEL_1, channel_b_d, 500);
    qwt_plot_wave(CHANNEL_2, channel_c_d, 500);
    qwt_plot_fft(CHANNEL_2, channel_c_d, 500);
    qwt_plot_wave(CHANNEL_3, channel_d_d, 500);
    qwt_plot_fft(CHANNEL_3, channel_d_d, 500);

}

void MainWindow::qwt_plot_fft(int channel, double *rom, int NP)
{
    fftwf_plan p;
    fftwf_complex  *in1_c = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex)* NP);;
    fftwf_complex  *out1_c = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex) * NP);
    double* draw_buffer = (double*)malloc(sizeof(double)*NP);
    QVector<QPointF> vector;
    double current_fft_value;

    for (int i = 0; i < NP; i ++) {
        in1_c[i][0] = *(rom + i);
        in1_c[i][1] = 0;
    }
    p = fftwf_plan_dft_1d(NP, in1_c, out1_c, FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(p);
    fftwf_destroy_plan(p);
    fftwf_cleanup();
    memset(draw_buffer, 0, NP);
    for( quint64 i = 0; i < NP/4-1 ; i++ ){
        QPointF point;
        current_fft_value = sqrt(out1_c[i][0] * out1_c[i][0] + out1_c[i][1] * out1_c[i][1]);
        point.setX(i);
        point.setY(current_fft_value);
        vector.append(point);
    }
    QwtPointSeriesData* series = new QwtPointSeriesData(vector);
    if (channel == CHANNEL_0) {
        qwt_curve1_ch1_fft->setData(series);
        ui->qwt_ch1_fft->replot();
        ui->qwt_ch1_fft->show();
    } else if (channel == CHANNEL_1) {
        qwt_curve1_ch2_fft->setData(series);
        ui->qwt_ch2_fft->replot();
        ui->qwt_ch2_fft->show();
    } else if (channel == CHANNEL_2) {
        qwt_curve1_ch3_fft->setData(series);
        ui->qwt_ch3_fft->replot();
        ui->qwt_ch3_fft->show();
    } else if (channel == CHANNEL_3) {
        qwt_curve1_ch4_fft->setData(series);
        ui->qwt_ch4_fft->replot();
        ui->qwt_ch4_fft->show();
    }
}

