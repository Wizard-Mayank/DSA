#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void push(node **head, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (*head != NULL)
    {
        node *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
    else
    {
        *head = new;
    }
}

node *iterReverse(node *head)
{
    node *prev = NULL, *next = NULL, *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

node *recReverse(node *curr, node **head)
{
    if (curr == NULL)
        return NULL;

    if (curr->next == NULL)
    {
        *head = curr;
        return curr;
    }

    node *rev = recReverse(curr->next, head);
    rev->next = curr;
    curr->next = NULL;

    return curr;
}

void traverse(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("List entered: ");
    traverse(head);

    head = iterReverse(head);
    printf("\nReversed list using iteration: ");
    traverse(head);

    head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    recReverse(head, &head);
    printf("\nReversed list using recursion: ");
    traverse(head);

    return 0;
}
