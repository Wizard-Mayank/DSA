#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

bool isEmpty(node **head)
{
    if ((*head) == NULL)
        return true;
    else
        return false;
}

void insertFront(node **head, int data)
{
    if (isEmpty(head))
    {
        *head = (node *)malloc(sizeof(node));
        (*head)->data = data;
        (*head)->next = *head;
    }
    else
    {
        node *new = (node *)malloc(sizeof(node));
        new->data = data;
        new->next = *head;

        node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = new;
        *head = new;
    }
}

bool insertAfter(node **head, int data, int key)
{
    if ((*head)->next == *head)
    {
        if ((*head)->data == key)
        {
            node *new = (node *)malloc(sizeof(node));

            new->data = data;
            new->next = (*head)->next;
            (*head)->next = new;

            return true;
        }
    }

    else
    {
        node *temp = (node *)malloc(sizeof(node));

        node *new = (node *)malloc(sizeof(node));

        new->data = data;
        new->next = NULL;

        temp = *head;

        do
        {
            if (temp->data == key)
            {
                new->next = temp->next;
                temp->next = new;
                return true;
            }

            temp = temp->next;

        } while (temp != (*head));

        return false;
    }
}

void insertEnd(node **head, int data)
{
    if (isEmpty(head))
    {
        *head = (node *)malloc(sizeof(node));
        (*head)->data = data;
        (*head)->next = *head;
    }
    else
    {
        node *temp = *head;
        node *new = (node *)malloc(sizeof(node));

        new->data = data;
        new->next = *head;

        while (temp->next != *head)
            temp = temp->next;

        temp->next = new;
    }
}

int deleteFront(node **head)
{
    if ((*head)->next == *head)
    {
        int dt = (*head)->data;

        free(head);
        *head = NULL;
        return dt;
    }

    int data = (*head)->data;
    node *temp = *head;

    while (temp->next != *head)
        temp = temp->next;

    temp->next = (*head)->next;

    node *tempHead = *head;
    (*head) = (*head)->next;

    free(tempHead);

    return data;
}

int deleteRear(node **head)
{
    if ((*head)->next == *head)
    {
        int dt = (*head)->data;
        *head = NULL;
        return dt;
    }

    node *temp = *head;
    node *prev = NULL;

    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp->next != (*head));

    prev->next = (*head);

    int dt = temp->data;
    free(temp);

    return dt;
}

bool deleteMid(node **head, int key)
{
    node *temp = *head;

    if ((*head)->next == *head)
    {
        if ((*head)->data == key)
        {
            *head = NULL;
            return true;
        }

        else
            return false;
    }

    else
    {
        if ((*head)->data == key)
        {
            return deleteFront(head);
        }

        node *prev = NULL;

        do
        {
            if (temp->data == key)
            {
                prev->next = temp->next;
                return true;
            }

            prev = temp;
            temp = temp->next;
        } while (temp->next != (*head));
    }

    if (temp->data == key && temp->next == (*head))
    {
        return deleteRear(head);
        
    }

    return false;
}

void traverse(node **head)
{
    printf("\n\nList: ");

    if (isEmpty(head))
        printf("EMPTY!!");
    else
    {
        node *temp = *head;

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != (*head));
    }
}

void menu()
{
    printf("\n\n============================================ OPERATIONS MENU ============================================");
    printf("\n\n1. Show list\n2. Insert value at front\n3. Insert value after the key value\n4. Insert value at last\n5. Delete front value\n6. Delete a mid value\n7. Delete last value\n8. Exit");
}

void bye()
{
    printf("\n\n--------------------------------------------------- THANK YOU ---------------------------------------------------");
}

int main()
{
    struct Node *head = NULL;
    // head = NULL;

    int flag = 0;

    do
    {
    A:

        menu();

        int ch, dt, key;
        bool res;

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            traverse(&head);
            break;

        case 2:
            printf("\nEnter data: ");
            scanf("%d", &dt);

            insertFront(&head, dt);
            break;

        case 3:
            printf("\nEnter data: ");
            scanf("%d", &dt);

            printf("\nEnter key: ");
            scanf("%d", &key);

            res = insertAfter(&head, dt, key);

            if (res == false)
                printf("\nCan't find the key value!");
            else
                printf("\nData entered successfully!");
            break;

        case 4:
            printf("\nEnter data: ");
            scanf("%d", &dt);

            insertEnd(&head, dt);
            break;

        case 5:
            if (isEmpty(&head))
            {
                printf("\nList already EMPTY !!");
                break;
            }

            dt = deleteFront(&head);

            printf("\nDeleted value: %d", dt);
            break;

        case 6:
            if (isEmpty(&head))
            {
                printf("\nList already EMPTY !!");
                break;
            }

            printf("\nEnter key: ");
            scanf("%d", &key);

            bool res = deleteMid(&head, key);

            if (res == false)
                printf("\nCan't find the key value!");
            else
                printf("\nData deleted successfully!");
            break;

        case 7:
            if (isEmpty(&head))
            {
                printf("\nList already EMPTY !!");
                break;
            }

            dt = deleteRear(&head);

            printf("\nDeleted value: %d", dt);
            break;

        case 8:
            bye();
            flag = 1;
            break;

        default:
            printf("\n\nInvalid Choice! Enter again...");
            goto A;
        }
    } while (!flag);

    return 0;
}