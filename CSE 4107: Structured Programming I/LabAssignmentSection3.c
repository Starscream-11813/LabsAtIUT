#include<stdio.h>

int main ()
{
    int i, n, marks;

    printf ("Enter a number:\n");
    scanf ("%d", &n);
    printf ("Enter %d students' marks as input:\n", n);
    for (i = 1; i <=n; i++)
    {
        printf("Enter the marks of a student:\n");
        scanf("%d",&marks);
        if(marks>100||marks<0)
        {
            printf("Invalid marks!");
        }
        else if(marks<=100&&marks>=80)
        {
            printf("Grade: A+\n");

        }
        else if(marks<80&&marks>=75)
        {
            printf("Grade: A-\n");
        }
        else if(marks<75&&marks>=70)
        {
            printf("Grade: B+\n");
        }
        else if(marks<70&&marks>=65)
        {
            printf("Grade: B+\n");

        }
        else if(marks<65&&marks>=60)
        {
            printf("Grade: B\n");
        }
        else if(marks<60&&marks>=40)
        {
            printf("Grade: D\n");
        }
        else if(marks<40&&marks>=0)
        {
            printf("Grade: F\n");
        }
    }
}
