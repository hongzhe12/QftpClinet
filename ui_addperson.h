/********************************************************************************
** Form generated from reading UI file 'addperson.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSON_H
#define UI_ADDPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addPerson
{
public:
    QPushButton *pushButtonAddButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPhone;

    void setupUi(QWidget *addPerson)
    {
        if (addPerson->objectName().isEmpty())
            addPerson->setObjectName(QString::fromUtf8("addPerson"));
        addPerson->resize(229, 197);
        pushButtonAddButton = new QPushButton(addPerson);
        pushButtonAddButton->setObjectName(QString::fromUtf8("pushButtonAddButton"));
        pushButtonAddButton->setGeometry(QRect(80, 120, 71, 21));
        widget = new QWidget(addPerson);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 40, 126, 54));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        horizontalLayout->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditPhone = new QLineEdit(widget);
        lineEditPhone->setObjectName(QString::fromUtf8("lineEditPhone"));

        horizontalLayout_2->addWidget(lineEditPhone);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(addPerson);

        QMetaObject::connectSlotsByName(addPerson);
    } // setupUi

    void retranslateUi(QWidget *addPerson)
    {
        addPerson->setWindowTitle(QCoreApplication::translate("addPerson", "\346\267\273\345\212\240\350\201\224\347\263\273\344\272\272", nullptr));
        pushButtonAddButton->setText(QCoreApplication::translate("addPerson", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("addPerson", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("addPerson", "\347\224\265\350\257\235\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addPerson: public Ui_addPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSON_H
