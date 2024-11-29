#include<stdio.h>
#define max 2
int arr[max][max]={0};
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
void BFS(int source)
{
    int front=-1,rear=-1,i,j;
    int queue[max],visited[max]={0};
    queue[++rear]=source;
    visited[source]=1;
    while (front<rear)
    {
        queue[++rear]=i;
        visited[i]=1;
        for (int  i = 0; i < max; i++)
        {
            int curr= queue[++front];
            if(arr[curr][i]==1&&visited[i]!=1)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
        
    }
    
    
}
void display()
{
    int i,j;
    printf("matrix is:\n");
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    create();
    BFS(3);
    display();
}