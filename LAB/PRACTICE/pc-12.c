#include<stdio.h>
#define max 4
int arr[max]={3,4,5,2};
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
    int i,mul;
    mul=(arr[max-1]-1)*(arr[max-2]-1);
    for(i=0;i<max;i++)
    {
        printf("%d ",arr[i]);
        
    }
    printf("\nmul of %d and %d is = %d ",arr[max-1],arr[max-2],mul);
}
int main()
{
    insertion_sort();
    display();
    return 0;
}