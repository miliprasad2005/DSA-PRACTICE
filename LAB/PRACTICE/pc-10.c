#include<stdio.h>
#define max 5
int arr[max]={23,78,13,89,32};
void selection_sort()
{
    int i,j,min;
    for(i=0;i<max-1;i++)
    {
        min=i;
        for(j=i+1;j<max;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
}
void bubble_sort()
{
    int i,j,temp,flag=0;
    for(i=0;i<max-1;i++)
    {
        for(j=0;j<max-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}
void insertion_sort()
{
    int i,j,temp;
    for(i=0;i<max;i++)
    { 
       temp=arr[i];
       j=i-1;
       while (j>=0&&temp<arr[j])
       { 
         arr[j+1]=arr[j]; 
         j--;
       }
       arr[j+1]=temp;
       
    }
}
void display()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    selection_sort();
    bubble_sort();
   insertion_sort();
    display();
}