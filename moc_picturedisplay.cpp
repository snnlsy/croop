/****************************************************************************
** Meta object code from reading C++ file 'picturedisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "picturedisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picturedisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PictureDisplay_t {
    QByteArrayData data[8];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PictureDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PictureDisplay_t qt_meta_stringdata_PictureDisplay = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PictureDisplay"
QT_MOC_LITERAL(1, 15, 22), // "sendMousePressPosition"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 7), // "QPoint&"
QT_MOC_LITERAL(4, 47, 24), // "sendMouseCurrentPosition"
QT_MOC_LITERAL(5, 72, 24), // "sendMouseReleasePosition"
QT_MOC_LITERAL(6, 97, 20), // "sendRubberBandVector"
QT_MOC_LITERAL(7, 118, 26) // "std::vector<QRubberBand*>&"

    },
    "PictureDisplay\0sendMousePressPosition\0"
    "\0QPoint&\0sendMouseCurrentPosition\0"
    "sendMouseReleasePosition\0sendRubberBandVector\0"
    "std::vector<QRubberBand*>&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PictureDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,
       6,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void PictureDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PictureDisplay *_t = static_cast<PictureDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMousePressPosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->sendMouseCurrentPosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->sendMouseReleasePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->sendRubberBandVector((*reinterpret_cast< std::vector<QRubberBand*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PictureDisplay::*)(QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PictureDisplay::sendMousePressPosition)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PictureDisplay::*)(QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PictureDisplay::sendMouseCurrentPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PictureDisplay::*)(QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PictureDisplay::sendMouseReleasePosition)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PictureDisplay::*)(std::vector<QRubberBand*> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PictureDisplay::sendRubberBandVector)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PictureDisplay::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_PictureDisplay.data,
      qt_meta_data_PictureDisplay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PictureDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PictureDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PictureDisplay.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int PictureDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PictureDisplay::sendMousePressPosition(QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PictureDisplay::sendMouseCurrentPosition(QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PictureDisplay::sendMouseReleasePosition(QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PictureDisplay::sendRubberBandVector(std::vector<QRubberBand*> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
