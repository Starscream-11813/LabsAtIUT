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
min_element(a+left,a+right+1) [0 based index]
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
    //Godspeed;
    ll n;
    cin>>n;
    int t;
    cin>>t;
    ll a[10],top=0;
    while(t--)
    {
        ll q;
        cin>>q;
        if(q==1)//push
        {
            ll x;
            cin>>x;
            a[top]=x;
            top++;
        }
        else if(q==2)
        {
            a[top]=0;
            top--;
        }
        cout<<"Size= "<<top<<" ";
        if(top==0)
        {
            cout<<"Items= NULL";
        }
        else
        {
            cout<<"Items= ";
            REP(i,top)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    Bye;
}*/
/*void printstack(stack<ll>s)
{
    if(s.empty())
    {
        return;
    }
    ll x=s.top();
    s.pop();
    printstack(s);
    cout<<x<<" ";
    s.push(x);
}
int main()
{
    Godspeed;
    stack<ll>a;
    ll n;
    cin>>n;
    int t;
    cin>>t;
    while(t--)
    {
        ll q;
        cin>>q;
        if(q==1)
        {
            ll x;
            cin>>x;
            a.push(x);
        }
        else if(q==2)
        {
            a.pop();
        }
        if(a.size()>0)
        {
            cout<<"Size= "<<a.size()<<" ";
            cout<<"Items= ";
            printstack(a);
        }
        else
        {
            cout<<"Size= 0 Items= NULL";
        }
        cout<<endl;
    }
    Bye;
}
*/
/*int main()
{
    Godspeed;
    ll n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        stack<char>a;
        REP(i,s.length())
        {
            a.push(s[i]);
        }
        while(!a.empty())
        {
            cout<<a.top();
            a.pop();
        }
        cout<<endl;
    }
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
        string s;
        cin>>s;
        stack<string>a;
        REP(i,s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                a.push(s.substr(i,1));
            }
            else
            {
                if(s[i]=='*')
                {
                    ll x=stoll(a.top());
                    a.pop();
                    ll y=stoll(a.top());
                    a.pop();
                    ll prod=y*x;
                    a.push(to_string(prod));
                }
                if(s[i]=='+')
                {
                    ll x=stoll(a.top());
                    a.pop();
                    ll y=stoll(a.top());
                    a.pop();
                    ll sum=y+x;
                    a.push(to_string(sum));
                }
                if(s[i]=='-')
                {
                    ll x=stoll(a.top());
                    a.pop();
                    ll y=stoll(a.top());
                    a.pop();
                    ll diff=y-x;
                    a.push(to_string(diff));
                }
                if(s[i]=='/')
                {
                    ll x=stoll(a.top());
                    a.pop();
                    ll y=stoll(a.top());
                    a.pop();
                    ll quo=y/x;
                    a.push(to_string(quo));
                }
            }
        }
        cout<<a.top()<<endl;
    }
    Bye;
}
