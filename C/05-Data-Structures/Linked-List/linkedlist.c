#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void findMiddle(struct Node *head)
{
    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Node = %d\n", slow->data);
}

int main()
{
    struct Node *head = NULL;

    head = createNode(106);
    head->next = createNode(205);
    head->next->next = createNode(307);
    head->next->next->next = createNode(406);
    head->next->next->next->next = createNode(504);

    display(head);

    findMiddle(head);

    return 0;
}