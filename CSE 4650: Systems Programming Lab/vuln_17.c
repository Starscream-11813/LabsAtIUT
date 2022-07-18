#include <stdio.h>
#include <stdlib.h>

void win()
{
    printf("CONGRATS! You've finally ascended the throne. You're to become a MASTER!\n");
    exit(1);
}

void vuln(int a, int b, int c, int d, int e, int f, int g)
{
    int var = 0;
    char buf[69];
    gets(buf);

    if (g == 15691569 && var == 0x5e1f1e55)
    {
        printf("Well done! You've crossed the first obstacle! Now, shut up and cross the next.\n");
    }
    else
    {
        printf("You don't have what it takes! Go sleep on your little couch.\n");
        exit(1);
    }
}

int main()
{
    printf("Can you be the Master, my precious?\n");
    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;
    int g = 6;
    vuln(a, b, c, d, e, f, g);
}