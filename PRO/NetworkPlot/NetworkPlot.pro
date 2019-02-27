#-------------------------------------------------
#
# Project created by QtCreator 2018-06-13T22:13:48
#
#-------------------------------------------------

QT       += core gui printsupport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkPlot
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
unix {
    INCLUDEPATH += /usr/local/qwt-6.1.4/include
    INCLUDEPATH += /usr/local/fftw/include
    LIBS += -L"/usr/local/qwt-6.1.4/lib/" -lqwt
    LIBS += "/usr/local/fftw/lib/libfftw3f.a"
}

win32 {
    INCLUDEPATH += C:\opt\Qwt-6.1.3\include
    INCLUDEPATH += C:\opt\fftw-3.3.5\b32
    LIBS += -L"C:\opt\Qwt-6.1.3\lib" -lqwt
    LIBS += "C:\opt\fftw-3.3.5\b32\libfftw3f-3.dll"
}
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    netclientthread.cpp \
    ringbuffer.cpp \
    filemanager.cpp \
    da_dialog.cpp

HEADERS += \
    mainwindow.h \
    netclientthread.h \
    com.h \
    ringbuffer.h \
    filemanager.h \
    da_dialog.h

FORMS += \
        mainwindow.ui \
    da_dialog.ui
