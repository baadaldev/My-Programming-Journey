#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create Node
Node* createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert Node
Node* insert(Node *root, int value)
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
void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Delete Leaf Node
Node* deleteLeaf(Node *root, int value)
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
        // Delete only if it is a leaf node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
    }

    return root;
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Before Deletion:\n");
    inorder(root);

    root = deleteLeaf(root, 20);

    printf("\nAfter Deleting Leaf Node (20):\n");
    inorder(root);

    return 0;
}
