#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coff;
    int exp;
    struct node *next;
};
struct node *createheader()
{
    struct node *header=(struct node*)malloc(sizeof(struct node));
    if(!header)
    {
        printf("memory not allocated");
        exit(1);
    }
    header->coff=0;
    header->exp=-1;
    header->next=NULL;
    return header;
}
void insert(struct node *header,int coff,int exp)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode)
    {
        printf("memory not allocated");
        exit(1);
    }
    newnode->coff=coff;
    newnode->exp=exp;
    newnode->next=NULL;
    struct node *temp= header;
    while(temp->next!=NULL && temp->next->exp>exp)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void display(struct node *result)
{
    struct node *temp=result->next;
    while (temp!=NULL)
    {
       printf("%dx^%d  ",temp->coff,temp->exp);
       temp=temp->next;
    }
    
}
void addpolynomial(struct node *p1,struct node *p2)
{
    struct node *temp1=p1->next;
    struct node *temp2=p2->next;
    struct node *result = createheader();
    while(temp1!=NULL&&temp2!=NULL){
    if(temp1->exp >temp2->exp)
    {
        insert(result,temp1->coff,temp1->exp);
        temp1=temp1->next;
    }
    else if(temp2->exp>temp1->exp)
    {
        insert(result,temp2->coff,temp2->exp);
        temp2=temp2->next;
    }
    else{
        int sum=temp1->coff+temp2->coff;
        if(sum!=0){
        insert(result,sum,temp1->exp);
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }}
    while (temp1!=NULL)
    {
       insert(result,temp1->coff,temp1->exp);
       temp1=temp1->next;
    }
    while (temp2!=NULL)
    {
        insert(result,temp2->coff,temp2->exp);
        temp2=temp2->next;
    }
    printf("result\n");
    display(result);
    
    
}
void main()
{
    struct node *p1=createheader();
    struct node *p2=createheader();
    printf("polynomial 1:\n");
    insert(p1,20,3);
    insert(p1,30,2);
    insert(p1,40,1);
    insert(p1,50,0);
    printf("polynomial 2:\n");
    insert(p2,50,3);
    insert(p2,60,2);
    insert(p2,70,1);
    
    addpolynomial(p1,p2);
    
}