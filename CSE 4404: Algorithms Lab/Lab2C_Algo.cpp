#include<bits/stdc++.h>
using namespace std;
template<class T> using min_heap=priority_queue<T,vector<T>,greater<T> >;
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
vector<pll>adj[100001];
vector<bool>vis(100001,false);
//vector<ll>railway(100001,false);
set<pll>pq;
//min_heap<pair<pll,bool> >pq;
vector<ll>d(100001,inf);
//map<pll,ll>edge;
//unordered_map<ll,vector<ll> >track;
//unordered_map<ll,ll>degree;
ll res=0;
void dijkstra(ll start)
{
    d[start]=0;
    pq.insert({0,start});
    while(!pq.empty())
    {
        ll w=pq.begin()->ff;
        ll v=pq.begin()->ss;
        pq.erase(pq.begin());
        if(w>d[v])
        {
            continue;
        }
        else
        {
            d[v]=w;//weight I got on the top of pq is less equal to curr dis?
        }
        //what_is(vis[v]);
        for(auto x:adj[v])
        {
            if(d[v]+x.ss<=d[x.ff])//relaxation condition.
            {
                if(vis[x.ff])//if railway exists.
                {
                    res++;//we can omit that railway.
                    vis[x.ff]=false;
                }

                d[x.ff]=d[v]+x.ss;//update distance.
                pq.insert({d[x.ff],x.ff});
            }
        }
    }
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll n,m,k;
        //cin>>n>>m>>k;
        scanf("%lld %lld %lld",&n,&m,&k);
        while(m--)
        {
            ll u,v,x;
            //cin>>u>>v>>x;
            scanf("%lld %lld %lld",&u,&v,&x);
            adj[u].pb({v,x});
            adj[v].pb({u,x});
        }
        REP(i,k)
        {
            ll s,y;
            //cin>>s>>y;
            scanf("%lld %lld",&s,&y);
            //railway[s]=true;
            if(!vis[s])
            {
                vis[s]=true;
                d[s]=y;
            }
            else
            {
                d[s]=min(d[s],y);
                res++;//expendable railway tracks.
            }
        }
        FOR(i,2,n)
        {
            if(d[i]!=inf)
            {
                pq.insert({d[i],i});
            }
        }
        dijkstra(1);
        printf("%lld",res);
    }
    Bye;
}




