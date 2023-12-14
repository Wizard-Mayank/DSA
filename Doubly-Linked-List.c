#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

bool isEmpty(struct Node *head)
{
    if (head == NULL)
        return true;
    else
        return false;
}

void insertFront(struct Node *head, int data)
{

    if (!(isEmpty(head)))
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));

        new->data = data;
        new->prev = NULL;
        new->next = head;
        head->prev = new;

        head = new;

        return;
    }

    head = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = data;
    head->next = NULL;
}

bool insertAfter(struct Node *head, int data, int key)
{
    struct Node *temp = head;
    struct Node *new = NULL;
    bool res = false;

    while(temp->next!=NULL)
    {
        if (temp->data == key)
        {
        }
    }
}

void insertRear(struct Node *head, int data)
{
    if (isEmpty(head))
    {
        head = (struct Node *)malloc(sizeof(struct Node));

        head->prev = NULL;
        head->data = data;
        head->next = NULL;

        return;
    }

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    new->data = data;
    new->prev = temp;
    temp->next = new;
    new->next = NULL;
}

int deleteFront(struct Node *head)
{
    struct Node *new = head;
    int value = head->data;

    head = head->next;
    free(new);
    return value;
}

bool deleteMid(struct Node* head, int key)
{
    struct Node *temp = head;
    bool res = false;

    while(temp->next != NULL)
    {
        if (temp->data == key)
        {
            struct Node *del = temp;
            temp->prev->next = temp->next;
            free(del);
            res = true;
        }

        temp = temp->next;
    }

    return res;
}

int deleteRear(struct Node *head)
{
    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    int value = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return value;
}

int main()
{

    // printf("Hello World!");

    return 0;
}