#ifndef QFOURSTATEBUTTON_H
#define QFOURSTATEBUTTON_H

#include <QPushButton>

class QFourStateButton : public QPushButton
{
	Q_OBJECT

	enum ButtonState 
	{
		Normal,			// ����
		Hover,			// �������
		Pressed,		// ��갴��
		Disable,		// ��ʹ��
	};

	enum DrawPart
	{
		PART_ONE = 0,
		PART_TWO = 1,
		PART_THD = 2,
		PART_FOR = 3,
	};

public:
	explicit QFourStateButton(QString pic, QWidget *parent=NULL);
	~QFourStateButton();

protected:
	void paintEvent(QPaintEvent *pEvent);
	void enterEvent(QEvent *pEvent);
	void leaveEvent(QEvent *pEvent);
	void mousePressEvent(QMouseEvent *pEvent);
	void mouseReleaseEvent(QMouseEvent *pEvent);

private:
	QPixmap m_pix;
	QString m_strPic;
	QSize   m_size;
	ButtonState m_state;
};

#endif // QFOURSTATEBUTTON_H
