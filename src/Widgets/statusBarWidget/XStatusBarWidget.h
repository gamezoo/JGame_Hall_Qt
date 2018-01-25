#ifndef XSTATUSBARWIDGET_H
#define XSTATUSBARWIDGET_H

#include "XBorderlessWidget.h"

class XStatusBarWidget : public XBorderlessWidget
{
	Q_OBJECT

public:
	XStatusBarWidget(QWidget *parent=NULL);
	~XStatusBarWidget();

public slots:
	void OnStackedWidgetChanged(int);

private:
	
};

#endif // XSTATUSBARWIDGET_H
