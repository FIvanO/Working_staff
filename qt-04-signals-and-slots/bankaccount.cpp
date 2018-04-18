#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    // TODO: connect Bank slots to BankAccount signals
    connect(
        this, SIGNAL(balanceChanged(long)),
        parentBank, SLOT(updateTotalBalance())
    );
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    Q_ASSERT(newBalance > 0);
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
    setBalance(m_balance + amount);
}

void BankAccount::withdraw(long amount)
{
    Q_ASSERT(amount > 0);
    // TODO: implement this function
    setBalance(m_balance - amount);
}
