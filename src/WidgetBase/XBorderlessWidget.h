#ifndef XBORDERLESSWIDGET_H
#define XBORDERLESSWIDGET_H

#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))


#include <QWidget>
class QPaintEvent;

class XBorderlessWidget : public QWidget
{
	Q_OBJECT

public:
	XBorderlessWidget(QWidget *parent=NULL);
	~XBorderlessWidget();

	void setTitle(const QString &title);
	QString getTitle();

	void setClrBk(QColor clr);
	QColor getClrBk();

	void setClrBorder(QColor clr);
	QColor getClrBorder();

	void setDrawBorder(bool bHas);
	bool hasDrawBorder();

	void setTextColor(QColor clr);
	QColor getTextColor();

protected:
	virtual void paintEvent(QPaintEvent *);
	bool winEvent ( MSG * message, long * result );

private:
	QString title;
	QColor  clrBk;
	QColor  clrBorder;
	QColor  clrText;

	bool	bDrawBorder;
	
};

#endif // XBORDERLESSWIDGET_H
