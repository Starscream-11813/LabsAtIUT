#include<bits/stdc++.h>
using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define SQR(a)                  ((a)*(a))
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define all(a)                  a.begin(),a.end()
#define lastEle(v)              v[v.size()-1]
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define max5(a,b,c,d,e)         max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)         min(min3(a,b,c),min(d,e))
#define MEM(a,x)                memset(a,x,sizeof(a))
#define Godspeed                ios_base::sync_with_stdio(0);cin.tie(NULL)
#define urs(r...)               typename decay<decltype(r)>::type
#define FOR(i,a,b)              for(urs(b) i=a;i<=b;i++)
#define ROF(i,a,b)              for(urs(b) i=a;i>=b;i--)
#define REP(i,b)                for(urs(b) i=0;i<b;i++)
#define PER(i,a,b)              for(urs(b) i=a;i>b;i--)
#define FOREACH(i,t)            for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define PRESENT(c,x)            ((c).find(x) != (c).end())
#define CPRESENT(c,x)           (find(all(c),x) != (c).end())
#define SPRESENT(c,x)           ((c).find(x) != string::npos)
#define Bye                     return 0
#define ODD(x)                  (bool)(x&1)
#define Debug                   cout<<endl<<"I AM BATMAN"<<endl;
#define what_is(x)              cerr << __LINE__ <<": " << #x << " is " << x << endl;
//Datatypes
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short
#define endl                    '\n'
const long long int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const ll inf = 0xFFFFFFFFFFFFFFFL;
#define PI                      acos(-1.0)

bool sortbysec(const pair<long long int,long long int> &a, const pair<long long int,long long int> &b)
{
    return (a.second < b.second);
}

//Debugging stuff
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>

//vector<ll>adj[100001];
//vector<bool>vis(100001,false);
unordered_map<ll,ll>parent;///Map is used since no. of foxlings can be upto 10^9
                           ///but the no of relations can be 10^5 at max which can be stored.
ll res=0;

//void dfs(ll node, ll parent)
//{
//    if(!vis[node])
//    {
//        vis[node]=true;
//        for(auto x:adj[node])
//        {
//            dfs(x,node);
//        }
//    }
//}
void make_set(ll v)///Creates a new set consisting of the new element v.
{
    parent[v]=v;///Assigning v as its own representative.
}

ll find_set(ll v)///returns the representative/leader of the set that contains the element v.
{
    if (v==parent[v])///if v itself is a representative of a set.
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);///Performing path compression. A micro-optimization to speed up the find_set function. O(n) to O(logn).
}

void union_sets(ll a, ll b)///Merges the two specified sets
{
    a=find_set(a);///Find the representative of the set in which a is located.
    b=find_set(b);///Find the representative of the set in which b is located.
    if (a!=b)///If reps are different, then merge them.
    {
        res++;///For each union, no. of connected components decreases by 1.
        parent[b]=a;///(Optional) Can be further optimized with weighted union.
    }
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll n,m;
        cin>>n>>m;
        REP(i,m)
        {
            ll u,v;
            cin>>u>>v;
//            adj[u].pb(v);
//            adj[v].pb(u);
            if(!parent[u])
            {
                make_set(u);
            }
            if(!parent[v])
            {
                make_set(v);
            }
//            ll a=find_set(u);
//            ll b=find_set(v);
            union_sets(u,v);
        }
//        FOR(i,1,n)
//        {
//            if(!vis[i])
//            {
//                res++;
//                dfs(i,0);
//            }
//        }
        cout<<n-res;///(Total foxlings - Total unions) is my answer.
//        REP(i,100001)
//        {
//            adj[i].clear();
//            vis[i]=false;
//        }
//        res=0;
    }
    Bye;
}




