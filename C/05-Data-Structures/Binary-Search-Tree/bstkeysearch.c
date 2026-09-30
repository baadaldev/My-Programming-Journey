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

// Inorder Traversal
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Search Function
node* search(node *root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    node *root = NULL;

    root = insert(root,39);
    root = insert(root,3);
    root = insert(root,9);
    root = insert(root,89);
    root = insert(root,66);
    root = insert(root,6);
    root = insert(root,36);
    root = insert(root,78);

    printf("Inorder : ");
    inorder(root);

    int key;

    printf("\n\nEnter Search Key : ");
    scanf("%d",&key);

    node *result = search(root,key);

    if(result == NULL)
    {
        printf("Key Not Found.");
    }
    else
    {
        printf("Key Found : %d", result->data);
    }

    return 0;
}
