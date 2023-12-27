#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node *left;
    float data;
    struct Node *right;
} node;

//                              Pre-Order Traversal
void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%.2f -> ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//                              In-Order Traversal
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%.2f -> ", root->data);
        inOrder(root->right);
    }
}

//                              Post-Order Traversal
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%.2f -> ", root->data);
    }
}

//                              BST Check
bool isBST(node *root)
{
    static node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
            return false;
        else if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;
        return isBST(root->right);
    }

    else
        return true;
}

//                              Insertion
void insertBST(node *root, float data)
{
    node *temp = root;
    node *new = (node *)malloc(sizeof(node));

    new->left = NULL;
    new->data = data;
    new->right = NULL;

    if (root == NULL)
    {
        *root = *new;
        return;
    }

    while (data <= temp->data && temp->left != NULL)
        temp = temp->left;

    while (data >= temp->data && temp->right != NULL)
        temp = temp->right;

    if (data <= temp->data)
    {
        new->left = temp->left;
        temp->left = new;
    }

    else
    {
        new->right = temp->right;
        temp->right = new;
    }
}

void menu()
{
    printf("\n\n1. PreOrder Traversal\n2. InOrder Traversal\n3. PostOrder Traversal\n4. Insert a new data\n5. Exit");
}

int main()
{
    char cont;
    int ch;
    float dt;

    node *root = NULL;

    do
    {
    A:

        menu();
        printf("\n\nEnter your choice -> ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            preOrder(root);
            printf("NULL");
            break;
        case 2:
            inOrder(root);
            printf("NULL");
            break;
        case 3:
            postOrder(root);
            printf("NULL");
            break;
        case 4:
            printf("\n\nEnter the data you want to insert: ");
            scanf("%f", &dt);

            insertBST(root, dt);
            break;
        case 5:
            cont = 'n';
            printf("\n\n-----------------------------------------------------------Thank You-----------------------------------------------------------");
            break;
        default:
            printf("\n\nWrong Choice! Enter again...");
            goto A;
        };

    } while (cont == 'y');

    return 0;
}