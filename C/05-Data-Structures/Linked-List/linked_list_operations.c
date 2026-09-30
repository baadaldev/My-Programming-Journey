#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

void traverse(node *head, int VALUE)
{
    while(head->VALUE != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    node *head, *second, *third, *newNode, *temp;

    // Memory Allocation
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    // Data Assign
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Linking
    head->next = second;
    second->next = third;
    third->next = NULL;

    // New Node
    newNode = (node*)malloc(sizeof(node));

    newNode->data = 40;
    newNode->next = NULL;

    // Insert at Last
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    // Print List
    traverse(head);

    return 0;
}
