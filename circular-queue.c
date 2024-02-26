#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct circularQueue
{
    int arr[MAX];
    int front, rear;
} cQueue;

void init(cQueue *Q)
{
    Q->front = Q->rear = -1;
}

int isEmpty(cQueue *Q)
{
    if (Q->front == -1)
        return 1;

    return 0;
}

int isFull(cQueue *q)
{
    if ((q->front == 0 && q->rear == MAX - 1) || (q->rear == q->front - 1))
        return 1;

    return 0;
}

void enqueue(cQueue *q, int data)
{
    if (isFull(q))
    {
        printf("\nQueue Overflow !!\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;

    else
        q->rear = (q->rear + 1) % MAX;

    q->arr[q->rear] = data;
}

void dequeue(cQueue *q)
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
        q->front = (q->front + 1) % MAX;

    printf("\nRemoved : %d\n", data);
}

void traverse(cQueue *q)
{
    printf("\nQueue: ");

    if (isEmpty(q))
        printf("EMPTY !!\n");
    else if (q->front <= q->rear)
    {
        for (int i = q->front; i <= q->rear; ++i)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
    else
    {
        for (int i = q->front; i < MAX; ++i)
            printf("%d ", q->arr[i]);
        for (int i = 0; i <= q->rear; ++i)
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
    cQueue *q = (cQueue *)malloc(sizeof(cQueue));
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