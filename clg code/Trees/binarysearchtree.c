#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct Node *search(struct Node *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

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
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
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

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 10);

    printf("BST (Inorder): ");
    inorder(root);
    printf("\n");

    int key = 6;
    struct Node *result = search(root, key);
    if (result != NULL)
        printf("Value %d found in BST\n", key);
    else
        printf("Value %d NOT found in BST\n", key);

    root = deleteNode(root, 3);

    printf("BST After Deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
