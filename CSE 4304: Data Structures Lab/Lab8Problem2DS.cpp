#include<bits/stdc++.h>
using namespace std;
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define all(a)                  a.begin(),a.end()
#define Godspeed                ios_base::sync_with_stdio(0);cin.tie(NULL)
#define urs(r...)               typename decay<decltype(r)>::type
#define FOR(i,a,b)              for(urs(b) i=a;i<=b;i++)
#define REP(i,b)                for(urs(b) i=0;i<b;i++)
#define FOREACH(i,t)            for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define what_is(x)              cerr << __LINE__ <<": " << #x << " is " << x << endl;

#define ll                      long long
#define ULL                     unsigned long long
#define endl                   '\n'
const ll inf = 0xFFFFFFFFFFFFFFFL;

int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll m;
        cin>>m;
        if(m<=0 || m>=100)///Checking validity of inputs.
        {
            cout<<"Invalid input";
            return 0;
        }
        vector<ll>c(m);
        ll maxm=-inf;
        unordered_map<ll,ll>mp;///<number,frequency>
        REP(i,m)
        {
            cin>>c[i];
            mp[c[i]]++;///if the number appears in the array, frequency++.
            maxm=max(maxm,mp[c[i]]);///the variable maxm signifies the maximum frequency among all the frequencies.
        }
        ll res,freq;
        FOREACH(it,mp)///iterating through the unordered_map. Check the macro for the whole for loop.
        {
            if(it->ss==maxm)///if any of the frequencies equals the maximum frequency, we have out answer.
            {
                res=it->ff;///first element(key) of the tuple is the number.
                freq=it->ss;///second element(value) of the tuple is the frequency.
                break;///breaking the loop, because the problem statement requires to print only one of the numbers with maximum appearances.
            }
        }
        cout<<"Most frequent element: "<<res<<endl;///now, just print them.
        cout<<"Frequency: "<<freq;
    }
    return 0;
}

