#include<stdio.h>
#define max 17
#define k 9
int arr[max];
int b[max];
int count[k+1];
void create()
{
    int i;
    printf("enter elements:");
    for(i=0;i<max;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void countersort()
{
    int i;
    for(i=0;i<=k;i++)
    {
        count[i]=0;
    }
    for(i=0;i<max;i++)
    {
        ++count[arr[i]];
    }
    for(i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=max-1;i>=0;i--)
    {
       b[--count[arr[i]]]=arr[i];
    }
    for(i=0;i<max;i++)
    {
        arr[i]=b[i];
    }
}
void display()
{
    int i;
    printf("elements are:\n");
    for(i=0;i<max;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    create();
    display();
    countersort();
    printf("\nsorted :\n");
    display();
}