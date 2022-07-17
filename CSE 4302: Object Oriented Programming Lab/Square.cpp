#include<bits/stdc++.h>
#include "Square.h"
using namespace std;
Square::Square():side(0.0)
{
    //ctor
}
Square::Square(float s):side(s)
{
    //ctor
}
void Square::setside(float val)
{
    if(val<0.0)
    {
        cout<<val<<" is not Valid Side Length!"<<endl;
        //flag=false;
    }
    else side=val;
}
float Square::getside()
{
    //if(flag)
        return side;
    //else
        //cout<<"Valid Input wasn't given!"<<endl;
}
float Square::perimeter()
{
    return (4.0*side);
}
float Square::diagonal()
{
    return (sqrt(side*side+side*side));
}
float Square::area()
{
    return (side*side);
}
Square Square::operator ++ ()
{
    ++side;
    Square temp;
    temp.side=side;
    return temp;
}
Square Square::operator ++ (int)
{
    return Square(side++);
}
Square Square::operator -- ()
{
    --side;
    Square temp;
    temp.side=side;
    return temp;
}
Square Square::operator -- (int)
{
    return Square(side--);
}
Square Square::operator + (Square sq2) const
{
    float s=side+sq2.side;
    return Square(s);
}
Square Square::operator - (Square sq2) const
{
    float s=side-sq2.side;
    return Square(s);
}
bool Square::operator == (Square sq) const
{
    return (side*side==sq.area());
}
bool Square::operator > (Square sq) const
{
    return (side*side>sq.area());
}
bool Square::operator < (Square sq) const
{
    return (side*side<sq.area());
}
Square::~Square()
{
    //dtor
}
