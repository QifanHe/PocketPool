#include "game.h"


Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,480,272);
    scene->setBackgroundBrush(QBrush(Qt::green));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(480,272);

    // Set the table
    table = new Table();
    table->setPos(0, 25);
    scene->addItem(table);


    // Set Balls
    balls.resize(11);
    resetBalls();
    balls[0]->setState(0, 5);

    timer = new QTimer(this);
    timer->start(500);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(ballMoveHandler()));


}

void Game::gameLogic()
{
    // do something
}

void Game::scoreChangeHandler(int ballNumber)
{
    // do something
}

void Game::ballMoveHandler()
{
    for (int i = 0; i < balls.size(); i++){
        balls[i]->move();
    }
}

void Game::resetBalls()
{
    position.append(qMakePair(25, 130));
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

    for (int i = 0; i < balls.size(); i++){
        balls[i] = new Ball(i);
        balls[i]->setPos(position[i].first, position[i].second);
        balls[i]->setState(0, 0);
        scene->addItem(balls[i]);
    }
}
