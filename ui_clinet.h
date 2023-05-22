/********************************************************************************
** Form generated from reading UI file 'clinet.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINET_H
#define UI_CLINET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clinet
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditClinetIP;
    QLabel *label_2;
    QSpinBox *spinBoxClientPort;
    QPushButton *pushButtonSendFile;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditSendFile;
    QPushButton *pushButtonSelectFile;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QProgressBar *progressBarSendProgress;

    void setupUi(QWidget *Clinet)
    {
        if (Clinet->objectName().isEmpty())
            Clinet->setObjectName(QString::fromUtf8("Clinet"));
        Clinet->resize(400, 269);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Clinet->setWindowIcon(icon);
        layoutWidget = new QWidget(Clinet);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 381, 231));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditClinetIP = new QLineEdit(layoutWidget);
        lineEditClinetIP->setObjectName(QString::fromUtf8("lineEditClinetIP"));

        horizontalLayout->addWidget(lineEditClinetIP);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxClientPort = new QSpinBox(layoutWidget);
        spinBoxClientPort->setObjectName(QString::fromUtf8("spinBoxClientPort"));
        spinBoxClientPort->setMinimum(1024);
        spinBoxClientPort->setMaximum(88888);
        spinBoxClientPort->setValue(12345);

        horizontalLayout->addWidget(spinBoxClientPort);

        pushButtonSendFile = new QPushButton(layoutWidget);
        pushButtonSendFile->setObjectName(QString::fromUtf8("pushButtonSendFile"));

        horizontalLayout->addWidget(pushButtonSendFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditSendFile = new QLineEdit(layoutWidget);
        lineEditSendFile->setObjectName(QString::fromUtf8("lineEditSendFile"));
        lineEditSendFile->setEnabled(false);

        horizontalLayout_2->addWidget(lineEditSendFile);

        pushButtonSelectFile = new QPushButton(layoutWidget);
        pushButtonSelectFile->setObjectName(QString::fromUtf8("pushButtonSelectFile"));

        horizontalLayout_2->addWidget(pushButtonSelectFile);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        progressBarSendProgress = new QProgressBar(layoutWidget);
        progressBarSendProgress->setObjectName(QString::fromUtf8("progressBarSendProgress"));
        progressBarSendProgress->setValue(0);

        horizontalLayout_3->addWidget(progressBarSendProgress);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Clinet);

        QMetaObject::connectSlotsByName(Clinet);
    } // setupUi

    void retranslateUi(QWidget *Clinet)
    {
        Clinet->setWindowTitle(QCoreApplication::translate("Clinet", "\351\230\277\347\213\270\347\232\204\344\274\240\350\276\223\345\267\245\345\205\267(\345\217\221\351\200\201\346\226\271)", nullptr));
        label->setText(QCoreApplication::translate("Clinet", "\345\217\221\351\200\201\347\253\257 IP", nullptr));
        lineEditClinetIP->setText(QCoreApplication::translate("Clinet", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("Clinet", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        pushButtonSendFile->setText(QCoreApplication::translate("Clinet", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("Clinet", "\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
        pushButtonSelectFile->setText(QCoreApplication::translate("Clinet", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label_5->setText(QCoreApplication::translate("Clinet", "\345\217\221\351\200\201\350\277\233\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clinet: public Ui_Clinet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINET_H
