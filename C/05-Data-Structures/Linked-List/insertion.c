#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};
typedef struct node node;
node *head = NULL;
void insertBegin(int value){
node *newnode = (node*)malloc(sizeof(node));
newnode->data = value;
newnode-> next = head;
head =newnode;
}
void insertEnd(int value){
node *newnode = (node*)malloc(sizeof(node));
newnode->data = value;
newnode->next =NULL;
if (head==NULL){ //linkedlist empty
  head = newnode;
  return;
}
node *temp = head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next = newnode;
}

void afterInsertion(int key, int value){
if(head==NULL){ //linkedlist empty
    printf("Linked list empty\n");
    return;
}
node *newnode = (node*)malloc(sizeof(node));
newnode->data= value;
newnode->next = NULL;
node *temp = head;
while(temp!=NULL){
    if(temp->data==key){
        newnode->next=temp->next;
        temp->next =newnode;
        return;
    }
    else{
        temp = temp->next;
    }
}
printf("Node does not exist\n");
}

void beforeInsertion(int key, int value){
if(head==NULL){ //linkedlist empty
    printf("Linked list empty\n");
    return;
}
node *newnode = (node*)malloc(sizeof(node));
newnode->data= value;
newnode->next = NULL;
if(head->data == key){ // insert begin??
    newnode->next = head;
    head=newnode;
    return;
}
node *temp = head;
while(temp->next!=NULL){
    if(temp->next->data==key){
        newnode->next=temp->next;
        temp->next =newnode;
        return;
    }
    else{
        temp = temp->next;
    }
}
printf("Node does not exist\n");
}

void positionalInsertion(int pos, int value){
if(head==NULL && pos!=1){ //linkedlist empty
    printf("Linked list empty and cant performinsertion\n");
    return;
}
if(pos<=0){
    printf("invalid position\n");
    return;
}
node *newnode = (node*)malloc(sizeof(node));
newnode->data= value;
newnode->next = NULL;
if(pos==1){ //insert begin
    newnode->next = head;
    head=newnode;
    return;
}
node *temp = head;
int index =1;
while(temp!=NULL){
    if(index ==pos-1 ){
        newnode->next=temp->next;
        temp->next =newnode;
        return;
    }
    else{
        temp = temp->next;
        index++;
    }
}
printf("position not exist\n");
}

void display(){
node *temp = head;
while(temp!=NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
}}
int main(){
insertBegin(50);
insertBegin(32);
insertBegin(22);
insertEnd(85);
afterInsertion(85, 100);
beforeInsertion(100,96);
positionalInsertion(3,80);
display();
}
