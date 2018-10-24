#ifndef FILEMANAGER_H
#define FILEMANAGER_H

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

#include <QString>
#include <QByteArray>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QDataStream>
#include <QIODevice>
#include <QDebug>
#include <QThread>
#include <QMutex>

#define             GB              1073741824l//1024*1024*1024 = 1073741824 byte is 1GB
#define             MB              1048576l
#define             KB              1024l

#define             FILE_SIZE_MAX   (512*MB)

class FileManager : public QThread{
    Q_OBJECT
public:
    explicit FileManager();
    ~FileManager();

    void write(QByteArray);
    void write(quint8* buffer, quint64 length);
    void preWriteExam();
    bool isDirExist(QString);
    bool isFileExist(QString);
    bool isFileFull(QString);
    void fileClose();
    QFile *file;
    QString qFilePath;
    bool prewriteexame;

private slots:
    void on_save_data_to_disk(quint8*, quint64);

protected:
    void run();

signals:
    void file_manager_file_size(double);
    void file_manager_add_file_name(QString);

private:
    bool dir_flag;
    qint64 filesize;
    bool fileopen;
    bool fileclose;
    QString qFileDirPath;
    void file_size();
    QDateTime *datetime;
    QString currenttime;
//    QMutex *mutex;

};

#endif // FILEMANAGER_H
