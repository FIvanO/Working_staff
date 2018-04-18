#include "human.h"

Human::Human(QObject *parent) : QObject(parent)
{



}

int Human::age() const
{
    return m_age;
}

char Human::sexSymbol() const
{
    return m_sexSymbol;
}

void Human::setAge(int age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}

void Human::setSexSymbol(char sexSymbol)
{
    if (m_sexSymbol == sexSymbol)
        return;

    m_sexSymbol = sexSymbol;
    emit sexSymbolChanged(m_sexSymbol);
}


