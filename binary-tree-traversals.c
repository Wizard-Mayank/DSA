#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//                              Defining tNode structure
typedef struct btNode
{
    struct btNode *left;
    int data;
    struct btNode *right;
} tNode;

//                              Defining linkedNode structure
typedef struct linkedNode
{
    tNode *data;
    struct linkedNode *next;
} lNode;

//                              Defining Queue structure
typedef struct Queue
{
    lNode *front;
    lNode *rear;
} queue;

//                              Queue isEmpty()

bool isEmpty(queue *Q)
{
    if (Q->front == NULL)
        return true;
    else
        return false;
}

//                              Insert operation in queue
void enqueue(queue *Q, tNode *new)
{
    lNode *temp = (lNode *)malloc(sizeof(lNode));

    temp->data = new;
    temp->next = NULL;

    if (Q->front == NULL)
        Q->front = temp;

    if (Q->rear == NULL)
        Q->rear = temp;
    
    else
    {
        Q->rear->next = temp;
        Q->rear = Q->rear->next;
    }
}

//                              Delete Operation in queue
tNode *dequeue(queue *Q)
{
    if (isEmpty(Q))
        return NULL;
    
    tNode *new = Q->front->data;

    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }

    else
    {
        Q->front = Q->front->next;
    }

    return (new);
}

//                              Creating a new tNode
tNode *createNode(int data)
{
    tNode *new = malloc(sizeof(tNode));

    new->left = NULL;
    new->data = data;
    new->right = NULL;

    return new;
}

//                              Pre-Order Traversal
void preOrder(tNode *root)
{
    if (root != NULL)
    {
        printf("%d -> ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//                              In-Order Traversal
void inOrder(tNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d -> ", root->data);
        inOrder(root->right);
    }
}

//                              Post-Order Traversal
void postOrder(tNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d -> ", root->data);
    }
}

//                              Level-Order Traversal - 1
void currentLevel(tNode *root, int level)
{
    if (root == NULL)
        return;
    else if (level == 1)
        printf("%d -> ", root->data);
    else
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

//                              Level-Order Traversal - 2

void levelOrder(tNode *root)
{
    queue *Q = (queue*)malloc(sizeof(queue));
    Q->front = NULL;
    Q->rear = NULL;

    enqueue(Q, root);

    while (!isEmpty(Q))
    {
        tNode *data = dequeue(Q);

        if (data==NULL)
            break;

        printf("%d -> ", data->data);

        if (data->left != NULL)
            enqueue(Q, data->left);

        if (data->right != NULL)
            enqueue(Q, data->right);

        free(data);
    }
}

int main()
{
    tNode *root, *p1, *p2, *p3, *p4, *p5, *p6;

    root = (tNode *)createNode(1);
    p1 = (tNode *)createNode(2);
    p2 = (tNode *)createNode(3);
    p3 = (tNode *)createNode(4);
    p4 = (tNode *)createNode(5);
    p5 = (tNode *)createNode(6);
    p6 = (tNode *)createNode(7);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    printf("Pre-Order Traversal: ");
    preOrder(root);
    printf("NULL\n\n");

    printf("In-Order Traversal: ");
    inOrder(root);
    printf("NULL\n\n");

    printf("Post-Order Traversal: ");
    postOrder(root);
    printf("NULL\n\n");

    printf("Level-Order Traversal - 1: ");
    for (int i = 1; i <= 3; ++i)
        currentLevel(root, i);
    printf("NULL\n\n");

    printf("Level-Order Traversal - 2: ");
    levelOrder(root);
    printf("NULL\n\n");

    return 0;
}