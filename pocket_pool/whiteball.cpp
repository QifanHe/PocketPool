#include "whiteball.h"
#include "game.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include <math.h>
#include <typeinfo>
#include <QString>



extern Game * game;


whiteBall::whiteBall(int num)
{
    if (num == 0){
        setPixmap(QPixmap(":/new/balls/whiteBall.png").scaled(20,20,Qt::KeepAspectRatio));
        setData(0, num);
    }
    else{
        setData(0, num);
        setPixmap(QPixmap(":/new/balls/1.png").scaled(20,20,Qt::KeepAspectRatio));
        }

    colliding.resize(11);
    for (int i = 0; i < 11; i++){
        colliding[i] = 0;
}

    //timer = new QTimer(this);
    //timer->start(10);
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}


void whiteBall::setState(double x, double y)
{
    vX = x;
    vY = y;
}


void whiteBall::move()
{
    double theta1, theta2, alpha, beta1, beta2, d_x, d_y, delta_vX, delta_vY, delta_v, cos_alpha, sin_alpha;
    double enemyX, enemyY, enemyVx, enemyVy;



    VX = vX;
    VY = vY;



    for (int i = 0; i < 11; i++){
        setData(i + 5, 0);
        setData(i+35,0);
    }

    for (int i = 0; i < 11; i++){
        if (colliding[i] > 0){
            colliding[i] --;
        }
    }

    QList<QGraphicsItem *>colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;++i){
        if (typeid(*(colliding_items[i])) == typeid(whiteBall)){

            //collisionList<<colliding_items[i]->data()
            //setData(colliding_items[i]->data(0).toInt()+35, 1);
            setData(colliding_items[i]->data(0).toInt() + 5, 1);

            whiteBall *t = (whiteBall*)colliding_items[i];


            //if (colliding_items[i]->data(data(0).toInt()+5).toInt() == 1 && data(colliding_items[i]->data(0).toInt() + 25) == 0)
            //if (colliding_items[i]->data(data(0).toInt()+5).toInt() == 1
            if (t->colliding[data(0).toInt()] == 0 && colliding[t->data(0).toInt()] == 0)
{
            //setData(colliding_items[i]->data(0).toInt() + 25, 1);
            qDebug()<<"ID:::::::::"<<this->data(0);
            qDebug()<<"colliding!!";
            colliding[colliding_items[i]->data(0).toInt()] = 2;
            t->colliding[data(0).toInt()] = 2;
            enemyX = colliding_items[i]->pos().x();
            enemyY = colliding_items[i]->pos().y();
            enemyVx = t->VX;
            enemyVy = t->VY;
            qDebug()<<"enemyVx:"<<enemyVx<<"enemyVy:"<<enemyVy;
            d_x = x() - enemyX;
            d_y = y() - enemyY;
            qDebug()<<"d_x:"<<d_x<<"d_y:"<<d_y;
            alpha = getRad(d_x, d_y);
            beta1 = getRad(vX, vY);
            theta1 = beta1 - alpha;
            beta2 = getRad(enemyVx, enemyVy);
            theta2 = beta2 - alpha;
            qDebug()<<"alpha:"<<alpha;
            delta_v = sqrt(enemyVx*enemyVx + enemyVy*enemyVy)*cos(theta2) - sqrt(vX*vX+vY*vY)*cos(theta1);

            qDebug()<<"cos(theta2):"<<cos(theta1)<<"  cos(theta2):"<<cos(theta2);

            qDebug()<<"theta1:"<<theta1<<"  theta2:"<<theta2;


            cos_alpha = (d_x) / (sqrt(pow(d_x, 2)+pow(d_y, 2)));
            sin_alpha = (d_y) / (sqrt(pow(d_x, 2)+pow(d_y, 2)));
            qDebug()<<"delta_v:"<<delta_v;
            delta_vX = getAbs(delta_v) * cos_alpha;
            delta_vY = getAbs(delta_v) * sin_alpha;
            qDebug()<<"delta_vX:"<<delta_vX<<"delta_vy:"<<delta_vY;
            vX = vX + delta_vX * 0.9;
            vY = vY + delta_vY * 0.9;

            qDebug()<<"vx:"<<vX<<"vy:"<<vY;
            //qDebug()<<colliding_items[i]->data(0)<<enemyX<<"Ey:";
            t->setState(t->vX - delta_vX * 0.9, t->vY - delta_vY * 0.9);
}

        }
    }



    if (pos().y() > scene()->height() - 20 || pos().y() < 0)
    {
        qDebug()<<"xxxx!!";
        if(pos().x() > scene()->width() - 20 || pos().x() < 0)
            vX = - vX * 1.01;
        vY = - vY * 1.01;
    }
    else if(pos().x()> scene()->width() - 20 || pos().x() < 0)
    {
        qDebug()<<"yyyyy!!";
        if (pos().y() > scene()->height() - 20 || pos().y() < 0)
            vY = - vY * 1.01;
        vX = - vX;
    }

    //velocity = velocity * 0.99;



    setPos(x()+vX, y()+vY);

    vX = vX * 0.994;
    vY = vY * 0.994;

    if (pow((vX * vX + vY * vY),2) < 0.0001)
    {
        vX = 0;
        vY = 0;
    }
}

double whiteBall::getRad(double x, double y)
{
    //qDebug()<<"x is : "<<x<<"y is : "<<y;
    if (x > 0 && y > 0){
        return atan(getAbs(y/x));}
    else if (x < 0 && y > 0){
        //qDebug()<<"x is : "<<x<<"y is : "<<y;
        //qDebug()<<"abs is: "<<getAbs(y/x);
        //return atan(getAbs(y/x)) + (PI / 2);}
        return PI-atan(getAbs(y/x));}
    else if (x < 0 && y < 0)
        return atan(getAbs(y/x)) + PI;
        //return atan(getAbs(y/x));
    else if (x > 0 && y < 0)
        return (2 * PI)-atan(getAbs(y/x));
    else if (x > 0 && y == 0)
        return 0;
    else if (x < 0 && y == 0)
        return PI;
    else if (x == 0 && y > 0)
        return 3*PI/2;
    else if (x == 0 && y < 0)
        return PI/2;
    else if (x == 0 && y == 0)
        return 0;
    else{
        qDebug()<<"getRad Error!";
        return 0;
    }
}

double whiteBall::getAbs(double x)
{
    if (x<0)
        return -x;
    return x;
}
