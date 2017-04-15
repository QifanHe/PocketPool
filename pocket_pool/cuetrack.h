#ifndef CUETRACK_H
#define CUETRACK_H

#include<QPair>


class Cuetrack
{
public:
    Cuetrack();
    QPair<double, double> startTracking(QPair<double, double> ballPos);
private:
    double vX;
    double vY;
};

#endif // CUETRACK_H
