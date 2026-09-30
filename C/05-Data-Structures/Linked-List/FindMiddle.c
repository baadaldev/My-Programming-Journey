#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;

};
struct node* createNode(int data){

struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=NULL;
   return newnode;


}
void display(struct node *head){
    struct node *temp=head;

    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
  printf("NULL\n");

}
void findMiddle(struct node *head){

if(head==NULL){
    printf("Linked list is empty\n");
    return ;
}
struct node *slow=head;
struct node *fast=head;

   while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
   }
   printf("Middle node is %d:\n",slow->data);
}
int main(){
struct node *head=NULL;
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
display(head);
findMiddle(head);
return 0;
}
