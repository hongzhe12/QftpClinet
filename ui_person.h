/********************************************************************************
** Form generated from reading UI file 'person.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSON_H
#define UI_PERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_person
{
public:
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonUpdate;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonAddPerson;
    QPushButton *pushButtonAddPersonDelete;

    void setupUi(QWidget *person)
    {
        if (person->objectName().isEmpty())
            person->setObjectName(QString::fromUtf8("person"));
        person->resize(300, 331);
        listWidget = new QListWidget(person);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 60, 241, 192));
        layoutWidget = new QWidget(person);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 241, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditSearch = new QLineEdit(layoutWidget);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));

        horizontalLayout->addWidget(lineEditSearch);

        pushButtonSearch = new QPushButton(layoutWidget);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));

        horizontalLayout->addWidget(pushButtonSearch);

        pushButtonUpdate = new QPushButton(person);
        pushButtonUpdate->setObjectName(QString::fromUtf8("pushButtonUpdate"));
        pushButtonUpdate->setGeometry(QRect(200, 270, 70, 20));
        pushButtonOk = new QPushButton(person);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(200, 300, 70, 20));
        pushButtonAddPerson = new QPushButton(person);
        pushButtonAddPerson->setObjectName(QString::fromUtf8("pushButtonAddPerson"));
        pushButtonAddPerson->setGeometry(QRect(30, 270, 70, 20));
        pushButtonAddPersonDelete = new QPushButton(person);
        pushButtonAddPersonDelete->setObjectName(QString::fromUtf8("pushButtonAddPersonDelete"));
        pushButtonAddPersonDelete->setGeometry(QRect(30, 300, 70, 20));

        retranslateUi(person);

        QMetaObject::connectSlotsByName(person);
    } // setupUi

    void retranslateUi(QWidget *person)
    {
        person->setWindowTitle(QCoreApplication::translate("person", "\351\200\232\350\256\257\345\275\225", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("person", "\346\220\234\347\264\242", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("person", "\345\210\267\346\226\260", nullptr));
        pushButtonOk->setText(QCoreApplication::translate("person", "\351\200\211\346\213\251", nullptr));
        pushButtonAddPerson->setText(QCoreApplication::translate("person", "\346\267\273\345\212\240/\344\277\256\346\224\271", nullptr));
        pushButtonAddPersonDelete->setText(QCoreApplication::translate("person", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class person: public Ui_person {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSON_H
