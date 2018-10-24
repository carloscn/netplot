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
    is_start_read_socket = false;
    net_socket->enable_socket_read(is_start_read_socket);
    connect( (QObject*)this->net_socket, SIGNAL( data_prepared(float*,uint) ), this, SLOT( on_double_data_prepared(float*,uint) ));
    connect( (QObject*)this->net_socket, SIGNAL(data_plot(double*)),this,SLOT(on_plot_picture(double*)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_ready(char*,quint32)),this,SLOT(on_net_data_read(char*,quint32)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_ready(QByteArray)),this,SLOT(on_net_data_read(QByteArray)));
    connect( (QObject*)this->net_socket, SIGNAL(net_data_plot(quint32*,quint32) ),this,SLOT(on_net_plot_read(quint32*,quint32)));
    connect( (QObject*)this->net_socket, SIGNAL(net_close_file() ),this,SLOT(on_net_close_file()));
    connect( (QObject*)this->net_socket, SIGNAL(net_add_doc_list(QString) ),this ,SLOT(on_net_add_doc_list(QString)));
    connect( this, SIGNAL(net_enable_save(bool) ),(QObject*)this->net_socket ,SLOT(on_net_enable_save(bool)));
    connect( (QObject*)this->net_socket, SIGNAL(net_file_size(double)), this, SLOT(on_net_file_size(double)));

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
    ui->checkBox_ch1_time->setChecked(true);
    ui->checkBox_ch1_fft->setChecked(true);
    ui->pushButton_close_test->setEnabled(false);
    ui->progressBar->setValue(0);
    isSaveEnable = true;
    on_pushButton_close_test_clicked();
    table_widget = new QTableWidget();
    table_widget->setRowCount(1000);
    table_widget->setColumnCount(2);
    table_widget->setHorizontalHeaderLabels(QStringList()<<tr("文件名")<<tr("进度"));
    table_widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_widget->verticalHeader()->hide();
    for (int i = 0; i < 1000; i ++) {
        //table_widget->setColumnWidth(i,80);
        table_widget->setRowHeight(i,20);
    }
    table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:10pt;}");
    file_count = 0;
    c_bar = new QProgressBar();
    ui->gridLayout->addWidget(table_widget);

    QProcess process;
    process.start("free -m");
    process.waitForFinished();
    process.readLine();
    QString str = process.readLine();
    str.replace("\n","");
    str.replace(QRegExp("( ){1,}")," ");
    auto lst = str.split(" ");
    double sum = lst[1].toDouble();
    double free = lst[6].toDouble();
    ui->progressBar->setValue((int)(free/sum));
    /*
    * Init qwt plugin.
    */
    init_qwt();
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
    QwtPlotGrid* grid_ch = new QwtPlotGrid();
    QwtPlotGrid* grid_fft = new QwtPlotGrid();

    brush2.setStyle(Qt::NoBrush);
    font.setBold(true);
    font.setItalic(false);
    title.setFont(font);
    title.setColor(QColor(25,25,112));
    title.setText("Channel Time Domain");
    //ui->qwt_ch->setTitle(title);
    title.setText("Channel Freqency Domain");
    //ui->qwt_fft->setTitle("Channel 01 FFT");
    ui->qwt_fft->setAxisTitle(2,"Hz");
    ui->qwt_ch->insertLegend(new QwtLegend(), QwtPlot::TopLegend);
    ui->qwt_fft->insertLegend(new QwtLegend(), QwtPlot::TopLegend);
    this->qwt_curve1_ch1 = new QwtPlotCurve("CH1");
    this->qwt_curve1_ch2 = new QwtPlotCurve("CH2");
    this->qwt_curve1_ch3 = new QwtPlotCurve("CH3");
    this->qwt_curve1_ch4 = new QwtPlotCurve("CH4");
    this->qwt_curve1_ch1_fft = new QwtPlotCurve("CH1 FFT");
    this->qwt_curve1_ch2_fft = new QwtPlotCurve("CH2 FFT");
    this->qwt_curve1_ch3_fft = new QwtPlotCurve("CH3 FFT");
    this->qwt_curve1_ch4_fft = new QwtPlotCurve("CH4 FFT");
    this->qwt_curve1_ch1->setPen(QColor(75,0,130),2,Qt::SolidLine);
    this->qwt_curve1_ch1_fft->setPen(QColor(75,0,130),2,Qt::SolidLine);
    this->qwt_curve1_ch2->setPen(QColor(124,205,124),2,Qt::SolidLine);
    this->qwt_curve1_ch2_fft->setPen(QColor(124,205,124),2,Qt::SolidLine);
    this->qwt_curve1_ch3->setPen(QColor(220,20,60),2,Qt::SolidLine);
    this->qwt_curve1_ch3_fft->setPen(QColor(220,20,60),2,Qt::SolidLine);
    this->qwt_curve1_ch4->setPen(QColor(0,0,0),2,Qt::SolidLine);
    this->qwt_curve1_ch4_fft->setPen(QColor(0,0,0),2,Qt::SolidLine);
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
    this->qwt_curve1_ch1->attach(ui->qwt_ch);
    this->qwt_curve1_ch2->attach(ui->qwt_ch);
    this->qwt_curve1_ch3->attach(ui->qwt_ch);
    this->qwt_curve1_ch4->attach(ui->qwt_ch);
    this->qwt_curve1_ch1_fft->attach(ui->qwt_fft);
    this->qwt_curve1_ch2_fft->attach(ui->qwt_fft);
    this->qwt_curve1_ch3_fft->attach(ui->qwt_fft);
    this->qwt_curve1_ch4_fft->attach(ui->qwt_fft);
    grid_ch->setPen(QColor(220,220,220),1);
    grid_fft->setPen(QColor(220,220,220),1);
    grid_ch->attach(ui->qwt_ch);
    grid_fft->attach(ui->qwt_ch);
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
        ui->pushButton_close_remote->setEnabled(true);
        ui->pushButton_close_sample->setEnabled(true);
        ui->pushButton_close_test->setEnabled(true);
        ui->pushButton_freq_set->setEnabled(true);
        ui->pushButton_fs_set->setEnabled(true);
        ui->pushButton_gain_set->setEnabled(true);
        ui->pushButton_sample->setEnabled(true);
    }
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

    net_socket->enable_socket_read(is_start_read_socket);
    if (is_start_read_socket == true) {
        ui->textBrowser->append("@System: start read socket..");
    }else {
        ui->textBrowser->append("@system: stop read socket..");
    }
    is_start_read_socket = !is_start_read_socket;


}

void MainWindow::on_double_data_prepared( float* array_datas, uint length)
{

}

void MainWindow::on_net_data_read(QByteArray block)
{

}

void MainWindow::on_net_data_read(char *block, quint32 length)
{

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
    if (isSaveEnable == true) {
        isSaveEnable = false;
        ui->pushButton_close_test->setText("打开存储");
        ui->textBrowser->append("@System: 系统关闭存储功能\n");
        ui->pushButton_close_test->setStyleSheet("background-color: rgb(170,0,255)");

    }else{
        isSaveEnable = true;
        ui->pushButton_close_test->setText("关闭存储");
        ui->textBrowser->append("@System: 系统开启存储功能\n");
        ui->pushButton_close_test->setStyleSheet("background-color: rgb(255,0,0)");
    }

    emit net_enable_save(isSaveEnable);

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
    uint8_t cmd[5];
    lineStr = ui->lineEdit_freq->text();
    uint8_t value = lineStr.toUInt();
    if (value > 50) {
        value = 50;
        QMessageBox::warning(this, "Warning", "设置失败，频率最高值为50KHz");
        return;
    }
    cmd[0] = CMD_SET_FREQ;
    cmd[1] = value;
    this->net_socket->send_cmd_to_remote( cmd , 2);
    ui->textBrowser->append("@System: 设定频率为" + QString::number(value) + ".");
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

    if (gain1 > 40) {
        gain1 = 40;
        QMessageBox::warning(this, "Warning", "设置失败，一级增益最大值为40");
        return;
    }

    if (gain2 > 40) {
        gain2 = 40;
        QMessageBox::warning(this, "Warning", "设置失败，二级增益最大值为40");
        return;
    }

    cmd[0] = CMD_SET_GAIN;
    cmd[1] = gain1;
    cmd[2] = gain2;
    qDebug("Gain1 : 0x%x, Gain2: 0x%x", gain1, gain2);
    this->net_socket->send_cmd_to_remote( cmd , 3);
    ui->textBrowser->append("@System: 设定一二级增益分别为" + QString::number(gain1) + ", " + QString::number(gain2));
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
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Write speed : 3.3MB/s...",0);
    ui->textBrowser->append("@System: Start Sample..");

}

void MainWindow::on_pushButton_close_sample_clicked()
{
    uint8_t   cmd[5];
    cmd[0] = CMD_ALL_STOP;
    this->net_socket->send_cmd_to_remote( cmd , 1);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("Closed sample...",0);
    ui->textBrowser->append("@System: Stop Sample..");
    emit net_close_file();
}

void MainWindow::on_net_plot_read(quint32 *block, quint32 length)
{
    qint32 channel_a[500];
    qint32 channel_b[500];
    qint32 channel_c[500];
    qint32 channel_d[500];

    double channel_a_d[500];
    double channel_b_d[500];
    double channel_c_d[500];
    double channel_d_d[500];
    //qDebug() << "slot plot!";

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
    for (quint32 i = 0; i < 500; i ++) {
        channel_a_d[i] = channel_a[i] / 100000;
        channel_b_d[i] = channel_b[i] / 100000;
        channel_c_d[i] = channel_c[i] / 100000;
        channel_d_d[i] = channel_d[i] / 100000;
        //qDebug() << "sample: " << channel_a_d[i];
    }
    if (ui->checkBox_ch1_time->isChecked()) {
        this->qwt_curve1_ch1->attach(ui->qwt_ch);
        qwt_plot_wave(CHANNEL_0, channel_a_d, 500);
    }else{
        this->qwt_curve1_ch1->detach();
    }
    if (ui->checkBox_ch2_time->isChecked()) {
        this->qwt_curve1_ch2->attach(ui->qwt_ch);
        qwt_plot_wave(CHANNEL_1, channel_b_d, 500);
    }else{
        this->qwt_curve1_ch2->detach();
    }

    if (ui->checkBox_ch3_time->isChecked()) {
        this->qwt_curve1_ch3->attach(ui->qwt_ch);
        qwt_plot_wave(CHANNEL_2, channel_c_d, 500);
    }else{
        this->qwt_curve1_ch3->detach();
    }


    if (ui->checkBox_ch4_time->isChecked()) {
        this->qwt_curve1_ch4->attach(ui->qwt_ch);
        qwt_plot_wave(CHANNEL_3, channel_d_d, 500);
    }else{
        this->qwt_curve1_ch4->detach();
    }


    if (ui->checkBox_ch1_fft->isChecked()) {
        this->qwt_curve1_ch1_fft->attach(ui->qwt_fft);
        qwt_plot_fft(CHANNEL_0, channel_a_d, 500);
    }else{
        this->qwt_curve1_ch1_fft->detach();
    }

    if (ui->checkBox_ch2_fft->isChecked()) {
        this->qwt_curve1_ch2_fft->attach(ui->qwt_fft);
        qwt_plot_fft(CHANNEL_1, channel_b_d, 500);
    }else{
        this->qwt_curve1_ch2_fft->detach();
    }

    if (ui->checkBox_ch3_fft->isChecked()) {
        this->qwt_curve1_ch3_fft->attach(ui->qwt_fft);
        qwt_plot_fft(CHANNEL_2, channel_c_d, 500);
    }else{
        this->qwt_curve1_ch3_fft->detach();
    }

    if (ui->checkBox_ch4_fft->isChecked()) {
        this->qwt_curve1_ch4_fft->attach(ui->qwt_fft);
        qwt_plot_fft(CHANNEL_3, channel_d_d, 500);
    }else{
        this->qwt_curve1_ch4_fft->detach();
    }

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
    for( quint64 i = 0; i < NP/2-1 ; i++ ){
        QPointF point;
        current_fft_value = sqrt(out1_c[i][0] * out1_c[i][0] + out1_c[i][1] * out1_c[i][1]);
        point.setX((210000/500)*i);
        if ( i < 2 )
            point.setY(0);
        else
            point.setY(current_fft_value);
        vector.append(point);
    }
    QwtPointSeriesData* series = new QwtPointSeriesData(vector);
    if (channel == CHANNEL_0) {
        qwt_curve1_ch1_fft->setData(series);
    } else if (channel == CHANNEL_1) {
        qwt_curve1_ch2_fft->setData(series);
    } else if (channel == CHANNEL_2) {
        qwt_curve1_ch3_fft->setData(series);
    } else if (channel == CHANNEL_3) {
        qwt_curve1_ch4_fft->setData(series);
    }
    ui->qwt_fft->replot();
    ui->qwt_fft->show();
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
        qwt_curve1_ch1->setData(series);
        break;
    case CHANNEL_1:
        qwt_curve1_ch2->setData(series);
        break;
    case CHANNEL_2:
        qwt_curve1_ch3->setData(series);
        break;
    case CHANNEL_3:
        qwt_curve1_ch4->setData(series);
        break;

    default:

        break;
    }
    ui->qwt_ch->replot();
    ui->qwt_ch->show();
}
void MainWindow::on_net_add_doc_list(QString filename)
{
    QProgressBar *bar = new QProgressBar();
    QString str_file_name = filename.mid(8,10);
    QLabel *label = new QLabel(".."+str_file_name);

    ui->textBrowser->append("@System: 已建立"+ filename + "文件");
    table_widget->setCellWidget(file_count,0,label);
    table_widget->setCellWidget(file_count,1,bar);

    c_bar = bar;


    file_count++;
    if (file_count == 1000) {
        file_count = 0;
    }

}

void MainWindow::on_net_file_size(double percent)
{
    //ui->progressBar->setValue((int)(percent*100));
    c_bar->setValue((int)(percent*100));
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->textBrowser->clear();
}
