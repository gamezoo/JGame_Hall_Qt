#ifndef XTITLEWIDGET_H
#define XTITLEWIDGET_H

#include "XBorderlessWidget.h"

class SysButton;
class QLabel;
class QSignalMapper;
class QFourStateButton;

class XTitleWidget : public XBorderlessWidget
{
	Q_OBJECT

public:
	XTitleWidget(QWidget *parent=NULL);
	~XTitleWidget();

	QLabel *getTitleLabel();

public slots:
	void OnCloseBtnClicked();
	
private:
	void createUI();
	void createLayouts();
	void createConnects();

	void initBtns();

signals:
	void closeBtnClicked();
	void minBtnClicked();
	void maxBtnClicked();

protected:
	virtual void resizeEvent(QResizeEvent *);
	bool winEvent(MSG *message, long *result);
	bool eventFilter(QObject *obj, QEvent *event);

private:

	// 左上Logo
	QLabel *logo;
	QLabel *title;

	// 系统按钮
	SysButton *minSysButton;
	SysButton *maxSysButton;
	SysButton *closeSysButton;

	// 等级、保险箱、消息、安全
	SysButton *levelSysBtn;
	SysButton *strongboxSysBtn;
	SysButton *notifySysBtn;
	SysButton *accountSafeSysBtn;
	QSignalMapper *signalMapper;

	// 用户头像
	QLabel *userLogo;
	QLabel *userName;
	QLabel *userID;
	QLabel *userVIPLogo;
	QLabel *userGoldLogo;
	QLabel *userGoldNum;

	// 功能栏 按钮
	QFourStateButton *m_btnHome;				// 主页
	QFourStateButton *m_btnFillMoney;		// 充值
	QFourStateButton *m_btnExchange;			// 兑换
	QFourStateButton *m_btnMall;				// 商城
	QFourStateButton *m_btnVIP;				// VIP
	QFourStateButton *m_btnTickets;			// 奖劵
	QFourStateButton *m_btnExtend;			// 推广	

	
};

#endif // XTITLEWIDGET_H
