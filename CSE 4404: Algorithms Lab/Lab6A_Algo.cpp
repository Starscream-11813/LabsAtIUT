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

///Idea: http://ruslanledesma.com/2016/05/26/arbitrage.html#candidates-are-most-beneficial-paths
const ll mxN=20;
#define MIN_PROFIT 1.01

void print_path(ll s, ll t, ll l, ll succ[mxN][mxN][mxN])///succ[l][s][t]=the successor of s in a path of length L, where the destination node is t.
{
    if(!l)///If length is 0, it means we have reached the end of the path, so just print the destination node, which will be equal to the source node too.
    {
        cout<<s+1<<endl;
    }
    else
    {
        cout<<s+1<<" ";///Else, print the source node, then set the next successor as the source node.
                       ///Decrease L by 1 as well.
        print_path(succ[l][s][t], t, l-1, succ);
    }
}
///Before starting, let's imagine the given directed graph as a complete directed graph.
///My target is to find out the shortest profitable cycle. (that is, a path that starts and ends with the same node)
void foo(ll n, LD rate[mxN][mxN])
{
    LD benefit[mxN][mxN][mxN];///benefit[l][i][j]=the rate obtained for source node i
                              ///and destination node j, where the length of the path
                              ///is L, and it is considered the most beneficial path
                              ///from i to j.
    ll succ[mxN][mxN][mxN];
    REP(i,n)
    {
        REP(j,n)
        {
            benefit[1][i][j]=rate[i][j];///Since, path of length 1 is the edge itself.
            if(rate[i][j]>0)///If conversion is possible from i to j, then set j as the successor of i.
            {
                succ[1][i][j]=j;
            }
        }
    }
    ///Now, from path lengths of 2 and onward...
    ///(Here, we are going from lowest to highest path, so when we
    ///find a profitable cycle, we can for sure say that the cycle
    ///found has the least length.)
    FOR(l,2,n)
    {
        REP(ii,n)
        {
            REP(jj,n)
            {
                benefit[l][ii][jj]=0.0;///Set the corresponding 2D array's entries to 0.
            }
        }
        REP(i,n)///Now, let's see how the recurrence relationship is established.
        {
            REP(j,n)
            {
                REP(k,n)
                {
                    ///For a given source node i and a destination node j,
                    ///benefit[l][i][j] = max(rate[i][k]*benefit[l-1][k][j] where the value of k is from 1 to n).
                    ///Here, i->k is the prefix edge and k->...->j is the suffix path of length L-1, which together make up the whole path of length L.
                    if(benefit[l][i][j]<rate[i][k]*benefit[l-1][k][j])
                    {
                        benefit[l][i][j]=rate[i][k]*benefit[l-1][k][j];
                        succ[l][i][j]=k;
                        ///If the rate obtained equals or surpasses
                        ///the MIN_PROFIT threshold given in the problem statement,
                        ///then I have successfully found a profitable cycle. Notice that,
                        ///the source node and the destination node is the same, which means that
                        ///the found path is a cycle.
                        if(benefit[l][i][i]>=MIN_PROFIT)
                        {
                            print_path(i,i,l,succ);///Since we have constructed a successor matrix,
                                                   ///we can now print the path, and that will be our answer.
                            return;
                        }
                    }
                }
            }
        }
    }
    cout<<"no arbitrage sequence exists"<<endl;
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    ll n;
    while(cin>>n)
    {
        LD t[mxN][mxN];
        REP(i,n)
        {
            REP(j,n)
            {
                if(i!=j)
                {
                    cin>>t[i][j];///Take the conversion matrix as input.
                }
                else
                {
                    t[i][j]=0.0;///There is no point in converting a currency to itself, so take 0.
                }
            }
        }
        foo(n,t);
    }
    Bye;
}




