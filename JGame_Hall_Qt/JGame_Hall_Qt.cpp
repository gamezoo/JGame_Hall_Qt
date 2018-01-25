#include "JGame_Hall_Qt.h"
#include "myhelper.h"
#include "XTitleWidget.h"
#include "XStatusBarWidget.h"
#include "XMainWidget.h"
#include "XGameWidget.h"
#include "app.h"

#include <Windows.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QDebug>

JGame_Hall_Qt::JGame_Hall_Qt(QWidget *parent, Qt::WFlags flags)
	: XBorderlessWidget(parent)
	, bMousePressedOnTitleWidget(false)
{
	ui.setupUi(this);

	initStyle();
	createChildWidgets();
	createLayouts();
	createConnect();
	installFilter();

	rcLastGeometry = QRect(0,0,qApp->desktop()->availableGeometry().width()/2,qApp->desktop()->availableGeometry().height()/2);
}

JGame_Hall_Qt::~JGame_Hall_Qt()
{

}


void JGame_Hall_Qt::createChildWidgets()
{
	// ±êÌâ
	titleWidget = new XTitleWidget(this);

	bodyWidgetMain = new XMainWidget(); 
	bodyWidgetGame = new XGameWidget();
	// ...
	// ...
	// ...

	bodyWidget = new QStackedWidget(this);
	bodyWidget->addWidget(bodyWidgetMain);
	bodyWidget->addWidget(bodyWidgetGame);
	bodyWidget->setCurrentIndex(index_main_widget);
	bodyWidget->setMinimumSize(800,450);
	// ×´Ì¬
	statusWidget = new XStatusBarWidget();
}


void JGame_Hall_Qt::initStyle()		   // 
{
	setTitle(QString("Ö÷´°¿ÚÈÝÆ÷"));
	setClrBk(QColor(0,0,0,255));
	setDrawBorder(true);
	setClrBorder(QColor(66,175,240,255));

	//setWindowFlags (windowFlags () | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
}

void JGame_Hall_Qt::createConnect()
{
	connect(titleWidget, SIGNAL(closeBtnClicked()), this, SLOT(OnClose()));
	connect(titleWidget, SIGNAL(minBtnClicked()), this, SLOT(OnMin()));
	connect(titleWidget, SIGNAL(maxBtnClicked()), this, SLOT(OnMax()));

	connect(bodyWidget, SIGNAL(currentChanged (int)), statusWidget, SLOT(OnStackedWidgetChanged(int)));
}

void JGame_Hall_Qt::createLayouts()
{
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addWidget((QWidget*)titleWidget);
	vLayout->addWidget((QWidget*)bodyWidget);
	vLayout->addWidget((QWidget*)statusWidget);
	vLayout->setSpacing(0);
	
	int margin = 0;
	hasDrawBorder()?margin=1:margin=0;
	vLayout->setContentsMargins(margin,margin,margin,margin);	// Áô³ö±ß¿ò
	
	QHBoxLayout *main_layout = new QHBoxLayout(this);
	main_layout->addLayout(vLayout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(margin,margin,margin,margin);	// Áô³ö±ß¿ò

	this->setLayout(main_layout);
}

void JGame_Hall_Qt::showEvent(QShowEvent *event)
{
	//bodyWidget->setCurrentIndex(index_game_widget);
}

bool JGame_Hall_Qt::winEvent(MSG *message, long *result)
{
	switch(message->message)  
	{  
	case WM_NCHITTEST:
		{
			int xPos = GET_X_LPARAM(message->lParam) - this->frameGeometry().x();  
			int yPos = GET_Y_LPARAM(message->lParam) - this->frameGeometry().y();  

			QWidget *widget = this->childAt (xPos, yPos);
			if(widget == 0)  
			{  
				*result = HTCAPTION;  
			}
			else
			{  
				if (widget == titleWidget)
				{
					*result = HTCAPTION;
				}
				return false;  
			}  
			if(xPos > 18 && xPos < 22)  
				*result = HTLEFT;  
			if(xPos > (this->width() - 22) && xPos < (this->width() - 18))  
				*result = HTRIGHT;  
			if(yPos > 18 && yPos < 22)  
				*result = HTTOP;  
			if(yPos > (this->height() - 22) && yPos < (this->height() - 18))  
				*result = HTBOTTOM;  
			if(xPos > 18 && xPos < 22 && yPos > 18 && yPos < 22)  
				*result = HTTOPLEFT;  
			if(xPos > (this->width() - 22) && xPos < (this->width() - 18) && yPos > 18 && yPos < 22)  
				*result = HTTOPRIGHT;  
			if(xPos > 18 && xPos < 22 && yPos > (this->height() - 22) && yPos < (this->height() - 18))  
				*result = HTBOTTOMLEFT;  

			int iWidth = this->width();
			int iHeight = this->height ();
			QRect rcGeo = this->geometry ();
			if(		xPos > (iWidth - 22) && xPos < (iWidth) 
				&&  yPos > (iHeight - 22) && yPos < (iHeight))  
			{
				*result = HTBOTTOMRIGHT;  
			}
			return true;  
		}
		break;
	default:
		break;
	}  

	return false;
}

void JGame_Hall_Qt::installFilter()		// 
{
	titleWidget->installEventFilter (this);
}


bool JGame_Hall_Qt::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress) 
	{
		if (obj == titleWidget && obj != titleWidget->getTitleLabel())
		{
			QMouseEvent* mouse = dynamic_cast<QMouseEvent *>(event);
			QPoint ptGlobal = mouse->globalPos ();
			QLabel*label = titleWidget->getTitleLabel ();
			QPoint GlobalPointTL(label->mapToGlobal(QPoint(label->rect ().left (),label->rect ().top ())));
			QPoint GlobalPointRB(label->mapToGlobal(QPoint(label->rect ().right (),label->rect ().bottom ())));
			QRect rcTitleLabel(GlobalPointTL, GlobalPointRB);
			if (!rcTitleLabel.contains(ptGlobal))
			{
				origion = mouse->globalPos ();
				qDebug()<<"origion::"<<origion;
				bMousePressedOnTitleWidget = true;
			}
		}
	} 
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		bMousePressedOnTitleWidget = false;
	}
	else if (event->type() == QEvent::MouseMove)
	{
		if (obj == titleWidget && bMousePressedOnTitleWidget)
		{
			QRect rcWork = qApp->desktop()->availableGeometry();
			QSize gemotryNow = this->size ();
			if (gemotryNow == rcWork.size ())
			{
				resize(rcLastGeometry.width (), rcLastGeometry.height ());
			}
			else
			{
				QMouseEvent* mouse = dynamic_cast<QMouseEvent *>(event);
				QRect rcNow = this->geometry ();
				rcNow.translate (mouse->globalPos() - origion);
				setGeometry (rcNow);
				origion = mouse->globalPos();
			}
		}
	}
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		if (obj == titleWidget)
		{
			processWindowSize();
		}
	}
	else 
	{
		return XBorderlessWidget::eventFilter(obj, event);
	}

	return XBorderlessWidget::eventFilter(obj, event);
}

void JGame_Hall_Qt::resizeEvent (QResizeEvent *event)
{
	
}


void JGame_Hall_Qt::OnClose()
{
	qApp->quit();
}


void JGame_Hall_Qt::OnMax()
{
	processWindowSize();
}

void JGame_Hall_Qt::OnMin()
{
	showMinimized();
}

void JGame_Hall_Qt::processWindowSize()
{
	QRect rcWork = qApp->desktop()->availableGeometry();
	rcCurGeometry = this->geometry ();
	if (this->size () == rcWork.size ())
	{
		//resize(rcLastGeometry.width (), rcLastGeometry.height ());
		setGeometry(rcLastGeometry);
		//myHelper::FormInCenter (this, App::DeskWidth,App::DeskHeight);
	}
	else
	{
		setGeometry(rcWork);
	}
	rcLastGeometry = rcCurGeometry;
}
