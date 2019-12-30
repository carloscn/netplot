#ifndef FILEMANAGER_H
#define FILEMANAGER_H

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
    FileManager(quint8 index);
    ~FileManager();

    void write(QByteArray);
    void write(quint8* buffer, quint64 length);
    void write(float *ch_data, quint64 data_len);
    void preWriteExam();
    bool isDirExist(QString);
    bool isFileExist(QString);
    bool isFileFull(QString);
    void fileClose();

    QFile *file;
    QString qFilePath;
    bool prewriteexame;
    quint64 storge_size;
    quint64 storge_size_current;
    QString dispaly_store_value_def;
    QString dispaly_store_value_splite;
    bool show_file_name;

private slots:
    void on_save_data_to_disk(quint8*, quint64);
    void on_save_data_to_disk(QByteArray);

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
    quint8  index;
//    QMutex *mutex;

};

#endif // FILEMANAGER_H
