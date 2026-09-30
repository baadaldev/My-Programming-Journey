#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

// Insert at Last
void insertEnd(int value){

    node *newnode = (node*)malloc(sizeof(node));

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

// Display Function
void display(){

    node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){

    // আগে থেকেই List আছে
    insertEnd(23);
    insertEnd(34);
    insertEnd(45);

    // এখন 55 শেষে Insert হবে
    insertEnd(55);

    display();

    return 0;
}
