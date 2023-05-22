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

ll getKth(vector<ll>A,vector<ll>B,ll a,ll b,ll k)
{
    if(a>A.size()-1)
    {
        return B[b+k-1];
    }
    if(b>B.size()-1)
    {
        return A[a+k-1];
    }
    if(k==1)
    {
        return min(A[a],B[b]);
    }
    ll am=inf,bm=inf;
    if(a+(k/2)-1<A.size())
    {
        am=A[a+(k/2)-1];
    }
    if(b+(k/2)-1<B.size())
    {
        bm=B[b+(k/2)-1];
    }
    if(am<bm)
    {
        return getKth(A,B,a+(k/2),b,k-(k/2));
    }
    else
    {
        return getKth(A,B,a,b+(k/2),k-(k/2));
    }
}

int main()
{
    Godspeed;
    int Tests=1;
    cin>>Tests;
    while(Tests--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n),b(m);
        REP(i,n)
        {
            cin>>a[i];
        }
        REP(i,m)
        {
            cin>>b[i];
        }
        ll l=(n+m+1)/2;
        ll r=(n+m+2)/2;
        cout<<fixed<<setprecision(5)<<(getKth(a,b,0,0,l)+getKth(a,b,0,0,r))/2.0<<endl;
    }
    Bye;
}
/*
3
2 1
1 3
2
5 5
1 2 3 4 5
6 7 8 9 10
2 3
4 5
1 2 6
*/



