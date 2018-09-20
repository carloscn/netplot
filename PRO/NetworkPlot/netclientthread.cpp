#include "netclientthread.h"



NetClientThread::NetClientThread( QString server_ip, int server_port )
{
    this->data_prepared_flag = false;
    this->socket = new QTcpSocket();
    this->server = new QTcpServer();
    this->count = 0;
    //this->data_buffer = new double[];
    this->data_draw_buffer = new double[1024];
}

bool NetClientThread::set_connect(QString server_ip, int server_port)
{
    qDebug() << "netclientread@set_connect() >: seting the connection...." ;
    this->socket->connectToHost( server_ip, server_port , QIODevice::ReadWrite );

    QObject::connect((QObject*) this->socket,SIGNAL(readyRead()),(QObject*)this,SLOT(on_read_message()));
    if( !this->socket->waitForConnected(30000) ) {
        qDebug("netclientread@set_connect() >: socket Connection failed!!");
        return false;
    }else {
        qDebug("netclientread@set_connect() >: socket conncetion succussful.");
        return true;
    }
}
void NetClientThread::set_disconnet()
{
    this->socket->flush();
    this->socket->close();
}
void NetClientThread::on_read_message()
{
#if false
    QByteArray block;
    QDataStream iostream(&block,QIODevice::ReadOnly);
    float *stream_code;
    uint16_t  code_length = 32666;
    float header[3];

    iostream.setVersion(QDataStream::Qt_4_0);
    iostream.setFloatingPointPrecision(QDataStream::SinglePrecision);
    block.clear();
    block.append( this->socket->read(1024) );

    iostream >> header[0];
    iostream >> header[1];
    iostream >> header[2];

    if( header[0] == 99.9f && header[2] == 99.9f  ) {
        code_length = (uint16_t) (header[1]/1.0);
    }


    stream_code = (float*)malloc(sizeof(float)*code_length);

    for( int i = 0; i < code_length; i ++ ) {
        iostream >> *(stream_code + i);
    }

    emit data_prepared(stream_code, code_length );
    free(stream_code);
#endif
    // ASCII stream float
    // (char *)@@@ + (uint8_t)length_h (uint8_t)length_l ->  (char *) bcd encode datas....  (char *)###

    QByteArray block;
    float *fd;
    union {
        struct {
            uint8_t lenghtLow;
            uint8_t lenghtHigh;
        } lengthSpere;

        uint16_t length;
    } lengthDraw;

    uint16_t index;
    block.clear();
    block.append( this->socket->readAll() );

    QList<QString> strString = QString(block).split(',');
    fd = (float*) malloc( sizeof(float) * strString.length() );
    for ( int i = 0; i < strString.length(); i ++  ) {
        *( fd + i) = strString.at(i).toFloat();
    }

    emit data_prepared(fd, strString.length());
    free(fd);
}

float NetClientThread::bcd_decoding(uint8_t *dHandle)
{
    float *df;
    uint32_t temp;
    for ( int i = 0; i < 4; i ++ ) {
        temp |= *(dHandle + 4 - i) & 0xFF;
        temp = temp << 8;
    }
    df = (float *)&temp;
    return *df;
}

void NetClientThread::bcd_encoding(float df, uint8_t *distChar)
{

    uint8_t* dHandle;
    dHandle = (uint8_t *)&df;
    *distChar = *dHandle & 0xFF;
    *(distChar + 1) = *(dHandle + 1) & 0xFF ;
    *(distChar + 2) = *(dHandle + 2) & 0xFF ;
    *(distChar + 3) = *(dHandle + 3) & 0xFF ;
}


void NetClientThread::send_cmd_close_app()
{
    QByteArray cmd;
    cmd.clear();
    cmd.append(0xAA);
    cmd.append(0xBB);
    cmd.append(0x01);
    cmd.append(0x01);
    cmd.append(0xFF);
    cmd.append(0xAA^0xBB^0x01^0x01^0xFF);
    this->socket->write(cmd);
    this->socket->flush();
    qDebug() << "netclientread@send_cmd_close_app() >: close remote...." ;
}

void NetClientThread::send_cmd_to_remote(uint8_t *users, quint16 length)
{

    QByteArray cmd;
    quint8 cmdLength = 0;
    quint8  checkSum = 0;

    cmd.clear();
    cmd.append(CMD_HEADER_1);
    cmd.append(CMD_HEADER_2);
    /* cmd length not contains cmd headers(0xAA 0xBB) and length byte. */
    cmdLength = length + 1;
    cmd.append( cmdLength );
    checkSum = 0xAA^0xBB^cmdLength;
    for ( int i = 0; i < length; i ++ ) {
        cmd.append(*(users + i));
        checkSum ^= *(users + i);
    }
    cmd.append( checkSum );
    qDebug() << "send :" << cmd;
    this->socket->write(cmd);
    this->socket->flush();
    qDebug() << "netclientread@send_cmd_close_app() >: send to remote...." ;
}


void NetClientThread::run()
{
    // tail sample buffer
#if false
    while( true ) {
        this->count ++;
        qDebug() << this->count;
        if( this->data_prepared_flag == true ) {
            this->data_prepared_flag = false;
            emit data_plot(this->data_draw_buffer);
        }
    }
#endif

}

void NetClientThread::stop()
{
    this->stop();
}
