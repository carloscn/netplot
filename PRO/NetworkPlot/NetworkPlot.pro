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

LINUX_QWT_DIR=../NetworkPlot/lib/qwt-gcc-6.1.3
LINUX_FFTW_DIR=../NetworkPlot/lib/fftw-gcc


WIN_QWT_DIR=..\NetworkPlot\lib\qwt-mingw32\qwt-6.1.3
WIN_FFTW_DIR=..\NetworkPlot\lib\fftw-mingw32

ARM_QWT_DIR=../NetworkPlot/lib/qwt-arch64-6.1.3
ARM_FFTW_DIR=../NetworkPlot/lib/fftw-arch64
# add file: qwt.dll file: libfftw3f-3.dll to *.exe path

win32 {
    INCLUDEPATH += $${WIN_QWT_DIR}\include
    INCLUDEPATH += $${WIN_FFTW_DIR}
    LIBS += -L"$${WIN_QWT_DIR}\lib" -lqwt
    LIBS += "$${WIN_FFTW_DIR}\libfftw3f-3.dll"
}

linux-oe-g++ {
    INCLUDEPATH += $${ARM_QWT_DIR}/include
    INCLUDEPATH += $${ARM_FFTW_DIR}/include
    LIBS += -L"$${ARM_QWT_DIR}/lib/" -lqwt
    LIBS += $${ARM_FFTW_DIR}/lib/libfftw3f.a
}

linux-g++ {
    INCLUDEPATH += $${LINUX_QWT_DIR}/include
    INCLUDEPATH += $${LINUX_FFTW_DIR}/include
    LIBS += -L"$${LINUX_QWT_DIR}/lib/" -lqwt
    LIBS += $${LINUX_FFTW_DIR}/lib/libfftw3f.a
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
