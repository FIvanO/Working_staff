#include "ballobj.h"
#include <QDebug>
#include <QThread>

BallObj::BallObj(QObject *parent) : QObject(parent), m_center(120, 120) {}
bool BallObj::cond() const
{
    return m_cond;
}

QPoint BallObj::center() const
{
    return m_center;
}

int BallObj::CenterY() const
{
    return m_CenterY;
}

void BallObj::processing()
{
	if (!cond()) {
		emit finished();
	}
}

void BallObj::setCond(bool cond)
{
    if (m_cond == cond)
        return;

    m_cond = cond;
    emit condChanged(m_cond);
}

void BallObj::setCenter(QPoint center)
{
    if (m_center == center)
        return;

    m_center = center;
    emit centerChanged(m_center);
}

void BallObj::setCenterY(int CenterY)
{
    if (m_CenterY == CenterY)
        return;

    m_CenterY = CenterY;
    emit CenterYChanged(m_CenterY);
}
