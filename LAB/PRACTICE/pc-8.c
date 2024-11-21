#include<stdio.h>
#define max 5
int arr[max]={34,89,12,98,13};


void merge(int lower,int high,int mid)
{
    int i=lower;
    int j=mid+1;
    int k=0;
    int new[high-lower+1];
    while (i<=mid&&j<=high)
    {
        if (arr[i]<=arr[j])
        {
           new[k]=arr[i];
           i++;k++;

        }
        else 
        {
            new[k]=arr[j];
            k++;j++;
        }
        
    }
    if(i>mid)
    {
        while (j<=high)
        {
           new[k]=arr[j];
           k++;j++;
        }
        
    }
    else{
        while (i<=mid)
        {
            new[k]=arr[i];
            k++;i++;
        }
        
    }
    for(i=lower,k=0;i<=high;k++,i++)
    {
        arr[i]=new[k];
    }

}
void merge_sort(int lower,int high)
{
    int mid;
    if(lower<high)
    {
       mid=(lower+high)/2;
       merge_sort(lower,mid);
       merge_sort(mid+1,high);
       merge(lower,high,mid);
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
    merge_sort(0,max-1);
    display();
}