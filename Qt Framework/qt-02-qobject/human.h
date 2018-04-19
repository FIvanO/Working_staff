#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged);
    Q_PROPERTY(char sexSymbol READ sexSymbol WRITE setSexSymbol NOTIFY sexSymbolChanged);

    int m_age;

    char m_sexSymbol;

public:
    explicit Human(QObject *parent = nullptr);

int age() const;

char sexSymbol() const;

signals:

void ageChanged(int age);

void sexSymbolChanged(char sexSymbol);

public slots:
void setAge(int age);
void setSexSymbol(char sexSymbol);
};



#endif // HUMAN_H
