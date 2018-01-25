#include "sysbutton.h"

SysButton::SysButton(QString picname,QWidget *parent):
    QPushButton(parent)
{
    mouse_pressed = false;
    status = 0;
    pixmap = QPixmap(picname);
    btn_width = pixmap.width()/4;
    btn_height = pixmap.height();
    this->setFixedSize(btn_width,btn_height);
}

SysButton::~SysButton()
{

}

void SysButton::enterEvent(QEvent *)
{
    status = 1;
    update();
}

void SysButton::mousePressEvent(QMouseEvent *)
{
    status = 2;
    mouse_pressed = true;
    update();
}

void SysButton::mouseReleaseEvent(QMouseEvent*)
{
    if(mouse_pressed)
    {
        status = 1;
        update();
        emit btn_clicked();
    }
}

void SysButton::leaveEvent(QEvent*)
{
    status = 0;
    update();
}

void SysButton::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,pixmap.copy(btn_width*status,0,btn_width,btn_height));
    painter.end();
}
