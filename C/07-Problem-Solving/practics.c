#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

// Create Node
node* createNode(int value)
{
    node *newnode = (node*)malloc(sizeof(node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Insert Node
node* insert(node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Descending Order (Reverse Inorder)
void descending(node *root)
{
    if(root != NULL)
    {
        descending(root->right);
        printf("%d ", root->data);
        descending(root->left);
    }
}

// Height Function
int height(node *root)
{
    if(root == NULL)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}
int main(){

node *root=NULL;
int n,value;
printf("Enter the node :");
scanf("%d",&n);

printf("Enter the %d value",n);

for(int i=0;i<=n;i++){

    scanf("%d",&value);
    root=insert(root,value);

}
printf("Descending order;");
descending(root);
printf("\nHeight of BST = %d",height(root));

return 0;



}
