#include <bits/stdc++.h>
#include "Taka.h"
using namespace std;
Taka::Taka():one(0),two(0),five(0),ten(0),twenty(0)
{
    //ctor
}
void Taka::setone(int o)
{
    if(o<0)
    {
        cout<<o<<" is an invalid amount!"<<endl;
    }
    else
        one=o;
}
void Taka::settwo(int t)
{
    if(t<0)
    {
        cout<<t<<" is an invalid amount!"<<endl;
    }
    else
        two=t;
}
void Taka::setfive(int f)
{
    if(f<0)
    {
        cout<<f<<" is an invalid amount!"<<endl;
    }
    else
        five=f;
}
void Taka::setten(int te)
{
    if(te<0)
    {
        cout<<te<<" is an invalid amount!"<<endl;
    }
    else
        ten=te;
}
void Taka::settwenty(int tw)
{
    if(tw<0)
    {
        cout<<tw<<" is an invalid amount!"<<endl;
    }
    else
        twenty=tw;
}
int Taka::getTaka()
{
    return (one*1+two*2+five*5+ten*10+twenty*20);
}
bool Taka::operator == (Taka tt) const
{
    return (one*1+two*2+five*5+ten*10+twenty*20==tt.getTaka());
}
bool Taka::operator > (Taka tt) const
{
    return (one*1+two*2+five*5+ten*10+twenty*20>tt.getTaka());
}
bool Taka::operator < (Taka tt) const
{
    return (one*1+two*2+five*5+ten*10+twenty*20<tt.getTaka());
}
Taka Taka::operator + (Taka tt)
{
    Taka temp;
    temp.one=one+tt.one;
    temp.two=two+tt.two;
    temp.five=five+tt.five;
    temp.ten=ten+tt.ten;
    temp.twenty=twenty+tt.twenty;
    return temp;
    //int s=one*1+two*2+five*5+ten*10+twenty*20+tt.getTaka();
    //return Taka(s);
}
Taka Taka::operator - (Taka tt)
{
    Taka temp;
    if(one>=tt.one)
        temp.one=one-tt.one;
    else
        temp.one=0;

    if(two>=tt.two)
        temp.two=two-tt.two;
    else
        temp.two=0;

    if(five>=tt.five)
        temp.five=five-tt.five;
    else
        temp.five=0;

    if(ten>=tt.ten)
        temp.ten=ten-tt.ten;
    else
        temp.ten=0;

    if(twenty>=tt.twenty)
        temp.twenty=twenty-tt.twenty;
    else
        temp.twenty=0;

    return temp;
//int s=one*1+two*2+five*5+ten*10+twenty*20+tt.getTaka();
//return Taka(s);
}
Taka Taka::operator | (Taka tt)
{
    Taka temp;
    int s=one*1+two*2+five*5+ten*10+twenty*20-tt.getTaka();
    temp.twenty=s/20;
    s-=temp.twenty*20;
    temp.ten=s/10;
    s-=temp.ten*10;
    temp.five=s/5;
    s-=temp.five*5;
    temp.two=s/2;
    s-=temp.two*2;
    temp.one=s/1;
    return temp;
}
Taka::~Taka()
{
    //dtor
}
