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

// Delete Only Leaf Node
node* deleteLeaf(node *root, int value)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(value < root->data)
    {
        root->left = deleteLeaf(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = deleteLeaf(root->right, value);
    }
    else
    {
        // Leaf Node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else
        {
            printf("\n%d is not a Leaf Node!\n", value);
        }
    }

    return root;
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

    printf("Before Deletion (Inorder): ");
    inorder(root);

    printf("\n\n");

    root = deleteLeaf(root,6);

    printf("After Deletion (Inorder): ");
    inorder(root);

    return 0;
}
