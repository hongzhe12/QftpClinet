#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QWidget>


namespace Ui
{
class addPerson;
}

class addPerson : public QWidget
{
    Q_OBJECT

public:
    explicit addPerson(QWidget* parent = nullptr);
    ~addPerson();

private slots:
    void on_pushButtonAddButton_clicked();

private:
    Ui::addPerson* ui;
};

#endif // ADDPERSON_H
