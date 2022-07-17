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
ll adj[101][101],d[101][101];///adj[i][j]=edge weight between i and j.
                             ///d[i][j]=minimum sound intensity level that needs
                             ///to be tolerated to go from node i to node j.
void quasiFloydWarshall()
{
    REP(i,101)
    {
        REP(j,101)
        {
            d[i][j]=adj[i][j];
        }
    }
    REP(k,101)
    {
        REP(i,101)
        {
            REP(j,101)
            {
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));///My target is to minimize the intensity threshold.
                                                          ///For that I find the minimum between d[i][j] and
                                                          ///the maximum edge value between the path from node i
                                                          ///to node k and node k to node j. This maximum edge
                                                          ///value represents the road with the maximum noise
                                                          ///pollution in the path from node i to node j.
                                                          ///And we will compare this value with the value
                                                          ///already stored in d[i][j].
            }
        }
    }
}
int main()
{
    Godspeed;
    int Tests=0;
    //cin>>Tests;
    while(true)
    {
        ll c,s,q;
        cin>>c>>s>>q;
        if(!c && !s && !q)
        {
            break;
        }
        Tests++;
        REP(i,101)
        {
            REP(j,101)
            {
                adj[i][j]=inf;///Set the entries of the adjacency matrix to infinity.
            }
        }
        REP(i,s)
        {
            ll c1,c2,dd;
            cin>>c1>>c2>>dd;
            adj[c1][c2]=dd;
            adj[c2][c1]=dd;///Since, the edge is bidirectional.
        }
        quasiFloydWarshall();
        if(Tests>=2)
        {
            cout<<endl;
        }
        cout<<"Case #"<<Tests<<endl;
        while(q--)
        {
            ll c1,c2;
            cin>>c1>>c2;
            if(d[c1][c2]!=inf)///if a valid path exists between c1 and c2.
            {
                cout<<d[c1][c2]<<endl;
            }
            else///if there are no paths between c1 and c2 then d[c1][c2]==inf.
            {
                cout<<"no path"<<endl;
            }
        }
        //puts("");
    }
    Bye;
}




