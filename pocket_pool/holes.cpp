#include "holes.h"
#include<QBrush>

Holes::Holes(int num)
{
setRect(0, 0, 3, 3);
setBrush(QBrush(Qt::white));
if (num == 0)
    setPos(4, 29);
if (num == 1)
    setPos(4, 262);
if (num == 2)
    setPos(238, 270);
if (num == 3)
    setPos(470, 262);
if (num == 4)
    setPos(470, 29);
if (num == 5)
    setPos(238, 22);
}

