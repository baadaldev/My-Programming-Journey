#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
  node* createNode(int value)
   node *newnode=(node*)malloc(sizeof(node);
   newnode->data=value;
   ne->left=NULL;
   node->right=NULL;
