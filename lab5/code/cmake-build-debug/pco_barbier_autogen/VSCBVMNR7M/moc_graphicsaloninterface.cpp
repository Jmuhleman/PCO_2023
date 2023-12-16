/****************************************************************************
** Meta object code from reading C++ file 'graphicsaloninterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/utils/graphicsaloninterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsaloninterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicSalonInterface_t {
    QByteArrayData data[23];
    char stringdata0[437];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicSalonInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicSalonInterface_t qt_meta_stringdata_GraphicSalonInterface = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GraphicSalonInterface"
QT_MOC_LITERAL(1, 22, 27), // "sig_consoleAppendTextClient"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 9), // "consoleId"
QT_MOC_LITERAL(4, 61, 4), // "text"
QT_MOC_LITERAL(5, 66, 27), // "sig_consoleAppendTextBarber"
QT_MOC_LITERAL(6, 94, 24), // "sig_clientAccessEntrance"
QT_MOC_LITERAL(7, 119, 2), // "id"
QT_MOC_LITERAL(8, 122, 20), // "sig_clientSitOnChair"
QT_MOC_LITERAL(9, 143, 8), // "chair_nb"
QT_MOC_LITERAL(10, 152, 21), // "sig_clientWaitHairCut"
QT_MOC_LITERAL(11, 174, 24), // "sig_clientWaitHairToGrow"
QT_MOC_LITERAL(12, 199, 8), // "comeBack"
QT_MOC_LITERAL(13, 208, 24), // "sig_clientWaitRoomIsFull"
QT_MOC_LITERAL(14, 233, 24), // "sig_clientSitOnWorkChair"
QT_MOC_LITERAL(15, 258, 20), // "sig_clientWalkAround"
QT_MOC_LITERAL(16, 279, 22), // "sig_clientHairCutEnded"
QT_MOC_LITERAL(17, 302, 22), // "sig_clientWakeUpBarber"
QT_MOC_LITERAL(18, 325, 19), // "sig_barberGoToSleep"
QT_MOC_LITERAL(19, 345, 22), // "sig_barberStopSleeping"
QT_MOC_LITERAL(20, 368, 24), // "sig_barberPicksNewClient"
QT_MOC_LITERAL(21, 393, 21), // "sig_barberGoesHairCut"
QT_MOC_LITERAL(22, 415, 21) // "sig_barberCuttingHair"

    },
    "GraphicSalonInterface\0sig_consoleAppendTextClient\0"
    "\0consoleId\0text\0sig_consoleAppendTextBarber\0"
    "sig_clientAccessEntrance\0id\0"
    "sig_clientSitOnChair\0chair_nb\0"
    "sig_clientWaitHairCut\0sig_clientWaitHairToGrow\0"
    "comeBack\0sig_clientWaitRoomIsFull\0"
    "sig_clientSitOnWorkChair\0sig_clientWalkAround\0"
    "sig_clientHairCutEnded\0sig_clientWakeUpBarber\0"
    "sig_barberGoToSleep\0sig_barberStopSleeping\0"
    "sig_barberPicksNewClient\0sig_barberGoesHairCut\0"
    "sig_barberCuttingHair"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicSalonInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       5,    1,   99,    2, 0x06 /* Public */,
       6,    1,  102,    2, 0x06 /* Public */,
       8,    2,  105,    2, 0x06 /* Public */,
      10,    1,  110,    2, 0x06 /* Public */,
      11,    2,  113,    2, 0x06 /* Public */,
      13,    1,  118,    2, 0x06 /* Public */,
      14,    1,  121,    2, 0x06 /* Public */,
      15,    1,  124,    2, 0x06 /* Public */,
      16,    1,  127,    2, 0x06 /* Public */,
      17,    0,  130,    2, 0x06 /* Public */,
      18,    0,  131,    2, 0x06 /* Public */,
      19,    0,  132,    2, 0x06 /* Public */,
      20,    0,  133,    2, 0x06 /* Public */,
      21,    0,  134,    2, 0x06 /* Public */,
      22,    0,  135,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt, QMetaType::Int,    7,    9,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    7,   12,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicSalonInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphicSalonInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_consoleAppendTextClient((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sig_consoleAppendTextBarber((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sig_clientAccessEntrance((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->sig_clientSitOnChair((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sig_clientWaitHairCut((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->sig_clientWaitHairToGrow((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->sig_clientWaitRoomIsFull((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->sig_clientSitOnWorkChair((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->sig_clientWalkAround((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: _t->sig_clientHairCutEnded((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 10: _t->sig_clientWakeUpBarber(); break;
        case 11: _t->sig_barberGoToSleep(); break;
        case 12: _t->sig_barberStopSleeping(); break;
        case 13: _t->sig_barberPicksNewClient(); break;
        case 14: _t->sig_barberGoesHairCut(); break;
        case 15: _t->sig_barberCuttingHair(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphicSalonInterface::*)(unsigned int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_consoleAppendTextClient)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_consoleAppendTextBarber)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientAccessEntrance)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientSitOnChair)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientWaitHairCut)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientWaitHairToGrow)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientWaitRoomIsFull)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientSitOnWorkChair)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientWalkAround)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)(unsigned  );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientHairCutEnded)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_clientWakeUpBarber)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_barberGoToSleep)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_barberStopSleeping)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_barberPicksNewClient)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_barberGoesHairCut)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (GraphicSalonInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicSalonInterface::sig_barberCuttingHair)) {
                *result = 15;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphicSalonInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GraphicSalonInterface.data,
    qt_meta_data_GraphicSalonInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphicSalonInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicSalonInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicSalonInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GraphicSalonInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void GraphicSalonInterface::sig_consoleAppendTextClient(unsigned int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicSalonInterface::sig_consoleAppendTextBarber(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicSalonInterface::sig_clientAccessEntrance(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicSalonInterface::sig_clientSitOnChair(unsigned  _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphicSalonInterface::sig_clientWaitHairCut(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphicSalonInterface::sig_clientWaitHairToGrow(unsigned  _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GraphicSalonInterface::sig_clientWaitRoomIsFull(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GraphicSalonInterface::sig_clientSitOnWorkChair(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GraphicSalonInterface::sig_clientWalkAround(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GraphicSalonInterface::sig_clientHairCutEnded(unsigned  _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GraphicSalonInterface::sig_clientWakeUpBarber()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GraphicSalonInterface::sig_barberGoToSleep()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void GraphicSalonInterface::sig_barberStopSleeping()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void GraphicSalonInterface::sig_barberPicksNewClient()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void GraphicSalonInterface::sig_barberGoesHairCut()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void GraphicSalonInterface::sig_barberCuttingHair()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
