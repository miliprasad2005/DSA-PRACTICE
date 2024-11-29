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
void DFS(int source)
{
    int top=-1;
    int stack[max],visited[max]={0};
    stack[++top]=source;
    visited[source]=1;
    while (top!=-1)
    {
        int curr= stack[top--];
        for(int i=0;i<max;i++)
        {
            if(arr[curr][i]==1&&visited[i]!=1)
            {
            stack[++top]=i;
            visited[i]=1;
            }
        }      
    }
   printf("\n"); 


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
    DFS(1);
    display();

}