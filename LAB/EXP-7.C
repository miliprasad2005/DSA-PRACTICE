#include<stdio.h>
#include<stdlib.h>
#define max 2
struct node
{
    int appointment_status;
    char name[30];
    int id;
};
int linear_search(struct node *p[],int id)
{
    int i;
    for(i=0;i<max;i++)
    {
       if(p[i]->id==id)
       {
         return i;
       }
    }
    return -1;
}
int binary_search(struct node *p[],int id)
{
    int mid,i,left=0,right=max-1;
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(p[mid]->id==id){
            return mid;
        }
        else if(p[mid]->id<id)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;

}
int appointment_status(struct node *p)
{
     p->appointment_status=!p->appointment_status;
    return p->appointment_status;
}

void display(struct node *p)
{
    int i;  
    printf("\npatient id %d",p->id);
    printf("\npatient name %s",p->name);
    printf("\nappointment_status %s",p->appointment_status?"booked":"not booked") ;

}
void tdisplay(struct node *p)
{
    int neww = appointment_status(p);
    printf("satatus :%s",neww?"booked":"not booked");
    display(p);
}
void main()
{
    int id=1001;
    char name[30];
    struct node *p[max];
    for(int i=0;i<max;i++)
    {
       printf("enter patient details for  %d:\n",id);
       p[i]=(struct node*)malloc(sizeof(struct node));
       scanf("%s",p[i]->name);
       p[i]->id=id++;
       p[i]->appointment_status=0;
    }
    int search;
    printf("enter the patient id you want to search:");
    scanf("%d",&search);
    int result=linear_search(p,search);
    if(result==-1)
    {
        printf("patient not found");
    }
    else{
        printf("patient found");
        display(p[result]);
         tdisplay(p[result]);
    }
    int se;
    printf("enter id:");
    scanf("%d",&se);
    int res=binary_search(p,se);
    if(res!=-1)
    {
        printf("patient found\n");
        display(p[res]);
         tdisplay(p[res]);
    }
    else{
        printf("patient not found");
    }

}