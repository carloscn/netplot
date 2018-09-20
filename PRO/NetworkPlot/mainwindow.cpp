#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    *  init the ui.plot class
    */
    QFont legendFont = font();  // start out with MainWindow's font..
    ui->plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->plot->legend->setVisible(true);
    legendFont.setPointSize(15); // and make a bit smaller for legend
    ui->plot->legend->setFont(legendFont);
    ui->plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->plot->addGraph();
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    ui->plot->xAxis->setRange(0, xrange);
    ui->plot->yAxis->setRange(-10, 10);
    /*
     *  init network
    */
    this->net_socket = new NetClientThread( ui->lineEdit_server_ip->text(), ui->lineEdit_port_num->text().toInt() );


    /*
     *  init file operation.
    */
    this->file  =   new QFile("../rom.hex");

    ui->lineEdit_host_ip->setText( this->get_local_ip() );

}

MainWindow::~MainWindow()
{
    on_pushButton_disconnect_clicked();
    this->net_socket->stop();
    free(this->net_socket);
    delete ui;
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
        //this->net_socket->start();
        if( this->file->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate) );
        connect( (QObject*)this->net_socket, SIGNAL( data_prepared(float*,uint) ), this, SLOT( on_double_data_prepared(float*,uint) ));
        connect( (QObject*)this->net_socket, SIGNAL(data_plot(double*)),this,SLOT(on_plot_picture(double*)));
        QMessageBox::information(this,"Info","Remote server connected.");
        ui->pushButton_set->setEnabled(false);
        ui->pushButton_disconnect->setEnabled(true);
    }
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    qDebug() << "listener has been closed!\n";
    disconnect( (QObject*)this->net_socket, SIGNAL( data_prepared(float*,uint) ), this, SLOT( on_double_data_prepared(float*,uint) ));
    disconnect( (QObject*)this->net_socket, SIGNAL(data_plot(double*)),this,SLOT(on_plot_picture(double*)));
    this->net_socket->set_disconnet();
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_set->setEnabled(true);
    file->close();
}

void MainWindow::on_pushButton_close_remote_clicked()
{
    this->net_socket->send_cmd_close_app();
    file->close();
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

void MainWindow::on_plot_picture( double *array_datas )
{
    qDebug() << "MainWindow@on_plot_picture() :> plot datas...";
    ui->plot->xAxis->setRange(0, 1024);
    ui->plot->yAxis->setRange(-3, 3 );
    ui->plot->graph(0)->data().data()->clear();
    for( int xcount = 0; xcount < 1024; xcount ++) {

        double data = *(array_datas + xcount);

        if( data < this->min_value ) {
            if( data < -10 ) {
                this->min_value = -10;
            }else {
                this->min_value = data;
            }
        }
        if( data > this->max_value ) {

            if ( this->max_value > 10 )
                this->max_value = 10;
            else
                this->max_value = data;
        }

        ui->plot->graph(0)->addData(xcount, data);
        if( xcount%3 == 0 )
            ui->plot->replot();
    }

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
    union {
        struct {
            uint8_t bit0_8;
            uint8_t bit8_16;
        } serper;
        uint16_t data;
    } kHzFreq;

    lineStr = ui->lineEdit_freq->text();
    kHzFreq.data = lineStr.toUInt();
    cmd[0] = CMD_SET_FREQ;
    cmd[1] = kHzFreq.serper.bit8_16;
    cmd[2] = kHzFreq.serper.bit0_8;

    this->net_socket->send_cmd_to_remote( cmd , 3);

}

void MainWindow::on_pushButton_gain_set_clicked()
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

    lineStr = ui->lineEdit_gain->text();
    kHzFreq.data = lineStr.toUInt();
    cmd[0] = CMD_SET_GAIN;
    cmd[1] = kHzFreq.serper.bit8_16;
    cmd[2] = kHzFreq.serper.bit0_8;

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
