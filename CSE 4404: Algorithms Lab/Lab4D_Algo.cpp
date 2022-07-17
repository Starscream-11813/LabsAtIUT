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
void join(vector<ll>&a,ll b,ll mid,ll e)
{
    ll nL=mid-b+1;
    ll nR=e-mid;
    vector<ll>L(nL+1),R(nR+1);
    REP(i,nL)
    {
        L[i]=a[b+i];///Copying the Left half.
    }
    REP(i,nR)
    {
        R[i]=a[mid+i+1];///Copying the Right half.
    }
    ll idxL=0,idxR=0,n=0;
    while(idxL!=nL && idxR!=nR)
    {
        if(L[idxL]>R[idxR])
        {
            a[b+n]=R[idxR];///From Right side array.
            idxR++;///Right half array er oi index er kaaj shesh so proceed to next one.
        }
        else
        {
            a[b+n]=L[idxL];///From Left side array.
            idxL++;///Left half array er oi index er kaaj shesh so proceed to next one.
        }
        n++;///increasing index of merged array.
    }
    while(idxR!=nR)///If the former while loop broke due to idxL.
    {
        a[b+n]=R[idxR];
        idxR++;
        n++;///increasing index of merged array.
    }
    while(idxL!=nL)///If the former while loop broke due to idxR.
    {
        a[b+n]=L[idxL];
        idxL++;
        n++;///increasing index of merged array.
    }
}
void mergeSort(vector<ll>&a,ll b,ll e)
{
    if(e>b)
    {
        ll mid=(b+e)/2;
        mergeSort(a,b,mid);///beginning to mid.
        mergeSort(a,mid+1,e);///mid+1 to end.
        join(a,b,mid,e);///Then, merge them together.
    }
}
int main()
{
    Godspeed;
    //int Tests=1;
    //cin>>Tests;
    ll n;
    while(true)
    {
        cin>>n;
        if(!n)
        {
            break;
        }
        vector<ll>a(n);
        REP(i,n)
        {
            cin>>a[i];
        }
        mergeSort(a,0,n-1);///Call from 0 to n-1 in the main() function.
        REP(i,n)
        {
            if(i==n-1)
            {
                cout<<a[i];
            }
            else
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    Bye;
}




