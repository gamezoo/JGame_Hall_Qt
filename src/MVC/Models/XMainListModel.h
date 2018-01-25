#ifndef XMAINLISTMODEL_H
#define XMAINLISTMODEL_H

#include <QAbstractListModel>

class XMainListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	XMainListModel(QObject *parent);
	~XMainListModel();

private:
	
};

#endif // XMAINLISTMODEL_H
