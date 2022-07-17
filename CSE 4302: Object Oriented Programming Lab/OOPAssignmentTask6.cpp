#include<bits/stdc++.h>
using namespace std;

#define LD                      long double
#define ll                      long long int
#define FastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ff                      first
#define ss                      second
#define pb                      push_back


class myString
{
    char s[50];
    int size_of_string;
public:
    myString()
    {
        size_of_string=0;
        s[0]='\0';
    }
    myString(const char *ch)
    {
        size_of_string=strlen(ch);
        strcpy(s,ch);
    }
    myString operator += (myString ch)
    {
        size_of_string+=sizeof(ch);//strlen(ch.s) also valid.
        strcat(s,ch.s);
    }
    operator bool ()const
    {
        return (s[0]!='\0');
    }
    myString operator + (myString ch)
    {
        myString ch2;
        ch2.s[0]='\0';
        strcat(ch2.s,s);
        strcat(ch2.s,ch.s);
        ch2.size_of_string=size_of_string+ch.size_of_string;
        return ch2;
    }
    char& operator[](int index)
    {
        if(index>=0 && index<size_of_string)
        {
            return s[index];
        }
        else
        {
            cout<<"Index is out of bounds!~"<<endl;
            exit(1);
        }
    }
    friend ostream& operator <<(ostream &output, const myString &ch)
    {
        output<<ch.s;
        return output;
    }
    friend myString operator + (const char *ch,const myString &ch2)
    {
        myString ch3;
        ch3.s[0]='\0';
        strcat(ch3.s,ch);
        strcat(ch3.s,ch2.s);
        ch3.size_of_string=strlen(ch)+ch2.size_of_string;
        return ch3;
    }
};
int main()
{
    FastIO;
    myString s1="my";
    myString s2="";
    myString s3=" buddy!";
    char x[4] = {'a', 'b', 'c', '\0'};
//    s1="Welcome To IUT, "+s1;
    s1 = x + s1;
    s1=s1+s2;
    s1+=s3;
    if(!s1)
    {
        cout<<"Empty String"<<endl;
    }
    cout<<s1[2]<<endl;
    cout<<s1<<endl;
    return 0;
}
