#include "person.h"
#include "ui_person.h"


person* person::instance = nullptr;

person::person(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/9040497_lightning_icon.ico"));
    clinet_obj = new Clinet(nullptr);
    QObject::connect(this, SIGNAL(textEntered(QString)), clinet_obj, SLOT(onTextEntered(QString)));

    initDb();
    createTable();
    queryAllData();
}

person::~person()
{
    delete ui;
}


bool person::initDb()
{
    // 检查数据库是否已经初始化
    if(db.isValid())
    {
        qDebug() << "Database has already been initialized.";
        return true;
    }

    // 移除名为 'qt_sql_default_connection' 的连接
    QSqlDatabase::removeDatabase("qt_sql_default_connection");

    // 初始化数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");

    // 打开数据库
    if(!db.open())
    {
        qDebug() << "Failed to open database!";
        return false;
    }

    qDebug() << "数据库打开成功！";

    return true;
}





bool person::createTable()
{
    QSqlQuery query;

    // 创建联系人表
    if(!query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT)"))
    {
        qDebug() << "Failed to create table!";
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

bool person::insertData(const QString& name, const QString& phone)
{
    QSqlQuery query;

    // 插入数据
    query.prepare("INSERT INTO contacts (name, phone) VALUES (:name, :phone)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);

    if(!query.exec())
    {
        qDebug() << "Failed to insert data!";
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool person::updateData(const QString& name, const QString& phone)
{
    QSqlQuery query;

    // 更新数据
    query.prepare("UPDATE contacts SET phone = :phone WHERE name = :name");
    query.bindValue(":phone", phone);
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "Failed to update data!";
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool person::deleteData(const QString& name)
{
    QSqlQuery query;

    // 删除数据
    query.prepare("DELETE FROM contacts WHERE name = :name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "Failed to delete data!";
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool person::queryOneData(const QString& name)
{
    QSqlQuery query;

    // 查询单个数据
    query.prepare("SELECT phone FROM contacts WHERE name = :name");
    query.bindValue(":name", name);

    if(!query.exec())
    {
        qDebug() << "Failed to query data!";
        qDebug() << query.lastError().text();
        return false;
    }

    ui->listWidget->clear();

    if(query.next())
    {
        QString phone = query.value(0).toString();
        ui->listWidget->addItem(name + ": " + phone);
        qDebug() << "查询成功:";
        qDebug() << phone;
        return true;
    }

    return false;
}

bool person::queryAllData()
{
    QSqlQuery query;

    // 查询全部数据
    if(!query.exec("SELECT name, phone FROM contacts"))
    {
        qDebug() << "Failed to query data!";
        qDebug() << query.lastError().text();
        return false;
    }
    ui->listWidget->clear();
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString phone = query.value(1).toString();
        // 渲染数据到列表
        ui->listWidget->addItem(name + ": " + phone);
    }

    return true;
}


void person::on_pushButtonSearch_clicked()
{
    QString name = ui->lineEditSearch->text();
    queryOneData(name);
}


void person::on_pushButtonAddPerson_clicked()
{
    add_ui = new addPerson(nullptr);
    add_ui->show();
}


void person::on_pushButtonOk_clicked()
{
    QSqlQuery query;
    QString phone;
    // 获取当前选择的联系人
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if(selectedItem)
    {
        QString contactInfo = selectedItem->text();
        // 提取联系人姓名
        QString name = contactInfo.split(":").at(0).trimmed();

        // 查询单个数据
        query.prepare("SELECT phone FROM contacts WHERE name = :name");
        query.bindValue(":name", name);

        if(!query.exec())
        {
            qDebug() << "Failed to query data!";
            qDebug() << query.lastError().text();
            return;
        }

        if(query.next())
        {
            phone = query.value(0).toString();
        }

        // 使用QMessageBox显示电话号码
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "联系人电话号码", "联系人：" + name + "\n号码：" + phone, QMessageBox::Ok | QMessageBox::Cancel);

        if(reply == QMessageBox::Ok)
        {
            emit textEntered(phone);
            clinet_obj->show();
        }
        else
        {
            return;
        }

    }

}


void person::on_pushButtonUpdate_clicked()
{
    queryAllData();
}


void person::on_pushButtonAddPersonDelete_clicked()
{
    // 获取当前选择的联系人
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if(selectedItem)
    {
        QString contactInfo = selectedItem->text();
        // 提取联系人姓名
        QString name = contactInfo.split(":").at(0).trimmed();
        bool ans = deleteData(name);
        if(ans)
        {
            QMessageBox::information(this, "成功", "联系人删除成功");
        }
    }


}

