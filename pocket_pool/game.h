#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "ball.h"
#include "table.h"
#include "holes.h"
#include "cuetrack.h"
#include "pocket.h"
#include <QVector>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QGraphicsRectItem>
#include <QPair>


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    QGraphicsScene * scene;
    QGraphicsRectItem * cursor;
    QVector<Ball*> balls;
    //QVector<pockets*> pocket;
    Cuetrack tracker;
    QList<QPair<int, int>> position;
    Table *table;
    QVector<Pocket*> pockets;
    QVector<Holes*> holes;
    int state;
private:
    QTimer * timer;
    void resetBalls();
    void ballMoveHandler();
    void scoreChangeHandler(int ballNumber);
private slots:
    void gameLogic();
};

#endif // GAME_H
