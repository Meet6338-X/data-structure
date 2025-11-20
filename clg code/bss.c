#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack
{
    struct Node *arr[100];
    int top;
};

void push(struct Stack *s, struct Node *node)
{
    s->arr[++(s->top)] = node;
}

struct Node *pop(struct Stack *s)
{
    return s->arr[(s->top)--];
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void inorderNonRecursive(struct Node *root)
{
    struct Stack s;
    s.top = -1;

    struct Node *curr = root;

    while (curr != NULL || !isEmpty(&s))
    {
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->left;
        }

        curr = pop(&s);
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

void preorderNonRecursive(struct Node *root)
{
    if (!root)
        return;

    struct Stack s;
    s.top = -1;

    push(&s, root);

    while (!isEmpty(&s))
    {
        struct Node *node = pop(&s);
        printf("%d ", node->data);

        // Push right first so left is processed first
        if (node->right)
            push(&s, node->right);
        if (node->left)
            push(&s, node->left);
    }
}

void postorderNonRecursive(struct Node *root)
{
    if (!root)
        return;

    struct Stack s1, s2;
    s1.top = s2.top = -1;

    push(&s1, root);

    while (!isEmpty(&s1))
    {
        struct Node *node = pop(&s1);
        push(&s2, node);

        if (node->left)
            push(&s1, node->left);
        if (node->right)
            push(&s1, node->right);
    }

    while (!isEmpty(&s2))
    {
        printf("%d ", pop(&s2)->data);
    }
}

int main()
{
    /*
             1
           /   \
          2     3
         / \   / \
        4  5  6   7
    */

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("\n\n--- Non-Recursive Traversals ---\n");
    printf("Inorder: ");
    inorderNonRecursive(root);
    printf("\nPreorder: ");
    preorderNonRecursive(root);
    printf("\nPostorder: ");
    postorderNonRecursive(root);

    return 0;
}