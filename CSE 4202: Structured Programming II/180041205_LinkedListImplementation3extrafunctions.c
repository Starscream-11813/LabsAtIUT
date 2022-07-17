#include<stdio.h>
#include<stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;
node head;
node current;
node prev;
//node prevnode;
//node newnode;
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
    printf("\nThe elements in the list right now:\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void update_data(int old, int neww)
{
    int position=0;
    if(head==NULL)
    {
        printf("\nThe List doesn't exist!\n");
        return;
    }
    current=head;
    while(current!=NULL)
    {
        if(current->data==old)
        {
            current->data=neww;
            if(position==0)
            {
                printf("\n%d at %dst position has been replaced with %d\n",old,position+1,neww);
            }
            else if(position==1)
            {
                printf("\n%d at %dnd position has been replaced with %d\n",old,position+1,neww);
            }
            else if(position==2)
            {
                printf("\n%d at %drd position has been replaced with %d\n",old,position+1,neww);
            }
            else
            {
                printf("\n%d at %dth position has been replaced with %d\n",old,position+1,neww);
            }
            return;
        }
        current=current->next;
        position++;
    }
    printf("\n%d doesn't exist here!\n",old);
}
void delete_node(int data)
{
    int pos=0;
    if(head==NULL)
    {
        printf("\nThe List doesn't exist!\n");
        return;
    }
    if(head->data==data)
    {
        if(head->next!=NULL)
        {
            head=head->next;
            return;
        }
        else
        {
            head=NULL;
            printf("\nList Emptied!\n");
            return;
        }
    }
    else if(head->data!=data && head->next==NULL)
    {
        printf("\n%d doesn't exist in the list!\n",data);
        return;
    }
    current=head;
    while(current->next!=NULL && current->data!=data)
    {
        prev=current;
        current=current->next;
    }
    if(current->data==data)
    {
        prev->next=prev->next->next;
        free(current);
        printf("\n%d has been deleted\n",data);
    }
    else
    {
        printf("\n%d doesn't exist in the list!\n",data);
    }
}
node insert_node(int value, int after)
{
    node newptr=(node)malloc(sizeof(node));
    current=head;
    while(current->data!=after && current->next!=NULL)
    {
        current=current->next;
    }
    if(current->data!=after)
    {
        printf("\nElement Not Found!\n");
    }
    else
    {
        newptr->next=current->next;
        newptr->data=value;
        current->next=newptr;
        printf("\n%d has been placed after %d successfully\n",value,after);
    }
}
int main()
{
    int x,n,choice,old,neww,data,after;
    //node head;
    head=NULL;
    printf("This is the interface for Linked List Data Structure\n");
start:
    printf("\nYour options are:\n");
    printf("\n0- Exit the Interface\n1- Add Node\n2- Print the nodes of the Linked List\n3- Update a value of a Node\n4- Delete a node\n5- Insert a node\n");
    scanf("%d",&choice);
    if(choice==0)
    {
        printf("\nInterface exited successfully!~\n");
        exit(0);
    }
    else if(choice==1)
    {
        //printf("How many nodes should the linked list have?\n");
        //scanf("%d",&n);
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
        printf("\nThe data you wanna replace?\n");
        scanf("%d",&old);
        printf("\nThe data you want to replace with?\n");
        scanf("%d",&neww);
        update_data(old,neww);
        goto start;
    }
    else if(choice==4)
    {
        printf("\nWhich data do you wanna delete?\n");
        scanf("%d",&data);
        delete_node(data);
        goto start;
    }
    else if(choice==5)
    {
        printf("\nAfter which item do you wanna insert the node?\n");
        scanf("%d",&after);
        printf("\nWhich value do you wanna insert?\n");
        scanf("%d",&data);
        insert_node(data,after);
        //insert_node(after,data);
        goto start;
    }
    else
    {
        printf("\nInvalid Option!\n");
        goto start;
    }
    return 0;
}
