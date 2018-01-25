#ifndef XMAINWIDGET_H
#define XMAINWIDGET_H

#include "XBorderlessWidget.h"
class XLeftWidgetInMain;
class XRightWidgetInMain;
class XMainWidget : public XBorderlessWidget
{
	Q_OBJECT

public:
	XMainWidget(QWidget *parent=NULL);
	~XMainWidget();

private:
	void createUI();
	void createLayouts();
	void createConnect();


private:
	XLeftWidgetInMain *leftWidget;
	XRightWidgetInMain *rightWidget;
};

#endif // XMAINWIDGET_H
