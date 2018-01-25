#include "XGameWidget.h"

XGameWidget::XGameWidget(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(0,0,0,255));
	setTextColor(QColor(255,255,255,255));
	setTitle(QString(""));
}

XGameWidget::~XGameWidget()
{

}
