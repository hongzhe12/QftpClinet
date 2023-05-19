#ifndef CLINET_H
#define CLINET_H

#include <QWidget>
#include <QObject>
#include <QFileDialog>
#include <QtCore>
#include <QtNetwork>
#include <QMessageBox>
namespace Ui
{
class Clinet;
}

class Clinet : public QWidget
{
    Q_OBJECT

public:
    explicit Clinet(QWidget* parent = nullptr);
    ~Clinet();

private slots:
    void on_pushButtonSelectFile_clicked();

    void on_pushButtonSendFile_clicked();

private:
    Ui::Clinet* ui;
};

// 校验IP地址
static bool IsVaild_IP(QString strIP)
{
    QRegularExpression rx2("(\\d+)(\\.)(\\d+)(\\.)(\\d+)(\\.)(\\d+)");
    if(!rx2.match(strIP).hasMatch())
    {
        return false;
    }
    else
    {
        QStringList list = strIP.split(".");
        for(int i = 0; i < list.count(); i++)
        {
            if(list.at(i).toInt() > 255)
            {
                return false;
            }
        }
    }
    return true;
}
#endif // CLINET_H
