#include "XRightWidgetInMain.h"

XRightWidgetInMain::XRightWidgetInMain(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(255,125,125,255));
	setTitle("webkit");
	setMinimumSize(300,400);
}

XRightWidgetInMain::~XRightWidgetInMain()
{

}
