#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "ball.h"
#include "table.h"
#include <QVector>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QPair>


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene * scene;
    QVector<Ball*> balls;
    //QVector<pockets*> pocket;
    QList<QPair<int, int>> position;
    Table *table;
private:
    QTimer * timer;
    void resetBalls();
    void gameLogic();
    void scoreChangeHandler(int ballNumber);
private slots:
    void ballMoveHandler();
};

#endif // GAME_H
