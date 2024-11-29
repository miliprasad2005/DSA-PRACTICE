#include<stdio.h>
#define max 10
int arr[max]={34,68,42,90,53,46,34,79,46,58};
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
    int i,sum;
    sum=arr[max-1]+arr[max-2];
    for(i=0;i<max;i++)
    {
        printf("%d ",arr[i]);
        
    }
    printf("\nsum of %d and %d is = %d ",arr[max-1],arr[max-2],sum);
}
void main()
{
    insertion_sort();
    display();
}