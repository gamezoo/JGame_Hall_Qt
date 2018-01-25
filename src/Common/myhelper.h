#ifndef MYHELPER_H
#define MYHELPER_H

#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#include <QtNetwork>
#include "frmmessagebox.h"
#include "frminputbox.h"

/* 说明:全局辅助操作类实现文件
 * 功能:窗体显示/编码设置/开机启动/文件选择与复制/对话框等
 */
class myHelper: public QObject
{

public:

    //设置为开机启动
    static void AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath) {
        QSettings *reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (IsAutoRun) {
            reg->setValue(AppName, AppPath);
        } else {
            reg->setValue(AppName, "");
        }
    }

    //设置应用程序通过UAC
    static void SetApplicationPassUAC(QString AppPath, QString AppValue) {
        QSettings *reg = new QSettings(
            "HKEY_CURRENT_USERS\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers",
            QSettings::NativeFormat);
        QString tempAppValue = reg->value(AppPath).toString();
        if(tempAppValue == "RunAsInvoker")
            return;
        else
            reg->setValue(AppPath, AppValue);
    }

    //设置编码为UTF8
    static void SetUTF8Code() {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    }

	static void SetCharacterCode(const QString &codeName)
	{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
		QTextCodec *codec = QTextCodec::codecForName(codeName.toLocal8Bit());
		QTextCodec::setCodecForLocale(codec);
		QTextCodec::setCodecForCStrings(codec);
		QTextCodec::setCodecForTr(codec);
#endif
	}

    //设置为中文字符
    static void SetChinese() {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(":/image/qt_zh_CN.qm");
        qApp->installTranslator(translator);
    }

    static void LoadTranslator(const QString &transFile) {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(transFile);
        qApp->installTranslator(translator);
    }
    //设置指定样式
    static void LoadStyleFile(const QString &qssFile) {
        QFile file(qssFile);
        if (file.open(QFile::ReadOnly)) {
            QString qss = QLatin1String(file.readAll());
            qApp->setStyleSheet(qss);
            file.close();
        }
    }

    //设置指定样式
    static void SetStyle(const QString &qssFile) {
        QFile file(qssFile);
        if (file.open(QFile::ReadOnly)) {
            QString qss = QLatin1String(file.readAll());
            QString PaletteColor = qss.mid(20, 7);
            qApp->setPalette(QPalette(QColor(PaletteColor)));
            qApp->setStyleSheet(qss);
            file.close();
        }
    }

    //获取本地用户名和IP地址
    static QString GetLocalIP(){
        QString localHostName = QHostInfo::localHostName();
        QHostInfo info = QHostInfo::fromName(localHostName);
        foreach(QHostAddress address,info.addresses())
        {
            if(address.protocol() == QAbstractSocket::IPv4Protocol)
                return address.toString();
        }
        return QString("");
    }

    //判断本地ip是否在地址列表中，ipList为IP地址列表的起始地址
    static bool IsIpInIpList(QString localIP,QString baseIP)
    {
        if(localIP.contains(".") && baseIP.contains("."))
        {
            QStringList localIPSplit = localIP.split(".");
            QStringList baseIPSplit = baseIP.split(".");
            if(localIPSplit.count() != 4 || baseIPSplit.count() != 4)
            {
                return false;//不是IP地址
            }
            else
            {
                QString localip_pre = localIPSplit[0]+"."+localIPSplit[1]+"."+localIPSplit[2];//本地IP前缀
                QString localip_suf = localIPSplit[3];//本地IP后缀
                QString baseip_pre = baseIPSplit[0]+"."+baseIPSplit[1]+"."+baseIPSplit[2];//起始IP前缀
                QString baseip_suf = baseIPSplit[3];//起始IP后缀
                if(localip_pre == baseip_pre)
                {
                    int _localip_suf = localip_suf.toInt();
                    int _baseip_suf = baseip_suf.toInt();
                    if(_localip_suf > _baseip_suf && _localip_suf < _baseip_suf+32)
                    {
                        return true;//IP在当前段
                    }
                    else
                    {
                        return false;//IP不在当前段
                    }
                }
                else
                {
                    return false;//IP不在当前段
                }
            }
        }
        else
        {
            return false;//不是IP地址
        }
    }

    //判断是否是IP地址
    static bool IsIP(QString IP) {
        QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return RegExp.exactMatch(IP);
    }

    //显示输入框
    static QString ShowInputBox(QString info, bool &ok) {
        frmInputBox input;
        input.SetMessage(info);
        ok = input.exec();
        return input.GetValue();
    }

    //显示信息框,仅确定按钮
    static void ShowMessageBoxInfo(QString info) {
        frmMessageBox msg ;
        msg.SetMessage(info, 0);
        msg.exec();
    }

    //显示错误框,仅确定按钮
    static void ShowMessageBoxError(QString info) {
        frmMessageBox msg;
        msg.SetMessage(info, 2);
        msg.exec();
    }

    //显示询问框,确定和取消按钮
    static int ShowMessageBoxQuesion(QString info) {
        frmMessageBox msg;
		msg.setWindowTitle(QString("提示"));
        msg.SetMessage(info, 1);
        return msg.exec();
    }

    //16进制字符串转字节数组
    static QByteArray HexStrToByteArray(QString str) {
        QByteArray senddata;
        int hexdata, lowhexdata;
        int hexdatalen = 0;
        int len = str.length();
        senddata.resize(len / 2);
        char lstr, hstr;
        for (int i = 0; i < len; ) {
            hstr = str[i].toLatin1();
            if (hstr == ' ') {
                i++;
                continue;
            }
            i++;
            if (i >= len) {
                break;
            }
            lstr = str[i].toLatin1();
            hexdata = ConvertHexChar(hstr);
            lowhexdata = ConvertHexChar(lstr);
            if ((hexdata == 16) || (lowhexdata == 16)) {
                break;
            } else {
                hexdata = hexdata * 16 + lowhexdata;
            }
            i++;
            senddata[hexdatalen] = (char)hexdata;
            hexdatalen++;
        }
        senddata.resize(hexdatalen);
        return senddata;
    }

    static char ConvertHexChar(char ch) {
        if ((ch >= '0') && (ch <= '9')) {
            return ch - 0x30;
        } else if ((ch >= 'A') && (ch <= 'F')) {
            return ch - 'A' + 10;
        } else if ((ch >= 'a') && (ch <= 'f')) {
            return ch - 'a' + 10;
        } else {
            return (-1);
        }
    }

    //字节数组转16进制字符串
    static QString ByteArrayToHexStr(QByteArray data) {
        QString temp = "";
        QString hex = data.toHex();
        for (int i = 0; i < hex.length(); i = i + 2) {
            temp += hex.mid(i, 2) + " ";
        }
        return temp.trimmed().toUpper();
    }

    //16进制字符串转10进制
    static int StrHexToDecimal(QString strHex) {
        bool ok;
        return strHex.toInt(&ok, 16);
    }

    //10进制字符串转10进制
    static int StrDecimalToDecimal(QString strDecimal) {
        bool ok;
        return strDecimal.toInt(&ok, 10);
    }

    //2进制字符串转10进制
    static int StrBinToDecimal(QString strBin) {
        bool ok;
        return strBin.toInt(&ok, 2);
    }

    //16进制字符串转2进制字符串
    static QString StrHexToStrBin(QString strHex) {
        uchar decimal = StrHexToDecimal(strHex);
        QString bin = QString::number(decimal, 2);
        uchar len = bin.length();
        if (len < 8) {
            for (int i = 0; i < 8 - len; i++) {
                bin = "0" + bin;
            }
        }
        return bin;
    }

    //10进制转2进制字符串一个字节
    static QString DecimalToStrBin1(int decimal) {
        QString bin = QString::number(decimal, 2);
        uchar len = bin.length();
        if (len <= 8) {
            for (int i = 0; i < 8 - len; i++) {
                bin = "0" + bin;
            }
        }
        return bin;
    }

    //10进制转2进制字符串两个字节
    static QString DecimalToStrBin2(int decimal) {
        QString bin = QString::number(decimal, 2);
        uchar len = bin.length();
        if (len <= 16) {
            for (int i = 0; i < 16 - len; i++) {
                bin = "0" + bin;
            }
        }
        return bin;
    }

    //10进制转16进制字符串,补零.
    static QString DecimalToStrHex(int decimal) {
        QString temp = QString::number(decimal, 16);
        if (temp.length() == 1) {
            temp = "0" + temp;
        }
        return temp;
    }

    //延时
    static void Sleep(int msec) {
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while ( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    //设置系统日期时间
    static void SetSystemDateTime(int year, int month, int day, int hour, int min, int sec) {
        QProcess p;

        p.start("cmd");
        p.waitForStarted();
        p.write(QString("date %1-%2-%3\n").arg(year).arg(month).arg(day).toLatin1());
        p.closeWriteChannel();
        p.waitForFinished(1000);
        p.close();

        p.start("cmd");
        p.waitForStarted();
        p.write(QString("time %1:%2:%3.00\n").arg(hour).arg(min).arg(sec).toLatin1());
        p.closeWriteChannel();
        p.waitForFinished(1000);
        p.close();
    }

    //设置时间同步，需管理员权限
    static void SetResync() {
        QProcess p;

        p.start("cmd");
        p.waitForStarted();
        p.write(QString("w32tm /resync").toLatin1());
        p.closeWriteChannel();
        p.waitForFinished(2000);
        p.close();
    }

    static void SetResyncForAdministrator() {
        QProcess p;

        p.start("cmd");
        p.waitForStarted();
        p.write(QString("runas /noprofile /user:Administrator cmd").toLatin1());
        p.closeWriteChannel();
        p.waitForFinished(1000);

        frmInputBox inputPassword;
		inputPassword.SetMessage("请输入管理员密码: ");
        int ok  = inputPassword.exec();
        if(ok)
        {
            p.write(inputPassword.GetValue().toLatin1());
            p.closeWriteChannel();
            p.waitForFinished(1000);
            p.write(QString("w32tm /resync").toLatin1());
            p.closeWriteChannel();
            p.waitForFinished(2000);
        }
        p.close();
    }

    //窗体居中显示
    static void FormInCenter(QWidget *frm, int deskWidth, int deskHeigth) {
        int frmX = frm->width();
        int frmY = frm->height();
        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeigth / 2 - frmY / 2);
        frm->move(movePoint);
    }

    //获取选择的文件
    static QString GetFileName(QString filter) {
        return QFileDialog::getOpenFileName(0, "选择文件", QCoreApplication::applicationDirPath(), filter);
    }

    //获取选择的文件集合
    static QStringList GetFileNames(QString filter) {
        return QFileDialog::getOpenFileNames(0, "选择文件", QCoreApplication::applicationDirPath(), filter);
    }

    //获取选择的目录
    static QString GetFolderName() {
        return QFileDialog::getExistingDirectory();;
    }

    //获取文件名,含拓展名
    static QString GetFileNameWithExtension(QString strFilePath) {
        QFileInfo fileInfo(strFilePath);
        return fileInfo.fileName();
    }

    //获取选择文件夹中的文件
    static QStringList GetFolderFileNames(QStringList filter) {
        QStringList fileList;
        QString strFolder = QFileDialog::getExistingDirectory();
        if (!strFolder.length() == 0) {
            QDir myFolder(strFolder);
            if (myFolder.exists()) {
                fileList = myFolder.entryList(filter);
            }
        }
        return fileList;
    }

    //文件夹是否存在
    static bool FolderIsExist(QString strFolder) {
        QDir tempFolder(strFolder);
        return tempFolder.exists();
    }

    //文件是否存在
    static bool FileIsExist(QString strFile) {
        QFile tempFile(strFile);
        return tempFile.exists();
    }

    //复制文件
    static bool CopyFile(QString sourceFile, QString targetFile) {
        if (FileIsExist(targetFile)) {
            if (ShowMessageBoxQuesion("文件已经存在,是否替换?") == 1) {
                return false;
            }
        }
        return QFile::copy(sourceFile, targetFile);
    }

    //异或加密算法，加密时使用用户不使用的字符，否则会出现字符串中出现'\0',导致字符获取识别
    static QString getXorEncryptDecrypt(QString str, char key) {
        QByteArray data = str.toLatin1();
        int size = data.size();
        for (int i = 0; i < size; i++) {
            data[i] = data[i] ^ key;
        }
        return QLatin1String(data);
    }

    //检查摄像机是否在线
    static bool IPCEnable(QString IPAddr,quint16 port = 80) {
        QTcpSocket tcpClient;
        tcpClient.abort();
        tcpClient.connectToHost(IPAddr, port);
        //100毫秒没有连接上则判断该摄像机不在线
        bool ok = tcpClient.waitForConnected(300);
        return ok;
    }

    //生成RTSP主码流
    static QString GetRTSPAddrMain(QString IPAddr,QString brand,QString username,QString pwd) {
        QString tempRTSPMain;
        if(brand == "海康")
        {
            tempRTSPMain = "rtsp://" + username + ":" + pwd + "@" + IPAddr + ":554/h264/ch1/main/av_stream";
            return tempRTSPMain;
        }
        else if(brand == "测试")
        {
            tempRTSPMain = "rtsp://" + IPAddr + ":8554/test.264";
            return tempRTSPMain;
        }
    }

    //生成RTSP子码流
    static QString GetRTSPAddrSub(QString IPAddr,QString brand,QString username,QString pwd) {
        QString tempRTSPSub;
        if(brand == "海康")
        {
            tempRTSPSub = "rtsp://" + username + ":" + pwd + "@" + IPAddr + ":554/h264/ch1/sub/av_stream";
            return tempRTSPSub;
        }
        else if(brand == "测试")
        {
            tempRTSPSub = "rtsp://" + IPAddr + ":8554/test.264";
            return tempRTSPSub;
        }
    }

//    //检查摄像机是否在线
//    //海康
//    static bool IPCEnable(QString rtspAddr) {
//        QStringList temp1 = rtspAddr.split(":");
//        QStringList temp2 = rtspAddr.split("@");
//        QStringList temp = rtspAddr.split("/");
//        if(temp1.count() == 4 && temp2.count() == 2 && temp.count() == 7)
//        {
//            if(temp[2].contains("@"))
//            {
//                QString ip = temp[2].split("@")[1].split(":")[0];
//                QTcpSocket tcpClient;
//                tcpClient.abort();
//                tcpClient.connectToHost(ip, 80);
//                //100毫秒没有连接上则判断该摄像机不在线
//                bool ok = tcpClient.waitForConnected(100);
//                return ok;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        else
//        {
//            if(temp1.count() == 3 && temp2.count() == 1 && temp.count() == 4)
//            {
//                QString ip = temp[2].split(":")[0];
//                QTcpSocket tcpClient;
//                tcpClient.abort();
//                tcpClient.connectToHost(ip, 80);
//                //100毫秒没有连接上则判断该摄像机不在线
//                bool ok = tcpClient.waitForConnected(100);
//                return ok;
//            }
//        }
//    }
    //本地测试视频
//    static bool IPCEnable(QString rtspAddr) {
//        QStringList temp = rtspAddr.split("/");
//        QString ip = temp[2].split(":")[0];
//        qDebug() << ip;
//        QTcpSocket tcpClient;
//        tcpClient.abort();
//        tcpClient.connectToHost(ip, 80);
//        //100毫秒没有连接上则判断该摄像机不在线
//        bool ok = tcpClient.waitForConnected(100);
//        return ok;
//    }
};

#endif // MYHELPER_H
