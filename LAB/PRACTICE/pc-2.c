#include<stdio.h>
struct priority
{
    int data;
    int p;
};
struct priority arr[10];
int size=0;
void insertion(int data,int p)
{ int i;
    for( i=size-1;i>=0;i--)
    {
        if(p<arr[i].p)
        {
            arr[i+1]=arr[i];
        }
        else{
            break;
        }
    }
    arr[i+1].data=data;
    arr[i+1].p=p;
    size++;

}
void delete(int data,int p)
{
    int i;
    printf("elemets left are:\n");
    for(i=0;i<size-1;i++)
    {
        arr[i]=arr[i+1];

    }
    arr[i+1].data=data;
    arr[i+1].p=p;
    size--;

}
void display()
{
    for(int i=0;i<size;i++)
    {
        printf("%d  ",arr[i].data);
        printf("%d  ",arr[i].p);
        printf("\n");
    }
}
void main()
{
    insertion(21,1);
    insertion(20,2);
    insertion(30,3);
    insertion(40,1);
    insertion(50,3);
    display();
    delete(21,1);
    display();
}