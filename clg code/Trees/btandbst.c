#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary Tree using Array
void binaryTreeArray()
{
    int tree[MAX];
    int n, i;
    printf("Enter number of nodes for binary tree (array): ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("Binary Tree (Array Representation):\n");
    for (i = 0; i < n; i++)
        printf("Index %d: %d\n", i, tree[i]);
}

// Binary Tree using Linked List (BST structure used)
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Insert
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find minimum value node (for case 3 deletion)
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// BST Deletion
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 1 & 2
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver for BST
void bstOperations()
{
    struct Node *root = NULL;
    int n, val, del;
    printf("\nEnter number of elements to insert into BST: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    printf("Enter node to delete (leaf / 1-child / 2-children): ");
    scanf("%d", &del);
    root = deleteNode(root, del);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");
}

int main()
{
    binaryTreeArray();
    bstOperations();
    return 0;
}