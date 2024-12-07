#include<stdio.h>
#define max 10
#define k 10
int arr[max];
int count[k];
int b[max];
void create()
{
    int i;
    printf("enter elements:\n");
    for(i=0;i<max;i++)
    {
        scanf("%d",&arr[i]);
    }
}
int maximum()
{
    int i,maxe=arr[0];
    for(i=1;i<max;i++)
    {
        if(arr[i]>maxe)
        {
            maxe=arr[i];
        }
    }
    return maxe;
}
void counter_sort(int pos)
{
    int i;
    for(i=1;i<=k;i++)
    {
        count[i]=0;
    }
    for(i=0;i<max;i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    for(i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=max-1;i>=0;i--)
    {
      b[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(i=0;i<max;i++)
    {
        arr[i]=b[i];
    }
}
void radix()
{
    int pos,i;
    int ele=maximum();
    for(pos=1;ele/pos>0;pos*=10)
    {
      counter_sort(pos);
    }
}
void display()
{
    int i;
    printf("elements are:\n");
    for(i=0;i<max;i++)
    {
        printf("%d ",arr[i]);
    }
}
void main()
{
    create();
    display();
    radix();
    printf("\nsorted:\n");
    display();
}