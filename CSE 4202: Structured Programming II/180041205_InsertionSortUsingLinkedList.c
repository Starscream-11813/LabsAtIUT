#include<stdio.h>
#include<stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;
node head;
node createnode(int x)
{
    node newnode;
    newnode=(node)malloc(sizeof(struct linkedlist));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void addnode(int value)
{
    node newnode=createnode(value),temp=head;
    //temp->data=value;
    if(head==NULL)
    {
        head=newnode;
        printf("\nHead is %d\n",head->data);
        return;
    }
    //p=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    //newnode->previous=temp;
}
//return head;

void printnode()
{
    struct linkedlist *temp;
    if(head==NULL)
    {
        printf("\nNothing to show!\n");
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
node Insertion_Sort_Using_LinkedList(node head)
{
    node x,y,e;
    x=head;
    head=NULL;
    while(x!=NULL)
    {
        e=x;
        x=x->next;
        if(head!=NULL)
        {
            if(e->data > head->data)
            {
                y=head;
                while((y->next!=NULL) && (e->data > (y->next)->data))
                {
                    y=y->next;
                }
                e->next=y->next;
                y->next=e;
            }
            else
            {
                e->next=head;
                head=e;
            }
        }
        else
        {
            e->next=NULL;
            head=e;
        }
    }
    return head;
}
int main()
{
    int x,n,choice;
    //node head;
    head=NULL;
    printf("This is the interface for Linked List Data Structure\n");
start:
    printf("\nYour options are:\n");
    printf("\n0- Exit the Interface\n1- Add Node(LEFT)\n2- Print the nodes of the Linked List(LEFT TO RIGHT)\n3- Sort the list using Insertion Sort(ASCENDING ORDER)\n");
    scanf("%d",&choice);
    if(choice==0)
    {
        printf("\nInterface exited successfully.\n");
        exit(0);
    }
    else if(choice==1)
    {
        printf("\nType the value you want to add:\n");
        scanf("%d",&n);
        addnode(n);
        goto start;
    }
    else if(choice==2)
    {
        printnode();
        goto start;
    }
    else if(choice==3)
    {
        head=Insertion_Sort_Using_LinkedList(head);
        if(head!=NULL)
        {
            printnode();
        }
        goto start;
    }
    else
    {
        printf("\nInvalid Option!\n");
        goto start;
    }
    return 0;
}

