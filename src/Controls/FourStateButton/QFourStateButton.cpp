#include "QFourStateButton.h"

#include <QPainter>
#include <QPushButton>
#include <QPixmap>
#include <QMouseEvent>
#include <QBitmap>

QFourStateButton::QFourStateButton(QString pic,QWidget *parent)
	: QPushButton(parent)
	, m_strPic(pic)
	, m_state(Normal)
{

	QPixmap pixmap(pic);
	pixmap.setMask(pixmap.createMaskFromColor(QColor(255,0,255)));
	m_pix = pixmap;

	m_size = QSize(m_pix.width()/4, m_pix.height());
	this->setFixedSize(m_size);
	this->setContentsMargins(0, 0, 0, 0);
}

QFourStateButton::~QFourStateButton()
{
}

void QFourStateButton::paintEvent(QPaintEvent *pEvent)
{
	QPainter painter(this);
	QRectF source(0.0, 0.0, 0.0, 0.0);

	switch(m_state)
	{
	case Normal:
		source.setRect(m_size.width() * 0, 0, m_size.width(), m_size.height());
		painter.drawPixmap(this->rect(), m_pix, source);
		break;
	case Hover:
		source.setRect(m_size.width() * 1, 0, m_size.width(), m_size.height());
		painter.drawPixmap(this->rect(), m_pix, source);
		break;
	case Pressed:
		source.setRect(m_size.width() * 2, 0, m_size.width(), m_size.height());
		painter.drawPixmap(this->rect(), m_pix, source);
		break;
	case Disable:
		source.setRect(m_size.width() * 3, 0, m_size.width(), m_size.height());
		painter.drawPixmap(this->rect(), m_pix, source);
		break;
	default:
		break;
	}
}

void QFourStateButton::enterEvent(QEvent *)
{
	m_state = Hover;
	update();
}

void QFourStateButton::leaveEvent(QEvent *pEvent)
{
	m_state = Normal;
	update();
}

void QFourStateButton::mousePressEvent(QMouseEvent *pEvent)
{
	if(pEvent->button() == Qt::LeftButton)
	{
		m_state = Pressed;
		update();
	}
}

void QFourStateButton::mouseReleaseEvent(QMouseEvent *pEvent)
{
	if(pEvent->button() == Qt::LeftButton)
	{
		////判断鼠标抬起时是否在PushButton之上
		//if(isOnPushButton(pEvent->pos(), this))
		//{
		//	emit clicked();
		//}

		m_state = Hover;
		update();
	}
}