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

	// ����Logo
	QLabel *logo;
	QLabel *title;

	// ϵͳ��ť
	SysButton *minSysButton;
	SysButton *maxSysButton;
	SysButton *closeSysButton;

	// �ȼ��������䡢��Ϣ����ȫ
	SysButton *levelSysBtn;
	SysButton *strongboxSysBtn;
	SysButton *notifySysBtn;
	SysButton *accountSafeSysBtn;
	QSignalMapper *signalMapper;

	// �û�ͷ��
	QLabel *userLogo;
	QLabel *userName;
	QLabel *userID;
	QLabel *userVIPLogo;
	QLabel *userGoldLogo;
	QLabel *userGoldNum;

	// ������ ��ť
	QFourStateButton *m_btnHome;				// ��ҳ
	QFourStateButton *m_btnFillMoney;		// ��ֵ
	QFourStateButton *m_btnExchange;			// �һ�
	QFourStateButton *m_btnMall;				// �̳�
	QFourStateButton *m_btnVIP;				// VIP
	QFourStateButton *m_btnTickets;			// ����
	QFourStateButton *m_btnExtend;			// �ƹ�	

	
};

#endif // XTITLEWIDGET_H
