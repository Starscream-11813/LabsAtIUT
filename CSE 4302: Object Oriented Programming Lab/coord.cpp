#include "coord.h"
#include<bits/stdc++.h>
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
void Coord::setx(double val)
{
    x=val;
}
void Coord::sety(double val)
{
    y=val;
}
void Coord::setCoordInPolar(double distance, double angleInDegree)
{
    ///x=distance*cos(angleInDegree/180.0);
    ///y=distance*sin(angleInDegree/180.0);
    setx(distance*cos(angleInDegree/57.295));
    //std::cout<<"lul"<<std::endl;
    sety(distance*sin(angleInDegree/57.295));
    //std::cout<<"lul2"<<std::endl;
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
double Coord::distance(Coord other)
{
    return sqrt(pow((other.getx()-getx()),2.0)+pow((other.gety()-gety()),2.0));
}
