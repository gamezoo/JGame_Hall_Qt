/****************************************************************************
** Meta object code from reading C++ file 'frminputbox.h'
**
** Created: Tue Jan 30 10:11:58 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Common/frminputbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frminputbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_frmInputBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_frmInputBox[] = {
    "frmInputBox\0\0okbtn_clicked()\0"
    "on_btnOk_clicked()\0"
};

void frmInputBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        frmInputBox *_t = static_cast<frmInputBox *>(_o);
        switch (_id) {
        case 0: _t->okbtn_clicked(); break;
        case 1: _t->on_btnOk_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData frmInputBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject frmInputBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_frmInputBox,
      qt_meta_data_frmInputBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmInputBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmInputBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmInputBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmInputBox))
        return static_cast<void*>(const_cast< frmInputBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int frmInputBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void frmInputBox::okbtn_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
