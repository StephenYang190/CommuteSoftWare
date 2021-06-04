/****************************************************************************
** Meta object code from reading C++ file 'cw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qqclient/cw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cw_t {
    QByteArrayData data[12];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cw_t qt_meta_stringdata_Cw = {
    {
QT_MOC_LITERAL(0, 0, 2), // "Cw"
QT_MOC_LITERAL(1, 3, 5), // "SendM"
QT_MOC_LITERAL(2, 9, 0), // ""
QT_MOC_LITERAL(3, 10, 8), // "send_str"
QT_MOC_LITERAL(4, 19, 6), // "NewMss"
QT_MOC_LITERAL(5, 26, 3), // "str"
QT_MOC_LITERAL(6, 30, 22), // "on_SendF_returnPressed"
QT_MOC_LITERAL(7, 53, 6), // "LoginS"
QT_MOC_LITERAL(8, 60, 2), // "id"
QT_MOC_LITERAL(9, 63, 6), // "NewFri"
QT_MOC_LITERAL(10, 70, 7), // "ReadMss"
QT_MOC_LITERAL(11, 78, 6) // "Sendto"

    },
    "Cw\0SendM\0\0send_str\0NewMss\0str\0"
    "on_SendF_returnPressed\0LoginS\0id\0"
    "NewFri\0ReadMss\0Sendto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cw[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,
      10,    1,   62,    2, 0x0a /* Public */,
      11,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void Cw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cw *_t = static_cast<Cw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendM((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->NewMss((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_SendF_returnPressed(); break;
        case 3: _t->LoginS((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->NewFri((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->ReadMss((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->Sendto((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cw::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cw::SendM)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cw::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cw::NewMss)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Cw::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Cw.data,
      qt_meta_data_Cw,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Cw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cw.stringdata0))
        return static_cast<void*>(const_cast< Cw*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Cw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Cw::SendM(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cw::NewMss(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
