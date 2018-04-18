#include "mainwidget.h"
#include "bank.h"
#include "bankaccount.h"
#include "logger.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWidget w;

    BankAccount *account = new BankAccount(&w);
    account->setObjectName("account");
    QObject::connect(
        account, &BankAccount::balanceChanged,
        &w, &MainWidget::updateInfo
    );
    QObject::connect(
        account, &BankAccount::balanceNegative,
        &w, &MainWidget::balanceNegative);
    QObject::connect(
        account, &BankAccount::wrongData,
        &w, &MainWidget::wrongData);
    w.show();

    return a.exec();
}
