#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int p;
    struct node *next;
};
struct node *head=NULL,*temp;
void insertion(int data,int p)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->p=p;
    newnode->next=NULL;
    if(head==NULL||head->p>p)
    {
        newnode->next=head;
        head=newnode;

    }
    else{
        temp=head;
        while (temp->next!=NULL&&temp->next->p<p)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        
    }
}
void delete()
{
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else{
        temp=head;
        printf("%d  %d is deleted\n",head->data,head->p);
        head=head->next;
        free(temp);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else{
        temp=head;
        printf("elements are:\n");
        while (temp!=NULL)
        {
           printf("%d  %d\n",temp->data,temp->p);
           temp=temp->next;
        }
        
    }
}
void main()
{
    insertion(20,1);
    insertion(30,2);
    insertion(40,3);
    insertion(50,1);
    insertion(60,2);
    display();
    delete();
    display();
}