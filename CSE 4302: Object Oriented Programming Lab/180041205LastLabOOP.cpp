#include<bits/stdc++.h>
using namespace std;

#define Godspeed                ios_base::sync_with_stdio(0);cin.tie(NULL)
#define urs(r...)               typename decay<decltype(r)>::type
#define REP(i,b)                for(urs(b) i=0;i<b;i++)
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short
#define ff                      first
#define ss                      second
#define endl                    '\n'

template<class T>
void swaps(T& a, T& b)
{
    T tempvar;
    tempvar=a;
    a=b;
    b=tempvar;
}

int main()
{
    Godspeed;
    cout<<"Let's swap two int variables"<<endl;
    int intA=-69, intB=420;
    cout<<"Initially, intA= "<<intA<<" "<<"intB= "<<intB<<endl;
    swaps(intA,intB);
    cout<<"After calling swaps(intA,intB), intA= "<<intA<<" "<<"intB= "<<intB<<endl;
    cout<<endl;

    cout<<"Let's swap two long long int variables"<<endl;
    ll llA=1234567890,llB=9876543210;
    cout<<"Initially, llA= "<<llA<<" "<<"llB= "<<llB<<endl;
    swaps(llA,llB);
    cout<<"After calling swaps(llA,llB), longlongA= "<<llA<<" "<<"llB= "<<llB<<endl;
    cout<<endl;

    cout<<"Let's swap two unsigned long long int variables"<<endl;
    ULL ullA=12345,ullB=98765;
    cout<<"Initially, ullA= "<<ullA<<" "<<"ullB= "<<ullB<<endl;
    swaps(ullA,ullB);
    cout<<"After calling swaps(ullA,ullB), ullA= "<<ullA<<" "<<"ullB= "<<ullB<<endl;
    cout<<endl;

    cout<<"Let's swap two unsigned int variables"<<endl;
    UI uiA=60,uiB=420;
    cout<<"Initially, uiA= "<<uiA<<" "<<"uiB= "<<uiB<<endl;
    swaps(uiA,uiB);
    cout<<"After calling swaps(uiA,uiB), uiA= "<<uiA<<" "<<"uiB= "<<uiB<<endl;
    cout<<endl;

    cout<<"Let's swap two unsigned short int variables"<<endl;
    US usA=2,usB=5;
    cout<<"Initially, usA= "<<usA<<" "<<"usB= "<<usB<<endl;
    swaps(usA,usB);
    cout<<"After calling swaps(usA,usB), usA= "<<usA<<" "<<"usB= "<<usB<<endl;
    cout<<endl;

    cout<<"Let's swap two double variables"<<endl;
    double dA=69.420,dB=9.11;
    cout<<"Initially, dA= "<<dA<<" "<<"dB= "<<dB<<endl;
    swaps(dA,dB);
    cout<<"After calling swaps(dA,dB), dA= "<<dA<<" "<<"dB= "<<dB<<endl;
    cout<<endl;

    cout<<"Let's swap two float variables"<<endl;
    float fA=6.66,fB=3.1416;
    cout<<"Initially, fA= "<<fA<<" "<<"fB= "<<fB<<endl;
    swaps(fA,fB);
    cout<<"After calling swaps(fA,fB), fA= "<<fA<<" "<<"fB= "<<fB<<endl;
    cout<<endl;

    cout<<"Let's swap two long double variables"<<endl;
    LD ldA=-6.9420,ldB=42.0;
    cout<<"Initially, ldA= "<<ldA<<" "<<"ldB= "<<ldB<<endl;
    swaps(ldA,ldB);
    cout<<"After calling swaps(ldA,ldB), ldA= "<<ldA<<" "<<"ldB= "<<ldB<<endl;
    cout<<endl;

    cout<<"Let's swap two STL strings"<<endl;
    string sA="Faisal",sB="Hussain";
    cout<<"Initially, sA= "<<sA<<" "<<"sB= "<<sB<<endl;
    swaps(sA,sB);
    cout<<"After calling swaps(sA,sB), sA= "<<sA<<" "<<"sB= "<<sB<<endl;
    cout<<endl;

    cout<<"Let's swap two dynamically resize-able arrays/vectors"<<endl;
    vector<ll>vA= {1,2,3,4,5};
    vector<ll>vB= {11,22,33,44,55};
    cout<<"Initially, vA= ";
    REP(i,vA.size())
    {
        cout<<vA[i]<<" ";
    }
    cout<<endl;
    cout<<"Initially, vB= ";
    REP(i,vB.size())
    {
        cout<<vB[i]<<" ";
    }
    cout<<endl;
    REP(i,min(vA.size(),vB.size()))
    {
        swaps(vA[i],vB[i]);
    }
    cout<<"After calling swaps(), vA= ";
    REP(i,vA.size())
    {
        cout<<vA[i]<<" ";
    }
    cout<<endl;
    cout<<"After calling swaps(), vB= ";
    REP(i,vB.size())
    {
        cout<<vB[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"Let's swap two C-Style strings/char arrays"<<endl;
    char cA[]="OOP";
    char cB[]="COA";
    cout<<"Initially, cA= ";
    REP(i,strlen(cA))
    {
        cout<<cA[i];
    }
    cout<<endl;
    cout<<"Initially, cB= ";
    REP(i,strlen(cB))
    {
        cout<<cB[i];
    }
    cout<<endl;
    REP(i,min(strlen(cA),strlen(cB)))
    {
        swaps(cA[i],cB[i]);
    }
    cout<<"After calling swaps(), cA= ";
    REP(i,strlen(cA))
    {
        cout<<cA[i];
    }
    cout<<endl;
    cout<<"After calling swaps(), cB= ";
    REP(i,strlen(cB))
    {
        cout<<cB[i];
    }
    cout<<endl;
    cout<<endl;

    cout<<"Let's swap two STL pairs"<<endl;
    pair<ll,ll>pA={911,119},pB={666,69420};
    cout<<"Initially, pA= {"<<pA.ff<<","<<pA.ss<<"} pB= {"<<pB.ff<<","<<pB.ss<<"}"<<endl;
    swaps(pA,pB);
    cout<<"After calling swaps(pA,pB), pA= {"<<pA.ff<<","<<pA.ss<<"} pB= {"<<pB.ff<<","<<pB.ss<<"}"<<endl;
    cout<<endl;

    cout<<"Let's swap elements of a single STL pair containing char pointers"<<endl;
    pair<char*,char*>cpA={"CGPA","4"};
    cout<<"Initially, cpA= {"<<cpA.ff<<","<<cpA.ss<<"}"<<endl;
    swaps(cpA.ff,cpA.ss);
    cout<<"After calling swaps(cpA.ff,cpa.ss), cpA= {"<<cpA.ff<<","<<cpA.ss<<"}"<<endl;
    cout<<endl;
    return 0;
}
