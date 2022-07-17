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
#define PRESENT(c,x)            ((c).find(x) != (c).end())

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
        unordered_map<ll,ll>mp;///will store the frequencies of the respective keys.
        REP(i,m)
        {
            cin>>c[i];///Taking the array as input.
            //mp[c[i]]++;
        }
        ll sum;
        vector<pair<ll,ll> >v;///This pair vector will store all the possible pairs whose element's sum will equal the given sum.
        cin>>sum;///Input the given sum.
        REP(i,m)///Iterating through the array.
        {
            if(mp[sum-c[i]])///checks if we can form a legitimate pair with c[i].
            {
                REP(j,mp[sum-c[i]])///if yes, we push_back the pairs in our pair vector.
                {
                    v.pb({c[i],sum-c[i]});///the number of similar such pairs will be equal to the frequency of sum-c[i] up till that iteration of the loop.
                }
            }
            mp[c[i]]++;///incrementing the frequency of the i-th element of the array.
        }
        if(v.empty())///if the pair vector is empty, it means no valid pairs were found.
        {
            cout<<"No pairs found";
            return 0;
        }
        sort(all(v));///This step isn't necessary, just to print the pairs in ascending order.
        cout<<"Pairs with sum "<<sum<<" are: ";
        REP(i,v.size()-1)///Print out the pairs that have been found to be valid.
        {
            cout<<"("<<v[i].ff<<", "<<v[i].ss<<"), ";
        }
        cout<<"("<<v[v.size()-1].ff<<", "<<v[v.size()-1].ss<<")";
    }
    return 0;
}
/*
-->12 tah pairs howar kotha.
10
1 4 2 3 3 2 4 1 1 1
5
*/
