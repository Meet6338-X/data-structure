#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int d, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    if (front == NULL || p < front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        struct Node *curr = front;
        while (curr->next != NULL && curr->next->priority <= p)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;
    }

    printf("null\n");
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n", front->data);
    struct Node *temp = front;
    front = front->next;
    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n", front->data);
}

void display()
{
    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Current Queue (data, priority): ");
    while (temp != NULL)
    {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data, priority, n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}