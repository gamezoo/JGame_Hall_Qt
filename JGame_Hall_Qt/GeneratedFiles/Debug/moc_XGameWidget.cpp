/****************************************************************************
** Meta object code from reading C++ file 'XGameWidget.h'
**
** Created: Tue Jan 30 09:40:38 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Widgets/bodyWidget/gameWidget/XGameWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XGameWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XGameWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_XGameWidget[] = {
    "XGameWidget\0"
};

void XGameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData XGameWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject XGameWidget::staticMetaObject = {
    { &XBorderlessWidget::staticMetaObject, qt_meta_stringdata_XGameWidget,
      qt_meta_data_XGameWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XGameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XGameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XGameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XGameWidget))
        return static_cast<void*>(const_cast< XGameWidget*>(this));
    return XBorderlessWidget::qt_metacast(_clname);
}

int XGameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = XBorderlessWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
