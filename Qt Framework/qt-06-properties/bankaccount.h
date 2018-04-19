#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>
struct myStruct {
    int first_var;
    int second_var;
};
Q_DECLARE_METATYPE(myStruct)



class BankAccount : public QObject
{
    Q_OBJECT
    // TODO: declare QString holderName property that's represents account holder name
    //       this property must have getter and setter
    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName NOTIFY holderNameChanged)

    // TODO: declare long balance property
    //       this property should be read-only and associated with variable m_balance
    Q_PROPERTY(long balance READ balance MEMBER m_balance)

    Q_PROPERTY(long smth READ smth WRITE setSmth NOTIFY smthChanged)



    Q_PROPERTY(myStruct myStructSmth READ myStructSmth)

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);
    enum smth{
        one, two, three
    };
    Q_ENUM(smth)



    // TODO: declare and implement holderName getter/setter
    // TODO: decalre and implement balance getter
    QString holderName() const;
    long balance() const;
    long smth() const;
    myStruct myStructSmth() const;

public slots:
    void setHolderName(QString holderName);
    void setSmth(long smth);

signals:
    void holderNameChanged(QString holderName);    
    void smthChanged(long smth);

private:
    // TODO: declare holderName
    long m_balance;
    QString m_holderName;
    long m_smth;
    myStruct m_myStructSmth;
};

#endif // BANKACCOUNT_H
