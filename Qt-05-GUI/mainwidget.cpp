#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "bankaccount.h"
#include <QMessageBox>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->depositRadioButton->click();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::updateInfo()
{
    BankAccount *account = findChild<BankAccount *>("account");
    long balance = account->balance();
    QLineEdit *totalBalanceLineEdit = findChild<QLineEdit *>("totalBalanceLineEdit");
    totalBalanceLineEdit->setText(QString::number(balance));
}

void MainWidget::on_operationPushButton_clicked()
{
    QString amountText
        = findChild<QLineEdit *>("amountLineEdit")
            ->text();
    BankAccount *account
        = findChild<BankAccount *>("account");
    try {

        long amount = amountText.toLong();
        if (findChild<QRadioButton *>("depositRadioButton")
                ->isChecked()) {
            account->deposit(amount);
        }
        if (findChild<QRadioButton *>("withdrawRadioButton")
               ->isChecked()) {
            account->withdraw(amount);
        }
    }
    catch (...) {
        emit account->wrongData();
    }
}

void MainWidget::balanceNegative()
{
    QMessageBox *mb = new QMessageBox;
    mb->setText("Error! Negative balance!");
    mb->addButton("OK", QMessageBox::AcceptRole);
    mb->show();
}

void MainWidget::wrongData()
{
    QMessageBox *mb = new QMessageBox;
    mb->setText("Error! Wrong data format!");
    mb->addButton("OK", QMessageBox::AcceptRole);
    mb->show();
}
