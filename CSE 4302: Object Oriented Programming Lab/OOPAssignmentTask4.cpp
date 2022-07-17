#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff                      first
#define ss                      second


class Flight
{
private:
    int flight_number;
    int max_capacity;
    string destination;
    LD distance_from_Dhaka;
    LD fuel_now;
    bool flag;
    static int counter;
public:
    Flight()
    {
        counter++;
        flight_number=counter;
        max_capacity=0;
        destination="";
        distance_from_Dhaka=0.0;
        fuel_now=0.0;
        flag=false;
    }
    void set_data(int maxm, string s, LD dis)
    {
        max_capacity=maxm;
        destination=s;
        distance_from_Dhaka=dis;
        LD fuel_needed=0.25*distance_from_Dhaka;///eita private kora lagbe
        if(fuel_needed>2000.0)
        {
            flag=false;
        }
        else
        {
            flag=true;
        }
        if(!flag)
        {
            cout<<"Fuel Capacity is not enough for the flight!"<<endl;
        }
        fuel_now=0.25*distance_from_Dhaka;
    }
    void show_data()
    {
        cout<<"Flight No.: "<<flight_number<<endl;
        cout<<"Maximum Passengers: "<<max_capacity<<endl;
        cout<<"Destination City: "<<destination<<endl;
        cout<<"Distance from Dhaka: "<<distance_from_Dhaka<<endl;
        cout<<"Plane's Fuel: "<<fuel_now<<endl;
        if(!flag)
        {
            cout<<"Flight isn't possible!"<<endl;
        }
        else
        {
            cout<<"There is enough fuel. Have a safe journey!"<<endl;
        }
    }
};
int Flight::counter=0;
class Airline
{
private:
    Flight v[5];
public:
    //vector<Flight> v(5);
    //Flight v[5];
    void set_Info()
    {
        for(int i=0; i<5; i++)
        {
            int maxm;
            string s;
            LD dis;
            cin>>maxm>>s>>dis;
            v[i].set_data(maxm,s,dis);
        }
    }
    void show_Info()
    {
        for(int i=0;i<5;i++)
        {
            v[i].show_data();
        }
    }
};
int main()
{
    FastIO;
    Airline Biman,Lufthansa,SingaporeAirlines;
    Biman.set_Info();
    cout<<endl;
    Biman.show_Info();
    cout<<endl;
    Lufthansa.set_Info();
    cout<<endl;
    Lufthansa.show_Info();
    cout<<endl;
    SingaporeAirlines.set_Info();
    cout<<endl;
    SingaporeAirlines.show_Info();
    cout<<endl;
    return 0;
}
