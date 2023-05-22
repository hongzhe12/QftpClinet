#include "addperson.h"
#include "ui_addperson.h"
#include "ui_person.h"
#include "person.h"



addPerson::addPerson(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::addPerson)
{
    ui->setupUi(this);
}

addPerson::~addPerson()
{
    delete ui;
}




void addPerson::on_pushButtonAddButton_clicked()
{

    person* p = person::getInstance();

    // 获取姓名和电话号码输入框的文本
    QString name = ui->lineEditName->text();
    QString phone = ui->lineEditPhone->text();

    // 查询姓名是否存在
    bool isExists = p->queryOneData(name);

    if(isExists)
    {
        bool success = p->updateData(name, phone);
        if(success)
        {
            // 数据插入成功
            QMessageBox::information(this, "成功", "联系人更新成功");
            // 在此添加其他操作或显示消息
        }
        else
        {
            // 数据插入失败
            QMessageBox::critical(this, "错误", "联系人更新失败");
            // 在此添加错误处理或显示消息
        }
    }
    else
    {
        // 调用person对象的insertData函数
        bool success = p->insertData(name, phone);
        if(success)
        {
            // 数据插入成功
            QMessageBox::information(this, "成功", "联系人添加成功");
            // 在此添加其他操作或显示消息
        }
        else
        {
            // 数据插入失败
            QMessageBox::critical(this, "错误", "联系人添加失败");
            // 在此添加错误处理或显示消息
        }
    }
}


