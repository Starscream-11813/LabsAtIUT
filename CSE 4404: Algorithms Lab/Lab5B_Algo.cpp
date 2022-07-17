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

ll myPartition(vector<ll>&a, ll l, ll h)///Hoare's partitioning scheme use korsi.
{
    ll pivot=a[(l+h)/2];///Take the middle element as the pivot.
                        ///Eita korle amar ar inner loops er bhitore bounds check kora lagtese na.
    ll i=l-1;
    ll j=h+1;
    while(true)
    {
        i++;
        while(a[i]<pivot)///Pivot er baam pashe pivot er cheye boro kisu na pawa porjontoh.
        {
            i++;///i daane agaite thakbe.
        }
        j--;
        while(a[j]>pivot)///Pivot er daan pashe pivot er cheye choto kisu na pawa porjontoh.
        {
            j--;///j baame agaite thakbe.
        }
        if(i>=j)///If i and j equal hoy, or ekta arekta re surpass kore,
                ///then j ke partitioning index dhore return kore dibo.
        {
            return j;
        }
        swap(a[i],a[j]);///Ar nahole we can be sure that a[i] belongs to right of pivot and a[j] belongs to left of pivot. So, swap them.
                        ///Eitar advantage hoilo, on average it does 3 times less swaps. And in case of already sorted inputs, no swaps need to be done,
                        ///so, eita best case for quicksort with this partitioning scheme and O(nlogn) e hoy eita.
    }
//    FOR(j,l,h-1)
//    {
//        if(a[j]<pivot)
//        {
//            i++;
//            swap(a[i],a[j]);
//        }
//    }
//    swap(a[i+1],a[h]);
//    error(i+1);
//    REP(idx,a.size())
//    {
//        cout<<a[idx]<<" ";
//    }
//    cout<<endl<<endl<<endl;
//    return i+1;
}

void quicksort(vector<ll>&a, ll l, ll h)
{
    if(l<h)
    {
        ll partitioningIdx=myPartition(a,l,h);
        quicksort(a,l,partitioningIdx);///ekhane partitioningIdx-1 kortesi na
                                       ///cuz oi place eh jei element ase oita jeh actual sorted position eh oita for sure bolte parbo na.
        quicksort(a,partitioningIdx+1,h);
    }
}

int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    ll n;
    while(true)
    {
        //cin>>n;
        scanf("%lld",&n);
        if(!n)
        {
            break;
        }
        vector<ll>a(n);
        REP(i,n)
        {
            //cin>>a[i];
            scanf("%lld",&a[i]);
        }
        random_shuffle(all(a));///Randomly O(n) eh shuffle korsi to take care of already sorted inputs.
        quicksort(a,0,n-1);
        REP(i,n-1)
        {
            printf("%lld ",a[i]);
        }
        printf("%lld\n",a[n-1]);
    }
    Bye;
}





