#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory not allocated");
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
int search(struct node *root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(data==root->data)
    {
        printf("element %d found\n",data);
        return 1;
    }
    else if(data<root->data)
    {
       return search(root->left,data);
    }
    else if(data>root->data)
    {
        return search(root->right,data);
    }

}
int main()
{
    struct node *root;
    if(root==NULL)
    {
        printf("memory not allocated\n");
        return 0;
    }
    root=insert(root,20);
    insert(root,30);
    insert(root,40);
    insert(root,50);
    insert(root,60);
    insert(root,80);
    if(search(root,30))
    {
        printf("successfull\n");
    }
    else{
        printf("unsuccessfull\n");
    }
}