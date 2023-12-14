#include<stdio.h>
#include<stdlib.h>

//                              Defining node structure
typedef struct Node{
    struct Node *left;
    int data;
    struct Node *right;
} node;

//                              Creating a new node
node* createNode(int data)
{
    node *new = malloc(sizeof(node));
    
    new -> left = NULL;
    new -> data = data;
    new -> right = NULL;

    return new;
}

//                              Pre-Order Traversal
void preOrder(node *root)
{
    if (root!=NULL){
        printf("%d -> ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//                              In-Order Traversal
void inOrder(node *root)
{
    if (root!=NULL){
        inOrder(root->left);
        printf("%d -> ", root->data);
        inOrder(root->right);
    }
}

//                              Post-Order Traversal
void postOrder(node *root)
{
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d -> ", root->data);
    }
}

int main()
{
    node *root, *p1, *p2, *p3, *p4;

    root = malloc(sizeof(node));
    p1 = malloc(sizeof(node));
    p2 = malloc(sizeof(node));
    p3 = malloc(sizeof(node));
    p4 = malloc(sizeof(node));

    root = (node*)createNode(1);
    p1 = (node*)createNode(2);
    p2 = (node*)createNode(3);
    p3 = (node*)createNode(4);
    p4 = (node*)createNode(5);

    root ->left = p1;
    root -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    
    printf("Pre-Order Traversal:-");
    preOrder(root);
    printf("NULL\n\n");

    printf("In-Order Traversal:-");
    inOrder(root);
    printf("NULL\n\n");

    printf("Post-Order Traversal:-");
    postOrder(root);
    printf("NULL\n\n");

return 0;
}