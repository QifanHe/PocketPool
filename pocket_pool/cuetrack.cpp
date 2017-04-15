#include "cuetrack.h"
#include "game.h"

extern Game * game;


Cuetrack::Cuetrack()
{

    vX = 0;
    vY = 0;

}

QPair<double, double> Cuetrack::startTracking(QPair<double, double> ballPos)
{

    double x, y;
    x = ballPos.first;
    y = ballPos.second;

    // do something to compute vX, vY;

    return qMakePair(vX, vY);
}
