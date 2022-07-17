#include<stdio.h>
int datastructurechoice,stack[100],top=-1,choice,n1,n2,x,i,bottom,queue[100];
void pop(void);
void push(void);
void display(void);
void pop(void)
{
    if(datastructurechoice==1 && choice==2)
    {
        if(top<=-1)
        {
            printf("\nStack Underflow! There is nothing in the Stack to that can be removed!\n");
        }
        else
        {
            printf("\nElement that has been removed= %d from Stack index %d\n",stack[top],top+1);
            top--;
        }
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
    else if(datastructurechoice==2 && choice==2)
    {
        if(bottom>=n2)
        {
            printf("\nQueue Underflow! There is nothing in the Queue to that can be removed!\n");
        }
        else
        {
            printf("\nElement that has been removed= %d from Queue index %d\n",queue[n2-1],n2);
            //bottom++;
            n2=n2-1;
        }
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
}
void push(void)
{
    if(datastructurechoice==1 && choice==1)
    {
        if(top>=n1-1)
        {
            printf("\nStack Overflow! Increase the size to make it work.\n");
        }
        else
        {
            printf("\nType the value that you want to input in the Stack:\n");
            scanf("%d",&x);
            top++;
            stack[top]=x;
            printf("\nThe value %d has been stored in the Stack index %d\n",x,top+1);
        }
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
    else if(datastructurechoice==2 && choice==1)
    {
        if(bottom<=0)
        {
            printf("\nQueue Overflow! Increase the size to make it work.\n");
        }
        else
        {
            printf("\nType the value that you want to input in the Queue:\n");
            scanf("%d",&x);
            bottom--;
            queue[bottom]=x;
            printf("\nThe value %d has been stored in the Queue index %d\n",x,bottom+1);
        }
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
}
void display(void)
{
    if(datastructurechoice==1 && choice==3)
    {
        printf("\nThe values stored in the stack now are:\n");
        for(int i=top; i>=0; i--)
        {
            printf("%d\n",stack[i]);
        }
        printf("\nThe top element is= %d\n",stack[top]);
        printf("\nThe bottom element is= %d\n",stack[0]);
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
    else if(datastructurechoice==2 && choice==3)
    {
        printf("\nThe values stored in the Queue now are:\n");
        for(int i=n2-1; i>=bottom; i--)
        {
            printf("%d\n",queue[i]);
        }
        printf("\nThe top element is= %d\n",queue[n2-1]);
        printf("\nThe bottom element is= %d\n",queue[bottom]);
        printf("\nNext operation in 1-Stack or 2-Queue? Press 3 to terminate the program:\n");
    }
}

int main()
{
    printf("\nSet a size for your Stack and Queue that you will be using:\n");
    printf("\nWhat is the size of your Stack?\n");
    scanf("%d",&n1);
    printf("\nWhat is the size of your Queue?\n");
    scanf("%d",&n2);
    bottom=n2;
start:
    {
        //printf("\nINSIDE START\n");
        printf("\nSelect the Data Structure you want to work with:\n");
        printf("\n1-Stack\n2-Queue\n3-Terminate the program\n");
        scanf("%d",&datastructurechoice);
        if(datastructurechoice==3)
        {
            printf("\nProgram exited successfully\n");
            return 0;
        }
        if(datastructurechoice!=1 && datastructurechoice!=2 && datastructurechoice!=3)
        {
            printf("\nInvalid choice! Pick 1 or 2\n");
            goto start;
        }
        goto nexterpor;
        /*if(datastructurechoice==1)
        {
            //printf("\nWhat is the size of your Stack?\n");
            //scanf("%d",&n1);
        }
        else if(datastructurechoice==2)
        {
            //printf("\nWhat is the size of your Queue?\n");
            //scanf("%d",&n2);
            //bottom=n2;
        }*/
        /*if(datastructurechoice!=1 && datastructurechoice!=2)
        {
            printf("\nInvalid choice! Pick 1 or 2\n");
            goto start;
        }*/
next:
        {
            //printf("\nINSIDE NEXT\n");
            scanf("%d",&datastructurechoice);
            if(datastructurechoice==3)
            {
                printf("\nProgram exited successfully\n");
                return 0;
            }
nexterpor:
            {
                //printf("\nINSIDE NEXTERPOR\n");
                if(datastructurechoice==1)
                {
                    //top=-1;
                    printf("\nYour options are:\n");
                    printf("\nOption 1: Push a value\nOption 2: Pop a value\nOption 3: Display a the Stack\nOption 4: Exit the Interface\n");
                    printf("\nChoose your option\n");
                    while(choice!=4)
                    {
                        scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1:
                        {
                            push();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 2:
                        {
                            pop();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 3:
                        {
                            display();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 4:
                        {
                            printf("\nStack Interface exited successfully!\n");
                            break;
                        }
                        default:
                        {
                            printf("\nInvalid Option! Choose from the Options 1-4:\n");
                        }
                        }
                    }
                }
                else if(datastructurechoice==2)
                {
                    printf("\nYour options are:\n");
                    printf("\nOption 1: Push a value\nOption 2: Pop a value\nOption 3: Display a the Queue\nOption 4: Exit the Interface\n");
                    printf("\nChoose your option\n");
                    //bottom=n2;
                    while(choice!=4)
                    {
                        scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1:
                        {
                            push();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 2:
                        {
                            pop();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 3:
                        {
                            display();
                            //scanf("%d",&datastructurechoice);
                            goto next;
                            break;
                        }
                        case 4:
                        {
                            printf("\nQueue Interface exited successfully!\n");
                            break;
                        }
                        default:
                        {
                            printf("\nInvalid Option! Choose from the Options 1-4:\n");
                        }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
