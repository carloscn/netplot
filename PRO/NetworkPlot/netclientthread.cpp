#include "netclientthread.h"

#define             RING_BUFFER_SIZE    19200ul

NetClientThread::NetClientThread( QString server_ip, int server_port )
{
    data_prepared_flag = false;
    socket = new QTcpSocket();
    server = new QTcpServer();
    count = 0;
    data_draw_buffer = new double[1024];
    ring_buffer = new ringbuffer(RING_BUFFER_SIZE);
    mutex = new QMutex();
    data_packet = (struct data_packet_t*)malloc(sizeof(struct data_packet_t));
    is_head = false;
    buffer_index = 0;
    is_packet_num = false;
    packet_number = 0;
    file_ctr = new FileManager();
    //qDebug() << "connect to svae dask";
    connect( this, SIGNAL(net_data_save_to_disk(quint8*,quint64) ),(QObject*)this->file_ctr ,SLOT(on_save_data_to_disk(quint8*,quint64)));




}

bool NetClientThread::set_connect(QString server_ip, int server_port)
{
    qDebug() << "netclientread@set_connect() >: seting the connection...." ;
    socket->connectToHost( server_ip, server_port , QIODevice::ReadWrite );

    QObject::connect((QObject*) socket,SIGNAL(readyRead()),(QObject*)this,SLOT(on_read_message()));
    if( !socket->waitForConnected(30000) ) {
        qDebug("netclientread@set_connect() >: socket Connection failed!!");
        return false;
    }else {
        qDebug("netclientread@set_connect() >: socket conncetion succussful.");
        return true;
    }
}
void NetClientThread::set_disconnet()
{
    socket->flush();
    socket->close();
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
    socket->write(cmd);
    socket->flush();
    qDebug() << "netclientread@send_cmd_close_app() >: close remote...." ;
}

void NetClientThread::send_cmd_to_remote(uint8_t *users, quint16 length)
{
    QByteArray cmd;
    quint8  checkSum = 0;
    union {
        struct {
            uint8_t bit0_8;
            uint8_t bit8_16;
        } bits;
        uint16_t all;
    } lengthCmd;

    cmd.clear();
    cmd.append(CMD_HEADER_1);
    cmd.append(CMD_HEADER_2);
    /* cmd length not contains cmd headers(0xAA 0xBB) and length byte. */
    lengthCmd.all = length - 1;
    cmd.append( lengthCmd.bits.bit8_16);
    cmd.append( lengthCmd.bits.bit0_8);
    for (int i = 0; i < length; i ++)
        cmd.append(users[i]);
    qDebug() << "send :" << cmd;
    socket->write(cmd);
    socket->flush();
    qDebug() << "netclientread@send_cmd_close_app() >: send to remote...." ;
}
// socket ascii stream.
// [0xAD 0xAC] : 2bytes frame heads.
// [0xLL 0xLL 0xLL 0xLL] : 4bytes data number.
// 500 x [0xQQ 0xQQ 0xQQ 0xTT | 0xQQ 0xQQ 0xQQ 0xTT | 0xQQ 0xQQ 0xQQ 0xTT | 0xQQ 0xQQ 0xQQ 0xTT] : 500*16 adc datas
// [0xEE 0xEE 0xEE 0xEE] : 4bytes end flags.
void NetClientThread::run()
{
    quint64 count = 0;
    uint8_t head[2];
    uint8_t i = 0;
    uint8_t* k_buffer = new uint8_t[ONE_PACKET_LENGTH*10];
    while (1) {

        if (ring_buffer->get_length() > 2) {
            head[i++] = ring_buffer->pop();
            head[i++] = ring_buffer->pop();
            count += i;
            i = 0;
            if ((head[0] & 0xFF) == 0xAD && (head[1] & 0xFF) == 0xAC ) {
                is_head = true;
            }

        }

    }
}

void NetClientThread::case_1(quint8 *buffer,  quint64 length, quint32 vector_counter)
{
    case_1(buffer, length);
}

void NetClientThread::case_1(quint8 *buffer,  quint64 length)
{
    quint64 count = 0;
#if TEST_DEBUG
    QFile *file = new QFile("adc.hex");
    file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    file->write((char*)buffer,length);
    file->close();
#endif
    count = length / ONE_PACKET_LENGTH;
    //qDebug() << "emit net data save to disk singal.";
    emit net_data_save_to_disk(buffer, length);
    //qDebug() << "@case_1 : count is :" << count;
    // plot data
    quint8 plot_buffer[ONE_PACKET_LENGTH];
    quint32 channel_data[2000];
    quint32 uh = 0, h = 0, l = 0, ul = 0;

    for (quint64 i = 0 ; i < 500*16; i ++) {
        plot_buffer[i] = buffer[i+6];
    }
/*
    uh = (plot_buffer[2] << 24) & 0xFF000000;
    h  = (plot_buffer[3] << 16) & 0x00FF0000;
    l  = (plot_buffer[4] << 8)  & 0x0000FF00;
    ul = (plot_buffer[5] << 0)  & 0X000000FF;
    data_packet->number = uh | h | l | ul;
*/
    for (quint64 i = 0; i < 500; i ++) {

        uh = (plot_buffer[16*i + 2] << 16) & 0x00FF0000;
        h  = (plot_buffer[16*i + 1] << 8)  & 0x0000FF00;
        l  = (plot_buffer[16*i + 0] << 0)  & 0x000000FF;
        ul = (plot_buffer[16*i + 3] << 0)  & 0X000000FF;

        data_packet->da = uh | h | l;

        uh = (plot_buffer[16*i + 6] << 16) & 0x00FF0000;
        h  = (plot_buffer[16*i + 5] << 8)  & 0x0000FF00;
        l  = (plot_buffer[16*i + 4] << 0)  & 0x000000FF;
        ul = (plot_buffer[16*i + 7] << 0)  & 0X000000FF;

        data_packet->db = uh | h | l;

        uh = (plot_buffer[16*i + 10] << 16) & 0x00FF0000;
        h  = (plot_buffer[16*i + 9] << 8)  & 0x0000FF00;
        l  = (plot_buffer[16*i + 8] << 0)  & 0x000000FF;
        ul = (plot_buffer[16*i + 11] << 0)  & 0X000000FF;

        data_packet->dc = uh | h | l;

        uh = (plot_buffer[16*i + 14] << 16) & 0x00FF0000;
        h  = (plot_buffer[16*i + 13] << 8)  & 0x0000FF00;
        l  = (plot_buffer[16*i + 12] << 0)  & 0x000000FF;
        ul = (plot_buffer[16*i + 15] << 0)  & 0X000000FF;

        data_packet->dd = uh | h | l;

        channel_data[i] = data_packet->da;
        channel_data[500 + i] = data_packet->db;
        channel_data[1000 + i] = data_packet->dc;
        channel_data[1500 + i] = data_packet->dd;
    }
    qDebug() << "emit net data plot signal.";
    emit net_data_plot(channel_data, 2000);


}
void NetClientThread::case_2(quint8 *socket_buffer, quint64 length, quint8 *left_buffer, quint64 *left_length)
{
    quint32 final_head_index = 0;
    // step 1: save left buffer data.
    for (quint64 i = length; i > 0; i --) {
        if ( socket_buffer[i] == 0xAC && socket_buffer[i-1] == 0xAD ) {
            final_head_index = i - 1;
            break;
        }
    }

    *left_length = length - final_head_index + 1;
    // positive direction save.
    for (quint64 i = 0; i < *left_length; i ++) {
        *(left_buffer + i) = *(socket_buffer + final_head_index + i);
    }

    // step 2: save complete data packet.
    //qDebug() << "join case 1";
    case_1(left_buffer, final_head_index);
}

void NetClientThread::case_3(quint8 *socket_buffer, quint64 length, quint8 *right_buffer, quint64 right_length)
{
    quint64 first_header_index = 0;
    quint8 *unknown_buffer = new quint8[ONE_PACKET_LENGTH*10];
    quint32 unknown_length = 0;
    quint32 unknown_pac_num = 0;

    for (quint64 i = 0; i < length; i ++) {
        if ( (*(socket_buffer + i) == 0xAD) && (*(socket_buffer + i + 1) == 0xAC) ) {
            first_header_index = i;
            break;
        }
    }
    quint8 *all_buffer = (quint8* )malloc(sizeof(quint8) * (ONE_PACKET_LENGTH + 1));

    memcpy(all_buffer, right_buffer, right_length);
    memcpy(all_buffer + right_length, socket_buffer, first_header_index);

    case_1(all_buffer, ONE_PACKET_LENGTH);
    unknown_length = length - first_header_index;
    memcpy(unknown_buffer, socket_buffer + first_header_index, unknown_length);

    int ret = check_packet(unknown_buffer,unknown_length,&unknown_pac_num);
    if (ret == 1) {
        //1qDebug() << "join case 1";
        case_1(unknown_buffer,unknown_length);
    }else if( ret == 2 ) {
        //1qDebug() << "join case 2";
        case_2(unknown_buffer, unknown_length, left_rom, &left_length);
    }else{
        qDebug() << "You are wrong about case not 1 or 2 what else?";
    }
}

void NetClientThread::case_4(quint8 *socket_buffer, quint64 length)
{
    quint64 first_header_index = 0;
    quint8 *unknown_buffer = new quint8[ONE_PACKET_LENGTH*10];
    quint32 unknown_length = 0;
    quint32 unknown_pac_num = 0;
    for (quint64 i = 0; i < length; i ++) {
        if ( (*(socket_buffer + i) == 0xAD) && (*(socket_buffer + i + 1) == 0xAC) ) {
            first_header_index = i;
            break;
        }
    }
    quint8 *all_buffer = (quint8* )malloc(sizeof(quint8) * (ONE_PACKET_LENGTH + 1));

    memcpy(all_buffer, socket_buffer + first_header_index, length - first_header_index + 1);

    int ret = check_packet(unknown_buffer, unknown_length, &unknown_pac_num);
    if (ret == 1) {
        //1qDebug() << "join case 1";
        case_1(unknown_buffer,unknown_length);
    }else if( ret == 2 ) {
        //1qDebug() << "join case 2";
        case_2(unknown_buffer, unknown_length, left_rom, &left_length);
    }else{
        qDebug() << "You are wrong about case not 1 or 2 what else?";
    }
}
void NetClientThread::on_read_message()
{
#if 0
    char c;
    float *fd;
    QByteArray block;
    block.clear();
    block.append(socket->readAll());
    //qDebug() << block;
    //qDebug() << "send size = " << block.size();
    //emit net_data_ready(block);
    //emit net_data_ready(emit_data, block.size());
    //ring_buffer->push(block.data(), block.size());
    int ret;
    QFile *file = new QFile("../adc.hex");
    QDataStream out(&block, QIODevice::ReadWrite);
    QDataStream in(file);
    ret = file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    qDebug() << "write size : " << block.length();
    if (!ret) {
        qDebug() << "Open failed\n";
        return;
    }

    in << block;
    file->close();
    block.clear();
#elif 0
    uint32_t read_buffer[4];
    QByteArray left_packet_buffer;
    //qDebug() << "slot times : " << read_counter ++;
    array_length = socket->bytesAvailable();
    array_rom.append(socket->readAll());
    array_length = array_rom.length();
    //ring_buffer->push(array_rom.data(), array_length);
    //qDebug() << "Push in ring buffer :" << array_length ;
    if (array_length <= 5*ONE_PACKET_LENGTH) {
        return;
    }
    qDebug() << "length is :" << array_length;
    // acceculate ONE_PACKET_LENGTH*5 datas.



    if ( (array_rom.contains(0xAD) && array_rom.contains(0xAC)) ) {
        vector_counter = 0;
        // Traverse the array_rom save index of headers.
        for (quint32 i = 0; i <= array_length; i ++) {
            if ( ((array_rom.at(i) & 0xFF)  == 0xad) && (((array_rom.at(i+1) & 0xFF) == 0xac))) {
                head_index_vector[vector_counter++] = i;
            }
        }
        qDebug() << "Find headers : " << vector_counter << "First header postion:" << head_index_vector[0] << "Finally header postion:" << head_index_vector[vector_counter];
        if (head_index_vector[0] != 0) {
            last_rom_b.clear();
            last_rom_b.append(array_rom.mid(0,head_index_vector[0]));
            qDebug() << "Get left header: " << last_rom_b.length();
        }

        //Deal tail data and new header left.
        if (!pre_rom_a.isEmpty()) {
            left_packet_buffer.append(pre_rom_a);
            left_packet_buffer.append(last_rom_b);
            if ( (left_packet_buffer.at(0) & 0xFF) == 0xAD ) {
                qDebug() << "Left data checked succussful";
            }else {
                qDebug() << "Left data checked failed and it index of = " << left_packet_buffer.indexOf(0xAD);
            }
            for (int j = 0; j < 4; j++) {
                read_buffer[j] = left_packet_buffer.at( j + 2 ) & 0xFF;
            }
            quint32 uh = 0;
            quint32 h = 0;
            quint32 l = 0;
            quint32 ul = 0;
            quint32 temp = (read_buffer[0] << 24) | (read_buffer[1] << 16) | (read_buffer[2] << 8) | read_buffer[3];
            data_packet->number = temp;
            for (int k = 0; k < 500; k++) {
                data_packet->da = (left_packet_buffer.at( (k-1)*16 + 7) & 0xFF) << 16 + \
                                                                                   (left_packet_buffer.at( (k-1)*16 + 6) & 0xFF) << 8 + \
                                                                                   (left_packet_buffer.at( (k-1)*16 + 5) & 0xFF) << 0;
                data_packet->db = (left_packet_buffer.at( (k-1)*16 + 11) & 0xFF) << 16 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 10) & 0xFF) << 8 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 9) & 0xFF) << 0;
                data_packet->dc = (left_packet_buffer.at( (k-1)*16 + 15) & 0xFF) << 16 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 14) & 0xFF) << 8 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 13) & 0xFF) << 0;
                data_packet->dd = (left_packet_buffer.at( (k-1)*16 + 19) & 0xFF) << 16 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 18) & 0xFF) << 8 + \
                                                                                    (left_packet_buffer.at( (k-1)*16 + 17) & 0xFF) << 0;
            }
            channel_a_buffer[packet_number] = data_packet->da;
            channel_b_buffer[packet_number] = data_packet->db;
            channel_c_buffer[packet_number] = data_packet->dc;
            channel_d_buffer[packet_number] = data_packet->dd;
            packet_number ++;
            qDebug() << "leftpacket enbale.";
        }
        // deal with the mid big packets.
        for (quint32 i = 0; i < vector_counter - 1; i ++) {
            for (int j = 0; j < 4; j++) {
                read_buffer[j] = array_rom.at( head_index_vector[i] + j + 2) & 0xFF;
            }
            quint32 temp = (read_buffer[0] << 24) | (read_buffer[1] << 16) | (read_buffer[2] << 8) | read_buffer[3];
            data_packet->number = temp;
            qDebug() << "packet num is :" << data_packet->number;
            for (int k = 0; k < 500; k ++) {
                data_packet->da = (array_rom.at( head_index_vector[i] + (k-1)*16 + 7) & 0xFF) << 16 + \
                                                                                                 (array_rom.at( head_index_vector[i] + (k-1)*16 + 6) & 0xFF) << 8 + \
                                                                                                 (array_rom.at( head_index_vector[i] + (k-1)*16 + 5) & 0xFF) << 0;
                data_packet->db = (array_rom.at( head_index_vector[i] + (k-1)*16 + 11) & 0xFF) << 16 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 10) & 0xFF) << 8 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 9) & 0xFF) << 0;
                data_packet->dc = (array_rom.at( head_index_vector[i] + (k-1)*16 + 15) & 0xFF) << 16 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 14) & 0xFF) << 8 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 13) & 0xFF) << 0;
                data_packet->dd = (array_rom.at( head_index_vector[i] + (k-1)*16 + 19) & 0xFF) << 16 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 18) & 0xFF) << 8 + \
                                                                                                  (array_rom.at( head_index_vector[i] + (k-1)*16 + 17) & 0xFF) << 0;
            }
            channel_a_buffer[packet_number] = data_packet->da;
            channel_b_buffer[packet_number] = data_packet->db;
            channel_c_buffer[packet_number] = data_packet->dc;
            channel_d_buffer[packet_number] = data_packet->dd;
            packet_number ++;
        }
        pre_rom_a.clear();

        if (array_length -  head_index_vector[vector_counter] < ONE_PACKET_LENGTH) {
            pre_rom_a.append(array_rom.mid(head_index_vector[vector_counter], array_length -  head_index_vector[vector_counter]));
            qDebug() << "@pre_rom_a: Left :" << array_length -  head_index_vector[vector_counter];
            if ((pre_rom_a.at(0) & 0xFF) == 0xAD) {
                qDebug() << "@pre_rom_a: Left : left is ok!";
            }else{
                qDebug() << "@pre_rom_a: Left : index of = " << pre_rom_a.indexOf(0xAD);
            }
        }else{
            qDebug() << "@pre_rom_a: No left.";
        }

    }

    qDebug() << "current pakcet number is:" << packet_number;
    if ( packet_number > 88000) {
        packet_number = 0;
    }
    packet_num = 0;
    array_rom.clear();
    array_length = 0;
    memset(head_index_vector,0,20);

#elif 1
    QByteArray left_packet_buffer;
    quint32 vector_counter = 0;
    qint8 ret;
    array_length = socket->bytesAvailable();
    array_rom.append(socket->readAll());
    array_length = array_rom.length();
    if (array_length < 5*ONE_PACKET_LENGTH) {
        return;
    }
    ret = -1;
    socket_buffer = new quint8[array_length];
    for (quint32 i = 0; i < array_length; i ++) {
        socket_buffer[i] = array_rom.at(i)&0xFF;
    }
    ret = check_packet(socket_buffer, array_length, &vector_counter);
    //1qDebug() << "Checked packet : length = " << vector_counter  ;

    switch(ret) {

    case 1:
        //1qDebug() << "case 1: ";
        case_1(socket_buffer, array_length, vector_counter);
        break;

    case 2:
        //1qDebug() << "case 2: ";
        case_2(socket_buffer, array_length, left_rom, &left_length);
        break;

    case 3:
        //1qDebug() << "case 3: ";
        case_3(socket_buffer, array_length, left_rom, left_length);
        break;

    case 4:
        //1qDebug() << "case 4: ";
        case_4(socket_buffer, array_length);
        break;
    }
    delete socket_buffer;
    vector_counter = 0;
    array_rom.clear();

#endif
}
qint8 NetClientThread::check_packet(quint8* array, quint64 length, quint32 *vec_con)
{
    quint16 header_vector_table[80000];
    quint32 vec_counter = 0;

    memset(header_vector_table,0xff,80000);
    header_vector_table[0] = 0xF;
    for (quint32 i = 0; i < length - 1; i ++) {
        if ( ((array[i] & 0xFF)  == 0xad) && (((array[i+1] & 0xFF) == 0xac)) ) {
            header_vector_table[vec_counter] = i;
            vec_counter ++;
        }
    }
    *(vec_con) = vec_counter;
    // case 1;
    if ((header_vector_table[0] == 0) && (length%ONE_PACKET_LENGTH == 0)) {
        is_head = true;
        return 1;
    }
    // case 2;
    if ((header_vector_table[0] == 0) && (length%ONE_PACKET_LENGTH != 0)) {
        is_head = true;
        return 2;
    }
    // case 3;
    if ((header_vector_table[0] != 0) && (is_head == true)) {
        return 3;
    }
    // case 4;
    if ((header_vector_table[0] != 0) && (is_head == false)) {
        is_head = true;
        return 4;
    }

    return -1;
}

void NetClientThread::on_net_close_file()
{
    if (file_ctr->file->isOpen()) {
        file_ctr->file->close();
    }
}

void NetClientThread::stop()
{
    stop();
}
