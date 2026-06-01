#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *stack[MAX];
int top = -1;

void push(struct Node *node)
{
    if (top < MAX - 1)
        stack[++top] = node;
}

struct Node *pop()
{
    if (top == -1)
        return NULL;
    return stack[top--];
}

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive Traversals
void inorderRec(struct Node *root)
{
    if (root)
    {
        inorderRec(root->left);
        printf("%d ", root->data);
        inorderRec(root->right);
    }
}

void preorderRec(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorderRec(root->left);
        preorderRec(root->right);
    }
}

void postorderRec(struct Node *root)
{
    if (root)
    {
        postorderRec(root->left);
        postorderRec(root->right);
        printf("%d ", root->data);
    }
}

// Iterative Inorder
void inorderIter(struct Node *root)
{
    struct Node *curr = root;
    top = -1;

    while (curr || top != -1)
    {
        while (curr)
        {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Iterative Preorder
void preorderIter(struct Node *root)
{
    top = -1;
    if (!root)
        return;
    push(root);
    while (top != -1)
    {
        struct Node *node = pop();
        printf("%d ", node->data);
        if (node->right)
            push(node->right);
        if (node->left)
            push(node->left);
    }
}

// Iterative Postorder (using two stacks)
void postorderIter(struct Node *root)
{
    if (!root)
        return;
    struct Node *stack1[MAX], *stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        struct Node *node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Recursive Inorder: ");
    inorderRec(root);
    printf("\n");

    printf("Recursive Preorder: ");
    preorderRec(root);
    printf("\n");

    printf("Recursive Postorder: ");
    postorderRec(root);
    printf("\n");

    printf("Iterative Inorder: ");
    inorderIter(root);
    printf("\n");

    printf("Iterative Preorder: ");
    preorderIter(root);
    printf("\n");

    printf("Iterative Postorder: ");
    postorderIter(root);
    printf("\n");

    return 0;
}
