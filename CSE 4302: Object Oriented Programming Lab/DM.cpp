#include "DM.h"
//#include "DB.h
DM::DM(float m, float cm):meters(m),centimeters(cm)
{
    //ctor
}

DM::~DM()
{
    //dtor
}
float DM::getmeters()
{
    return meters;
}
float DM::getcentimeters()
{
    return centimeters;
}
//void DM::add_dist(DB other)
//{
//    meters+=(other.feet*0.3048);
//    centimeters+=(other.inches*2.54);
//    if(centimeters>=100.0)
//    {
//        centimeters-=100.0;
//        meters++;
//    }
//}
