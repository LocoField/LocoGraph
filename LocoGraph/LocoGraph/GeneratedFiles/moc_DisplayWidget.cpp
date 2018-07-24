/****************************************************************************
** Meta object code from reading C++ file 'DisplayWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DisplayWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DisplayWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DisplayWidget_t {
    QByteArrayData data[14];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplayWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplayWidget_t qt_meta_stringdata_DisplayWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DisplayWidget"
QT_MOC_LITERAL(1, 14, 20), // "signalThreadFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 15), // "signalDrawGraph"
QT_MOC_LITERAL(4, 52, 15), // "onThreadStarted"
QT_MOC_LITERAL(5, 68, 16), // "onThreadFinished"
QT_MOC_LITERAL(6, 85, 11), // "onDrawGraph"
QT_MOC_LITERAL(7, 97, 28), // "onHorizontalScrollBarChanged"
QT_MOC_LITERAL(8, 126, 5), // "value"
QT_MOC_LITERAL(9, 132, 15), // "onXRangeChanged"
QT_MOC_LITERAL(10, 148, 8), // "QCPRange"
QT_MOC_LITERAL(11, 157, 5), // "range"
QT_MOC_LITERAL(12, 163, 14), // "onMousePressed"
QT_MOC_LITERAL(13, 178, 14) // "onMouseWheeled"

    },
    "DisplayWidget\0signalThreadFinished\0\0"
    "signalDrawGraph\0onThreadStarted\0"
    "onThreadFinished\0onDrawGraph\0"
    "onHorizontalScrollBarChanged\0value\0"
    "onXRangeChanged\0QCPRange\0range\0"
    "onMousePressed\0onMouseWheeled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplayWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplayWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplayWidget *_t = static_cast<DisplayWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalThreadFinished(); break;
        case 1: _t->signalDrawGraph(); break;
        case 2: { bool _r = _t->onThreadStarted();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->onThreadFinished(); break;
        case 4: _t->onDrawGraph(); break;
        case 5: _t->onHorizontalScrollBarChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onXRangeChanged((*reinterpret_cast< QCPRange(*)>(_a[1]))); break;
        case 7: _t->onMousePressed(); break;
        case 8: _t->onMouseWheeled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DisplayWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DisplayWidget::signalThreadFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DisplayWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DisplayWidget::signalDrawGraph)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DisplayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DisplayWidget.data,
      qt_meta_data_DisplayWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DisplayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayWidget.stringdata0))
        return static_cast<void*>(const_cast< DisplayWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DisplayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void DisplayWidget::signalThreadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DisplayWidget::signalDrawGraph()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
