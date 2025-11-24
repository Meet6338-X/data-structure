#include <stdio.h>
#include <stdlib.h>

int rotationCount = 0;

struct Node
{
    int data;
    struct Node *left, *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalance(struct Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

/* ROTATIONS  */

// Right Rotation (LL)
struct Node *rightRotate(struct Node *y)
{
    rotationCount++;
    printf("Rotation Applied: LL (Right Rotation)\n");

    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation (RR)
struct Node *leftRotate(struct Node *x)
{
    rotationCount++;
    printf("Rotation Applied: RR (Left Rotation)\n");

    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

/* INSERTION */

struct Node *insert(struct Node *node, int key)
{

    // Step 1: Normal BST insert
    if (node == NULL)
    {
        printf("Inserted %d\n", key);
        return createNode(key);
    }

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
    {
        printf("Duplicate %d ignored.\n", key);
        return node;
    }

    // Step 2: Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Step 3: Get balance factor
    int balance = getBalance(node);

    // Check imbalance and rotate accordingly
    if (balance > 1 && key < node->left->data)
    {
        printf("Imbalance Detected → LL Case\n");
        return rightRotate(node); // LL
    }

    if (balance < -1 && key > node->right->data)
    {
        printf("Imbalance Detected → RR Case\n");
        return leftRotate(node); // RR
    }

    if (balance > 1 && key > node->left->data)
    {
        printf("Imbalance Detected → LR Case\n");
        node->left = leftRotate(node->left);
        return rightRotate(node); // LR
    }

    if (balance < -1 && key < node->right->data)
    {
        printf("Imbalance Detected → RL Case\n");
        node->right = rightRotate(node->right);
        return leftRotate(node); // RL
    }

    return node;
}

/*  TRAVERSAL  */

void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* BALANCED CHECK  */

int isBalanced(struct Node *root)
{
    if (root == NULL)
        return 1;

    int bf = getBalance(root);
    return (bf >= -1 && bf <= 1);
}

/* MAIN */

int main()
{
    struct Node *root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);

        if (isBalanced(root))
            printf("Tree is AVL Balanced after inserting %d\n\n", val);
        else
            printf("Tree is NOT Balanced after inserting %d\n\n", val);
    }

    printf("\nFinal Inorder Traversal:\n");
    inorder(root);

    printf("\n\nTotal Rotations Performed: %d\n", rotationCount);

    return 0;
}