#include "clinet.h"
#include "ui_clinet.h"

Clinet::Clinet(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Clinet)
{
    ui->setupUi(this);
}

Clinet::~Clinet()
{
    delete ui;
}



// 选择文件按钮
void Clinet::on_pushButtonSelectFile_clicked()
{
    QString strFilter = "所有文件(*.*)";
    QString filepath = QFileDialog::getOpenFileName(0, "选择文件", QCoreApplication::applicationDirPath(), strFilter);
    ui->lineEditSendFile->setText(filepath);
}


// 发送按钮
void Clinet::on_pushButtonSendFile_clicked()
{
    // 获取文件名和路径
    QString filePath = ui->lineEditSendFile->text();
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    // 获取IP和端口
    QString ip =  ui->lineEditClinetIP->text();
    int port = ui->spinBoxClientPort->value();

    // 检查文件是否存在
    if(!fileInfo.exists())
    {
        QMessageBox::critical(this, "Error", "File does not exist");
        return;
    }



    // 校验IP合法性
    bool ip_is_valid = IsVaild_IP(ip);

    if(!ip_is_valid)
    {
        QMessageBox::critical(this, "Error", "非法的IP地址！");
        return;
    }



    // 创建套接字并连接到目标主机
    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);

    // 等待连接成功
    if(!socket->waitForConnected(5000))
    {
        QMessageBox::critical(this, "Error", "Could not connect to host");
        return;
    }

    // 发送文件名和文件大小
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out << qint64(0) << qint64(0) << fileName << qint64(fileInfo.size());

    // 计算发送的数据大小
    qint64 totalBytes = data.size() + fileInfo.size();
    qint64 bytesWritten = 0;
    ui->progressBarSendProgress->setMaximum(totalBytes);
    ui->progressBarSendProgress->setValue(bytesWritten);

    // 发送数据
    socket->write(data);
    bytesWritten += data.size();

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }

    qint64 bytesToWrite = fileInfo.size();
    qint64 bytesWrittenFromFile = 0;
    while(bytesToWrite > 0)
    {
        QByteArray buffer = file.read(qMin(bytesToWrite, qint64(8192)));
        bytesWrittenFromFile = socket->write(buffer);
        bytesWritten += bytesWrittenFromFile;
        bytesToWrite -= bytesWrittenFromFile;
        ui->progressBarSendProgress->setValue(bytesWritten);
    }

    file.close();

    // 等待数据发送完成
    socket->waitForBytesWritten(5000);

    // 关闭套接字
    socket->close();
    socket->deleteLater();
    QMessageBox::information(this, "阿狸文件工具", "文件已经成功发送！", QMessageBox::Ok);
    return;
}

