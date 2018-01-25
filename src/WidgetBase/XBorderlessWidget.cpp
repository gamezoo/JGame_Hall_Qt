#include "XBorderlessWidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QPen>

XBorderlessWidget::XBorderlessWidget(QWidget *parent)
	: QWidget(parent)
	, clrBk(QColor(128,128,128,233))
	, clrBorder(QColor(0,255,255,123))
	, bDrawBorder(false)
	, clrText(QColor(0,0,0,255))
{
	// ÎÞ±ß¿ò
	this->setWindowFlags(Qt::FramelessWindowHint/*|Qt::WindowStaysOnTopHint*/);
}

XBorderlessWidget::~XBorderlessWidget()
{

}

void XBorderlessWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	// ·ÛË¢
	painter.fillRect(this->rect(), QBrush(clrBk));
	
	// Íâ±ß¿ò
	QBrush noBrush(Qt::NoBrush);
	QPen penBorder( noBrush, 2, Qt::SolidLine, Qt::FlatCap,Qt::MiterJoin );
	painter.setBrush(noBrush);
	if (bDrawBorder)
	{
		painter.save();

		penBorder.setColor(clrBorder);
		painter.setPen(penBorder);
		QRect rcBorder = this->rect();
		rcBorder.adjust(1,1,-1,-1);
		painter.drawRect(rcBorder);

		painter.restore();
	}

	// »­title
	if (!title.isEmpty())
	{
		static QFont serifFont("Times", 10, QFont::Bold);
// 		QFont sansFont("Helvetica [Cronyx]", 12);
// 		QFont youyuan("Ó×Ô²", 12, QFont::Bold);
		
		penBorder.setColor(clrText);
		painter.setPen(penBorder);
		painter.setFont(serifFont);
		painter.drawText(this->rect(), Qt::AlignCenter, title);
	}
}

void XBorderlessWidget::setTitle(const QString &title)
{
	this->title = title;
	update();
}

QString XBorderlessWidget::getTitle()
{
	return title;
}

void XBorderlessWidget::setClrBk(QColor clr)
{
	clrBk = clr;
}
QColor XBorderlessWidget::getClrBk()
{
	return clrBk;
}

void XBorderlessWidget::setClrBorder(QColor clr)
{
	clrBorder = clr;
}
	
QColor XBorderlessWidget::getClrBorder()
{
	return clrBorder;
}

void XBorderlessWidget::setDrawBorder(bool bHas)
{
	bDrawBorder = bHas;
}

bool XBorderlessWidget::hasDrawBorder()
{
	return bDrawBorder;
}

bool XBorderlessWidget::winEvent ( MSG * message, long * result )
{
	return false;
}

void XBorderlessWidget::setTextColor(QColor clr)
{
	clrText = clr;
}

QColor XBorderlessWidget::getTextColor()
{
	return clrText;
}