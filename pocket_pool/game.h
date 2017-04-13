#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "whiteball.h"
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
    QVector<whiteBall*> ball;
    QList<QPair<int, int>> position;
private:
    QTimer * timer;
private slots:
    void update();
};

#endif // GAME_H
