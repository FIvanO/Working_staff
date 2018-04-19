#include "bank.h"
#include "bankaccount.h"

Bank::Bank(QObject *parent) : QObject(parent)
{
}

long Bank::totalBalance() const
{
    long totalBalance = 0;
    //TODO: refactor this for

//            for(int i = 0; i < this->children().length(); ++i) {
//            QObject *child = this->children().at(i);
//            if (this->children().at(i)->inherits("BankAccount")) {
//                totalBalance += qobject_cast<const BankAccount *> (child)->balance();
//            }
//        }

    for (auto child : this->children()) {
        if (child->inherits("BankAccount")) {
            const BankAccount *temp = qobject_cast<const BankAccount *> (child);
            if (temp != NULL) {
                totalBalance += temp->balance();
            }
        }
    }
    return totalBalance;
}

// TODO: implement slot to listen accounts and emit totalBalanceChanged signal

void Bank::updateTotalBalance()
{
//    qDebug() << "updateTotalBalance!!!";
    emit totalBalanceChanged(totalBalance());
}
