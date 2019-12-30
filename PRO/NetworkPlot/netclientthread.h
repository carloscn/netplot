#ifndef NETCLIENTTHREAD_H
#define NETCLIENTTHREAD_H

#include <QThread>
#include <QMutex>
#include <QtNetwork>
#include <QByteArray>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QString>
#include <QDebug>
#include "com.h"
#include "ringbuffer.h"
#include "filemanager.h"
#define             ONE_PACKET_LENGTH           (8010ul)
#define             ADC_MODE                    0
#define             DAC_MODE                    1

struct bcd_sper_t{
    uint8_t bit24_32;
    uint8_t bit16_24;
    uint8_t bit8_16;
    uint8_t bit0_8;
};
union bcd_code_t{

    struct bcd_sper_t bcdSperUint8;
    float fd;
    uint32_t uintd;
};

struct data_packet_t{

    quint32 number;
    quint32 da;
    quint32 db;
    quint32 dc;
    quint32 dd;

};


class NetClientThread:public QThread
{
    Q_OBJECT
public:
    NetClientThread( QString server_ip, int server_port );
    ~NetClientThread();

    void stop();
    bool set_connect( QString server_ip, int server_port );
    void set_disconnet();
    void send_cmd_close_app( void );
    void bcd_encoding( float , uint8_t * );
    float bcd_decoding( uint8_t * );
    union bcd_code_t bcdCode;
    void send_cmd_to_remote( uint8_t *cmd, quint16 length );
    void enable_socket_read(bool);
    void case_1(quint8* buffer, quint64 length, quint32 vector_counter);
    void case_1(quint8* buffer, quint64 length);
    void socket_write_byte_array(QByteArray array);
    bool is_network_setup();
protected:
    void run();

private slots:
    void on_read_message();
    void on_net_close_file();
    void on_net_enable_save(bool);
    void on_file_manager_add_doc_list(QString);
    void on_file_manager_file_size(double);
    void on_adc_dac_mode_set(int);

signals:

    void data_prepared( float* array_datas, uint length );

    void data_plot( double* array_datas );

    void net_data_ready(QByteArray block);

    void net_data_ready(char* block, quint32 length);

    void net_data_plot(quint32 *block, quint32 length);

    void net_data_save_to_disk(quint8*, quint64);

    void net_data_save_to_disk(QByteArray);

    void net_add_doc_list(QString);

    void net_file_size(double);

    void net_lic_check_failed();

    void net_notify_dac_hand_ok(bool);

private :
    struct data_packet_t *data_packet;
    QMutex *mutex;
    QTcpServer *server;
    QTcpSocket *socket;
    bool data_prepared_flag;
    unsigned long count;
    bool is_head;
    bool is_packet_num;
    QByteArray buffer;
    quint32 buffer_index;
    quint64 packet_number;
    QByteArray array_rom;
    quint32 array_length = 0;
    quint32 head_index = 0;
    quint32 vector_counter = 0;
    quint64 read_counter = 0;
    quint8* socket_buffer;
    quint8 left_rom[8010];
    quint8 right_rom[8010];
    quint64 left_length;
    quint64 right_length;
    quint64 displat_counter=0;
//    FileManager *file_ctr;
    quint64 kcount;
    bool isEnableSave;
    quint8 plot_buffer[ONE_PACKET_LENGTH];
    quint32 channel_data[2000];
    quint32 channel_data_display[2000];

    bool is_enable_socket_read;


    bool key_check;
    int adc_dac_mode;

public:
    FileManager *file_ctr;
    FileManager *file_ctr_1;
    FileManager *file_ctr_2;
    FileManager *file_ctr_3;
    FileManager *file_ctr_4;
    quint16 sample_level;

private:

    qint8 check_packet(quint8* array, quint64 length);
    void check_packet(QByteArray array);
    bool deal_true_packet(QByteArray array);

    void case_2(quint8* buffer, quint64 length, quint8 *left_buffer, quint64 *left_length);
    void case_3(quint8 *socket_buffer, quint64 length, quint8 *right_buffer, quint64 right_length);
    void case_4(quint8* buffer, quint64 length);
    QString gethostMac();
    bool check_key();




};

#endif // NETCLIENTTHREAD_H
