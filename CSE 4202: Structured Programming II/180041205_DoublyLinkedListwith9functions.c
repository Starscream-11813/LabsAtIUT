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
node current;
node prev;
node tail;
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
    notun->previous=NULL;
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
    notun->previous=temp;
    notun->next=NULL;
    tail=notun;
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
        prev->next=current->next;
        current->next->previous=prev;
        //prev->previous=prev->previous->previous;
        free(current);
        printf("\n%d has been deleted\n",data);
    }
    else
    {
        printf("\n%d doesn't exist in the list!\n",data);
    }
}
void insert_nodeafter(int value, int after)
{
    node newptr=(node)malloc(sizeof(node));
    current=head;
    /*while(current->data!=after && current->next!=NULL)
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
        newptr->previous=current;
        newptr->data=value;
        current->next=newptr;
        printf("\n%d has been placed after %d successfully\n",value,after);
    }*/
    if(head==NULL)
    {
        printf("\nList is Empty!\n");
    }
    else if(current->data==after)
    {
        newptr->data=value;
        newptr->next=current->next;
        current->next=newptr;
        newptr->previous=current;
        current->previous=NULL;
        printf("\n%d has been placed after %d successfully\n",value,after);
    }
    else
    {
        int counter=0;
        while(current!=NULL)
        {
            if(current->next==NULL)
            {
                addnewnodeback(value);
                printf("\n%d has been placed after %d successfully\n",value,after);
                return;
            }
            else
            {
                if(current->data==after)
                {
                    newptr->data=value;
                    newptr->next=current->next;
                    (current->next)->previous=newptr;
                    current->next=newptr;
                    newptr->previous=current;
                    counter++;
                    printf("\n%d has been placed after %d successfully\n",value,after);
                    break;
                }
                current=current->next;
            }
        }
        if(counter==0)
        {
            printf("\nValue not found!~\n");
        }
    }
}
void insert_nodebefore(int value, int before)
{
    node newptr=(node)malloc(sizeof(node));
    current=head;
    /*while(current->data!=before && current->previous!=NULL)
    {
        current=current->previous;
    }
    if(current->data!=before)
    {
        printf("\nElement Not Found!\n");
    }
    else
    {
        newptr->previous=current->previous;
        newptr->next=current;
        //current->previous=newptr;
        newptr->data=value;
        current->previous=newptr;
        printf("\n%d has been placed before %d successfully\n",value,before);
    */
    if(head==NULL)
    {
        printf("\nList Empty!\n");
    }
    else if(current->data==before)
    {
        newptr->data=value;
        newptr->next=current;
        current->previous=newptr;
        newptr->previous=NULL;
        head=newptr;
        printf("\n%d has been placed before %d successfully\n",value,before);
    }
    else
    {
        int counter=0;
        while(current!=NULL)
        {
            if(current->data==before)
            {
                newptr->data=value;
                newptr->next=current;
                newptr->previous=current->previous;
                (current->previous)->next=newptr;
                current->previous=newptr;
                counter++;
                printf("\n%d has been placed before %d successfully\n",value,before);
                break;
            }
            current=current->next;
        }
        if(counter==0)
        {
            printf("\nValue not found!~\n");
        }
    }
}
int main()
{
    head=NULL;
    tail=NULL;
    int n,choice,old,neww,data,after,before;
    printf("This is the interface for Doubly Linked List Data Structure\n");
start:
    printf("\nYour options are:\n");
    printf("\n0- Exit the Interface\n1- Add Node From Head (LEFT)\n2- Add Node From Tail (RIGHT)\n3- Print the nodes of the Linked List From Front (LEFT TO RIGHT)\n4- Print the nodes of the Linked List From Tail (RIGHT TO LEFT)\n5- Update the value of a Node\n6- Delete a Node\n7- Insert a Node in FRONT of another Node\n8- Insert a Node BEHIND another Node\n");
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
    else if(choice==5)
    {
        printf("\nThe data you wanna replace?\n");
        scanf("%d",&old);
        printf("\nThe data you want to replace with?\n");
        scanf("%d",&neww);
        update_data(old,neww);
        goto start;
    }
    else if(choice==6)
    {
        printf("\nWhich data do you wanna delete?\n");
        scanf("%d",&data);
        delete_node(data);
        goto start;
    }
    else if(choice==7)
    {
        printf("\nAfter which item do you wanna insert the node?\n");
        scanf("%d",&after);
        printf("\nWhich value do you wanna insert?\n");
        scanf("%d",&data);
        insert_nodeafter(data,after);
        //insert_node(after,data);
        goto start;
    }
    else if(choice==8)
    {
        printf("\nBefore which item do you wanna insert the node?\n");
        scanf("%d",&before);
        printf("\nWhich value do you wanna insert?\n");
        scanf("%d",&data);
        insert_nodebefore(data,before);
        goto start;
    }
    else
    {
        printf("\nInvalid Option! Please choose one from below -_-\n");
        goto start;
    }
    return 0;
}

