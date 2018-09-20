/****************************************************************************
** Meta object code from reading C++ file 'netclientthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../NetworkPlot/netclientthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netclientthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetClientThread_t {
    QByteArrayData data[9];
    char stringdata0[91];
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
QT_MOC_LITERAL(8, 75, 15) // "on_read_message"

    },
    "NetClientThread\0data_prepared\0\0float*\0"
    "array_datas\0length\0data_plot\0double*\0"
    "on_read_message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetClientThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       6,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void NetClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetClientThread *_t = static_cast<NetClientThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_prepared((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->data_plot((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 2: _t->on_read_message(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NetClientThread::*_t)(float * , uint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::data_prepared)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetClientThread::*_t)(double * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetClientThread::data_plot)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject NetClientThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_NetClientThread.data,
      qt_meta_data_NetClientThread,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NetClientThread::data_prepared(float * _t1, uint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetClientThread::data_plot(double * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
