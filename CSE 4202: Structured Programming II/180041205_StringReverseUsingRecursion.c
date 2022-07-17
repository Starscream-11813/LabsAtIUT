#include<stdio.h>
#include<string.h>
void swap(char a, char b)//swapping the character of the string from left and right onwards.
{                        //Global variable declare korle eita kora jabe apatoto baad
    char temp;
    temp=a;
    a=b;
    b=temp;
}
void RecursionReverse(char x[], int start, int end)
{
    char swapper;
    if(start>=end)//Terminating condition eita
    {
        return;
    }
    swapper=x[start];
    x[start]=x[end];
    x[end]=swapper;
    swap(x[start],x[end]);
    start++;
    end--;
    RecursionReverse(x,start,end);
}
int main()
{
    char str[100];
    int i;
    scanf("%s",&str);
    //gets(str);
    int length=strlen(str);
    //puts(str);
    RecursionReverse(str,0,length-1);//string er index 0 theke shuru and n-1 theke shesh
    printf("%s",str);                //majhkhaner dike agaite thakbe shuru>=shesh na howa porjontoh
    return 0;
}

