/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetworkPlot/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[44];
    char stringdata0[915];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "net_close_file"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "net_enable_save"
QT_MOC_LITERAL(4, 43, 16), // "adc_dac_mode_set"
QT_MOC_LITERAL(5, 60, 25), // "on_pushButton_set_clicked"
QT_MOC_LITERAL(6, 86, 32), // "on_pushButton_disconnect_clicked"
QT_MOC_LITERAL(7, 119, 34), // "on_pushButton_close_remote_cl..."
QT_MOC_LITERAL(8, 154, 23), // "on_double_data_prepared"
QT_MOC_LITERAL(9, 178, 6), // "float*"
QT_MOC_LITERAL(10, 185, 11), // "array_datas"
QT_MOC_LITERAL(11, 197, 6), // "length"
QT_MOC_LITERAL(12, 204, 15), // "on_plot_picture"
QT_MOC_LITERAL(13, 220, 7), // "double*"
QT_MOC_LITERAL(14, 228, 32), // "on_pushButton_close_test_clicked"
QT_MOC_LITERAL(15, 261, 30), // "on_pushButton_freq_set_clicked"
QT_MOC_LITERAL(16, 292, 30), // "on_pushButton_gain_set_clicked"
QT_MOC_LITERAL(17, 323, 28), // "on_pushButton_fs_set_clicked"
QT_MOC_LITERAL(18, 352, 28), // "on_pushButton_sample_clicked"
QT_MOC_LITERAL(19, 381, 34), // "on_pushButton_close_sample_cl..."
QT_MOC_LITERAL(20, 416, 16), // "on_net_data_read"
QT_MOC_LITERAL(21, 433, 5), // "block"
QT_MOC_LITERAL(22, 439, 5), // "char*"
QT_MOC_LITERAL(23, 445, 16), // "on_net_plot_read"
QT_MOC_LITERAL(24, 462, 8), // "quint32*"
QT_MOC_LITERAL(25, 471, 19), // "on_net_add_doc_list"
QT_MOC_LITERAL(26, 491, 16), // "on_net_file_size"
QT_MOC_LITERAL(27, 508, 23), // "on_net_lic_check_failed"
QT_MOC_LITERAL(28, 532, 27), // "on_pushButton_clear_clicked"
QT_MOC_LITERAL(29, 560, 23), // "on_actionexit_triggered"
QT_MOC_LITERAL(30, 584, 28), // "on_actionclear_all_triggered"
QT_MOC_LITERAL(31, 613, 26), // "on_actionDA_Back_triggered"
QT_MOC_LITERAL(32, 640, 35), // "on_horizontalSlider_do_valueC..."
QT_MOC_LITERAL(33, 676, 5), // "value"
QT_MOC_LITERAL(34, 682, 18), // "on_da_trans_packet"
QT_MOC_LITERAL(35, 701, 30), // "on_pushButton_da_start_clicked"
QT_MOC_LITERAL(36, 732, 37), // "on_pushButton_da_clear_buffer..."
QT_MOC_LITERAL(37, 770, 29), // "on_pushButton_da_stop_clicked"
QT_MOC_LITERAL(38, 800, 31), // "on_pushButton_da_reback_clicked"
QT_MOC_LITERAL(39, 832, 19), // "on_action_5_toggled"
QT_MOC_LITERAL(40, 852, 4), // "arg1"
QT_MOC_LITERAL(41, 857, 23), // "on_actionlcok_triggered"
QT_MOC_LITERAL(42, 881, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(43, 909, 5) // "index"

    },
    "MainWindow\0net_close_file\0\0net_enable_save\0"
    "adc_dac_mode_set\0on_pushButton_set_clicked\0"
    "on_pushButton_disconnect_clicked\0"
    "on_pushButton_close_remote_clicked\0"
    "on_double_data_prepared\0float*\0"
    "array_datas\0length\0on_plot_picture\0"
    "double*\0on_pushButton_close_test_clicked\0"
    "on_pushButton_freq_set_clicked\0"
    "on_pushButton_gain_set_clicked\0"
    "on_pushButton_fs_set_clicked\0"
    "on_pushButton_sample_clicked\0"
    "on_pushButton_close_sample_clicked\0"
    "on_net_data_read\0block\0char*\0"
    "on_net_plot_read\0quint32*\0on_net_add_doc_list\0"
    "on_net_file_size\0on_net_lic_check_failed\0"
    "on_pushButton_clear_clicked\0"
    "on_actionexit_triggered\0"
    "on_actionclear_all_triggered\0"
    "on_actionDA_Back_triggered\0"
    "on_horizontalSlider_do_valueChanged\0"
    "value\0on_da_trans_packet\0"
    "on_pushButton_da_start_clicked\0"
    "on_pushButton_da_clear_buffer_clicked\0"
    "on_pushButton_da_stop_clicked\0"
    "on_pushButton_da_reback_clicked\0"
    "on_action_5_toggled\0arg1\0"
    "on_actionlcok_triggered\0"
    "on_tabWidget_currentChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x06 /* Public */,
       3,    1,  180,    2, 0x06 /* Public */,
       4,    1,  183,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  186,    2, 0x08 /* Private */,
       6,    0,  187,    2, 0x08 /* Private */,
       7,    0,  188,    2, 0x08 /* Private */,
       8,    2,  189,    2, 0x08 /* Private */,
      12,    1,  194,    2, 0x08 /* Private */,
      14,    0,  197,    2, 0x08 /* Private */,
      15,    0,  198,    2, 0x08 /* Private */,
      16,    0,  199,    2, 0x08 /* Private */,
      17,    0,  200,    2, 0x08 /* Private */,
      18,    0,  201,    2, 0x08 /* Private */,
      19,    0,  202,    2, 0x08 /* Private */,
      20,    1,  203,    2, 0x08 /* Private */,
      20,    2,  206,    2, 0x08 /* Private */,
      23,    2,  211,    2, 0x08 /* Private */,
      25,    1,  216,    2, 0x08 /* Private */,
      26,    1,  219,    2, 0x08 /* Private */,
      27,    0,  222,    2, 0x08 /* Private */,
      28,    0,  223,    2, 0x08 /* Private */,
      29,    0,  224,    2, 0x08 /* Private */,
      30,    0,  225,    2, 0x08 /* Private */,
      31,    0,  226,    2, 0x08 /* Private */,
      32,    1,  227,    2, 0x08 /* Private */,
      34,    1,  230,    2, 0x08 /* Private */,
      35,    0,  233,    2, 0x08 /* Private */,
      36,    0,  234,    2, 0x08 /* Private */,
      37,    0,  235,    2, 0x08 /* Private */,
      38,    0,  236,    2, 0x08 /* Private */,
      39,    1,  237,    2, 0x08 /* Private */,
      41,    0,  240,    2, 0x08 /* Private */,
      42,    1,  241,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::UInt,   10,   11,
    QMetaType::Void, 0x80000000 | 13,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   21,
    QMetaType::Void, 0x80000000 | 22, QMetaType::UInt,   21,   11,
    QMetaType::Void, 0x80000000 | 24, QMetaType::UInt,   21,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->net_close_file(); break;
        case 1: _t->net_enable_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->adc_dac_mode_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_set_clicked(); break;
        case 4: _t->on_pushButton_disconnect_clicked(); break;
        case 5: _t->on_pushButton_close_remote_clicked(); break;
        case 6: _t->on_double_data_prepared((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 7: _t->on_plot_picture((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_close_test_clicked(); break;
        case 9: _t->on_pushButton_freq_set_clicked(); break;
        case 10: _t->on_pushButton_gain_set_clicked(); break;
        case 11: _t->on_pushButton_fs_set_clicked(); break;
        case 12: _t->on_pushButton_sample_clicked(); break;
        case 13: _t->on_pushButton_close_sample_clicked(); break;
        case 14: _t->on_net_data_read((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 15: _t->on_net_data_read((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 16: _t->on_net_plot_read((*reinterpret_cast< quint32*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 17: _t->on_net_add_doc_list((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->on_net_file_size((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->on_net_lic_check_failed(); break;
        case 20: _t->on_pushButton_clear_clicked(); break;
        case 21: _t->on_actionexit_triggered(); break;
        case 22: _t->on_actionclear_all_triggered(); break;
        case 23: _t->on_actionDA_Back_triggered(); break;
        case 24: _t->on_horizontalSlider_do_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_da_trans_packet((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 26: _t->on_pushButton_da_start_clicked(); break;
        case 27: _t->on_pushButton_da_clear_buffer_clicked(); break;
        case 28: _t->on_pushButton_da_stop_clicked(); break;
        case 29: _t->on_pushButton_da_reback_clicked(); break;
        case 30: _t->on_action_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_actionlcok_triggered(); break;
        case 32: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::net_close_file)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::net_enable_save)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::adc_dac_mode_set)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::net_close_file()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::net_enable_save(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::adc_dac_mode_set(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
