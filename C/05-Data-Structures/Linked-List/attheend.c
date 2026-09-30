#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *head=NULL;

void insertEnd(int value){

    node *newnode=(node*)malloc(sizeof(node));

    newnode->data=value;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        return;
    }

    node *temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
}

void display(){

    node *temp=head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    return 0;
}
