#include "pocket.h"
#include <QBrush>

Pocket::Pocket(int num)
{
    ID = num;
if (num == 0){
    Triangle.append(QPointF(19.,24.));
    Triangle.append(QPointF(26.,24.));
    Triangle.append(QPointF(26.,31.));
    Triangle.append(QPointF(19.,24.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 1){
    Triangle.append(QPointF(0.,45.));
    Triangle.append(QPointF(0.,52.));
    Triangle.append(QPointF(7.,52.));
    Triangle.append(QPointF(0.,45.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 2){
    Triangle.append(QPointF(0.,244.));
    Triangle.append(QPointF(7.,244.));
    Triangle.append(QPointF(0.,251.));
    Triangle.append(QPointF(0.,244.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 3){
    Triangle.append(QPointF(26.,264.));
    Triangle.append(QPointF(26.,271.));
    Triangle.append(QPointF(19.,271.));
    Triangle.append(QPointF(26.,264.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 4){
    Triangle.append(QPointF(453.,264.));
    Triangle.append(QPointF(453.,271.));
    Triangle.append(QPointF(460.,271.));
    Triangle.append(QPointF(453.,264.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 5){
    Triangle.append(QPointF(480.,244.));
    Triangle.append(QPointF(480.,251.));
    Triangle.append(QPointF(473.,244.));
    Triangle.append(QPointF(480.,244.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 6){
    Triangle.append(QPointF(480.,45.));
    Triangle.append(QPointF(480.,52.));
    Triangle.append(QPointF(473.,52.));
    Triangle.append(QPointF(480.,45.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 7){
    Triangle.append(QPointF(453.,24.));
    Triangle.append(QPointF(453.,31.));
    Triangle.append(QPointF(460.,24.));
    Triangle.append(QPointF(453.,24.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 8){
    Triangle.append(QPointF(223.,24.));
    Triangle.append(QPointF(223.,31.));
    Triangle.append(QPointF(228.,24.));
    Triangle.append(QPointF(223.,24.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 9){
    Triangle.append(QPointF(252.,24.));
    Triangle.append(QPointF(257.,24.));
    Triangle.append(QPointF(257.,31.));
    Triangle.append(QPointF(252.,24.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 10){
    Triangle.append(QPointF(252.,271.));
    Triangle.append(QPointF(257.,264.));
    Triangle.append(QPointF(257.,271.));
    Triangle.append(QPointF(252.,271.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
else if (num == 11){
    Triangle.append(QPointF(223.,264.));
    Triangle.append(QPointF(223.,271.));
    Triangle.append(QPointF(228.,271.));
    Triangle.append(QPointF(223.,264.));
    setPolygon(Triangle);
    setBrush(QBrush(Qt::red));
}
}
