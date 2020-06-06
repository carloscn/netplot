/****************************************************************************
** Meta object code from reading C++ file 'netclientthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../NetworkPlot/netclientthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netclientthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetClientThread_t {
    QByteArrayData data[25];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetClientThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetClientThread_t qt_meta_stringdata_NetClientThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NetClientThread"
QT_MOC_LITERAL(1, 16, 13), // "data_prepared"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "float*"
QT_MOC_LITERAL(4, 38, 11), // "array_datas"
QT_MOC_LITERAL(5, 50, 6), // "length"
QT_MOC_LITERAL(6, 57, 9), // "data_plot"
QT_MOC_LITERAL(7, 67, 7), // "double*"
QT_MOC_LITERAL(8, 75, 14), // "net_data_ready"
QT_MOC_LITERAL(9, 90, 5), // "block"
QT_MOC_LITERAL(10, 96, 5), // "char*"
QT_MOC_LITERAL(11, 102, 13), // "net_data_plot"
QT_MOC_LITERAL(12, 116, 8), // "quint32*"
QT_MOC_LITERAL(13, 125, 21), // "net_data_save_to_disk"
QT_MOC_LITERAL(14, 147, 7), // "quint8*"
QT_MOC_LITERAL(15, 155, 16), // "net_add_doc_list"
QT_MOC_LITERAL(16, 172, 13), // "net_file_size"
QT_MOC_LITERAL(17, 186, 20), // "net_lic_check_failed"
QT_MOC_LITERAL(18, 207, 22), // "net_notify_dac_hand_ok"
QT_MOC_LITERAL(19, 230, 15), // "on_read_message"
QT_MOC_LITERAL(20, 246, 17), // "on_net_close_file"
QT_MOC_LITERAL(21, 264, 18), // "on_net_enable_save"
QT_MOC_LITERAL(22, 283, 28), // "on_file_manager_add_doc_list"
QT_MOC_LITERAL(23, 312, 25), // "on_file_manager_file_size"
QT_MOC_LITERAL(24, 338, 19) // "on_adc_dac_mode_set"

    },
    "NetClientThread\0data_prepared\0\0float*\0"
    "array_datas\0length\0data_plot\0double*\0"
    "net_data_ready\0block\0char*\0net_data_plot\0"
    "quint32*\0net_data_save_to_disk\0quint8*\0"
    "net_add_doc_list\0net_file_size\0"
    "net_lic_check_failed\0net_notify_dac_hand_ok\0"
    "on_read_message\0on_net_close_file\0"
    "on_net_enable_save\0on_file_manager_add_doc_list\0"
    "on_file_manager_file_size\0on_adc_dac_mode_set"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetClientThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       8,    1,  107,    2, 0x06 /* Public */,
       8,    2,  110,    2, 0x06 /* Public */,
      11,    2,  115,    2, 0x06 /* Public */,
      13,    2,  120,    2, 0x06 /* Public */,
      13,    1,  125,    2, 0x06 /* Public */,
      15,    1,  128,    2, 0x06 /* Public */,
      16,    1,  131,    2, 0x06 /* Public */,
      17,    0,  134,    2, 0x06 /* Public */,
      18,    1,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  138,    2, 0x08 /* Private */,
      20,    0,  139,    2, 0x08 /* Private */,
      21,    1,  140,    2, 0x08 /* Private */,
      22,    1,  143,    2, 0x08 /* Private */,
      23,    1,  146,    2, 0x08 /* Private */,
      24,    1,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 10, QMetaType::UInt,    9,    5,
    QMetaType::Void, 0x80000000 | 12, QMetaType::UInt,    9,    5,
    QMetaType::Void, 0x80000000 | 14, QMetaType::ULongLong,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void NetClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetClientThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_prepared((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->data_plot((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 2: _t->net_data_ready((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->net_data_ready((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->net_data_plot((*reinterpret_cast< quint32*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 5: _t->net_data_save_to_disk((*reinterpret_cast< quint8*(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 6: _t->net_data_save_to_disk((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->net_add_doc_list((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->net_file_size((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->net_lic_check_failed(); break;
        case 10: _t->net_notify_dac_hand_ok((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_read_message(); break;
        case 12: _t->on_net_close_file(); break;
        case 13: _t->on_net_enable_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_file_manager_add_doc_list((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->on_file_manager_file_size((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_adc_dac_mode_set((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetClientThread::*)(float * , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::data_prepared)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(double * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::data_plot)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_data_ready)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(char * , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_data_ready)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(quint32 * , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_data_plot)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(quint8 * , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_data_save_to_disk)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_data_save_to_disk)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_add_doc_list)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_file_size)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_lic_check_failed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (NetClientThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::net_notify_dac_hand_ok)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetClientThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_NetClientThread.data,
    qt_meta_data_NetClientThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetClientThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetClientThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetClientThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int NetClientThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void NetClientThread::data_prepared(float * _t1, uint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetClientThread::data_plot(double * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetClientThread::net_data_ready(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetClientThread::net_data_ready(char * _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetClientThread::net_data_plot(quint32 * _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NetClientThread::net_data_save_to_disk(quint8 * _t1, quint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NetClientThread::net_data_save_to_disk(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NetClientThread::net_add_doc_list(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void NetClientThread::net_file_size(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void NetClientThread::net_lic_check_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void NetClientThread::net_notify_dac_hand_ok(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
