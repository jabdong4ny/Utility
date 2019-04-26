/****************************************************************************
** Meta object code from reading C++ file 'trigger_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trigger_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trigger_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Trigger_Controller_t {
    QByteArrayData data[11];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Trigger_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Trigger_Controller_t qt_meta_stringdata_Trigger_Controller = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Trigger_Controller"
QT_MOC_LITERAL(1, 19, 12), // "tryConncting"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "ACN_Trigger"
QT_MOC_LITERAL(4, 45, 17), // "SOS_Trigger_Press"
QT_MOC_LITERAL(5, 63, 19), // "SOS_Trigger_Release"
QT_MOC_LITERAL(6, 83, 11), // "setVolValue"
QT_MOC_LITERAL(7, 95, 9), // "setStdout"
QT_MOC_LITERAL(8, 105, 13), // "on_checkStart"
QT_MOC_LITERAL(9, 119, 12), // "on_checkStop"
QT_MOC_LITERAL(10, 132, 14) // "on_timer_count"

    },
    "Trigger_Controller\0tryConncting\0\0"
    "ACN_Trigger\0SOS_Trigger_Press\0"
    "SOS_Trigger_Release\0setVolValue\0"
    "setStdout\0on_checkStart\0on_checkStop\0"
    "on_timer_count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Trigger_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       3,    1,   62,    2, 0x0a /* Public */,
       4,    0,   65,    2, 0x0a /* Public */,
       5,    0,   66,    2, 0x0a /* Public */,
       6,    1,   67,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Trigger_Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Trigger_Controller *_t = static_cast<Trigger_Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tryConncting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ACN_Trigger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->SOS_Trigger_Press(); break;
        case 3: _t->SOS_Trigger_Release(); break;
        case 4: _t->setVolValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setStdout(); break;
        case 6: _t->on_checkStart(); break;
        case 7: _t->on_checkStop(); break;
        case 8: _t->on_timer_count(); break;
        default: ;
        }
    }
}

const QMetaObject Trigger_Controller::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Trigger_Controller.data,
      qt_meta_data_Trigger_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Trigger_Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Trigger_Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Trigger_Controller.stringdata0))
        return static_cast<void*>(const_cast< Trigger_Controller*>(this));
    return QWidget::qt_metacast(_clname);
}

int Trigger_Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
