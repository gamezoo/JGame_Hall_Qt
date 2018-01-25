#include "XLeftWidgetInMain.h"

XLeftWidgetInMain::XLeftWidgetInMain(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(125,125,255,255));
	setTitle("left");
	setMinimumSize(300,400);
	setFixedWidth(300);
}

XLeftWidgetInMain::~XLeftWidgetInMain()
{

}
