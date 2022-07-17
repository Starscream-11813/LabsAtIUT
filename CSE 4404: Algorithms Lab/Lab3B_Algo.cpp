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

int main()
{
    //Godspeed;
    //int Tests=1;
    ll coins[11]= {1,2,4,10,20,40,100,200,400,1000,2000};///no. of coins of 5 cents needed to make:
                                                        ///$100, $50, $20, $10, $5, $2, $1, 50c, 20c, 10c, 5c
    ll dp[6001];///cuz max possible is 300*20=6000 of 5c coins.
                ///dp[i] will store no. of ways i can me made using given coins.
                ///also done in bottom-up manner.
    //cin>>Tests;
    dp[0]=1;///Base case: if amount is 0 it can be done in 1 way i.e. not picking anything at all.
    REP(i,11)
    {
        FOR(j,coins[i],6000)///using ith coin and its preceding coins.
        {
            dp[j]+=dp[j-coins[i]];///add the no. of ways found with the amount remaining after subtracting with ith coin.
        }
    }
    ll a,b;
    char dot;
    while(true)
    {
        //cin>>a>>dot>>b;
        scanf("%lld.%lld",&a,&b);///Input as $.cents.
        ll k=(100*a+b)/5;///Convert them all to cents and find out how many 5 cent coins needed.
        if(!k)
        {
            break;
        }
        if(b>=10)///If cents value is greater equal 10 cents, then no extra 0s needed.
        {
            printf("%3lld.%lld",a,b);
        }
        else
        {
            printf("%3lld.0%lld",a,b);///if it's sth like 69.05 then an extra 0 is needed.
        }
        printf("%17lld\n",dp[k]);///Final answer will be in dp[k].
        //cout<<endl;
    }
    Bye;
}
///Time Complexity: O(11*6000)~O(no. of denominations*maximum possible amount).
//concat(concat((dateBetween(prop("Deadline"), prop(now()), "days") > 0) ? concat(format(dateBetween(prop("Deadline"), prop(now()), "days")), (dateBetween(prop("Deadline"), prop(now()), "days") > 1) ? " days" : " day") : "", concat((dateBetween(prop("Deadline"), prop(now()), "hours") - dateBetween(prop("Deadline"), prop(now()), "days") * 24 > 0 and dateBetween(prop("Deadline"), prop(now()), "days") > 0) ? ", " : "", (dateBetween(prop("Deadline"), prop(now()), "hours") - dateBetween(prop("Deadline"), prop(now()), "days") * 24 > 0) ? concat(format(dateBetween(prop("Deadline"), prop(now()), "hours") - dateBetween(prop("Deadline"), prop(now()), "days") * 24), (dateBetween(prop("Deadline"), prop(now()), "hours") - dateBetween(prop("Deadline"), prop(now()), "days") * 24 > 1) ? " hours" : " hour") : "")), concat((dateBetween(prop("Deadline"), prop(now()), "minutes") - dateBetween(prop("Deadline"), prop(now()), "hours") * 60 > 0 and dateBetween(prop("Deadline"), prop(now()), "hours") > 0) ? ", " : "", (dateBetween(prop("Deadline"), prop(now()), "minutes") - dateBetween(prop("Deadline"), prop(now()), "hours") * 60 > 0) ? concat(format(dateBetween(prop("Deadline"), prop(now()), "minutes") - dateBetween(prop("Deadline"), prop(now()), "hours") * 60), (dateBetween(prop("Deadline"), prop(now()), "minutes") - dateBetween(prop("Deadline"), prop(now()), "hours") * 60 > 1) ? " minutes" : " minute") : ""))
//
//if(empty(prop("Deadline")), toNumber(""), ceil((toNumber(prop("Deadline")) - toNumber(now())) / 86400000))
//
//if(dateBetween(prop("Deadline"), now(), "hours") > 24, format(dateBetween(prop("Deadline"), now(), "days")), dateBetween(prop("Deadline"), now(), "hours"))
//
//if(dateBetween(prop("Deadline"), now(), "hours") > 24, concat(format(dateBetween(prop("Deadline"), now(), "days")), " days"), concat(format(dateBetween(prop("Deadline"), now(), "hours")), " hours"))
//if(dateBetween(prop("Deadline"), now(), "hours")>24,concat(format(dateBetween(prop("Deadline"), now(), "days")), " days",concat(format(toNumber(format(dateBetween(prop("Deadline"), now(), "hours")))%24))," hours"),concat(format(dateBetween(prop("Deadline"), now(), "hours")), " hours"))
//concat(format(floor((toNumber(dateBetween(prop("Deadline"), now(), "seconds"))%(86400*30))/86400))," days",format(floor((toNumber(dateBetween(prop("Deadline"), now(), "seconds"))%(86400))/3600))," hours",format(floor((toNumber(dateBetween(prop("Deadline"), now(), "seconds"))%(3600))/60))," minutes",format(floor((toNumber(dateBetween(prop("Deadline"), now(), "seconds"))%(60))/1))," seconds")




