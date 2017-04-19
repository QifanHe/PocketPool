#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QList>
#define PI 3.14159265


class Ball: public QGraphicsPixmapItem
{
public:
    Ball(int num);
    double VX;
    double VY;
    double vX, vY;
    void setState(double x, double y);
    QTimer * timer;
    int timerState;
    QVector<double> colliding;
    void move();
    int stop;
    int inPocket;
private:
    double getRad(double x, double y);
    double getAbs(double x);
    int coldStart;
    int pocketZone();
    int pocketCounter;
};

#endif // BALL_H
