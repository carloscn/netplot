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
    show_file_name = false;
#ifdef Q_OS_LINUX
    qFileDirPath = "/run/media/nvme0n1p2/sample-data/";
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
    show_file_name = false;
#ifdef Q_OS_LINUX
    qFileDirPath = "/run/media/nvme0n1p2/sample-data/" + QString::number(index) + "/";
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
        qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".txt";
        emit file_manager_add_file_name(currenttime+ "_" + QString::number(index) + ".txt");
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
        if(show_file_name==true){
            qFilePath = qFileDirPath + currenttime + ".hex";
            emit file_manager_add_file_name(currenttime + ".hex");
            qDebug() << "Create another hex file ....................";
        } else {
            qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".txt";
            qDebug() << "Create another txt file ********************";
        }
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
        qDebug() << "prewrite..............";
        preWriteExam();
        prewriteexame = true;
        qDebug() << "prewrite+++++++++++++++";

    }
    // Determine if the hex file full with FILE_SIZE_MAX, if true, then, create another file
    if(isFileFull(qFilePath)==true) {

        if(fileclose == true) {
            file->close();
            fileopen = false;
        }
        storge_size_current = storge_size;
        currenttime = datetime->currentDateTime().toString("yyyyMMddHHmmss");
        if(show_file_name==true){
            qFilePath = qFileDirPath + currenttime + ".hex";
            emit file_manager_add_file_name(currenttime+ ".hex");
            qDebug() << "Create another hex file ....................";
        } else {
            qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".txt";
            qDebug() << "Create another txt file ********************";
        }
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
    nameFilters << QString("*.txt");//determine wether the hex file exist
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
    if(show_file_name==true){
        // Give file a name
        qFilePath = qFileDirPath + currenttime + ".hex";
        qDebug() << "Create the data file : " << qFilePath;
        emit file_manager_add_file_name(currenttime + ".hex");
    } else {
        qFilePath = qFileDirPath + currenttime + "_" + QString::number(index) + ".txt";
    }
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
