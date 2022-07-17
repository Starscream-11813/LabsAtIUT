/*
By- Syed Rifat Raiyan
ID- 180041205
CSE-Group-B1
*/
#include<stdio.h>
#include<string.h>
int a[100],i=0;      // array a[100] will have the numbers as integers.
char expression[200];//it'll have the numbers and operands as characters.
void addition(int x, int y, int i);//addition function declaration.
void multiplication(int x, int i);//multiplication function declaration.
void solveExpression(int n, char expression[]);//declaring the function which will solve the expression.
void addition(int x, int y, int i)//addition function definition.
{
    a[i]+=x+y;
}
void multiplication(int x, int i)//multiplication function definition.
{
    a[i]*=x;
}
void solveExpression(int n, char expression[])//defining the function which will solve the expression.
{
    a[0]=expression[0]-48;//char-48=int
    int j,k,p,q,r;
    for(j=2;j<n;j+=2)//checking each subsequent cell after the 3rd cell upto the length-1
    {
        if(expression[j-1]=='+')//if there is + operand before
        {
            p=expression[j]-48;//char-48=int
            i++;// determines the index of a[] in which the corresponding value will be stored after undergoing the function
            addition(p,a[i],i);//calling addition function.

        }
        else if(expression[j-1]=='*')//if the operand before is a * sign
        {
            q=expression[j]-48;//char-48=int
            multiplication(q,i);//calling the multiplication function.
        }
    }
    for(r=1;r<=i;r++)//from r=1 to r=i, just add up the values and store them in the rightmost cell in the last step when r=i.
    {
        a[r]+=a[r-1];
    }
    printf("%d",a[i]);//output is the summation obtained above i.e. the value in the ith or rth index of a[] array.

}
int main()  //defining the main function.
{
    scanf("%s",&expression);// input the arithmetic string that is to be evaluated.
    solveExpression(strlen(expression),expression);//calling the solveExpression function.
    return 0;
}



