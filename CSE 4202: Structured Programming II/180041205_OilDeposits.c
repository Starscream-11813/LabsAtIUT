#include<stdio.h>
int m,n;
char region[1002][1002];
void SearchingOilPocket(int x,int y)//Basically Depth First Search (DFS) arki
{

    if(x < 0 || y < 0 || x == m || y == n)//Nothing to search for when start and end points are reached
    {
        return;
    }
    if(region[x][y] != '@')//If no oil pocket present
    {
        return;
    }
    if(region[x][y] == '@')//If oil pocket present
    {
        region[x][y] = '*';//replace @ with * as it has already been visited
    }
    //now just checking if any of the adjacent plots are pockets or not
    SearchingOilPocket(x,y+1);//above
    SearchingOilPocket(x,y-1);//below
    SearchingOilPocket(x+1,y);//right
    SearchingOilPocket(x-1,y);//left
    SearchingOilPocket(x+1,y+1);//top-right
    SearchingOilPocket(x+1,y-1);//bottom-right
    SearchingOilPocket(x-1,y+1);//top-left
    SearchingOilPocket(x-1,y-1);//bottom-left
}
int main()
{
    int counter,i,j;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m == 0)
        {
            break;
        }
        getchar();//ignore the endls after each row is taken in
        for(i = 0; i < m; i++)
        {
            for(j = 0; j <= n; j++)
            {
                scanf("%c",&region[i][j]);
            }
        }
        counter=0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(region[i][j] != '*')
                {
                    SearchingOilPocket(i,j);//cholte thakbe recursively until all the adjacent pockets are taken into account
                    counter++;//so after the search function completes, counter variable will increase by 1 which means 1 whole oil pocket is counted
                }
            }
        }
        printf("%d\n",counter);//just print korlam the counter followed by an endl
    }
    return 0;
}
