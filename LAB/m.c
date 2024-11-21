#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data);
struct node *insert(struct node *root,int data);
int search(struct node *root,int data);
struct node *create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
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
    if(data<root->data)
    {
        root->left=insert(root->left,data);

    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;

}
int search(struct node * root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data==data)
    {
        printf("element found successfully");
        return 1;
    }
    if(data < root->data)
    {
        return search(root->left,data);
    }
    else if(data>root->data)
    {
        return search(root->right,data);
    }

}


int main() {
    struct node *root = NULL;  // Start with an empty BST

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    
    // Search for a value
    int value = 40;
    if (search(root, value)) {
        printf("Node with value %d found in the BST.\n", value);
    } else {
        printf("Node with value %d not found in the BST.\n", value);
    }

    return 0;
}