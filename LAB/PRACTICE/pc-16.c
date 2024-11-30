#include<stdio.h>
#define max 3
#define word 9999999
int arr[max][max];
void create()
{
    int i,j;
    printf("enter weights:");
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
int minimum(int weight[],int visited[])
{
    int i,j,min=word,min_index=-1;
    for(i=0;i<max;i++)
    {
        
        if(visited[i]==0&&weight[i]<min)
        {
            min=weight[i];
            min_index=i;
            
        }
        
    }
    return min_index;
}
void display(int parent[])
{
    int i,j;
    printf("edges \t weight \n");
    for(i=1;i<max;i++)
    {
        
        
            printf("%d - %d \t %d\n ",parent[i],i,arr[i][parent[i]]);
        
    }
}
void mst(int source)
{
    int visited[max]={0},parent[max],weight[max],i,j;
    for(i=0;i<max;i++)
    {
        parent[i]=-1;
        weight[i]=word;
    }
    weight[source]=0;
    for(i=0;i<max;i++)
    {
        int mini=minimum(weight,visited);
        visited[i]=1;
        for(j=0;j<max;j++)
        {
            if(visited[j]==0&&arr[mini][j]<weight[j])
            {
                weight[j]=arr[mini][j];
                parent[j]=mini;
            }

        }
    }
    display(parent);
}
void main()
{
    int source;
    printf("enter source:");
    scanf("%d",&source);
    create();
    mst(source);
}