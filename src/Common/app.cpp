#include "app.h"
#include "myhelper.h"
#include <QDebug>
#include "GBK.h"
#include <string>
QString App::AppPath = "";

#ifdef Q_OS_WIN
int App::AppFontSize = 10;
QString App::AppFontName = "Microsoft YaHei";
#endif

#ifdef Q_OS_LINUX
#ifdef __arm__
int App::AppFontSize = 11;
QString App::AppFontName = "WenQuanYi Micro Hei";
#else
int App::AppFontSize = 11;
QString App::AppFontName = "WenQuanYi";
#endif
#endif

#ifdef Q_OS_MAC
int App::AppFontSize = 11;
QString App::AppFontName = "Heiti SC";
#endif

int App::DeskWidth = 1024;
int App::DeskHeight = 768;

QString App::AppTitle = QString("金游大厅");
//QString App::NVRType = "深广;宝学;敏达;泰杰;汇迪;银江;海康;大华;宇视;皓维;银海";
//QString App::IPCType = "泰杰;敏达;银江;海康;大华;宇视";
QString App::AppStyle = ":/qss/blue";

QString App::VideoSavePath = "D:/WynlinkVideo";//视频保存路径
QString App::ImageSavePath = "D:/WynlinkImage";//视频保存路径
int App::VideoDelayTime = 300;//缓存时间300ms
//bool App::UseVideoOffLineCheck = true;//离线检测D
//int App::VideoOffLineCheckInterval = 30;//离线检测间隔30s
int App::RtspType = 1;//码流类型为子码流

bool App::AutoRun = false;//关闭开机自启动
bool App::AutoPoll = false;//关闭自动轮询
int App::PollType = 1;//轮询画面类型
int App::PollInterval = 2;//轮询间隔
int App::PollSleep = 0;//轮询延时
bool App::LoginState = true;
int App::DefaultModule = 0;//0:视频监控；1：用户权限；2：系统设置


//默认16个通道全部显示
QString App::VideoType = "16";//视频画面显示类型
int App::SystemSettingsWidth = 800;//系统设置界面宽度
int App::SystemSettingsHeight = 600;//系统设置界面宽度
int App::SystemUserAuthWidth = 800;//用户设置界面宽度
int App::SystemUserAuthHeight = 600;//用户设置界面宽度
//int App::FormType[6] = {16,12,9,6,4,1};//视频显示个数
int App::CurrentFormType = 4;//0:16,1:12,2:9,3:6,4:4,5:1
int App::FormTypeForDoubleClick = 4;
//16个通道对应rtsp地址,方便自启动后自动加载
//QString App::RtspAddr16 = "|||||||||||||||";
//最后配置信息,画面数
//QString App::LastConfig = "1";
//用户编号
int App::UserID = 0;
QString App::UserName = "admin";
QString App::UserNameAes = "";
QString App::PasswordAes = "";
QString App::UserNameEncode = "";
int App::RoleID = 0;
//用户权限
QList<QMap<QString,QString> > App::UserPermissionSource;

//数据库配置
QString App::sqlName = "VMS";
QString App::sqlIP = "10.6.0.18";
QString App::sqlUsername = "root";
QString App::sqlPassword = "root";
//QString App::positionString= "";

QString App::adminWeb = "10.6.0.19";
QString App::adminWebPort = "8089";

QStringList App::UserRegion;

//QString App::Version = "1.2.0";

void App::ReadConfigHall()          //读取配置文件
{
	QString fileName = App::AppPath + "CONFIG/config.txt";
	if (!myHelper::FileIsExist(fileName)) {
		return;
	}

	QSettings *set = new QSettings(fileName, QSettings::IniFormat);
	set->setIniCodec("GB2312");//或者GB2312
	set->beginGroup("AppConfig");
	App::AppStyle = set->value("AppStyle").toString();
	App::AppTitle = set->value("AppTitle").toString();
	set->endGroup();
}


//读取配置文件
void App::ReadConfig()
{
    QString fileName = App::AppPath + "CONFIG/config.txt";
    //如果配置文件不存在,则以初始值继续运行
    if (!myHelper::FileIsExist(fileName)) {
        //对应中文转成正确的编码
        App::AppTitle = App::AppTitle.toLatin1();
//        App::NVRType = App::NVRType.toLatin1();
//        App::IPCType = App::IPCType.toLatin1();
        return;
    }

    QSettings *set = new QSettings(fileName, QSettings::IniFormat);

    set->beginGroup("AppConfig");
    App::AppTitle = set->value("AppTitle").toString();
    App::UserNameEncode = set->value("LoginInfo").toString();
//    App::PasswordAes = set->value("Password").toString();
    App::AppStyle = set->value("AppStyle").toString();
    App::VideoSavePath = set->value("VideoSavePath").toString();
    if(!QDir(App::VideoSavePath).exists())
        App::VideoSavePath = App::AppPath.replace("/","\\") + "RECORD";
    App::ImageSavePath = set->value("ImageSavePath").toString();
    if(!QDir(App::ImageSavePath).exists())
        App::ImageSavePath = App::AppPath.replace("/","\\") + "IMAGE";
    App::VideoDelayTime = set->value("VideoDelayTime").toInt();
//    App::UseVideoOffLineCheck = set->value("UseVideoOffLineCheck").toBool();
//    App::VideoOffLineCheckInterval = set->value("VideoOffLineCheckInterval").toInt();
//    App::RtspType = set->value("RtspType").toInt();
    App::AutoRun = set->value("AutoRun").toBool();
    App::AutoPoll = set->value("AutoPoll").toBool();
    App::PollType = set->value("PollType").toInt();
    App::PollInterval = set->value("PollInterval").toInt();
    App::PollSleep = set->value("PollSleep").toInt();
//    App::LoginState = set->value("LoginState").toBool();
    App::VideoType = set->value("VideoType").toString();
    App::DefaultModule = set->value("DefaultModule").toInt();
    App::SystemSettingsWidth = set->value("SystemSettingsWidth").toInt();
    App::SystemSettingsHeight = set->value("SystemSettingsHeight").toInt();
    App::CurrentFormType = set->value("CurrentFormType").toInt();
//    App::RtspAddr16 = set->value("RtspAddr16").toString();
//    App::LastConfig = set->value("LastConfig").toString();
    App::sqlName = set->value("MySQLName").toString();
    App::sqlIP = set->value("MySQLIP").toString();
    App::sqlUsername = set->value("MySQLUsername").toString();
    App::sqlPassword = set->value("MySQLPassword").toString();
//    set->endGroup();

//    set->beginGroup("UserConfig");
//    App::positionString = set->value("MyPosition").toString();
    App::adminWeb = set->value("AdminWeb").toString();
    App::adminWebPort = set->value("AdminWebPort").toString();
//    App::Version = set->value("Version").toString();
    set->endGroup();
}

bool App::isUserPermissionByPId(QString pid){
     int rowCount = App::UserPermissionSource.size();
     bool flag = false;
     for(int i = 0 ; i < rowCount; i++){
             QMap<QString,QString> map = App::UserPermissionSource.at(i);
             QString tempPId = map.value("p_id");
             if(tempPId == pid){
                 flag = true;
                 break;
             }
     }
     return flag;
}

//写入配置文件
void App::WriteConfig()
{
    QString fileName = App::AppPath + "CONFIG/wynlinkconfig.txt";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);

    set->beginGroup("AppConfig");
    set->setValue("AppTitle", App::AppTitle);
    set->setValue("LoginInfo", App::UserNameEncode);
//    set->setValue("Password", App::PasswordAes);
    set->setValue("AppStyle", App::AppStyle);
    set->setValue("VideoSavePath", App::VideoSavePath);
    set->setValue("ImageSavePath", App::ImageSavePath);
    set->setValue("VideoDelayTime", App::VideoDelayTime);
//    set->setValue("UseVideoOffLineCheck", App::UseVideoOffLineCheck);
//    set->setValue("VideoOffLineCheckInterval", App::VideoOffLineCheckInterval);
//    set->setValue("RtspType", App::RtspType);
    set->setValue("AutoRun", App::AutoRun);
    set->setValue("AutoPoll", App::AutoPoll);
    set->setValue("PollType", App::PollType);
    set->setValue("PollInterval", App::PollInterval);
    set->setValue("PollSleep", App::PollSleep);
//    set->setValue("LoginState", App::LoginState);
    set->setValue("VideoType", App::VideoType);
    set->setValue("DefaultModule", App::DefaultModule);
    set->setValue("SystemSettingsWidth", App::SystemSettingsWidth);
    set->setValue("SystemSettingsHeight", App::SystemSettingsHeight);
    set->setValue("CurrentFormType", App::CurrentFormType);
//    set->setValue("RtspAddr16", App::RtspAddr16);
//    set->setValue("LastConfig", App::LastConfig);
//    set->value("MySQLName",App::sqlName);
//    set->value("MySQLIP",App::sqlIP);
//    set->value("MySQLUsername",App::sqlUsername);
//    set->value("MySQLPassword",App::sqlPassword);
//    set->endGroup();

//    set->beginGroup("UserConfig");
//    set->setValue("MyPosition",App::positionString);
    set->setValue("AdminWeb",App::adminWeb);
    set->setValue("AdminWebPort",App::adminWebPort);
//    set->setValue("Version",App::Version);
    set->endGroup();
}
