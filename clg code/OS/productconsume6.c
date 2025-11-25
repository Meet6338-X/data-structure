#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;

void down(int *s)
{
    while (*s <= 0)
        ;
    (*s)--;
}

void up(int *s)
{
    (*s)++;
}

void producer()
{
    int item;
    item = rand() % 100;

    down(&empty);
    down(&mutex);

    buffer[in] = item;
    printf("\nProduced: %d", item);
    in = (in + 1) % BUFFER_SIZE;

    up(&mutex);
    up(&full);
}

void consumer()
{
    int item;

    down(&full);
    down(&mutex);

    item = buffer[out];
    printf("\nConsumed: %d", item);
    out = (out + 1) % BUFFER_SIZE;

    up(&mutex);
    up(&empty);
}

int main()
{
    int n;
    printf("1. Produce\n2. Consume\n3. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            producer();
            break;

        case 2:
            consumer();
            break;

        case 3:
            return 0;

        default:
            printf("\nInvalid choice!");
        }
    }
}
