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
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

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

//Debugging stuff
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

//Data Structures
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>


/*struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node* head;
Node* createNode(int item, Node* next)
{
    Node* newnode=new Node();
    if(newnode==NULL)
    {
        cout<<"Error (Create Node)"<<endl;
    }
    else
    {
        newnode->data=item;
        newnode->next=next;
    }
    return newnode;
}
Node* prepend(int item, Node* head)
{
    Node* newnode=createNode(item,NULL);
    newnode->next=head;
    return newnode;
}
Node* append(int item,Node* head)
{
    Node* newnode=createNode(item,NULL);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        Node* temp=new Node();
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return head;
    }
}
Node* insertion(int item, Node* head, int key)
{
    Node* newnode=createNode(item,NULL);
    Node* temp=new Node();
    temp=head;
    while(temp!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
    }
    else
    {
        cout<<"Value Not Found"<<endl;
        return head;
    }
}
void displaylist(Node* head)
{
    if(head==NULL)
    {
        //cout<<"List is Empty!"<<endl;
        return;
    }
    else
    {
        cout<<head->data<<" ";
        displaylist(head->next);
    }
    //cout<<endl;
}
Node* deletefront(Node* head)
{
    head=head->next;
    return head;
}
Node* deletetail(Node* head)
{
    Node* temp=new Node();
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
Node* deleteitem(Node* head, int item)
{
    Node* temp=new Node();
    temp=head;
    while(temp->next!=NULL && temp->next->data!=item)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"Value not present"<<endl;
        return head;
    }
    else
    {
        temp->next=temp->next->next;
        return head;
    }
}
int main()
{
    Godspeed;
    head=NULL;
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int x;
            cin>>x;
            head=prepend(x,head);
        }
        if(q==2)
        {
            int x;
            cin>>x;
            head=append(x,head);
        }
        if(q==3)
        {
            int x,y;
            cin>>x>>y;
            head=insertion(y,head,x);
        }
        if(q==4)
        {
            head=deletefront(head);
        }
        if(q==5)
        {
            head=deletetail(head);
        }
        if(q==6)
        {
            int x;
            cin>>x;
            head=deleteitem(head,x);
        }
        displaylist(head);
        cout<<endl;
    }
    Bye;
}
*/
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;
Node* head;
Node* createNode(int item, Node* next, Node* prev)
{
    Node* newnode=new Node();
    if(newnode==NULL)
    {
        cout<<"Error (Create Node)"<<endl;
    }
    else
    {
        newnode->data=item;
        newnode->next=next;
        newnode->prev=prev;
    }
    return newnode;
}
Node* prepend(int item, Node* head)
{
    Node* newnode=createNode(item,NULL,NULL);
    newnode->next=head;
    newnode->prev=NULL;
    return newnode;
}
Node* append(int item,Node* head)
{
    Node* newnode=createNode(item,NULL,NULL);
    if(head==NULL)
    {
        return newnode;
    }
    else
    {
        Node* temp=new Node();
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        temp->prev=NULL;
        return head;
    }
}
Node* insertion(int item, Node* head, int key)
{
    Node* newnode=createNode(item,NULL,NULL);
    Node* temp=new Node();
    temp=head;
    while(temp!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }
    else
    {
        cout<<"Value Not Found"<<endl;
        return head;
    }
}
void displaylist(Node* head)
{
    if(head==NULL)
    {
        //cout<<"List is Empty!"<<endl;
        return;
    }
    else
    {
        cout<<head->data<<" ";
        displaylist(head->next);
    }
    //cout<<endl;
}
Node* deletefront(Node* head)
{
    head=head->next;
    head->prev=NULL;
    return head;
}
Node* deletetail(Node* head)
{
    Node* temp=new Node();
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
Node* deleteitem(Node* head, int item)
{
    Node* temp=new Node();
    temp=head;
    while(temp->next!=NULL && temp->next->data!=item)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"Value not present"<<endl;
        return head;
    }
    else
    {
        temp->next=temp->next->next;
        temp->next->prev=temp;
        return head;
    }
}
void reverselist()
{
    Node* next=new Node();
    Node* current=new Node();
    Node* previous=new Node();
    current=head;
    previous=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}
int main()
{
    Godspeed;
    head=NULL;
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            int x;
            cin>>x;
            head=prepend(x,head);
        }
        if(q==2)
        {
            int x;
            cin>>x;
            head=append(x,head);
        }
        if(q==3)
        {
            int x,y;
            cin>>x>>y;
            head=insertion(y,head,x);
        }
        if(q==4)
        {
            head=deletefront(head);
        }
        if(q==5)
        {
            head=deletetail(head);
        }
        if(q==6)
        {
            int x;
            cin>>x;
            head=deleteitem(head,x);
        }
        if(q==7)
        {
            reverselist();
        }
        displaylist(head);
        cout<<endl;
    }
    Bye;
}
