#include "drawer.h"
#include <QDebug>


bool Drawer::draw(CalculateDirection &dir, int var)
{
	int ans = dir.calculate(var);
	qDebug() << "Drawing direction: " << ans;
	return (ans == var % 4);
}

Drawer::Drawer()
{
	qDebug() << "Drawer obj";
}
