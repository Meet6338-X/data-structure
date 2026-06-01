#include <stdio.h>

int tree[100];
int n = 0;

void preorder(int index)
{
    if (index >= n)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void inorder(int index)
{
    if (index >= n)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void postorder(int index)
{
    if (index >= n)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

int main()
{
    tree[0] = 1;
    tree[1] = 2;
    tree[2] = 3;
    tree[3] = 4;
    tree[4] = 5;

    n = 5;

    printf("Preorder Traversal: ");
    preorder(0);

    printf("\nInorder Traversal: ");
    inorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    return 0;
}
