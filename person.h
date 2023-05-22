#ifndef PERSON_H
#define PERSON_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>
#include <QListWidget>

#include <QMessageBox>
#include "addperson.h"
#include "clinet.h"
namespace Ui
{
class person;
}

class person : public QWidget
{
    Q_OBJECT

public:
    explicit person(QWidget* parent = nullptr);
    ~person();

signals:
    void textEntered(const QString& text);


private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonAddPerson_clicked();

    void on_pushButtonOk_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonAddPersonDelete_clicked();


private:
    Ui::person* ui;
    addPerson* add_ui;
    // 数据库连接对象
    QSqlDatabase db;
    static person* instance;
    Clinet* clinet_obj;

public:
    bool initDb();
    bool createTable();
    bool insertData(const QString& name, const QString& phone);
    bool updateData(const QString& name, const QString& phone);
    bool deleteData(const QString& name);
    bool queryOneData(const QString& name);
    bool queryAllData();

public:
    static person* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new person();
        }
        return instance;
    }

};

#endif // PERSON_H
