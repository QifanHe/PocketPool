#include "game.h"
#include <QApplication>
#include "cuetrack.h"
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    //Cuetrack tracker;
    //tracker.startTracking();
    return a.exec();
}
