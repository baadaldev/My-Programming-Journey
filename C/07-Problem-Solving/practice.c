#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
 typedef struct node node;
 node* createNode(int value){
 node *newnode=(node*)malloc(sizeof(node));
 newnode->data=value;
 newnode->left=NULL;
 newnode->right=NULL;
     return newnode;
 }

 node* insert(node *root, int value){
     if(root==NULL){
        return createNode(value);
     }
  if(value<root->data){

    root->left=insert(root->left,value);

  }
  else if (value>root->data){

    root->right=insert(root->right,value);
  }

 return root;
 }
 void inorder(node *root){

 if (root!=NULL){

    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);


 }

 }
 int main(){

node *root=NULL;
root=insert(root,50);
root=insert(root,40);
root=insert(root,90);
root=insert(root,70);
root=insert(root,20);
root=insert(root,10);
root=insert(root,80);
printf("Inorder Insertion :");
inorder(root);
return 0;

 }
