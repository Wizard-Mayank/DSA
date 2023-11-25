#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

bool isEmpty(struct Node **head)
{
    return *head == NULL;
}

void insert_atEnd(struct Node **head, int data)
{
    struct Node *temp = *head;

    if (*head == NULL)
    {
        *head = (struct Node *)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    temp->next = new_node;
}

void insert_rear(struct Node **head, int data)
{
    if (isEmpty(head))
    {
        *head = (struct Node *)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        insert_atEnd(head, data);
    }
}

void insert_atFront(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

bool insert_before(struct Node **head, int data, int key)
{
    if (isEmpty(head))
        return false;

    struct Node *p = *head;
    struct Node *q = NULL;

    while (p != NULL && p->data != key)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
        return false;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    if (q == NULL)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        temp->next = p;
        q->next = temp;
    }

    return true;
}

int delete_first(struct Node **head)
{
    if (isEmpty(head))
        return -1;

    int data = (*head)->data;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);

    return data;
}

int delete_last(struct Node **head)
{
    if (isEmpty(head))
        return -1;

    struct Node *p = *head;
    struct Node *q = NULL;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    int data = p->data;

    if (q == NULL)
        *head = NULL;
    else
        q->next = NULL;

    free(p);

    return data;
}

bool delete_node(struct Node **head, int data)
{
    if (isEmpty(head))
        return false;

    struct Node *p = *head;
    struct Node *q = NULL;

    while (p != NULL && p->data != data)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
        return false;

    if (q == NULL)
        *head = p->next;
    else
        q->next = p->next;

    free(p);
    return true;
}

void traverseList(struct Node **head)
{
    if (isEmpty(head))
    {
        printf("\n\nList is EMPTY!");
        return;
    }

    struct Node *temp = *head;

    printf("\n\nList: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void showMenu()
{
    printf("\n\n1. Show List\n2. Insert a value at last position\n3. Insert a value at first position\n4. Insert before a specific value\n5. Delete first value\n6. Delete last value\n7. Delete any specific value in between the list\n8. Exit");
}

int main()
{
    char cont;

    do
    {
    A:

        if (cont == 'n')
            break;

    B:

        showMenu();

        int ch, value, key;
        bool result;

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            traverseList(&head);
            break;
        case 2:
            printf("\n\nEnter a value you want to insert at last: ");
            scanf("%d", &value);

            insert_rear(&head, value);
            break;
        case 3:
            printf("\n\nEnter a value you want to insert at front: ");
            scanf("%d", &value);

            insert_atFront(&head, value);
            break;
        case 4:
            printf("\n\nEnter a value you want to insert: ");
            scanf("%d", &value);

            printf("Enter the value before which you want to insert this value: ");
            scanf("%d", &key);

            result = insert_before(&head, value, key);

            if (result == true)
                printf("\n\nValue has been added successfully.");
            else
                printf("\n\nFAILED!!!");
            break;
        case 5:
            if (isEmpty(&head))
                printf("\n\nCan't delete because list is already EMPTY!");

            else
            {
                value = delete_first(&head);

                printf("Deleted value: %d", value);
            }
            break;
        case 6:
            if (isEmpty(&head))
                printf("\n\nCan't delete because list is already EMPTY!");

            else
            {
                value = delete_last(&head);

                printf("Deleted value: %d", value);
            }
            break;
        case 7:
            if (isEmpty(&head))
                printf("\n\nCan't delete because list is already EMPTY!");

            else
            {
                printf("Enter the value which you want to delete: ");
                scanf("%d", &key);

                bool result = delete_node(&head, key);

                if (result == true)
                    printf("\n\nValue has been deleted successfully.");
                else
                    printf("\n\nValue not found!");
            }
            break;
        case 8:
            printf("\n\nThank You! :)");
            cont = 'n';

            goto A;
            break;
        default:
            printf("\n\nWrong Choice! Try again...");
            goto B;
        }

    C:

        printf("\n\nDo you want to continue? (y/n) -> ");
        fflush(stdin);
        scanf("%c", &cont);

        if (cont == 'n')
            printf("Thank You! See you later :)");

        else if (cont != 'y' && cont != 'n')
        {
            printf("Sorry! I didn't understand! Enter again...\n");
            goto C;
        }
    } while (cont == 'y');

    return 0;
}
