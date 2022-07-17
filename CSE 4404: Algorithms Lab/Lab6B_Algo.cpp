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
///My target is to minimize the expected search cost for the items in the BST.
ll dp[251][251];///dp[i][j]=Optimal weight sum considering the ith node to the jth node.
vector<ll>frequency(250+1),prefixSum(250+1);

ll w(ll i, ll j)///Return the sum of frequencies starting from ith to the jth node.
{
    if(i>j)
    {
        return 0;
    }
    else
    {
        return (prefixSum[j]-prefixSum[i-1]);
    }
}
ll x(ll i, ll j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]==inf)///If dp[i][j] has not yet been memoized.
    {
        FOR(k,i,j)///Taking kth node as root node.
        {
            dp[i][j]=min(dp[i][j],x(i,k-1)+x(k+1,j)+w(i,k-1)+w(k+1,j));///We take the minimum of dp[i][j] and
                                                                       ///from optimal weight from ith node to (k-1)th node, which constitutes the left subtree,
                                                                       ///plus the optimal weight from (k+1)th node to jth node, which constitutes the right subtree,
                                                                       ///plus the sum of all weights from ith node to jth node considering kth node as the root node,
                                                                       ///which is the same as taking weight sum from ith to (k-1)th node and (k+1)th to jth node and adding them up.
        }
    }
    return dp[i][j];///then, just return the optimal weight sum.
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    ll n;
    while(cin>>n)
    {
        prefixSum[0]=0;
        FOR(i,1,n)
        {
            cin>>frequency[i];
            prefixSum[i]=prefixSum[i-1]+frequency[i];///Store the prefix sums of the frequencies in the prefixSum array.
        }
        REP(i,251)
        {
            REP(j,251)
            {
                if(i>=j)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=inf;
                }
            }
        }
        cout<<x(1,n)<<endl;///We will find our answer in the nth column of the 1st row of our 2D dp array.
        REP(i,n+1)
        {
            REP(j,n+1)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        fill(all(frequency),0LL);///Then, just reset the arrays for the next test case.
        fill(all(prefixSum),0LL);
    }
    Bye;
}




