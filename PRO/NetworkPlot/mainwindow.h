#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QHostInfo>
#include <QNetworkInterface>
#include "qcustomplot.h"
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <QMutex>
#include "netclientthread.h"
#include "com.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_set_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_close_remote_clicked();

    void on_double_data_prepared( float *array_datas, uint length );

    void on_plot_picture( double *array_datas );

    void on_pushButton_close_test_clicked();

    void on_pushButton_freq_set_clicked();

    void on_pushButton_gain_set_clicked();

    void on_pushButton_fs_set_clicked();

public:
    QCustomPlot *plot;
    long xcount;
    long xrange;

private:
    Ui::MainWindow *ui;
    QTcpServer *listener;
    QTcpSocket *socket;
    QFile *file;
    quint32 plot_count;
    double max_value;
    double min_value;
    QPen pen;
    NetClientThread *net_socket;
    unsigned long long byte_nums;
    QString get_local_ip();
    QMutex mutex;


};

#endif // MAINWINDOW_H
