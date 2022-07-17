#include<bits/stdc++.h>
using namespace std;

#define Node struct TrieNode
#define REP(i,n) for(int i=0;i<n;i++)
struct TrieNode
{
    struct TrieNode* next[26];
    bool flag;
};
Node* createnode()
{
    Node* newnode=new Node;
    newnode->flag=false;
    REP(i,26)
    {
        newnode->next[i]=nullptr;
    }
    return newnode;
}
void insertstring(Node* node, string s)
{
    Node* temp=node;
    REP(i,s.length())
    {
        if(temp->next[s[i]-'a']==nullptr)
        {
            temp->next[s[i]-'a']=createnode();
        }
        temp=temp->next[s[i]-'a'];
    }
    temp->flag=true;
}
bool searchstring(Node* node, string s)
{
    Node* temp=node;
    REP(i,s.length())
    {
        if(temp->next[s[i]-'a']==nullptr)
        {
            return false;
        }
        temp=temp->next[s[i]-'a'];
    }
    if(temp!=nullptr && temp->flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(Node* root)
{
    REP(i,26)
    {
        if(root->next[i])
        {
            return false;
        }
    }
    return true;
}
Node* deletestring(Node* root, string s,int depth=0)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(depth==s.length())
    {
        if(root->flag)
        {
            root->flag=false;
        }
        if(isEmpty(root))
        {
            delete(root);
            root=nullptr;
        }
        return root;
    }
    root->next[s[depth]-'a']=deletestring(root->next[s[depth]-'a'],s,depth+1);
    if(isEmpty(root) && root->flag==false)
    {
        delete(root);
        root=nullptr;
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root=createnode();
    insertstring(root,"rifat");
    insertstring(root,"sifat");
    insertstring(root,"sifath");
    cout<<"lol"<<endl;
    cout<<searchstring(root,"rifat")<<endl;
    cout<<searchstring(root,"sif")<<endl;
    cout<<searchstring(root,"sifath")<<endl;
    deletestring(root,"sifath");
    cout<<searchstring(root,"rifat")<<endl;
    cout<<searchstring(root,"sif")<<endl;
    cout<<searchstring(root,"sifath")<<endl;
    return 0;
}
