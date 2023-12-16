/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/utils/display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ActorItem_t {
    QByteArrayData data[3];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActorItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActorItem_t qt_meta_stringdata_ActorItem = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ActorItem"
QT_MOC_LITERAL(1, 10, 6), // "zValue"
QT_MOC_LITERAL(2, 17, 3) // "pos"

    },
    "ActorItem\0zValue\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActorItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QReal, 0x00095103,
       2, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void ActorItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ActorItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->zValue(); break;
        case 1: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ActorItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setZValue(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ActorItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ActorItem.data,
    qt_meta_data_ActorItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ActorItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActorItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ActorItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int ActorItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
struct qt_meta_stringdata_SeatItem_t {
    QByteArrayData data[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SeatItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SeatItem_t qt_meta_stringdata_SeatItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SeatItem"
QT_MOC_LITERAL(1, 9, 3) // "pos"

    },
    "SeatItem\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SeatItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void SeatItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SeatItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SeatItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SeatItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SeatItem.data,
    qt_meta_data_SeatItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SeatItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SeatItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SeatItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int SeatItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_SalonDisplay_t {
    QByteArrayData data[24];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SalonDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SalonDisplay_t qt_meta_stringdata_SalonDisplay = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SalonDisplay"
QT_MOC_LITERAL(1, 13, 17), // "barberCuttingHair"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "barberGoToSleep"
QT_MOC_LITERAL(4, 48, 16), // "clientSitOnChair"
QT_MOC_LITERAL(5, 65, 2), // "id"
QT_MOC_LITERAL(6, 68, 8), // "chair_nb"
QT_MOC_LITERAL(7, 77, 20), // "clientSitOnWorkChair"
QT_MOC_LITERAL(8, 98, 18), // "clientHairCutEnded"
QT_MOC_LITERAL(9, 117, 20), // "clientWaitHairToGrow"
QT_MOC_LITERAL(10, 138, 8), // "comeBack"
QT_MOC_LITERAL(11, 147, 14), // "clientHairGrow"
QT_MOC_LITERAL(12, 162, 21), // "clientAwayGrowinghair"
QT_MOC_LITERAL(13, 184, 16), // "clientWalkAround"
QT_MOC_LITERAL(14, 201, 18), // "clientWakeUpBarber"
QT_MOC_LITERAL(15, 220, 17), // "clientWaitHairCut"
QT_MOC_LITERAL(16, 238, 20), // "clientAccessEntrance"
QT_MOC_LITERAL(17, 259, 2), // "ms"
QT_MOC_LITERAL(18, 262, 10), // "hideBarber"
QT_MOC_LITERAL(19, 273, 17), // "finishedAnimation"
QT_MOC_LITERAL(20, 291, 24), // "finishedGroupedAnimation"
QT_MOC_LITERAL(21, 316, 27), // "clientsAccessEntranceFinish"
QT_MOC_LITERAL(22, 344, 23), // "barberCuttingHairStage1"
QT_MOC_LITERAL(23, 368, 23) // "barberCuttingHairStage2"

    },
    "SalonDisplay\0barberCuttingHair\0\0"
    "barberGoToSleep\0clientSitOnChair\0id\0"
    "chair_nb\0clientSitOnWorkChair\0"
    "clientHairCutEnded\0clientWaitHairToGrow\0"
    "comeBack\0clientHairGrow\0clientAwayGrowinghair\0"
    "clientWalkAround\0clientWakeUpBarber\0"
    "clientWaitHairCut\0clientAccessEntrance\0"
    "ms\0hideBarber\0finishedAnimation\0"
    "finishedGroupedAnimation\0"
    "clientsAccessEntranceFinish\0"
    "barberCuttingHairStage1\0barberCuttingHairStage2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SalonDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x0a /* Public */,
       3,    0,  115,    2, 0x0a /* Public */,
       4,    2,  116,    2, 0x0a /* Public */,
       7,    1,  121,    2, 0x0a /* Public */,
       8,    1,  124,    2, 0x0a /* Public */,
       9,    2,  127,    2, 0x0a /* Public */,
      11,    0,  132,    2, 0x0a /* Public */,
      12,    0,  133,    2, 0x0a /* Public */,
      13,    1,  134,    2, 0x0a /* Public */,
      14,    0,  137,    2, 0x0a /* Public */,
      15,    1,  138,    2, 0x0a /* Public */,
      16,    2,  141,    2, 0x0a /* Public */,
      16,    1,  146,    2, 0x2a /* Public | MethodCloned */,
      18,    0,  149,    2, 0x0a /* Public */,
      19,    0,  150,    2, 0x0a /* Public */,
      20,    0,  151,    2, 0x0a /* Public */,
       4,    0,  152,    2, 0x0a /* Public */,
      21,    0,  153,    2, 0x0a /* Public */,
      22,    0,  154,    2, 0x0a /* Public */,
      23,    0,  155,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    5,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,   17,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SalonDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SalonDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->barberCuttingHair(); break;
        case 1: _t->barberGoToSleep(); break;
        case 2: _t->clientSitOnChair((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->clientSitOnWorkChair((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->clientHairCutEnded((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->clientWaitHairToGrow((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->clientHairGrow(); break;
        case 7: _t->clientAwayGrowinghair(); break;
        case 8: _t->clientWalkAround((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: _t->clientWakeUpBarber(); break;
        case 10: _t->clientWaitHairCut((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->clientAccessEntrance((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 12: _t->clientAccessEntrance((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->hideBarber(); break;
        case 14: _t->finishedAnimation(); break;
        case 15: _t->finishedGroupedAnimation(); break;
        case 16: _t->clientSitOnChair(); break;
        case 17: _t->clientsAccessEntranceFinish(); break;
        case 18: _t->barberCuttingHairStage1(); break;
        case 19: _t->barberCuttingHairStage2(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SalonDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_SalonDisplay.data,
    qt_meta_data_SalonDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SalonDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SalonDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SalonDisplay.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int SalonDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
