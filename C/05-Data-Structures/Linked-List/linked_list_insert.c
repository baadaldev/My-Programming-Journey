#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

void traverse(node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    node *head, *second, *third, *fourth;
    node *newNode, *temp;

    // Memory Allocation
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));

    // Data Assign
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    // Linking
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // New Node
    newNode = (node*)malloc(sizeof(node));

    newNode->data = 25;

    // Find node before 30
    temp = head;

    while(temp->next != NULL && temp->next->data != 30)
    {
        temp = temp->next;
    }

    // Check if 30 exists
    if(temp->next == NULL)
    {
        printf("Value Not Found");
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;

        printf("After Insertion:\n");
        traverse(head);
    }

    return 0;
}
