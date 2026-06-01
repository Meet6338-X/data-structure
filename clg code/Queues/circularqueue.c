#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

void rotateQueue(struct Queue *q, int k)
{
    if (q->front == NULL)
        return;

    for (int i = 0; i < k; i++)
    {
        int val = dequeue(q);
        enqueue(q, val);
    }
}

void display(struct Queue *q)
{
    struct Node *temp = q->front;
    if (temp == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);

    int n, val, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("Enter k (positions to rotate): ");
    scanf("%d", &k);

    printf("Original Queue: ");
    display(&q);

    rotateQueue(&q, k);

    printf("Queue after rotating by %d positions: ", k);
    display(&q);

    return 0;
}