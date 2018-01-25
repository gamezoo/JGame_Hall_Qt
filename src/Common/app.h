#ifndef APP_H
#define APP_H
#include <QList>
#include <QMap>
#include <QStringList>

class QString;

class App
{
public:
    static QString AppPath;                 //应用程序路径
    static int AppFontSize;                 //应用程序字体大小
    static QString AppFontName;             //应用程序字体名称
    static int DeskWidth;                   //桌面可用宽度
    static int DeskHeight;                  //桌面可用高度

    static QString AppTitle;                //界面标题
//    static QString NVRType;                 //硬盘录像机厂家
//    static QString IPCType;                 //网络摄像机厂家
    static QString AppStyle;                //界面样式
    static QString VideoSavePath;           //视频保存路径
    static QString ImageSavePath;           //截图保存路径
    static int VideoDelayTime;              //视频加载响应延时时间
//    static bool UseVideoOffLineCheck;       //视频断线检测
//    static int VideoOffLineCheckInterval;   //视频断线检测间隔
    static int RtspType;                    //码流类型
    static bool AutoRun;                    //开机自动运行
    static bool AutoPoll;                   //自动轮询
    static int PollType;                    //轮询画面数
    static int PollInterval;                //轮询间隔
    static int PollSleep;                   //轮询延时
//    static QString RtspAddr16;              //16个通道对应rtsp地址
    static QString VideoType;               //当前画面展示类型
//    static QString LastConfig;              //软件最后配置信息

    static int UserID;                      //用户编号
    static QString UserName;                //用户名称
    static QString UserNameAes;                //用户名称
    static QString PasswordAes;                //用户密码
    static QString UserNameEncode;             //用户加密信息
    static int RoleID;                      //角色编号

    static void ReadConfig();               //读取配置文件
	static void ReadConfigHall();           //读取配置文件
    static void WriteConfig();              //写入配置文件
    static bool LoginState;                 //登陆状态
    static int  DefaultModule;              //登陆时默认界面
//    static int FormType[6];
    static int CurrentFormType;             //当前视频Label布局
    static int FormTypeForDoubleClick;      //保存双击前Label布局，用于还原
    static int SystemSettingsWidth;
    static int SystemSettingsHeight;
    static int SystemUserAuthWidth;
    static int SystemUserAuthHeight;
    static  QList<QMap<QString,QString> > UserPermissionSource; //当前用户权限;
    static bool isUserPermissionByPId(QString pid); //通过Pid判断此用户是否有对应查看模块权限
    static QString sqlName;
    static QString sqlIP;
    static QString sqlUsername;
    static QString sqlPassword;
//    static QString positionString;
    static QString adminWeb;
    static QString adminWebPort;
    static QStringList UserRegion;
    static QString Version;
};

#endif // APP_H
