#include "frmmessagebox.h"
#include "ui_frmmessagebox.h"
#include "iconhelper.h"
#include "myhelper.h"
#include "app.h"

frmMessageBox::frmMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMessageBox)
{
    ui->setupUi(this);
    this->InitStyle();

	// UI 默认 UTF-8
	//myHelper::SetCharacterCode(QString("UTF-8"));
}

frmMessageBox::~frmMessageBox()
{
    delete ui;
}

void frmMessageBox::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() && Qt::LeftButton)) {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void frmMessageBox::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void frmMessageBox::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void frmMessageBox::InitStyle()
{
    this->setProperty("Form", true);
    this->setStyleSheet("background-color:rgb(0,29,91);");
    //窗体居中显示
    myHelper::FormInCenter(this, App::DeskWidth, App::DeskHeight+60);
    this->setModal(true);
    this->mousePressed = false;
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //设置图形字体
    IconHelper::Instance()->SetIcon(ui->lab_Ico, QChar(0xf015)); //0xf015
    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d)); //0xf00d

    //关联关闭按钮
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void frmMessageBox::SetMessage(QString msg, int type)
{
    if(type>=0)
    {
        if (type == 0) {
            ui->labIcoMain->setStyleSheet("border-image: url(:/messagebox/info);");
            ui->btnCancel->setVisible(false);
			QString strUnicode = QString::fromUtf8("提示");
            ui->lab_Title->setText(strUnicode);
        } else if (type == 1) {
            ui->labIcoMain->setStyleSheet("border-image: url(:/messagebox/question);");
			QString strUnicode = QString::fromUtf8("询问");
            ui->lab_Title->setText(strUnicode);
        } else if (type == 2) {
            ui->labIcoMain->setStyleSheet("border-image: url(:/messagebox/error);");
            ui->btnCancel->setVisible(false);
			QString strUnicode = QString::fromUtf8("错误");
            ui->lab_Title->setText(strUnicode);
        } else if (type == 3) {
            ui->labIcoMain->setStyleSheet("border-image: url(:/messagebox/info);");
            ui->btnCancel->setVisible(false);
            ui->btnOk->setVisible(false);
			QString strUnicode = QString::fromUtf8("提示");
            ui->lab_Title->setText(strUnicode);
        }
        this->setWindowTitle(ui->lab_Title->text());
    }
    ui->labInfo->setText(msg);
}

void frmMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}

void frmMessageBox::SetOKButtonVisiable(bool falg)
{
    ui->btnOk->setVisible(true);
}
