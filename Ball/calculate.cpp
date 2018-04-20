#include "calculate.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QThread>

Calculate::Calculate(QObject *parent) : QObject(parent), bounce(10), rad(40) {}

int Calculate::getBounce() const
{
    return bounce;
}

int Calculate::getRad() const
{
    return rad;
}

bool Calculate::cond() const
{
    return m_cond;
}

QPoint Calculate::center() const
{
    return m_center;
}

bool Calculate::floor_roof(bool flag)
{
    int sign = getBounce() / abs(getBounce());
    if (center().ry() + getRad() + getBounce() >= QApplication::activeWindow()->height() && flag && sign == 1) {
        m_center.setY(QApplication::activeWindow()->height() - getRad());
        emit sendCoor(m_center.ry());
        setBounce(getBounce() * (-1));
        return false;
    }
    if (center().ry() - getRad() + getBounce() <= (getRad() / 4) && flag && sign == -1) {
        m_center.setY(getRad() + getRad() / 4);
        emit sendCoor(m_center.ry());
        setBounce(getBounce() * (-1));
        return false;
    }
    return true;
}

void Calculate::run()
{
    bool flag = false;
    while (cond()) {
        qDebug() << "Thread 1 is working";
        flag = floor_roof(flag);
        if (!flag) {
            continue;
        }
        flag = true;
        m_center.setY(m_center.ry() + getBounce());
        qDebug() << "Coordinate: " << m_center.ry();
        qDebug() << "Bounce: " << bounce;
        emit sendCoor(m_center.ry());
        QThread::msleep(100);
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
