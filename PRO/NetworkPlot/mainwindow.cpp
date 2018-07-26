#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Network init;
    this->listener = new QTcpServer(this);
    //this->socket = new QTcpSocket(this);
    xcount = 0;
    xrange = 256;
    ui->plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->plot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(15); // and make a bit smaller for legend
    ui->plot->legend->setFont(legendFont);
    ui->plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    // 生成数据，画出的是抛物线
    ui->plot->addGraph();
    // 为坐标轴添加标签
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // 设置坐标轴的范围，以看到所有数据
    ui->plot->xAxis->setRange(0, xrange);
    ui-> plot->yAxis->setRange(-3, 3);

}

MainWindow::~MainWindow()
{
    on_pushButton_disconnect_clicked();
    delete ui;
}

void MainWindow::on_pushButton_set_clicked()
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
    int host_port  = ui->lineEdit_port_num->text().toInt();
    ui->lineEdit_host_ip->setText(host_ip);
    int ret = this->listener->listen(QHostAddress::Any,host_port);
    connect( this->listener,SIGNAL(newConnection()),this,SLOT(on_new_connect()) );


    if( !ret ) {
        qDebug() << this->listener->errorString();
    }else {
        qDebug() << "listener has been set up!\n";
    }
    ui->pushButton_set->setEnabled(false);
    ui->pushButton_disconnect->setEnabled(true);
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    this->listener->close();
    qDebug() << "listener has been closed!\n";
    ui->pushButton_disconnect->setEnabled(false);
    ui->pushButton_set->setEnabled(true);
}

void MainWindow::on_new_connect()
{
    this->socket = this->listener->nextPendingConnection();
    connect( this->socket, SIGNAL(readyRead()),this,SLOT(on_read_message()) );
    QMessageBox::information(this,"Info","A new client join.");
}

void MainWindow::on_read_message()
{
    QByteArray res;
    res.append( this->socket->readAll() );

    QList<QByteArray> ss = res.split(',');
    qDebug() << "rec :" << res;
    for( int xcount = 0; xcount < 256; xcount ++) {

        double data = ss.at(xcount).toDouble();
        ui->plot->graph(0)->addData(xcount, data);
        ui->plot->replot();
    }
    ui->plot->graph(0)->data().data()->clear();


}
