#include "XStatusBarWidget.h"

XStatusBarWidget::XStatusBarWidget(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(66,175,240,255));
	setTextColor(QColor(255,0,0,255));
	setTitle(QString(""));
	setFixedHeight (25);
}
XStatusBarWidget::~XStatusBarWidget()
{

}

void XStatusBarWidget::OnStackedWidgetChanged(int index)
{
	setTitle(QString("index:%1").arg(index));
}
