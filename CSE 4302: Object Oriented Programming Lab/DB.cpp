#include "DB.h"
//#include "DM.h"
DB::DB(float ft, float in):feet(ft),inches(in)
{
    //ctor
}

DB::~DB()
{
    //dtor
}
float DB::getfeet()
{
    return feet;
}
float DB::getinches()
{
    return inches;
}
void DB::add_dist(DM other)
{

    feet+=(other.getmeters()*3.28);
    inches+=(other.getcentimeters()*0.393);
    if(inches>=12.0)
    {
        inches-=12.0;
        feet++;
    }
}
DB DB::add_dist_ret(DM other)
{
    //DB temp();
    feet+=(other.getmeters()*3.28);
    inches+=(other.getcentimeters()*0.393);
    if(inches>=12.0)
    {
        inches-=12.0;
        feet++;
    }
    return *this;
}
