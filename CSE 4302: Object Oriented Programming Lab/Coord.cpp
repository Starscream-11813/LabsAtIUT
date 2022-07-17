#include "Coord.h"
#include<math.h>
Coord::Coord()
{
    //ctor
}
Coord::Coord(double i, double j):x(i),y(j)
{
    //ctor
}
Coord::~Coord()
{
    //dtor
}
double Coord::getx()
{
    return x;
}
double Coord::gety()
{
    return y;
}
void Coord::setCoordInPolar(double distance, double angleInDegree)
{
    x=distance*cos(angleInDegree/180.0);
    y=distance*sin(angleInDegree/180.0);
}
int Coord::getQuadrants()
{
    if(x>0.0 && y>0.0)
    {
        return 1;
    }
    else if(x<0.0 && y>0.0)
    {
        return 2;
    }
    else if(x<0.0 && y<0.0)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
double distance(const Coord other)
{
    return sqrt(pow((other),2.0)-pow((),2.0));
}
