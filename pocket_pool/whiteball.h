#ifndef WHITEBALL_H
#define WHITEBALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QList>
#define PI 3.14159265


class whiteBall: public QGraphicsPixmapItem
{
public:
    whiteBall(int num);
    double VX;
    double VY;
    double vX, vY;
    void setState(double x, double y);
    QTimer * timer;
    int timerState;
    QVector<double> colliding;
    void move();
private:
    double getRad(double x, double y);
    double getAbs(double x);
    int coldStart;
};

#endif // WHITEBALL_H
