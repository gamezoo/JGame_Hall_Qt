#include "XTitleWidget.h"
#include "sysbutton.h"
#include "QFourStateButton.h"

#include <Windows.h>

#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QFontMetrics>
#include <QIcon>
#include <QSignalMapper>
#include <QToolTip>
#include <QMouseEvent>

XTitleWidget::XTitleWidget(QWidget *parent)
	: XBorderlessWidget(parent)
{
	setClrBk(QColor(66,175,240,255));
	setFixedHeight(97);
	setTitle(QString(""));

	createUI();
	createLayouts();
	createConnects();

	setMouseTracking(true);
}

XTitleWidget::~XTitleWidget()
{

}


void XTitleWidget::resizeEvent(QResizeEvent *event)
{

}

bool XTitleWidget::winEvent(MSG *message, long *result)
{
	switch(message->message)  
	{  
	case WM_NCHITTEST:{
		int xPos = GET_X_LPARAM(message->lParam) - this->frameGeometry().x();  
		int yPos = GET_Y_LPARAM(message->lParam) - this->frameGeometry().y();  
		if(this->childAt(xPos,yPos) == 0)  
		{  
			*result = HTCAPTION;  
		}else{  
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
		if(xPos > (this->width() - 22) && xPos < (this->width() - 18) && yPos > (this->height() - 22) && yPos < (this->height() - 18))  
			*result = HTBOTTOMRIGHT;  
		return true;  
		}
		break;
	default:
		break;
	}  

	return false;
}


void XTitleWidget::createUI()
{
	// 左logo
	logo = new QLabel();
	logo->setScaledContents(true);
	logo->setPixmap(QPixmap(":/main_icon"));
	logo->setFixedSize(20,20);

	title = new QLabel();
	title->setObjectName("version");
	title->setText(QString("<a href=http://www.51v.cn> www.51v.cn </a>"));
	title->setOpenExternalLinks(true);
	title->setFixedHeight(22);

	// 右 系统按钮
	minSysButton	= new SysButton(":/titleWidget/sys_min");
	maxSysButton	= new SysButton(":/titleWidget/sys_max");
	closeSysButton	= new SysButton(":/titleWidget/sys_close");

	// grid user btn
	levelSysBtn			= new SysButton(":/login/btn_userlevel_msg");
	strongboxSysBtn		= new SysButton(":/login/btn_strongbox_msg");
	notifySysBtn		= new SysButton(":/login/btn_opennotify_msg");
	accountSafeSysBtn	= new SysButton(":/login/btn_accountsafe_msg");

	// 用户头像
	userLogo = new QLabel();
	userLogo->setObjectName("userLogo");
	QPixmap pixLogo = QPixmap(":/avatar/avatar_10");
	userLogo->setPixmap(pixLogo);
	userLogo->setFixedSize(pixLogo.width(),pixLogo.height());
	userLogo->setScaledContents(true);

	// 用户姓名 粗体 
	userName		= new QLabel("唐浩吃大便");
	userName->setObjectName("userName");

	// 用户ID			[92735608]
	userID			= new QLabel("[92735608]");
	userID->setObjectName("info");
	userID->setFixedWidth(60);
	QFontMetrics elideFont(userID->font());
	userID->setText(elideFont.elidedText("[92735608]", Qt::ElideMiddle, userID->width()));
	userID->setMouseTracking(true);
	userID->installEventFilter(this);

	// 用户VIP图标
	userVIPLogo		= new QLabel();
	QPixmap pixmapVIP(":/login/vip_icon");
	QPixmap pixCopy = pixmapVIP.copy(pixmapVIP.width()/8 * 7,0,pixmapVIP.width()/8,pixmapVIP.height());
	userVIPLogo->setPixmap(pixCopy);
	userVIPLogo->setFixedSize(pixCopy.width(), pixCopy.height());

	// 用户元宝图标
	userGoldLogo	= new QLabel();
	QPixmap pixmap(":/login/goldingots");
	pixmap.setMask(pixmap.createMaskFromColor(QColor(255,0,255)));
	userGoldLogo->setPixmap(pixmap);
	userGoldLogo->setFixedSize(16,16);

	// 用户元宝数量 
	userGoldNum		= new QLabel("0");
	userGoldNum->setObjectName("info");

	// 初始化功能栏上的 按钮
	initBtns();
}

void XTitleWidget::createLayouts()
{
	//头 水平
	QHBoxLayout *sysLine = new QHBoxLayout();
	sysLine->addWidget(logo);
	sysLine->addSpacing(5);
	sysLine->addWidget(title);
	sysLine->addStretch();
	sysLine->addWidget(minSysButton);
	sysLine->addWidget(maxSysButton);
	sysLine->addWidget(closeSysButton);
	sysLine->setSpacing(0);
	sysLine->setContentsMargins(5,0,5,0);

	// 中间是格子布局
	QGridLayout *gridLy = new QGridLayout();
	gridLy->addWidget(userLogo,		0,0,2,2,Qt::AlignLeft);

	gridLy->addWidget(userName,		0,3,1,1,Qt::AlignLeft);
	gridLy->addWidget(userID,		0,4,1,1,Qt::AlignLeft);
	gridLy->addWidget(userVIPLogo,	0,5,1,1,Qt::AlignLeft);
	gridLy->addWidget(userGoldLogo, 1,3,1,1,Qt::AlignLeft);
	gridLy->addWidget(userGoldNum,	1,4,1,1,Qt::AlignLeft);

	gridLy->addWidget(levelSysBtn,3,3,1,1, Qt::AlignLeft);
	gridLy->addWidget(strongboxSysBtn,3,4,1,1, Qt::AlignLeft);
	gridLy->addWidget(notifySysBtn,3,5,1,1, Qt::AlignLeft);
	gridLy->addWidget(accountSafeSysBtn,3,6,1,1, Qt::AlignLeft);
	gridLy->setContentsMargins(5,0,0,10);
	gridLy->setSpacing(10);
	
	// 功能栏 按钮布局
	QHBoxLayout *mainBtns = new QHBoxLayout;
	m_btnHome = new QFourStateButton(":/winmain/webmain");
	m_btnFillMoney = new QFourStateButton(":/winmain/fillmoney");
	m_btnExchange = new QFourStateButton(":/winmain/exchange");
	m_btnMall = new QFourStateButton(":/winmain/mall");
	m_btnVIP = new QFourStateButton(":/winmain/vip");
	//m_btnTickets = new QFourStateButton(":/winmain/tickets");
	m_btnExtend = new QFourStateButton(":/winmain/extend");
	mainBtns->addWidget(m_btnHome);
	mainBtns->addWidget(m_btnFillMoney);
	mainBtns->addWidget(m_btnExchange);
	mainBtns->addWidget(m_btnMall);
	mainBtns->addWidget(m_btnVIP);
	//mainBtns->addWidget(m_btnTickets);
	mainBtns->addWidget(m_btnExtend);
	mainBtns->setContentsMargins(0,0,0,0);
	mainBtns->setSpacing(50);

	// 管理 格子布局
	QHBoxLayout *hGridMain = new QHBoxLayout;
	hGridMain->addLayout(gridLy);
	hGridMain->addSpacing(30);
	hGridMain->addLayout(mainBtns);
	hGridMain->addStretch();
	hGridMain->setContentsMargins(0,0,0,0);
	hGridMain->setSpacing(0);

	// 主布局
	QVBoxLayout *vertical = new QVBoxLayout(this);
	vertical->addLayout(sysLine);
	vertical->addLayout(hGridMain);
	vertical->setContentsMargins(0,0,0,0);
	vertical->setSpacing(0);

	this->setLayout(vertical);
}


void XTitleWidget::createConnects()
{
	connect(closeSysButton, SIGNAL(btn_clicked()), this, SLOT(OnCloseBtnClicked()));
	connect(closeSysButton, SIGNAL(btn_clicked()), this, SIGNAL(closeBtnClicked()));

	connect(minSysButton, SIGNAL(btn_clicked()), this, SIGNAL(minBtnClicked()));
	connect(maxSysButton, SIGNAL(btn_clicked()), this, SIGNAL(maxBtnClicked()));
}


bool XTitleWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseMove && obj == userID) 
	{
		QMouseEvent *mouse = dynamic_cast<QMouseEvent *>(event);
		QToolTip::showText(mouse->globalPos(), QString("用户ID：92735608")/*userID->text()*/);
	} 

	return XBorderlessWidget::eventFilter(obj, event);
}

QLabel *XTitleWidget::getTitleLabel()
{
	return title;
}

void XTitleWidget::OnCloseBtnClicked()
{
	
}

void XTitleWidget::initBtns()
{

}
