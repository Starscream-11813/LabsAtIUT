#include<stdio.h>
#include<stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *next;
    struct linkedlist *previous;
};
typedef struct linkedlist *node;
node head;//globally pointer to head declare dilam
node createnewnode(int x)
{
    node notun=(node)malloc(sizeof(struct linkedlist));
    notun->data=x;
    notun->previous=NULL;
    notun->next=NULL;
    return notun;//notun node er pointer tah return korbe
}
void addnewnodefront(int x)//shamne theke ekta node insert
{
    node notun=createnewnode(x);
    if(head==NULL)
    {
        head=notun;
        return;
    }
    head->previous=notun;
    notun->next=head;
    head=notun;
}
void addnewnodeback(int x)//pichon theke ekta node insert
{
    node temp=head;
    node notun=createnewnode(x);
    if(head==NULL)
    {
        head=notun;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;//last-er node eh gelam
    }
    temp->next=notun;
    notun->previous=temp;;
}
void printnodefront()//shamner theke shob print
{
    node temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void printnodereverse()//pichon theke shob print
{
    node temp=head;
    if(temp==NULL)
    {
        printf("\nThe List is Empty!\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->previous;
    }
    printf("\n");

}
int main()
{
    head=NULL;
    int n,choice;
    printf("This is the interface for Doubly Linked List Data Structure\n");
start:
    printf("\nYour options are:\n");
    printf("\n0- Exit the Interface\n1- Add Node From Head\n2-Add Node From Tail\n3- Print the nodes of the Linked List From Front\n4-Print the nodes of the Linked List From Tail\n");
    scanf("%d",&choice);
    if(choice==0)
    {
        printf("\nInterface exited successfully\n");
        exit(0);
    }
    else if(choice==1)
    {
        printf("\nType the value you want to add:\n");
        scanf("%d",&n);
        addnewnodefront(n);
        goto start;
    }
    else if(choice==2)
    {
        printf("\nType the value you want to add:\n");
        scanf("%d",&n);
        addnewnodeback(n);
        goto start;
    }
    else if(choice==3)
    {
        printnodefront();
        goto start;
    }
    else if(choice==4)
    {
        printnodereverse();
        goto start;
    }
    else
    {
        printf("\nInvalid Option! Please choose one from below -_-\n");
        goto start;
    }
    return 0;
}
