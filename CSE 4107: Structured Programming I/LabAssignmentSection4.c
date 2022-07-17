#include<stdio.h>

int main ()
{
    int i, n, primecheck, c=2 ;

    printf ("Enter a number:\n");
    scanf ("%d", &n);
    printf ("Enter %d integers as input:\n", n);
    for (i = 1; i <=n; i++)
    {
        printf("Enter an integer to check whether it's a Prime Number or not:\n");
        scanf("%d",&primecheck);
        for(c=2; c<=primecheck-1; c++)
        {
            if(primecheck%c==0)
            {
                printf("%d is not a Prime Number\n",primecheck);
                break;
            }
        }
        if(c==primecheck)
        {
            printf("%d is a Prime Number!\n",primecheck);
        }
    }
}
