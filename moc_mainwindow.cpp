/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_drawMode_stateChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "arg1"
QT_MOC_LITERAL(4, 42, 25), // "on_actionOpenen_triggered"
QT_MOC_LITERAL(5, 68, 26), // "on_actionOpslaan_triggered"
QT_MOC_LITERAL(6, 95, 28), // "on_actionAfsluiten_triggered"
QT_MOC_LITERAL(7, 124, 15), // "changeClickMode"
QT_MOC_LITERAL(8, 140, 19), // "on_pbLimits_clicked"
QT_MOC_LITERAL(9, 160, 18), // "on_pbLines_clicked"
QT_MOC_LITERAL(10, 179, 30), // "on_soilBox_currentIndexChanged"
QT_MOC_LITERAL(11, 210, 5), // "index"
QT_MOC_LITERAL(12, 216, 30), // "on_lineBox_currentIndexChanged"
QT_MOC_LITERAL(13, 247, 21), // "on_lineButton_clicked"
QT_MOC_LITERAL(14, 269, 27), // "on_intervalBox_valueChanged"
QT_MOC_LITERAL(15, 297, 28), // "on_xSchaalMeter_valueChanged"
QT_MOC_LITERAL(16, 326, 28) // "on_ySchaalMeter_valueChanged"

    },
    "MainWindow\0on_drawMode_stateChanged\0"
    "\0arg1\0on_actionOpenen_triggered\0"
    "on_actionOpslaan_triggered\0"
    "on_actionAfsluiten_triggered\0"
    "changeClickMode\0on_pbLimits_clicked\0"
    "on_pbLines_clicked\0on_soilBox_currentIndexChanged\0"
    "index\0on_lineBox_currentIndexChanged\0"
    "on_lineButton_clicked\0on_intervalBox_valueChanged\0"
    "on_xSchaalMeter_valueChanged\0"
    "on_ySchaalMeter_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    1,   91,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      15,    1,   98,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_drawMode_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_actionOpenen_triggered(); break;
        case 2: _t->on_actionOpslaan_triggered(); break;
        case 3: _t->on_actionAfsluiten_triggered(); break;
        case 4: _t->changeClickMode(); break;
        case 5: _t->on_pbLimits_clicked(); break;
        case 6: _t->on_pbLines_clicked(); break;
        case 7: _t->on_soilBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_lineBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lineButton_clicked(); break;
        case 10: _t->on_intervalBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_xSchaalMeter_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_ySchaalMeter_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::on_drawMode_stateChanged)) {
                *result = 0;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::on_drawMode_stateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
