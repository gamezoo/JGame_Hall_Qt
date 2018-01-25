#ifndef JGAME_HALL_QT_H
#define JGAME_HALL_QT_H

#include "XBorderlessWidget.h"
#include "ui_JGame_Hall_Qt.h"
#include <QtGui/QWidget>

class XTitleWidget;
class QStackedWidget;
class XMainWidget;
class XGameWidget;
class XStatusBarWidget;

class JGame_Hall_Qt : public XBorderlessWidget
{
	Q_OBJECT

	enum{
		index_main_widget,
		index_game_widget,
		index_max,
	};

public:
	JGame_Hall_Qt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~JGame_Hall_Qt();

public slots:
	void OnClose();
	void OnMin();
	void OnMax();

protected:
	void showEvent(QShowEvent *);
	bool winEvent(MSG *message, long *result);
	bool eventFilter(QObject *obj, QEvent *event);
	void resizeEvent (QResizeEvent *);

private:
	void initStyle();		   // 
	void createChildWidgets(); // 上部标题  中部[由大厅和游戏组成的stackedwidget]  下面状态栏
	void createConnect();
	void createLayouts();

	void installFilter();		// 

	void processWindowSize();
private:
	Ui::JGame_Hall_QtClass ui;

private:

	XTitleWidget *titleWidget;

	QStackedWidget *bodyWidget;
	XMainWidget    *bodyWidgetMain;
	XGameWidget    *bodyWidgetGame;

	XStatusBarWidget *statusWidget;


private:
	bool bMousePressedOnTitleWidget;
	QPoint origion;

	QRect rcLastGeometry;
	QRect rcCurGeometry;

};

#endif // JGAME_HALL_QT_H
