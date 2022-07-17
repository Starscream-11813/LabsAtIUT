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
vector<ll>adj[501];
//vector<bool>vis(501,false);
vector<ll>d(501,inf);
map<pll,ll>edge,edge2;
queue<ll>q;
void bfs(ll node)
{

    d[node]=0;
    q.push(node);
    //vis[node]=true;
    while(!q.empty())
    {
        ll qf=q.front();
        q.pop();
        for(auto x:adj[qf])
        {
            if(max(d[qf],edge[ {qf,x}])<d[x])
            {
                q.push(x);
                d[x]=max(d[qf],edge[ {qf,x}]);
            }
        }
    }
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    scanf("%d",&Tests);
    int tc=Tests;
    while(Tests--)
    {
        ll n,m;
        //cin>>n>>m;
        scanf("%lld %lld",&n,&m);
        while(m--)
        {
            ll u,v,w;
            //cin>>u>>v>>w;
            scanf("%lld %lld %lld",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            if(!edge[ {u,v}])
            {
                edge[ {u,v}]=inf;
            }
            if(!edge[ {v,u}])
            {
                edge[ {v,u}]=inf;
            }
            edge[ {u,v}]=min(w,edge[ {u,v}]);
            edge[ {v,u}]=min(w,edge[ {v,u}]);
        }
        ll t;
        //cin>>t;
        scanf("%lld",&t);
        bfs(t);
        //cout<<"Case "<<tc-Tests<<":\n";
        printf("Case %d:\n",tc-Tests);
        REP(i,n)
        {
            if(d[i]>20000)
            {
                //cout<<"Impossible"<<endl;
                printf("Impossible\n");
            }
            else
            {
                //cout<<d[i]<<endl;
                printf("%lld\n",d[i]);
            }
        }
        REP(i,n)
        {
            adj[i].clear();
        }
        edge.clear();
        //fill(all(vis),false);
        fill(all(d),inf);
    }
    Bye;
}



