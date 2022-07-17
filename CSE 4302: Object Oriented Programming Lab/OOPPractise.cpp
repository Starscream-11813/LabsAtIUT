#include<bits/stdc++.h>
using namespace std;
/*class Student
{
public:
    int id;
    double gpa;
    void display()
    {
        cout<<id<<" "<<gpa<<endl;
    }
    //Constructor
    Student(int x, double u)
    {
        id=x;
        gpa=u;
    }
    //Default Constructor
    Student()
    {
        cout<<"LMAO"<<endl;
    }

};
int main()
{
    Student pp;
    Student Alim(23,23.23);
    Alim.display();
    Student Dalim(34,34.34);
    Dalim.display();
    return 0;
}
*/
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() : feet(0),inches(0.0){}
    Distance(int ft, float in):feet(ft),inches(in){}
    void getdistance()
    {
        cout<<"Enter feet: "<<endl;
        cin>>feet;
        cout<<"Enter inches: "<<endl;
        cin>>inches;
    }
    void displaydistance() const
    {
        cout<<"Distance is "<<feet<<"' "<<inches<<"\""<<endl;
    }
    void add(Distance d1, Distance d2)
    {
        feet=d1.feet+d2.feet;
        inches=d1.inches+d2.inches;
        if(inches>=12.0)
        {
            feet++;
            inches-=12.0;
        }
    }
    Distance add(Distance d1)
    {
        Distance temp;
        temp.inches=inches+d1.inches;
        temp.feet=feet+d1.feet;
        if(temp.inches>=12.0)
        {
            temp.inches-=12.0;
            temp.feet++;
        }
        return temp;
    }
    Distance add_dist(const Distance&) const;
};
Distance Distance::add_dist(const Distance& d2) const
{
    Distance temp;
    //inches=0;
    temp.inches=inches+d2.inches;
    temp.feet=feet+d2.feet;
    if(temp.inches>=12.0)
    {
        temp.feet++;
        temp.inches-=12.0;
    }
    //cout<<__gcd(2,4)<<endl;
    return temp;
}

int main()
{
    Distance ob1,ob2(69,4.20),ob3,ob4,ob5(ob2);
    ob1.getdistance();
    ob3.add(ob1,ob2);
    ob4=ob2;
    ob5=ob5.add(ob2);
    const Distance ob6=ob5.add_dist(ob5);
    ob1.displaydistance();
    ob2.displaydistance();
    ob3.displaydistance();
    ob4.displaydistance();
    ob5.displaydistance();
    ob6.displaydistance();
    return 0;
}

/*class foo
{
private:
    static int counter;
public:
    foo() //const
    {
        counter++;
    }
    int getcount()
    {
        return counter;
    }
};
int foo::counter=0;
int main()
{
    foo ob1;
    cout<<ob1.getcount()<<endl;
    foo ob2;
    cout<<ob2.getcount()<<endl;
    foo ob3;
    cout<<ob3.getcount()<<endl;
}
*/
