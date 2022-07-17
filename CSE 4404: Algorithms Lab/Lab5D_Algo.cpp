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
const ll CUTOFF = 15;
const ll R = 256;
bool isLess(string v, string w, ll idx)///Compare string v and w from index idx to end,
                                       ///and determine which would come 1st in lexicographical ordering.
{
    FOR(i,idx,9)
    {
        if(v[i]<w[i])
        {
            return true;
        }
        if(v[i]>w[i])
        {
            return false;
        }
    }
    return v.length()<w.length();
}
//void insertion(vector<string>a,ll low, ll high, ll idx)
void insertion(string *a,ll low, ll high, ll idx)///Cutoff to Insertion Sort for small subarrays.
{
    FOR(i,low,high)
    {
        ROF(j,i,low+1)
        {
            if(!isLess(a[j],a[j-1],idx))///Compare string a[j] and a[j-1] starting from char at index idx.
            {
                break;
            }
            else
            {
                swap(a[j],a[j-1]);///swap if a[j]<a[j-1].
            }
        }
    }
}
//void MSDRadixSort(vector<string>a,ll low,ll high,ll idx,vector<string>aux)
void MSDRadixSort(string *a,ll low,ll high,ll idx,string *aux)
{
    if(high<low)///A not necessary micro-optimization. Cuz, need 258 size count[] arrays for even subarrays of size 2.
    {
        insertion(a,low,high,idx);///Call on insertion sort for smaller subarrays.
        return;
    }
    vector<ll>Count(R+2);///Array for key indexed accounting. Size is 2 more than the total possible characters in the language.
                         ///each cell of count[] represents the amount of words that will for sure appear before the words that start with the index's char.
    //ll *Count=new ll[R+2];
    FOR(i,low,high)
    {
        ll ch;
        if(idx==a[i].length())
        {
            ch=-1;
        }
        else
        {
            ch=a[i][idx];///ASCII of that character.
        }
        Count[ch+2]++;///+2 to handle case of -1.
    }
    REP(r,R+1)
    {
        Count[r+1]+=Count[r];///Cumulative sum.
    }
    FOR(i,low,high)
    {
        ll ch;
        if(idx==a[i].length())
        {
            ch=-1;
        }
        else
        {
            ch=a[i][idx];
        }
        //Count[ch+1]++;
        aux[Count[ch+1]]=a[i];
        Count[ch+1]++;
    }
    FOR(i,low,high)
    {
        a[i]=aux[i-low];
    }
    REP(r,R)
    {
        MSDRadixSort(a,low+Count[r],low+Count[r+1]-1,idx+1,aux);
    }
}
int main()
{
    Godspeed;
    int Tests=1;
    cin>>Tests;
    while(Tests--)
    {
        ll n;
        cin>>n;
        //vector<string>v(n);
        string v[n];
        REP(i,n)
        {
            cin>>v[i];
        }
        //vector<string>aux(n);
        string aux[n];///output buffer in auxiliary array.
        MSDRadixSort(v,0,n-1,0,aux);
        REP(i,n)
        {
            cout<<v[i]<<endl;
        }
    }
    Bye;
}




