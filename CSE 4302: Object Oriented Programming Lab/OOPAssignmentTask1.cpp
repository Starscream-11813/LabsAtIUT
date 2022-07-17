#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
class Supervisor
{
protected:
    string name;
    LD pay_rate;
public:
    Supervisor()
    {
        name+='\0';
        pay_rate=0.0;
    }
    Supervisor(string s, LD p)
    {
        name=s;
        pay_rate=p;
    }
    string getname()
    {
        return name;
    }
    LD getpay_rate()
    {
        return pay_rate;
    }
    LD calculatepay(LD hours)
    {
        return hours*pay_rate;
    }
};
class Manager
{
protected:
    string name;
    LD salary;
public:
    Manager()
    {
        name+='\0';
        salary=0.0;
    }
    Manager(string s, LD p)
    {
        name=s;
        salary=p;
    }
    string getname()
    {
        return name;
    }
    LD getsalary()
    {
        return salary;
    }
};
int main()
{
    FastIO;
    Supervisor s1("Faisal",9600.00);
    Manager m1("Rifat",91166.60);
    cout<<"Name: "<<s1.getname()<<" "<<"Pay Rate: "<<s1.getpay_rate()<<endl;
    cout<<"Salary based on working hours: "<<s1.calculatepay(8)<<endl;
    cout<<"Name: "<<m1.getname()<<" "<<"Pay Rate: "<<m1.getsalary()<<endl;
}
