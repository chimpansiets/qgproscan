/****************************************************************************
** Meta object code from reading C++ file 'drawwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drawwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawWidget_t {
    QByteArrayData data[19];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawWidget_t qt_meta_stringdata_DrawWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DrawWidget"
QT_MOC_LITERAL(1, 11, 10), // "setTopLeft"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "setBottomRight"
QT_MOC_LITERAL(4, 38, 19), // "showPopupMenuLimits"
QT_MOC_LITERAL(5, 58, 3), // "pos"
QT_MOC_LITERAL(6, 62, 18), // "showPopupMenuLines"
QT_MOC_LITERAL(7, 81, 6), // "setTop"
QT_MOC_LITERAL(8, 88, 3), // "top"
QT_MOC_LITERAL(9, 92, 9), // "setBottom"
QT_MOC_LITERAL(10, 102, 6), // "bottom"
QT_MOC_LITERAL(11, 109, 7), // "setLeft"
QT_MOC_LITERAL(12, 117, 4), // "left"
QT_MOC_LITERAL(13, 122, 8), // "setRight"
QT_MOC_LITERAL(14, 131, 5), // "right"
QT_MOC_LITERAL(15, 137, 10), // "deleteLine"
QT_MOC_LITERAL(16, 148, 14), // "deleteAllLines"
QT_MOC_LITERAL(17, 163, 11), // "setDrawMode"
QT_MOC_LITERAL(18, 175, 4) // "mode"

    },
    "DrawWidget\0setTopLeft\0\0setBottomRight\0"
    "showPopupMenuLimits\0pos\0showPopupMenuLines\0"
    "setTop\0top\0setBottom\0bottom\0setLeft\0"
    "left\0setRight\0right\0deleteLine\0"
    "deleteAllLines\0setDrawMode\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void DrawWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawWidget *_t = static_cast<DrawWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTopLeft(); break;
        case 1: _t->setBottomRight(); break;
        case 2: _t->showPopupMenuLimits((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->showPopupMenuLines((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->setTop((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setBottom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setLeft((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setRight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->deleteLine(); break;
        case 9: _t->deleteAllLines(); break;
        case 10: _t->setDrawMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DrawWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawWidget.data,
      qt_meta_data_DrawWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DrawWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DrawWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
