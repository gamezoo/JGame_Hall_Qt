#ifndef SYSBUTTON_H
#define SYSBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QString>
#include <QPainter>


class SysButton : public QPushButton
{
    Q_OBJECT
public:
    SysButton(QString picname,QWidget* parent = 0);
    QPixmap pixmap;
    int btn_width;
    int btn_height;
    int status;
    bool mouse_pressed;

    ~SysButton();

protected:
    void enterEvent(QEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void leaveEvent(QEvent*);
    void paintEvent(QPaintEvent*);

signals:
    void btn_clicked();
};

#endif // SYSBUTTON_H
