#include "XMainWidget.h"
#include "XLeftWidgetInMain.h"
#include "XRightWidgetInMain.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

XMainWidget::XMainWidget(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(255,255,255,255));
	setTitle("home");
	setMinimumSize(300,400);

	createUI();
	createLayouts();
	createConnect();
}

XMainWidget::~XMainWidget()
{

}

void XMainWidget::createUI()
{
	leftWidget = new XLeftWidgetInMain;
	rightWidget = new XRightWidgetInMain;
}

void XMainWidget::createLayouts()
{
	QHBoxLayout *lineLy = new QHBoxLayout;
	lineLy->addWidget(leftWidget);
	lineLy->addWidget(rightWidget);
	lineLy->setContentsMargins(1,1,1,1);
	lineLy->setSpacing(0);

	QVBoxLayout *main_layout = new QVBoxLayout(this);
	main_layout->addLayout(lineLy);
	
	main_layout->setContentsMargins(0,0,0,0);
	main_layout->setSpacing(0);
	
	this->setLayout(main_layout);

}

void XMainWidget::createConnect()
{

}