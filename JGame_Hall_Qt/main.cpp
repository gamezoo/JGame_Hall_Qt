#include "JGame_Hall_Qt.h"
#include "myhelper.h"
#include "app.h"
#include "GBK.h"
#include "CommonDef.h"
#include <QApplication>
#include <string>
#include <QObject>

#define _TIME_ qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"))
#define _DATE_ qPrintable (QDate::currentDate().toString("yyyy-MM-dd"))

namespace xxx{
	static QString AppTitle = "\xe6\x88\x91\xe6\x98\xaf\xe6\xb1\x89\xe5\xad\x97";
	const QString g_AppTitle = "金游世界大厅";
	const std::string g_strAppTitle = "金游世界大厅";
	const char *g_pAppTitle = "金游世界大厅";
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	a.setApplicationName(QString("Hall.exe"));
	a.setApplicationVersion(QString(appVersion));
	
	QCoreApplication::addLibraryPath ( QCoreApplication::applicationDirPath () + "/plugins");
	myHelper::SetCharacterCode(QString("GB2312"));

	App::AppPath = QApplication::applicationDirPath() + "/";
	App::DeskWidth = qApp->desktop()->availableGeometry().width();
	App::DeskHeight = qApp->desktop()->availableGeometry().height();
	qApp->setFont(QFont(App::AppFontName, App::AppFontSize));

	myHelper::SetStyle(App::AppStyle);

	JGame_Hall_Qt w;
	w.setWindowIcon (QIcon(QString(":/main_icon")));

	//App::AppTitle 是从qtcreator移植过来的，为全局变量 main启动之前已被编码为utf-8
	w.setWindowTitle(QString("%1 %2").arg(xxx::g_pAppTitle/*strAppTitle*//*GBK::ToUnicode(g_strAppTitle)*//*QString("金游世界大厅")*//*QString::fromUtf8(App::AppTitle.toLatin1().data())*/, appVersion));
 	myHelper::FormInCenter(&w, App::DeskWidth,App::DeskHeight);
 	w.setGeometry(qApp->desktop()->availableGeometry());
	w.show();
	return a.exec();
}
