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
//#define endl                    '\n'
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

#define DIFF    (LD)1e-7

LD crossProduct(pldld a, pldld b, pldld c)
{
    return (b.ff-a.ff)*(c.ss-a.ss)-(b.ss-a.ss)*(c.ff-a.ff);
}
bool counterClockwise(pldld a, pldld b, pldld c)
{
    return crossProduct(a,b,c)>DIFF;
}
int main()
{
    Godspeed;
    int Tests=1;
    cin>>Tests;
    while(Tests--)
    {
        vector<pldld>p;
        ll n;
        cin>>n;
        ll res=0;
        REP(i,n)
        {
            LD x,y;
            char ch;
            cin>>x>>y>>ch;
            if(ch=='Y')
            {
                p.pb({x,y});
                res++;
            }
        }
        //Debug;
        vector<pldld>CH;
        sort(all(p));///Sorting the set of points. The lowest and leftmost point is at the front.
        //Debug;
        ///Building the Upper Hull.
        REP(i,p.size())
        {
            ///While CH contains at least 2 points and the sequence of last 2 points of CH and the point p[i] makes a counter-clockwise turn.
            while (CH.size()>=2 && counterClockwise(CH[CH.size()-2],CH[CH.size()-1],p[i]))
            {
                CH.pop_back();
            }
            CH.push_back(p[i]);
        }
        REP(i,CH.size())
        {
            cout<<CH[i].ff<<" "<<CH[i].ss<<endl;
        }
        cout<<endl;
        ll upperHull=CH.size()+1;///+1 cuz, last element now is the 1st point of the Lower Hull.
        ///Building the Lower Hull.
        ROF(i,p.size()-2,0)///Starting from the 2nd last element, because the last element is already in the Upper Hull.
        {
            ///While CH is at least 2 points plus the Upper Hull points and the sequence of last 2 points of CH and the point p[i] makes a counter-clockwise turn.
            while (CH.size()>=upperHull && counterClockwise(CH[CH.size()-2],CH[CH.size()-1],p[i]))
            {
                CH.pop_back();
            }
            CH.push_back(p[i]);
        }
        CH.pop_back();
        REP(i,CH.size())
        {
            cout<<CH[i].ff<<" "<<CH[i].ss<<endl;
        }
        //Debug;
        cout<<res<<endl;
        pldld leftLowermost=CH.front();
        ll k=0;
//        FOR(i,1,CH.size()-1)
//        {
//            if(CH[i].ff<leftLowermost.ff || (CH[i].ff==leftLowermost.ff && CH[i].ss<leftLowermost.ss))
//            {
//                what_is(k);
//                k=i;
//            }
//        }
        REP(i,CH.size())
        {
            ll j=(k-i+CH.size())%(ll)CH.size();///1st print the leftest lowermost point then print the CH from backwards. (for Counter-clockwise).
            //what_is(j);
            //error(j);
            cout<<(ll)CH[j].ff<<" "<<(ll)CH[j].ss<<endl;
        }
    }
    Bye;
}




