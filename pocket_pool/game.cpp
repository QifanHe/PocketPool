#include "game.h"


Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,480,272);

    setBackgroundBrush(QBrush(Qt::green));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(480,272);


    ball.resize(11);
    position.append(qMakePair(30, 150));
    position.append(qMakePair(250, 130));
    position.append(qMakePair(270, 120));
    position.append(qMakePair(270, 140));
    position.append(qMakePair(290, 110));
    position.append(qMakePair(290, 130));
    position.append(qMakePair(290, 150));
    position.append(qMakePair(310, 100));
    position.append(qMakePair(310, 120));
    position.append(qMakePair(310, 140));
    position.append(qMakePair(310, 160));

    for (int i = 0; i < ball.size(); i++){
        ball[i] = new whiteBall(i);
        ball[i]->setPos(position[i].first, position[i].second);
        ball[i]->setState(0, 0);
        scene->addItem(ball[i]);
    }

    ball[0]->setState(6.1, 0.2);

    timer = new QTimer(this);
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));


}

void Game::update()
{
    for (int i = 0; i < ball.size(); i++){
        ball[i]->move();
    }
}
