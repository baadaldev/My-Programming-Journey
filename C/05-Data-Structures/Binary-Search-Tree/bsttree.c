#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

// Insert Function
node *insert(node *root, int value)
{
    if (root == NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));

        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }

    return root;
}

// Inorder (Left -> Root -> Right)
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder (Root -> Left -> Right)
void preorder(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder (Left -> Right -> Root)
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 30);
    root = insert(root, 25);

    printf("Postorder: ");
    postorder(root);

    printf("\n");

    printf("Inorder: ");
    inorder(root);

    printf("\n");

    printf("Preorder: ");
    preorder(root);

    printf("\n");

    return 0;
}

