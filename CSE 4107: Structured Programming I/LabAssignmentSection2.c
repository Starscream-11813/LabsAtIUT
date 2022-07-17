#include<stdio.h>
#include<string.h>


int main ()
{
    int i, n, m, length, digits=0, alphabets=0;
    char st[100];
    printf ("Enter a number:\n");
    scanf ("%d", &n);
    printf ("Enter %d strings as input:\n", n);
    for (i = 1; i <=n; i++)
    {

        printf ("Enter a string for calculating its length:\n");
        scanf("%s",st);
        length = strlen (st);
        printf ("Length of the string is=%d\n", length);
        for(m=0; st[m]!='\0'; ++m)
        {
            if((st[m]>='a'&& st[m]<='z') || (st[m]>='A'&& st[m]<='Z'))
            {
                ++alphabets;
            }
            else if(st[m]>='0' && st[m]<='9')
            {
                ++digits;
            }
        }
        printf("No. of Digits: %d\n",digits);
        printf("No. of Alphabets: %d\n", alphabets);
        digits = 0;
        alphabets = 0;
    }
    return 0;
}
