#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp;
void createnode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        return;
    }
        printf("enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else{
       temp->next=newnode;
       temp=newnode;
    }
    temp->next=head;
}
int cycle()
{
    
    if(head==NULL||head->next==NULL)
    {
        return 0;
    }
    else{
        
        {
         struct node *fast=head,*slow=head;
        while (fast!=NULL&&fast->next!=NULL)
           {
             slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return 1;
            }
            
        }
    }}
    return 0;
}
void display()
{
    temp=head;
    printf("elements are:");
    while (temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    
}
int main()
{
    int ch;
    while (ch)
    {
        createnode();
        printf("enter your choice(0/1):");
        scanf("%d",&ch);
    }
    
    display();
    if(cycle())
    {
        printf("\nIt cyclic");
    }
    else
    {
        printf(" \nIt is not cyclic\n");
    }
    
    return 0;
}