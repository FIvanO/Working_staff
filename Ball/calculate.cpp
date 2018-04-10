#include "calculate.h"
#include <QApplication>
#include <QWidget>

int Calculate::getBounce() const
{
    return bounce;
}

int Calculate::getRad() const
{
    return rad;
}

Calculate::Calculate(QObject *parent) : QObject(parent), m_center(120, 120), bounce(1), rad(40)
{

}

bool Calculate::cond() const
{
    return m_cond;
}

QPoint Calculate::center() const
{
    return m_center;
}

void Calculate::run()
{
    while (cond()) {
        if (QApplication::activeWindow()->height() - center().ry() <= getRad()) setBounce(-1);
        else setBounce(1);
        m_center.setY(m_center.ry() + getBounce());
    }
    emit finished();
}

void Calculate::setcond(bool cond)
{
    if (m_cond == cond)
        return;

    m_cond = cond;
    emit condChanged(m_cond);
}

void Calculate::setBounce(int b)
{
    bounce = b;
}

void Calculate::setCenter(QPoint center)
{
    if (m_center == center)
        return;

    m_center = center;
    emit centerChanged(m_center);
}
