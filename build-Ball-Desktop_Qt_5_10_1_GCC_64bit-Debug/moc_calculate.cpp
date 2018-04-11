/****************************************************************************
** Meta object code from reading C++ file 'calculate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ball/calculate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculate_t {
    QByteArrayData data[15];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculate_t qt_meta_stringdata_Calculate = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Calculate"
QT_MOC_LITERAL(1, 10, 11), // "condChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "cond"
QT_MOC_LITERAL(4, 28, 8), // "finished"
QT_MOC_LITERAL(5, 37, 8), // "sendCoor"
QT_MOC_LITERAL(6, 46, 1), // "y"
QT_MOC_LITERAL(7, 48, 13), // "centerChanged"
QT_MOC_LITERAL(8, 62, 6), // "center"
QT_MOC_LITERAL(9, 69, 8), // "starting"
QT_MOC_LITERAL(10, 78, 3), // "run"
QT_MOC_LITERAL(11, 82, 7), // "setcond"
QT_MOC_LITERAL(12, 90, 9), // "setBounce"
QT_MOC_LITERAL(13, 100, 1), // "b"
QT_MOC_LITERAL(14, 102, 9) // "setCenter"

    },
    "Calculate\0condChanged\0\0cond\0finished\0"
    "sendCoor\0y\0centerChanged\0center\0"
    "starting\0run\0setcond\0setBounce\0b\0"
    "setCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,
       9,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   70,    2, 0x0a /* Public */,
      11,    1,   71,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QPoint,    8,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495003,
       8, QMetaType::QPoint, 0x00495103,

 // properties: notify_signal_id
       0,
       3,

       0        // eod
};

void Calculate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Calculate *_t = static_cast<Calculate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->condChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->sendCoor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->centerChanged((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->starting(); break;
        case 5: _t->run(); break;
        case 6: _t->setcond((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setBounce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCenter((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Calculate::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculate::condChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Calculate::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculate::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Calculate::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculate::sendCoor)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Calculate::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculate::centerChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Calculate::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calculate::starting)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Calculate *_t = static_cast<Calculate *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->cond(); break;
        case 1: *reinterpret_cast< QPoint*>(_v) = _t->center(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Calculate *_t = static_cast<Calculate *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setcond(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setCenter(*reinterpret_cast< QPoint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calculate.data,
      qt_meta_data_Calculate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Calculate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculate::condChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Calculate::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Calculate::sendCoor(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Calculate::centerChanged(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Calculate::starting()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
