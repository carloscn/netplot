#ifndef NETCLIENTTHREAD_H
#define NETCLIENTTHREAD_H

#include <QThread>
#include <QtNetwork>
#include <QByteArray>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QString>
#include <QDebug>
#include "com.h"

struct bcd_sper_t{
    uint8_t bit24_32;
    uint8_t bit16_24;
    uint8_t bit8_16;
    uint8_t bit0_8;
};
union bcd_code_t{

    struct bcd_sper_t bcdSperUint8;
    float fd;
};


class NetClientThread:public QThread
{
    Q_OBJECT
public:
    NetClientThread( QString server_ip, int server_port );
    void stop();
    bool set_connect( QString server_ip, int server_port );
    void set_disconnet();
    void send_cmd_close_app( void );
    void bcd_encoding( float , uint8_t * );
    float bcd_decoding( uint8_t * );
    union bcd_code_t bcdCode;
    void send_cmd_to_remote( uint8_t *cmd, quint16 length );

protected:
    void run();

public  slots:
    void on_read_message();

signals:
    void data_prepared( float* array_datas, uint length );
    void data_plot( double* array_datas );

private :

    QTcpServer *server;
    QTcpSocket *socket;
    bool data_prepared_flag;
    double *data_buffer;
    double *data_draw_buffer;
    unsigned long count;



};

#endif // NETCLIENTTHREAD_H
