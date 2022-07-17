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
#define ULL                     unsigned long long
#define endl                   '\n'
const ll inf = 0xFFFFFFFFFFFFFFFL;
const ll MOD = 1e9 + 9;///MOD value, which is a very big prime number.
ll computeHash(string s)///This function returns the hash value of a string.
{
    const ll p=31;///Java's Tradition to take the prime number as 31 (but it can be any prime number >=31).
    ll hash_value=0;
    ll p_pow=1;
    for (char c:s)///iterating through the characters of the string.
    {
        hash_value=(hash_value+(c-'a'+1)*p_pow)%MOD;///hash=summation of (ASCII_of_s[i] * pow(prime,i))%MOD from i=[0...n-1].
        p_pow=(p_pow*p)%MOD;///in case of overflow.
    }
    return hash_value;
}
int main()
{
    Godspeed;
    int Tests=1;
    //cin>>Tests;
    while(Tests--)
    {
        string text, pattern;
        vector<ll>idx;///This array will store the indexes where match has been found.
        getline(std::cin>>std::ws,text);///using getline() for taking white-spaces as input with the string.
        cin>>pattern;
        ll pHash=computeHash(pattern);///pHash = hash value of the pattern string.
        REP(i,text.length()-pattern.length()+1)///iterate from i=[0...text_length-pattern_length]
        {
            string temp=text.substr(i,pattern.length());///temp = the window/substring that we will check in this iteration.
            ll tHash=computeHash(temp);///tHash = the selected sub-string's hash value.
            if(tHash==pHash)/// if the hash values are equal, we proceed to check if the pattern string and the selected substring is identical or not.
            {
                if(temp==pattern)///if the strings match, we push the index into the idx array.
                {
                    idx.pb(i);
                }
            }
        }
        if(idx.empty())///if the array is empty, we can conclude that, no matches were found.
        {
            cout<<"Pattern not found!";
            return 0;
        }
        REP(i,idx.size())///we print the indexes as shown in the sample output.
        {
            cout<<"Pattern found at index: "<<idx[i]<<endl;
        }
    }
    return 0;
}
