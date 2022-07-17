#include<bits/stdc++.h>
using namespace std;
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define all(a)                  a.begin(),a.end()
#define Godspeed                ios_base::sync_with_stdio(0);cin.tie(NULL)
#define urs(r...)               typename decay<decltype(r)>::type
#define FOR(i,a,b)              for(urs(b) i=a;i<=b;i++)
#define REP(i,b)                for(urs(b) i=0;i<b;i++)
#define FOREACH(i,t)            for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define what_is(x)              cerr << __LINE__ <<": " << #x << " is " << x << endl;

#define ll                      long long
#define LD                      long double
#define endl                   '\n'
const ll inf = 0xFFFFFFFFFFFFFFFL;

ll mxN=100000,logN=ceil((LD)log2(mxN));
vector<ll>Tree(1LL<<(logN+1)),a(mxN);

void build(ll node, ll b, ll e)
{
    if(b==e)
    {
        Tree[node]=a[b];
        return;
    }
    ll leftchild=(2*node)+1;
    ll rightchild=(2*node)+2;
    ll mid=(b+e)/2;
    build(leftchild,b,mid);
    build(rightchild,mid+1,e);
    Tree[node]=Tree[leftchild]+Tree[rightchild];
}
void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i>e || i<b)
    {
        return;
    }
    if(b>=i && e<=i)
    {
        Tree[node]=val;
        return;
    }
    ll leftchild=(2*node)+1;
    ll rightchild=(2*node)+2;
    ll mid=(b+e)/2;
    update(leftchild,b,mid,i,val);
    update(rightchild,mid+1,e,i,val);
    Tree[node]=Tree[leftchild]+Tree[rightchild];
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return Tree[node];
    }
    ll leftchild=(2*node)+1;
    ll rightchild=(2*node)+2;
    ll mid=(b+e)/2;
    ll segsum1=query(leftchild,b,mid,i,j);
    ll segsum2=query(rightchild,mid+1,e,i,j);
    ll sum=segsum1+segsum2;
    return sum;
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        ll n,q;
        cin>>n>>q;
        REP(i,n)
        {
            cin>>a[i];
        }
        build(0,0,n-1);
        while(q--)
        {
            ll op;
            cin>>op;
            if(op==1)
            {
                ll i;
                cin>>i;
                cout<<a[i]<<endl;
                update(0,0,n-1,i,0);
            }
            else if(op==2)
            {
                ll i,v;
                cin>>i>>v;
                ll newval=a[i]+v;
                a[i]=newval;
                update(0,0,n-1,i,newval);
            }
            else if(op==3)
            {
                ll i,j;
                cin>>i>>j;
                cout<<query(0,0,n-1,i,j)<<endl;
            }
        }
    }
    return 0;
}


