#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff                      first
#define ss                      second
class Department
{
private:
    string name;
    map<string,LD>m;
public:
    Department()
    {
        name+='\0';
        m.clear();
    }
    Department(string s, LD ch)
    {
        m[s]=ch;
    }
    void set_course(string s, LD ch)
    {
        if(m.size()==30)
        {
            cout<<"Course Limit Reached!"<<endl;
            return;
        }
        if(ch<0.0 || ch>4.0)
        {
            cout<<"Credit Hours not within range!"<<endl;
            return;
        }
        m[s]=ch;
    }
    void update_course(string s, string updated_title, LD updated_ch)
    {
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            if(it->ff==s)
            {
                m.erase(it);
                m[updated_title]=updated_ch;
            }
            else if(it==m.end())
            {
                cout<<"Course Not Found!"<<endl;
            }
        }
    }
    LD total_credit_hours()
    {
        LD sum=0.0;
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            sum+=it->ss;
        }
        return sum;
    }
    void get_courses()
    {
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            cout<<it->ff<<" "<<it->ss<<endl;
        }
    }
};

int main()
{
    FastIO;
    Department CSE("Object Oriented Programming",3.00);
    CSE.set_course("Database Management System",3.00);
    CSE.set_course("Data Structures",3.00);
    CSE.get_courses();
    cout<<"Total Credit Hours: "<<CSE.total_credit_hours()<<endl;
    CSE.update_course("Data Structures","Data Structures and Algorithms",4.0);
    CSE.get_courses();
    cout<<"Total Credit Hours: "<<CSE.total_credit_hours()<<endl;
    return 0;
}
