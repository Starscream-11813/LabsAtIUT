#include<bits/stdc++.h>
using namespace std;

//Commands and Functions
#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define SQR(a)                  ((a)*(a))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define getarray(a,n)           for(int i=0;i<n;i++) cin>>a[i]
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define lla(A)                  A.rbegin(), A.rend()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
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
#define rep(i, begin, end)      for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PER(i,a,b)              for(urs(b) i=a;i>b;i--)
#define FOREACH(i,t)            for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define PRESENT(c,x)            ((c).find(x) != (c).end())
#define CPRESENT(c,x)           (find(ALL(c),x) != (c).end())
#define Lower_bound(v, x)       distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x)       distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Bye                     return 0
#define SORT(v)                 sort(v.begin(),v.end())
#define revsort(a,n)            sort(a,a+n); reverse(a,a+n)
#define REV(v)                  reverse(v.begin(),v.end())
#define EVEN(x)                 (bool)(x%2==0)
#define ODD(x)                  (bool)(x&1)
#define Debug                   cout<<endl<<"I AM BATMAN"<<endl;
#define what_is(x)              cerr << #x << " is " << x << endl;
#define binleastsigonebit(x)    __builtin_ffs(x)
#define binleadingzeroes(x)     __builtin_clz(x)
#define bintrailingzeroes(x)    __builtin_ctz(x)
#define bintotalones(x)         __builtin_popcount(x)
#define getbit(n,i)             (((n)&(1<<(i)))!=0)
#define setbit0(n,i)            ((n)&(~(1<<(i))))
#define setbit1(n,i)            ((n)|(1<<(i)))
#define togglebit(n,i)          ((n)^(1<<(i)))
#define TIME                    (chrono::steady_clock::now().time_since_epoch().count())
//ll powmod(ll a,ll b)           {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int PowMod(int a,int l, int md)
{
    int res=1;
    while(l)
    {
        if(l&1)
            res=res*a%md;
        l/=2;
        a=a*a%md;
    }
    return res;
}
int phi(int n)
{
    int result = 1;
    for (int i = 2; i < n; i++)
        if (GCD(i, n) == 1)
            result++;
    return result;
}
int isprime(int n)
{
    bool flag = true;
    for(int i = 2; i*i <= n; ++i)
        //for(int i = 2; i <= sqrt(n); ++i)
        //for(int i = 2; i <= n/2; ++i)
    {
        if(n%i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
long long binaryPow(long long a, long long b)
{
    long long ans = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            ans = ans * a ;
        }
        a = a * a ;
        b >>= 1;
    }
    return ans;
}
bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.second < b.second);
}
//Reminders
/*
for taking in white-spaces, getline(std::cin>>std::ws,s);
if even, sub1=s.substr(0,s.length()/2); sub2=s.substr(s.length()/2,s.length()-1);
if odd, sub1=s.substr(0,s.length()/2); sub2=s.substr(s.length()/2+1,s.length()-1);
check complexity every time
for having sorted inputs, use multiset and use set for unique keys.
for ordered sequence of unique keys use map, and for unordered sequence of unique keys use unordered_map.
for multiple elements having same keys use multimap.
array dynamically resize korar jonno vector.
top element theke reverse sorted inputs er jonno priority_queue.
Raw string declaration string R("Hello\tWorld\n");
For having the ability to merge two sorted data-structures, use list.
For inputs in both head and tail use Deque.
Basics- LIFO Stack and FIFO Queue.
Don't forget Tuple!
*/
//Formulae
/*
No. of Diagonals of regular n-gon=n*(n-3)/2;
No. of Intersections(for odd n)=ceil(((pow(n,4)-(6*pow(n,3))+(11*pow(n,2))-(6*n)))/24);
*/
//Datatypes
#define ll                      long long
#define ULL                     unsigned long long
#define LD                      long double
#define UI                      unsigned int
#define US                      unsigned short

//Constants
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const ll inf = 0xFFFFFFFFFFFFFFFL;
#define PI                      acos(-1.0)
#define EulerGamma              0.57721566490153286060651209
long long pw(long long x, long long p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;
    long long v = pw(x, p / 2);
    v = v * v % MOD;
    if (p % 2 != 0)
        v = v * x % MOD;
    return v;
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
template<typename T, typename... Args>
T sum(T a, Args... args)
{
    return a + sum(args...);
}
//Data Structures
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>
/*
    Syed Rifat Raiyan
    IUT CSE-18
    Go Beyond! Plus Ultra!
*/

/*int main()
{
    Godspeed;
    ll n;
    cin>>n;
    ll a[n],sum=0,counter=0;
    REP(i,n)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            sum+=a[i];
            counter++;
        }
    }
    if(counter==0)
    {
        sum=*max_element(a,a+n);
        counter++;
    }
    cout<<sum<<" "<<counter;
    Bye;
}*/
/*int main()
{
    Godspeed;
    ll n;
    cin>>n;
    ll a[n],sum=0;
    ll maxm=-inf;
    ll minm=inf;
    REP(i,n)
    {
        cin>>a[i];
        maxm=max(maxm,a[i]);
        minm=min(minm,a[i]);
        sum+=a[i];
    }
    cout<<sum-maxm<<" "<<sum-minm;
    Bye;
}
*/
int main()
{
    Godspeed;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b,minm=inf;
        cin>>n>>a>>b;
        vector<ll>v;
        for(ll i=n,j=n-i;i>=0,j<=n;i--,j++)
        {
            v.pb(a*SQR(i)+b*SQR(j));
            minm=min(a*SQR(i)+b*SQR(j),minm);
            //what_is(minm);
        }
        ll res1=minm,res2,res3;
        /*for(ll i=n,j=n-i;i>=0,j<=n;i--,j++)
        {
            if(a*SQR(i)+b*SQR(j)==minm)
            {
                res1=minm;
                res2=i;
                res3=j;
                //what_is(res1);
                //what_is(res2);
                //what_is(res3);
                break;
            }
        }*/
        cout<<res1<<endl;
    }
    Bye;
}

/*int main()
{
    Godspeed;
    ll n;
    cin>>n;
    vector<ll> m(n);
    ll sum[n];
    ll temp=0;
    REP(i,n)
    {
        cin>>m[i];
        sum[i]=temp+m[i];
        temp=sum[i];
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll p;
        cin>>p;
        ll counter=ub(all(m),p)-m.begin();
        cout<<counter<<" "<<sum[counter-1]<<endl;
    }
    Bye;
}*/
/*ll x[100000],y[100000],icompare=0,bcompare=0;
void insertion_sort(ll a[],ll n)
{
    FOR(j,2,n)
    {
        ll key=a[j];
        ll i=j-1;
        while(i>0 && a[i]>key)
        {
            icompare++;
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}
void bubblesort(ll a[],ll n)
{
    FOR(i,1,n-1)
    {
        ROF(j,n,i+1)
        {
            if(a[j]<a[j-1])
            {
                bcompare++;
                swap(a[j],a[j-1]);
            }
        }
    }
}*/
/*int main()
{
    Godspeed;
    ll n;
    cin>>n;
    srand(time(0));
    REP(i,n)
    {
        x[i]=y[i]=rand();
    }
    cout<<"Random Input Set Generated"<<endl;
    /*REP(i,100)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    REP(i,100)
    {
        cout<<y[i]<<" ";
    }*/
    /*clock_t t;
    double cpu_time_used;
    t=clock();
    cout<<"Applying Insertion Sort"<<endl;
    insertion_sort(x,n);
    cout<<"Total comparisons: "<<icompare<<endl;
    t=clock()-t;
    cpu_time_used=((double)(t))/CLOCKS_PER_SEC;
    cout<<"Total clock ticks: "<<cpu_time_used<<endl;
    t=clock();
    cout<<"Applying Bubble Sort"<<endl;
    bubblesort(y,n);
    cout<<"Total comparisons: "<<bcompare<<endl;
    t=clock()-t;
    cpu_time_used=((double)(t))/CLOCKS_PER_SEC;
    cout<<"Total clock ticks: "<<cpu_time_used<<endl;
    Bye;
}*/
