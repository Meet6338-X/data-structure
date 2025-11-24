#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

struct Node **hashTable;
int size;

int hashFunction(int key)
{
    return key % size;
}

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(int key)
{
    int index = hashFunction(key);
    struct Node *newNode = createNode(key);

    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Inserted %d at index %d\n", key, index);
}

void search(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

void deleteKey(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found for deletion\n", key);
}

void display()
{
    for (int i = 0; i < size; i++)
    {
        struct Node *temp = hashTable[i];
        printf("Index %d: ", i);

        while (temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, key;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    hashTable = (struct Node **)malloc(size * sizeof(struct Node *));

    for (int i = 0; i < size; i++)
        hashTable[i] = NULL;

    while (1)
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 3:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteKey(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}