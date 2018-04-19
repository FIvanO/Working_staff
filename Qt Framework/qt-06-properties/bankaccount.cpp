#include "bankaccount.h"

BankAccount::BankAccount(QObject *parent) : QObject(parent)
{
    m_balance = 5000;
}

void BankAccount::deposit(long amount)
{
    m_balance += amount;
}

void BankAccount::withdraw(long amount)
{
    m_balance -= amount;
}

QString BankAccount::holderName() const
{
    return m_holderName;
}

long BankAccount::balance() const
{
    return m_balance;
}

long BankAccount::smth() const
{
    return m_smth;
}

myStruct BankAccount::myStructSmth() const
{
    return m_myStructSmth;
}

void BankAccount::setHolderName(QString holderName)
{
    if (m_holderName == holderName)
        return;

    m_holderName = holderName;
    emit holderNameChanged(m_holderName);
}

void BankAccount::setSmth(long smth)
{
    if (m_smth == smth)
        return;

    m_smth = smth;
    emit smthChanged(m_smth);
}


