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

int main()
{
    Godspeed;///FastIO.
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll m,n;
        cin>>m>>n;
        if(n>=m || m>=100)///Checking validity of inputs.
        {
            cout<<"Invalid input";
            return 0;
        }
        vector<ll>a(m),b(n);
        unordered_map<ll,bool>mp;///<number,whether it has appeared in the array>
        bool flag=true;
        REP(i,m)
        {
            cin>>a[i];
            mp[a[i]]=true;///if it's in a_array[], assign true, else it's by default false.
        }
        REP(i,n)
        {
            cin>>b[i];
            if(!mp[b[i]])///if any one of the numbers of b_array[] isn't present in the a_array[] we can immediately infer that b_array isn't a subset of a_array[].
            {
                flag=false;
                break;///we don't need to check further, so break the loop.
            }
        }
        if(flag)///Show respective output message.
        {
            cout<<"b_array is a subset of a_array";
        }
        else
        {
            cout<<"b_array is not a subset of a_array";
        }
    }
    return 0;
}
