#include<stdio.h>
#include<string.h>


int main ()
{
    int i, n, m, length, vowels=0, consonants=0;
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
            if(st[m]=='a'||st[m]=='e'||st[m]=='i'||st[m]=='o'||st[m]=='u'||st[m]=='A'||st[m]=='E'||st[m]=='I'||st[m]=='O'||st[m]=='U')
            {
                ++vowels;
            }
            else if((st[m]>='a' && st[m]<='z')||(st[m]>='A' && st[m]<='Z'))
            {
                ++consonants;
            }

        }
        printf("No. of Vowels: %d\n",vowels);
        printf("No. of Consonants: %d\n", consonants);
        vowels = 0;
        consonants = 0;

    }
    return 0;


}
