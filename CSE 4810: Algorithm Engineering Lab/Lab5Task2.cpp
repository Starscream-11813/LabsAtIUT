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
#define pldld pair<long double, long double>

/*
    Syed Rifat Raiyan
    IUT CSE-18
    Beautifully struggle every day~
*/
template<class T> using min_heap=priority_queue<T,vector<T>,greater<T>>;
vector<pll>adj[5001];
vector<ll>d(5001,inf),d2(5001,inf);
map<pll,ll>edge;
ll n,r;

void dijkstra(ll start)
{
    min_heap<pll>pq;
    d[start]=0;
    pq.push({0,start});
    while(!pq.empty())
    {
        ll v=pq.top().ss;
        ll dv=pq.top().ff;
        pq.pop();
        if(dv>d2[v])
        {
            continue;
        }
        for(auto x:adj[v])
        {
//            ll sum=dv+edge[{v,x}];
            ll sum=dv+x.ss;
            if(sum<d[x.ff])
            {
                d2[x.ff]=d[x.ff];
                d[x.ff]=sum;
                pq.push({sum,x.ff});
            }
            else if(sum<d2[x.ff] && sum>d[x.ff])
            {
                d2[x.ff]=sum;
                pq.push({sum,x.ff});
            }
        }
    }
}

int main()
{
    Godspeed;
    int Tests=1;
    cin>>Tests;
    int t=Tests;
    while(Tests--)
    {
        cin>>n>>r;
        while(r--)
        {
            char uc,vc;
            ll u,v,w;
            cin>>uc>>vc>>w;
            u=uc-'A'+1;
            v=vc-'A'+1;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
//            edge[{u,v}]=w;
//            edge[{v,u}]=w;
        }
        dijkstra(1);
        ll b=inf;
        for(auto x:adj[1])
        {
            b=min(b,x.ss<<1);
        }
        b+=d[n];
        cout<<"Case "<<t-Tests<<": "<<min(b,d2[n])<<endl;
        REP(i,n+1)
        {
            adj[i].clear();
        }
        fill(d.begin(),d.begin()+n+1,inf);
        fill(d2.begin(),d2.begin()+n+1,inf);
//        edge.clear();
    }
    Bye;
}

/*
4
11 17
A B 2
B C 3
C D 1
D J 9
J K 2
J I 1
D I 2
C I 3
B E 1
E I 2
B D 4
F E 5
F G 1
G H 9
H I 3
G I 5
G E 4
4 4
A B 100
B D 200
B C 250
C D 100
3 3
A B 100
B C 200
A C 50
2 1
A B 5
*/


