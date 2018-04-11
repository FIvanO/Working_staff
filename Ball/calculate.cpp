#include "calculate.h"
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QThread>

int Calculate::getBounce() const
{
    return bounce;
}

int Calculate::getRad() const
{
    return rad;
}

void Calculate::start()
{
    emit starting();
}


Calculate::Calculate(QObject *parent) : QObject(parent), bounce(10), rad(40)
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
    bool flag = false;
    while (cond()) {
        int sign = getBounce() / abs(getBounce());
        if (center().ry() + getRad() + getBounce() >= QApplication::activeWindow()->height() && flag && sign == 1) {
            m_center.setY(QApplication::activeWindow()->height() - getRad());
            emit sendCoor(m_center.ry());
            setBounce(getBounce() * (-1));
            flag = false;
            continue;
        }
        if (center().ry() - getRad() + getBounce() <= (getRad() / 4) && flag && sign == -1) {
            m_center.setY(getRad() + getRad() / 4);
            emit sendCoor(m_center.ry());
            setBounce(getBounce() * (-1));
            flag = false;
            continue;
        }
//        if ((center().ry() + getRad()) >= QApplication::activeWindow()->height() - 2 * getRad() ||
//            (center().ry() - getRad()) <= 2 * getRad()) setBounce(getBounce() * (-1));
        //if (QApplication::activeWindow()->height() - center().ry() <= getRad()) setBounce(getBounce() * (-1));
        //else setBounce(10);
        flag = true;
        m_center.setY(m_center.ry() + getBounce());
        qDebug() << m_center.ry() + getBounce();
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
