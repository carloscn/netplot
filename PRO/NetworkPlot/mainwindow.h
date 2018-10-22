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
#include <qwt.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <math.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_grid.h>
#include <qwt_scale_draw.h>
#include <QDateTime>
#include "fftw3.h"
#define         CHANNEL_0           0
#define         CHANNEL_1           1
#define         CHANNEL_2           2
#define         CHANNEL_3           3
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

    void on_pushButton_sample_clicked();

    void on_pushButton_close_sample_clicked();

    void on_net_data_read(QByteArray block);

    void on_net_data_read(char* block, quint32 length);

    void on_net_plot_read(quint32 *block, quint32 length);

    void on_net_add_doc_list(QString);

    void on_net_file_size(double);


signals:

    void net_close_file();
    void net_enable_save(bool);

public:
    QCustomPlot *plot;
    long xcount;
    long xrange;

private:
    Ui::MainWindow *ui;
    QTcpServer *listener;
    QTcpSocket *socket;
    QFile *file;
    bool isSaveEnable;
    QDateTime current_time;
    quint32 plot_count;
    double max_value;
    double min_value;
    QPen pen;
    NetClientThread *net_socket;
    unsigned long long byte_nums;
    QMutex mutex;

    QwtPlotCurve* qwt_curve1_ch1;
    QwtPlotCurve* qwt_curve1_ch2;
    QwtPlotCurve* qwt_curve1_ch3;
    QwtPlotCurve* qwt_curve1_ch4;
    QwtPlotCurve* qwt_curve1_ch1_fft;
    QwtPlotCurve* qwt_curve1_ch2_fft;
    QwtPlotCurve* qwt_curve1_ch3_fft;
    QwtPlotCurve* qwt_curve1_ch4_fft;

    void qwt_plot_wave( unsigned int , double* , unsigned long);
    void init_qwt();
    QString get_doc_name();
    QString get_local_ip();
    void qwt_plot_fft( int, double *, int);



};

#endif // MAINWINDOW_H
