#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPos(int val, int pos)
{
    if (pos == 1)
    {
        insertFront(val);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPos(int pos)
{
    if (head == NULL || pos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        deleteFront();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display()
{
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d , ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, val, pos;
    do
    {
        printf("\n1.Insert at start \n2.Insert at last \n3.Insert At fix position\n4.Delete start\n5.Delete End\n6.Delete At a Position\n7.Display\n8.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &val);
            insertFront(val);
            break;
        case 2:
            printf("Value: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            printf("Value and Position: ");
            scanf("%d %d", &val, &pos);
            insertAtPos(val, pos);
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Position: ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        case 7:
            display();
            break;
        }
    } while (choice != 8);
    return 0;
}
