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

void insertFront(struct Node **head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if (isEmpty(*head))
    {
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
        *head = new;
    }

    else
    {
        new->prev = NULL;
        new->data = data;
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

bool insertAfter(struct Node **head, int data, int key)
{
    if (isEmpty(*head))
        insertFront(head, data);

    else
    {
        struct Node *temp = *head;
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        bool res = false;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                res = true;
                break;
            }

            temp = temp->next;
        }

        if (res == true)
        {
            new->data = data;
            new->prev = temp;
            new->next = temp->next;
            temp->next->prev = new;
            temp->next = new;
            return true;
        }

        else
            return false;
    }
}

void insertRear(struct Node **head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if (isEmpty(*head))
    {
        new->prev = NULL;
        new->data = data;
        new->next = NULL;
        *head = new;
    }

    else
    {
        struct Node *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        new->data = data;
        new->prev = temp;
        temp->next = new;
        new->next = NULL;
    }
}

int deleteFront(struct Node **head)
{
    if ((*head)->next == NULL)
    {
        int data = (*head)->data;
        (*head) = NULL;
        return data;
    }

    struct Node *new = *head;
    int value = new->data;

    *head = (*head)->next;
    free(new);
    return value;
}

bool deleteMid(struct Node **head, int key)
{
    if ((*head)->next == NULL)
    {
        if ((*head)->data == key)
        {
            *head = NULL;
            return true;
        }
        else
            return false;
    }

    struct Node *temp = *head;
    bool res = false;

    if (!isEmpty(*head))
    {
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                res = true;
                struct Node *del = temp;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(del);
                break;
            }

            temp = temp->next;
        }
    }

    else
        return false;

    return res;
}

int deleteRear(struct Node **head)
{
    if ((*head)->next == NULL)
    {
        int data = (*head)->data;
        (*head) = NULL;
        return data;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    int value = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return value;
}

void traverse(struct Node **head)
{
    struct Node *temp = *head;

    printf("\n\nList: ");

    if (isEmpty(*head))
        printf("EMPTY!!");

    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    // free(temp);
}

void menu()
{
    printf("\n\n1. Show list\n2. Insert value at front\n3. Insert value after the key value\n4. Insert value at last\n5. Delete front value\n6. Delete a mid value\n7. Delete last value\n8. Exit");
}

int main()
{

    // struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *head = NULL;

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

            insertRear(&head, dt);
            break;

        case 5:
            if (isEmpty(head))
            {
                printf("\nList already EMPTY !!");
                break;
            }

            dt = deleteFront(&head);

            printf("\nDeleted value: %d", dt);
            break;

        case 6:
            if (isEmpty(head))
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
            if (isEmpty(head))
            {
                printf("\nList already EMPTY !!");
                break;
            }

            dt = deleteRear(&head);

            printf("\nDeleted value: %d", dt);
            break;

        case 8:
            printf("\n\n---------------------------------------------------THANK YOU---------------------------------------------------");
            flag = 1;
            break;

        default:
            printf("\n\nInvalid Choice! Enter again...");
            goto A;
        }
    } while (!flag);

    return 0;
}