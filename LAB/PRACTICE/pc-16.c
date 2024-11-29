#include<stdio.h>
#define max 2
int arr[max][max];
void create()
{
    int i,j,temp;
    printf("enter values:");
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            scanf("%d",&temp);
            arr[i][j]=temp;
        }
    }
}
void display()
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}