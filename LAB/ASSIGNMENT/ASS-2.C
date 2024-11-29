#include<stdio.h>
#define max 5
int arr[max]={23,89,35,36,84};
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
void minimum()
{
   int i,min=arr[0];
    for(i=0;i<max;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        
    }
   printf("minimum is: %d",min); 
}
void rotation(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=arr[0];
        for(j=0;j<max-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[max-1]=temp;
    }
}
void display()
{
    int i;
    for(i=0;i<max;i++)
    {
        printf("%d ",arr[i]);
    }
   
}
void main()
{
    printf("Original array:\n");
    display();

    insertion_sort();
    printf("\nSorted array:\n");
    display();

    minimum();

    int rotations = 3;
    rotation(rotations);
    printf("\nArray after %d rotations:\n", rotations);
    display();
}