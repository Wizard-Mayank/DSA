#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct linearQueue
{
    int arr[MAX];
    int front, rear;
} lQueue;

void init(lQueue *Q)
{
    Q->front = Q->rear = -1;
}

int isEmpty(lQueue *Q)
{
    if (Q->front == -1)
        return 1;

    return 0;
}

int isFull(lQueue *q)
{
    if (q->rear == MAX - 1)
        return 1;

    return 0;
}

void enqueue(lQueue *q, int data)
{
    if (isFull(q))
    {
        printf("\nQueue Overflow !!\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;

    else
        q->rear++;

    q->arr[q->rear] = data;
}

void dequeue(lQueue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue Underflow !!\n");
        return;
    }

    int data = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;

    else
        q->front++;

    printf("\nRemoved : %d", data);
}

void traverse(lQueue *q)
{
    printf("\nQueue: ");

    if (isEmpty(q))
        printf("EMPTY !!\n");
    else
    {
        for (int i = q->front; i <= q->rear; ++i)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
}

void showMenu()
{
    printf("\n1. Show queue\n2. Enqueue\n3. Dequeue\n4. Exit");
}

void main()
{
    lQueue *q = (lQueue *)malloc(sizeof(lQueue));
    init(q);

    char cont = 'y';
    int data;

    do
    {
    A:

        if (cont == 'n')
            break;

    B:

        showMenu();

        int ch;

        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            traverse(q);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &data);

            enqueue(q, data);
            break;
        case 3:
            dequeue(q);
            break;
        case 4:
            printf("\n---------------------------------- Thank You! :) ----------------------------------");
            cont = 'n';

            goto A;
            break;
        default:
            printf("\nWrong Choice! Try again...\n");
            goto B;
        }
    } while (cont == 'y');
}