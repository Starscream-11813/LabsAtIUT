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
        ll n;
        cin>>n;
        REP(i,n)
        {
            cin>>a[i];
        }
        build(0,0,n-1);
        cout<<query(0,0,n-1,1,3)<<endl;
        update(0,0,n-1,1,59);
        cout<<query(0,0,n-1,1,3)<<endl;
        REP(i,n)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
7
4 -9 3 7 1 0 2
*/
