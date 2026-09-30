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
    newnode->next = head;
    head = newnode;
}

void display(){
    node *temp = head;

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){

    insertBegin(50);
    insertBegin(30);
    insertBegin(10);

    display();

    return 0;
}
