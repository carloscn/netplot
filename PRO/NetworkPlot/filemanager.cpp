/**
 * \brief   This project about FileManager.
 *
 * \License  THIS FILE IS PART OF MULTIBEANS PROJECT ;
 *           all of the files  - The core part of the project;
 *           THIS PROGRAM IS FREE SOFTWARE, JUST NEED GPL 3.0 LICENSE;
 *           YOU SHOULD HAVE RECEIVED A COPY OF WTFPL LICENSE UTIL 5/1/2021, IF NOT,
 *           MULTIBEANS WILL TAKE APPROPRIATE MEASURES.
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
 *           * -> https://github.com/multibeans  <-
 *           * Copyright (c) 2013-2018 MULTIBEANS ORG. http://www.mltbns.com/
 *           * Copyright (c) 2018 Tian Zhiying(Davis Tian).
 *
 *  \note    void.
 ****************************************************************************/
/*                                                                          */
/*  @File       : main.c                                                    */
/*  @Revision   : Ver 1.0.                                                  */
/*  @Date       : 2018.10.21 Realse.                                        */
/*  @Belong     : PROJECT.                                                  */
/*  @GitHub     :                                                           */
/*  @ASCII : (UTF-8) in Linux amd64. Qt Creator5.12                         */
/****************************************************************************/
/*  @Attention:                                                             */
/*  ---------------------------------------------------------------------   */
/*  |    Data    |  Behavior |     Offer     |          Content         |   */
/*  |------------|-----------|---------------|--------------------------|   */
/*  | 2018.10.21 |   creat   |Tian Zhiying   | add file offer&debug     |   */
/*  ---------------------------------------------------------------------   */
/*                                                            MULTIBEANS.   */
/****************************************************************************/

#include "filemanager.h"


FileManager::FileManager(): file(new QFile),datetime(new QDateTime){
        this->index = 0;
        qFilePath = "123";
        filesize = 0;
        fileopen = false;
        fileclose = false;
        dir_flag = false;
        prewriteexame = false;
        currenttime = "20181019220522";
#ifdef Q_OS_LINUX
        qFileDirPath = "/usr/data/";
#endif
#ifdef Q_OS_WIN32
       qFileDirPath = "D:/data/";
#endif

}

FileManager::FileManager(quint8 index): file(new QFile),datetime(new QDateTime)
{
    this->index = index;
    qFilePath = "123";
    filesize = 0;
    fileopen = false;
    fileclose = false;
    dir_flag = false;
    prewriteexame = false;
    currenttime = "20181019220522";
#ifdef Q_OS_LINUX
        qFileDirPath = "/usr/data/" + QString::number(index) + "/";
#endif
#ifdef Q_OS_WIN32
       qFileDirPath = "D:/data/" + QString::number(index) + "/";
#endif
}


FileManager::~FileManager() {

}

void FileManager::write(quint8* buffer, quint64 length) {
    double percent;

    if(prewriteexame == false) {
        // preWriteExam only run once!
        preWriteExam();
        prewriteexame = true;

    }
    // Determine if the hex file full with FILE_SIZE_MAX, if true, then, create another file
    if(isFileFull(qFilePath)==true) {

        if(fileclose == true) {
            file->close();
            fileopen = false;
        }
        storge_size_current = storge_size;
        currenttime = datetime->currentDateTime().toString("yyyyMMddHHmmss");
        qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".hex";
        emit file_manager_add_file_name(currenttime+ "_" + QString::number(index) + ".hex");
        qDebug() << "Create another hex file ...................." + storge_size;
    }

    if(file->isOpen() == false) {
        file->setFileName(qFilePath);
        file->open(QIODevice::WriteOnly | QIODevice::Append);
        fileclose = false;
        fileopen = true;
    }
    QFileInfo fileInfo(qFilePath);
    filesize = fileInfo.size();

    percent = ((double)filesize)/(double)storge_size_current;

    file->write((char*)buffer, length);

    emit file_manager_file_size(percent);
    //qDebug() << "Writing data to hex file ... ...";
}
void FileManager::write(float *ch_data, quint64 data_len)
{
    double percent;

    if(prewriteexame == false) {
        // preWriteExam only run once!
        preWriteExam();
        prewriteexame = true;

    }
    // Determine if the hex file full with FILE_SIZE_MAX, if true, then, create another file
    if(isFileFull(qFilePath)==true) {

        if(fileclose == true) {
            file->close();
            fileopen = false;
        }
        storge_size_current = storge_size;
        currenttime = datetime->currentDateTime().toString("yyyyMMddHHmmss");
        qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".hex";
        qDebug() << "Splite data: Create another hex file " + qFilePath;
        //emit file_manager_add_file_name(currenttime + "_" + QString::number(index) + ".hex");
    }

    if(file->isOpen() == false) {
        file->setFileName(qFilePath);
        file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        fileclose = false;
        fileopen = true;
    }
    QFileInfo fileInfo(qFilePath);
    filesize = fileInfo.size();

    percent = ((double)filesize)/(double)storge_size_current;

    QTextStream out(file);
    for (quint32 i = 0; i < data_len; i ++) {
        QString temp_str = QString::number( *(ch_data + i) );
        out << temp_str << ",";
    }
    //emit file_manager_file_size(percent);
}
void FileManager::write(QByteArray array) {
    double percent;

    if(prewriteexame == false) {
        // preWriteExam only run once!
        preWriteExam();
        prewriteexame = true;

    }
    // Determine if the hex file full with FILE_SIZE_MAX, if true, then, create another file
    if(isFileFull(qFilePath)==true) {

        if(fileclose == true) {
            file->close();
            fileopen = false;
        }
        storge_size_current = storge_size;
        currenttime = datetime->currentDateTime().toString("yyyyMMddHHmmss");
        qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".hex";
        emit file_manager_add_file_name(currenttime+ "_" + QString::number(index) + ".hex");
        qDebug() << "Create another hex file ....................";
    }

    if(file->isOpen() == false) {
        file->setFileName(qFilePath);
        file->open(QIODevice::WriteOnly | QIODevice::Append);
        fileclose = false;
        fileopen = true;
    }
    QFileInfo fileInfo(qFilePath);
    filesize = fileInfo.size();

    percent = ((double)filesize)/(double)storge_size_current;

    file->write(array);

    emit file_manager_file_size(percent);
    //qDebug() << "Writing data to hex file ... ...";
}
bool FileManager::isDirExist(QString fileDirPath) {

    QDir dir(fileDirPath);
    if(dir.exists()) {
        return true;//file dir exist
    } else {
        return false;//file dir not exist
    }
}

bool FileManager::isFileExist(QString fileDirPath) {

    QDir dir(fileDirPath);
    QStringList nameFilters;
    nameFilters << QString("*.hex");//determine wether the hex file exist
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    dir.setNameFilters(nameFilters);
    if(dir.count()!=0) {
        return true;//hex file exist
    } else {
        return false;//hex file not exist
    }
}

bool FileManager::isFileFull(QString filePath) {

    QFileInfo fileInfo(filePath);
    filesize = fileInfo.size();
    if(filesize >= storge_size_current) {
        fileclose = true;
        return true;//The hex file is full with 1GB
    }
    return false;//The hex file can continue to store data
}

void FileManager::preWriteExam() {

    currenttime = datetime->currentDateTime().toString("yyyyMMddHHmmss");
    //qFileDirPath.append(currenttime + "/");
    // Determine if the file dir exists, if not, then, create it.
    if(isDirExist(qFileDirPath)==false) {
        QDir dir;
        dir.mkdir(qFileDirPath );//create the file dir
        qDebug() << "Create the file dir";
    }
    // Give file a name
    qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".hex";
    qDebug() << "Create the data file : " << qFilePath;
    prewriteexame = true;
    emit file_manager_add_file_name(currenttime+ "_" + QString::number(index) + ".hex");

}

void FileManager::run()
{

#ifdef TEST_DEBUG
    QByteArray nihao;
    while(1) {
        qDebug() << "Thread A....";
        //    ((MainWindow*)(this->parent()))->mutex->lock();
        //    mutex->tryLock();
        qDebug() << "Thread B....";
        for(qint64 i=0;i<65536;i++) {
            nihao.append("1234567898975457878746878768787867468768");
        }
        //    mutex->unlock();
        qDebug() << "Thread C....";
        this->write(nihao);
        this->usleep(100);
        nihao.clear();
        qDebug() << "Thread start....";
    }
#endif
    //    exec();
}

void FileManager::on_save_data_to_disk(quint8 *buffer, quint64 length)
{
    //qDebug() << "slot on save data to disk..";
    this->write(buffer, length);
}
void FileManager::on_save_data_to_disk(QByteArray array)
{
    this->write(array);
}


void FileManager::fileClose()
{
    file->close();
    prewriteexame = false;

}
void FileManager::file_size()
{

}
