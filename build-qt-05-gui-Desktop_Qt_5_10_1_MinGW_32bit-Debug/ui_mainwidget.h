/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *totalBalance;
    QLineEdit *totalBalanceLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *depositRadioButton;
    QRadioButton *withdrawRadioButton;
    QLabel *amount;
    QLineEdit *amountLineEdit;
    QPushButton *operationPushButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(360, 252);
        MainWidget->setMinimumSize(QSize(313, 223));
        MainWidget->setMaximumSize(QSize(360, 252));
        verticalLayout_2 = new QVBoxLayout(MainWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        totalBalance = new QLabel(MainWidget);
        totalBalance->setObjectName(QStringLiteral("totalBalance"));

        horizontalLayout_3->addWidget(totalBalance);

        totalBalanceLineEdit = new QLineEdit(MainWidget);
        totalBalanceLineEdit->setObjectName(QStringLiteral("totalBalanceLineEdit"));
        totalBalanceLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(totalBalanceLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        depositRadioButton = new QRadioButton(groupBox);
        depositRadioButton->setObjectName(QStringLiteral("depositRadioButton"));

        verticalLayout->addWidget(depositRadioButton);

        withdrawRadioButton = new QRadioButton(groupBox);
        withdrawRadioButton->setObjectName(QStringLiteral("withdrawRadioButton"));

        verticalLayout->addWidget(withdrawRadioButton);


        horizontalLayout_4->addWidget(groupBox);

        amount = new QLabel(MainWidget);
        amount->setObjectName(QStringLiteral("amount"));

        horizontalLayout_4->addWidget(amount);

        amountLineEdit = new QLineEdit(MainWidget);
        amountLineEdit->setObjectName(QStringLiteral("amountLineEdit"));

        horizontalLayout_4->addWidget(amountLineEdit);

        operationPushButton = new QPushButton(MainWidget);
        operationPushButton->setObjectName(QStringLiteral("operationPushButton"));

        horizontalLayout_4->addWidget(operationPushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        totalBalance->setText(QApplication::translate("MainWidget", "Total balance:", nullptr));
        groupBox->setTitle(QApplication::translate("MainWidget", "Operations", nullptr));
        depositRadioButton->setText(QApplication::translate("MainWidget", "Deposit", nullptr));
        withdrawRadioButton->setText(QApplication::translate("MainWidget", "Withdraw", nullptr));
        amount->setText(QApplication::translate("MainWidget", "Amount:", nullptr));
        operationPushButton->setText(QApplication::translate("MainWidget", "Do", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
