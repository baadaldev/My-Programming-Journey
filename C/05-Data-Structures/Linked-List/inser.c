#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
typedef struct Node Node;
Node *head = NULL;
int main(){
int size, value;
scanf("%d", &size);
Node *temp = NULL;
for (int i=0;i<size;i++){
Node *newnode = (Node*)malloc(sizeof(Node));
printf("Provide value for this node\n");
scanf("%d",&value);
newnode->data=value;
newnode->next = NULL;
//first case: Linked list didn't exist/first node
if(head==NULL){
    head=newnode;
    temp=head;
} //case two: Linked list existes
else{
    temp->next=newnode;
    temp=newnode;
}}

Node *ptr=head;


while (ptr!=NULL){
    printf ("%d \n", ptr->data);
    ptr=ptr->next;
}
//clear memory
ptr = head;
while (ptr != NULL) {
        Node *nextNode = ptr->next;
        free(ptr);
        ptr = nextNode;
    }
    head = NULL;


}

