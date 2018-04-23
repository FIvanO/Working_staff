#include "drawer.h"
#include <QDebug>

Drawer::Drawer()
{
	qDebug() << "Drawer obj";
}

void Drawer::draw(int dir)
{
	qDebug() << "Drawing direction: " << dir;
}
