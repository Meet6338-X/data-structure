#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1);
}

int isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf(" Underflow!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return data;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void reverseFirstK(int k)
{
    if (isEmpty() || k > (rear - front + 1) || k <= 0)
    {
        printf("Invalid value of K!\n");
        return;
    }

    int stack[MAX], top = -1;

    for (int i = 0; i < k; i++)
        stack[++top] = dequeue();

    while (top != -1)
        enqueue(stack[top--]);

    int size = rear - front + 1;
    for (int i = 0; i < size - k; i++)
    {
        int val = dequeue();
        enqueue(val);
    }
}

void sortQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty, cannot sort.\n");
        return;
    }

    int n = rear - front + 1;
    for (int i = front; i < rear; i++)
    {
        for (int j = front; j < rear - (i - front); j++)
        {
            if (queue[j] > queue[j + 1])
            {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, k, value;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter queue elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Enter value of K to reverse: ");
    scanf("%d", &k);

    printf("\nOriginal Queue: ");
    display();

    reverseFirstK(k);
    printf("Queue after reversing first %d elements: ", k);
    display();

    sortQueue();
    printf("Queue after sorting in ascending order: ");
    display();

    return 0;
}