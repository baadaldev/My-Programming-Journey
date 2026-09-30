#include<stdio.h>
#include<stdlib.h>

struct node {
int data ;
struct node *next;
};
typedef struct node node ;
node *next=NULL;

int main (){

int size, value ;
scanf("%d",size);
node *temp =NULL;
printf ("Enter size of node:");

for (int i ; i<size ; i++){
    node *newnode=(node*)malloc (sizeof(node));
    printf("value for this node\n");
    scanf("%d",value);
    newnode ->data=value;
    newnode->next=NULL;
}
}

