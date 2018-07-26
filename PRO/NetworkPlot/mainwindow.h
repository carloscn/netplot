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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    QCustomPlot *plot;
    long xcount;
    long xrange;
private slots:
    void on_pushButton_set_clicked();

    void on_pushButton_disconnect_clicked();

    void on_new_connect();

    void on_read_message();


private:
    Ui::MainWindow *ui;
    QTcpServer *listener;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
