#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

};

  typedef struct node node;
  node* createnode(int value){

  node *newnode=(node*)malloc(sizeof(node));
  newnode->data=value;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;

  }

 node* insert(node *root, int value){
  if (root==NULL)
  {
      return createnode(value);
  }
  if (value<root->data){

    root->left=insert(root->left,value);
  }
  else if(value>root->data){
    root->right=insert(root->right,value);
  }

  return root;

  };

  void postorder(node *root){
  if(root!=NULL){

  printf("%d ",root->data);


  postorder(root->right);
   postorder(root->left);
  }


  }
  int main(){

  node *root=NULL;
  root=insert(root,39);
  root=insert(root,3);
  root=insert(root,9);
  root=insert(root,89);
  root=insert(root,66);
  root=insert(root,6);
  root=insert(root,36);
  root=insert(root,78);
  printf("Insert:");
  postorder(root);
  return 0 ;


  }
