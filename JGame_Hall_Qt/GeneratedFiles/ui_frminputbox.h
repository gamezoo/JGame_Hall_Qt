/********************************************************************************
** Form generated from reading UI file 'frminputbox.ui'
**
** Created: Tue Jan 30 09:55:03 2018
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMINPUTBOX_H
#define UI_FRMINPUTBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmInputBox
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Ico;
    QLabel *lab_Title;
    QWidget *widget_menu;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMenu_Close;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxInput;
    QVBoxLayout *verticalLayout_3;
    QLabel *labInfo;
    QLineEdit *txtValue;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *frmInputBox)
    {
        if (frmInputBox->objectName().isEmpty())
            frmInputBox->setObjectName(QString::fromUtf8("frmInputBox"));
        frmInputBox->resize(339, 154);
        verticalLayout = new QVBoxLayout(frmInputBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_title = new QWidget(frmInputBox);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        widget_title->setMinimumSize(QSize(100, 28));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lab_Ico = new QLabel(widget_title);
        lab_Ico->setObjectName(QString::fromUtf8("lab_Ico"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Ico->sizePolicy().hasHeightForWidth());
        lab_Ico->setSizePolicy(sizePolicy1);
        lab_Ico->setMinimumSize(QSize(31, 0));
        lab_Ico->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Ico);

        lab_Title = new QLabel(widget_title);
        lab_Title->setObjectName(QString::fromUtf8("lab_Title"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy2);
        lab_Title->setStyleSheet(QString::fromUtf8(""));
        lab_Title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lab_Title);

        widget_menu = new QWidget(widget_title);
        widget_menu->setObjectName(QString::fromUtf8("widget_menu"));
        sizePolicy1.setHeightForWidth(widget_menu->sizePolicy().hasHeightForWidth());
        widget_menu->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget_menu);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnMenu_Close = new QPushButton(widget_menu);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy3);
        btnMenu_Close->setMinimumSize(QSize(40, 0));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setFlat(true);

        horizontalLayout->addWidget(btnMenu_Close);


        horizontalLayout_2->addWidget(widget_menu);


        verticalLayout->addWidget(widget_title);

        widget_main = new QWidget(frmInputBox);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));
        widget_main->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_main);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxInput = new QGroupBox(widget_main);
        groupBoxInput->setObjectName(QString::fromUtf8("groupBoxInput"));
        verticalLayout_3 = new QVBoxLayout(groupBoxInput);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        labInfo = new QLabel(groupBoxInput);
        labInfo->setObjectName(QString::fromUtf8("labInfo"));
        labInfo->setMinimumSize(QSize(0, 30));
        labInfo->setMaximumSize(QSize(16777215, 30));
        labInfo->setScaledContents(false);
        labInfo->setWordWrap(true);

        verticalLayout_3->addWidget(labInfo);

        txtValue = new QLineEdit(groupBoxInput);
        txtValue->setObjectName(QString::fromUtf8("txtValue"));

        verticalLayout_3->addWidget(txtValue);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnOk = new QPushButton(groupBoxInput);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setCursor(QCursor(Qt::PointingHandCursor));
        btnOk->setFocusPolicy(Qt::StrongFocus);
        btnOk->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOk->setIcon(icon);
        btnOk->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnOk);

        btnCancel = new QPushButton(groupBoxInput);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setCursor(QCursor(Qt::PointingHandCursor));
        btnCancel->setFocusPolicy(Qt::StrongFocus);
        btnCancel->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon1);
        btnCancel->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btnCancel);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBoxInput);


        verticalLayout->addWidget(widget_main);

        QWidget::setTabOrder(txtValue, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(frmInputBox);

        QMetaObject::connectSlotsByName(frmInputBox);
    } // setupUi

    void retranslateUi(QDialog *frmInputBox)
    {
        frmInputBox->setWindowTitle(QApplication::translate("frmInputBox", "\350\276\223\345\205\245\346\241\206", 0, QApplication::UnicodeUTF8));
        lab_Ico->setText(QString());
        lab_Title->setText(QApplication::translate("frmInputBox", "\350\276\223\345\205\245\346\241\206", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("frmInputBox", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        groupBoxInput->setTitle(QString());
        labInfo->setText(QApplication::translate("frmInputBox", "\350\257\267\350\276\223\345\205\245:", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("frmInputBox", "\347\241\256\345\256\232(&O)", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("frmInputBox", "\345\217\226\346\266\210(&C)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class frmInputBox: public Ui_frmInputBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMINPUTBOX_H
