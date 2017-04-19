#ifndef POCKET_H
#define POCKET_H

#include<QGraphicsPolygonItem>
#include<QPolygonF>

class Pocket: public QGraphicsPolygonItem
{
public:
    QPolygonF Triangle;
    int ID;
    Pocket(int num);
};

#endif // POCKET_H
