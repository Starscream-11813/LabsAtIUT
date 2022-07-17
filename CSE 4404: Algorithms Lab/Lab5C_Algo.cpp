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

vector<ll> paranoidQuickSort(vector<ll>&a)
{
    if(a.size()==1)///Array size 1 hoile sort korar kisu nai.
    {
        return a;
    }
    if(a.size()==2)///Array size 2 hoile max min ber kore return kore dibo.
    {
        ll minm,maxm;
        minm=min(a[0],a[1]);
        maxm=max(a[0],a[1]);
        a[0]=minm;
        a[1]=maxm;
        return a;
    }
    LD k=0;///k = ratio of size of L and total size of a.
    vector<ll>LL,GG;
    ll ppivot;
    while(true)
    {
        srand(time(nullptr));
        ll pivotIdx=(ll)rand()%((ll)a.size());///randomly select a pivot index from 0...size-1.
        ll pivot=a[pivotIdx];
        vector<ll>L,G,aNew;///L hocche vector with all elements less than pivot and G hocche greater than pivot.
        aNew=a;
        auto it=aNew.begin()+pivotIdx;
        aNew.erase(it);///pivot jeita ke dhorsi oita remove korlam ekta duplicate a array theke.
        REP(i,aNew.size())
        {
            if(aNew[i]<pivot)
            {
                L.pb(aNew[i]);///L er upojogi elements gula L eh push korlam.
            }
            else
            {
                G.pb(aNew[i]);///G er upojogi elements gula G eh push korlam.
            }
        }
        k=(LD)((LD)L.size()/(LD)aNew.size());///Ratio tah ber korlam.
        if((0.25<=k) && (k<=0.75))///Ekhon good region amra jani array er 1st 1/4th er pore and last 1/4th re pichone.
        {
            LL=L;///LL tahole valid L vector.
            GG=G;///GG tahole valid G vector.
            ppivot=pivot;///ppivot hoitese valid ekta pivot jeita good region eh pore.
            break;///Condition jehetu satisfy korse tai infinite loop break kore dilam.
        }
    }
    vector<ll>retL=paranoidQuickSort(LL);///ekhon LL er upor same process recurse korlam.
    vector<ll>retG=paranoidQuickSort(GG);///same with GG.
    retL.pb(ppivot);
    retL.insert(retL.end(),all(retG));///ekhon retL, jeita return kore arki, oitar shathe ppivot ar retR append kore dilam.
    return retL;///And ei combined version ta sorted array and eitake return kore dilam finally.
}

int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        REP(i,n)
        {
            cin>>a[i];
        }
        random_shuffle(all(a));///O(n) eh shuffle korsi to take care of already sorted inputs.
        vector<ll>res=paranoidQuickSort(a);
        REP(i,n-1)
        {
            cout<<res[i]<<" ";
        }
        cout<<res[n-1];
    }
    Bye;
}




