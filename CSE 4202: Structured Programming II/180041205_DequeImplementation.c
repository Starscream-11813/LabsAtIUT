#include<stdio.h>
#define MAX 10
int deque[MAX];
int left=-1, right=-1;
void Push_right(void);
void Push_left(void);
void Pop_right(void);
void Pop_left(void);
void display(void);

int main()
{
    int choice;
    do
    {
        printf("\n1.Push at right ");
        printf("\n2.Push at left ");
        printf("\n3.Pop from right ");
        printf("\n4.Pop from left ");
        printf("\n5.Display the Deque ");
        printf("\n6.Exit the program");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==6)
        {
            printf("\nDeque Interface exited successfully\n");
            return 0;
        }
        switch(choice)
        {
        case 1:
            Push_right();
            break;
        case 2:
            Push_left();
            break;
        case 3:
            Pop_right();
            break;
        case 4:
            Pop_left();
            break;
        case 5:
            display();
            break;
        }
    }
    while(choice!=6);
    getch();
    return 0;
}
void Push_right()
{
    int val;
    printf("\nEnter the value to be added ");
    scanf("%d",&val);
    if( (left==0 && right==MAX-1) || (left==right+1) )
    {
        printf("\nOVERFLOW");
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(right==MAX-1)
            right=0;
        else
            right=right+1;
    }
    deque[right]=val;
}
void Push_left()
{
    int val;
    printf("\nEnter the value to be added ");
    scanf("%d",&val);
    if( (left==0 && right==MAX-1) || (left==right+1) )
    {
        printf("\nOVERFLOW");
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==0)
            left=MAX-1;
        else
            left=left-1;
    }
    deque[left]=val;
}
void Pop_right()
{
    if(left==-1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe Popped element is %d\n", deque[right]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
            right=MAX-1;
        else
            right=right-1;
    }
}
void Pop_left()
{
    if(left==-1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("\nThe Popped element is %d\n", deque[left]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
    }
}
void display()
{
    int front=left, rear=right;
    if(front==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nThe elements in the queue are: ");
    if(front<=rear)
    {
        while(front<=rear)
        {
            printf("%d  ",deque[front]);
            front++;
        }
    }
    else
    {
        while(front<=MAX-1)
        {
            printf("%d\t",deque[front]);
            front++;
        }
        front=0;
        while(front<=rear)
        {
            printf("%d\t",deque[front]);
            front++;
        }
    }
    printf("\n");
}

