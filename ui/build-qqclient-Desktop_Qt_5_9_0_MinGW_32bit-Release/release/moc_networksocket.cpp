/****************************************************************************
** Meta object code from reading C++ file 'networksocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qqclient/networksocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networksocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RcMss_t {
    QByteArrayData data[5];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RcMss_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RcMss_t qt_meta_stringdata_RcMss = {
    {
QT_MOC_LITERAL(0, 0, 5), // "RcMss"
QT_MOC_LITERAL(1, 6, 10), // "receivemss"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 3), // "str"
QT_MOC_LITERAL(4, 22, 11) // "ReadMessage"

    },
    "RcMss\0receivemss\0\0str\0ReadMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RcMss[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void RcMss::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RcMss *_t = static_cast<RcMss *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivemss((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ReadMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RcMss::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RcMss::receivemss)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RcMss::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RcMss.data,
      qt_meta_data_RcMss,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RcMss::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RcMss::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RcMss.stringdata0))
        return static_cast<void*>(const_cast< RcMss*>(this));
    return QObject::qt_metacast(_clname);
}

int RcMss::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RcMss::receivemss(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_client_t {
    QByteArrayData data[16];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 11), // "ReadMessage"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "str"
QT_MOC_LITERAL(4, 24, 6), // "NewFri"
QT_MOC_LITERAL(5, 31, 6), // "fri_id"
QT_MOC_LITERAL(6, 38, 7), // "DropFri"
QT_MOC_LITERAL(7, 46, 6), // "LoginS"
QT_MOC_LITERAL(8, 53, 6), // "LoginF"
QT_MOC_LITERAL(9, 60, 3), // "run"
QT_MOC_LITERAL(10, 64, 5), // "Login"
QT_MOC_LITERAL(11, 70, 7), // "account"
QT_MOC_LITERAL(12, 78, 8), // "password"
QT_MOC_LITERAL(13, 87, 5), // "SendM"
QT_MOC_LITERAL(14, 93, 8), // "send_str"
QT_MOC_LITERAL(15, 102, 10) // "MessagePro"

    },
    "client\0ReadMessage\0\0str\0NewFri\0fri_id\0"
    "DropFri\0LoginS\0LoginF\0run\0Login\0account\0"
    "password\0SendM\0send_str\0MessagePro"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       7,    1,   68,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,
       9,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   73,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReadMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->NewFri((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->DropFri((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->LoginS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->LoginF(); break;
        case 5: _t->run(); break;
        case 6: _t->Login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->SendM((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->MessagePro((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::ReadMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::NewFri)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::DropFri)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (client::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::LoginS)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::LoginF)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::run)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_client.data,
      qt_meta_data_client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(const_cast< client*>(this));
    return QObject::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void client::ReadMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void client::NewFri(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void client::DropFri(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void client::LoginS(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void client::LoginF()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void client::run()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
