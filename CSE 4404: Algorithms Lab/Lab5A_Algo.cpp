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

ll MulMod(ll a, ll b, ll m)
{
    ll result = 0LL;
    a %= m;
    while (b)
    {
        if (b % 2)
            result = (result + a) % m;
        a = (a + a) % m;
        b /= 2LL;
    }
    return result;
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
        ll A[n][n],B[n][n];
        ll C[n][n];
        ll r[n][1],Br[n][1],ABr[n][1],Cr[n][1];
        REP(i,n)
        {
            REP(j,n)
            {
                cin>>A[i][j];
                //A[i][j]%=MOD;
            }
        }
        REP(i,n)
        {
            REP(j,n)
            {
                cin>>B[i][j];
                //B[i][j]%=MOD;
            }
        }
        REP(i,n)
        {
            REP(j,n)
            {
                cin>>C[i][j];
            }
        }
        bool flag=true;
        ll RNGesus=20;///Making the algorithm repeat 20 times to ensure correctness.
        while(RNGesus--)
        {
            srand(time(NULL));///Setting current time as seed value.
            REP(i,n)
            {
                //r[i][0]=(ll)ODD((ll)rand());
                r[i][0]=(ll)rand();///Generating the r vector using random values.
                //r[i][0]=abs((ll)rand()&7);
                //what_is(r[i][0]);
            }
            MEM(Br,0LL);///Using memset to set all entries as 0 for Br, ABr, Cr.
            MEM(ABr,0LL);
            MEM(Cr,0LL);
            REP(i,n)
            {
                REP(j,n)
                {
                    //Br[i][0]+=(B[i][j]*r[j][0]);
                    //Br[i][0]+=MulMod(B[i][j],r[j][0],MOD);
                    Br[i][0]+=((B[i][j]*r[j][0])%MOD);///For each row of Br, I am taking the sum of B[i][0] to B[i][n-1] multiplied by r[j][0],
                                                      ///cuz matrix multiplication eh baam pasher matrix er rows gula daan pasher matrix er columns er shathe multiplied hoy,
                                                      ///and I am modding by 10^9+7 in each step.
                    //Br[i][0]+=(MulMod(B[i][j],r[j][0],MOD)%MOD);
                    Br[i][0]%=MOD;
                }
            }
            REP(i,n)
            {
                REP(j,n)
                {
                    //ABr[i][0]+=(A[i][j]*Br[j][0]);
                    //ABr[i][0]+=MulMod(A[i][j],Br[j][0],MOD);
                    ABr[i][0]+=((A[i][j]*Br[j][0])%MOD);///Same with ABr.
                    //ABr[i][0]+=(MulMod(A[i][j],Br[j][0],MOD)%MOD);
                    ABr[i][0]%=MOD;
                }
            }
            REP(i,n)
            {
                REP(j,n)
                {
                    //Cr[i][0]+=(C[i][j]*r[j][0]);
                    //Cr[i][0]+=MulMod(C[i][j],r[j][0],MOD);
                    Cr[i][0]+=((C[i][j]*r[j][0])%MOD);///Same with Cr.
                    //Cr[i][0]+=(MulMod(C[i][j],r[j][0],MOD)%MOD);
                    Cr[i][0]%=MOD;
                }
            }
            flag=true;
            REP(i,n)
            {
                //what_is(ABr[i][0]);
                //what_is(Cr[i][0]);
                if(ABr[i][0]!=Cr[i][0])///Now, I will compare the Left hand side vector ABr with the Right hand side vector Cr.
                                       ///If they are equal, proceed to the next repetition. Else, we can conclude that the given product is incorrect and break the whole loop.
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    Bye;
}

/*
3
2 0 1
1 0 3
1 1 0
2 0 1
1 0 3
1 1 0
5 1 2
5 3 1
3 0 4

3
2 0 1
1 0 3
1 1 0
2 0 1
1 0 3
1 1 0
5 1 2
5 3 2
3 0 4
*/


