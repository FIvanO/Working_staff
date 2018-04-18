#include "bankaccount.h"

BankAccount::BankAccount(QObject *parent) : QObject(parent)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals
    connect(
        this, SIGNAL(balanceChanged(long)),
        parent, SLOT(updateTotalBalance())
    );
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    if (newBalance < 0) {
        emit balanceNegative();
        return;
    }
    if (m_balance == newBalance) {
        return;
    }

    m_balance = newBalance;
    // TODO: add here signal emition
    emit balanceChanged(m_balance);
}


void BankAccount::deposit(long amount)
{
    Q_ASSERT(amount > 0);
    // TODO: implement this function
    try {
        setBalance(m_balance + amount);
    }
    catch (...) {
        emit wrongData();
    }
}

void BankAccount::withdraw(long amount)
{
    Q_ASSERT(amount > 0);
    // TODO: implement this function
    try {
        setBalance(m_balance + amount);
    }
    catch (...) {
        emit wrongData();
    }
}
