/****************************************************************************
** Meta object code from reading C++ file 'MobileIM.h'
**
** Created: Wed Jul 7 15:30:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MobileIM.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MobileIM.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MobileIM[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      22,    9,    9,    9, 0x0a,
      46,   41,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MobileIM[] = {
    "MobileIM\0\0addMember()\0spreadMemberList()\0"
    "item\0goToChat(QListWidgetItem*)\0"
};

const QMetaObject MobileIM::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MobileIM,
      qt_meta_data_MobileIM, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MobileIM::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MobileIM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MobileIM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MobileIM))
        return static_cast<void*>(const_cast< MobileIM*>(this));
    return QWidget::qt_metacast(_clname);
}

int MobileIM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addMember(); break;
        case 1: spreadMemberList(); break;
        case 2: goToChat((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
