#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

int A[MAX][MAX], B[MAX][MAX];
int m, n, p, q;

typedef struct
{
    int row;
    int col;
} ThreadData;

void *multiply(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    int row = data->row;
    int col = data->col;

    int *result = (int *)malloc(sizeof(int));
    *result = 0;

    for (int i = 0; i < n; i++)
    {
        *result += A[row][i] * B[i][col];
    }

    pthread_exit(result);
}

int main()
{
    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &m, &n);

    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &p, &q);

    if (n != p)
    {
        printf("Matrix multiplication not possible. Columns of A != Rows of B\n");
        return 0;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    pthread_t threads[MAX][MAX];
    ThreadData *data[MAX][MAX];
    int C[MAX][MAX];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            data[i][j] = (ThreadData *)malloc(sizeof(ThreadData));
            data[i][j]->row = i;
            data[i][j]->col = j;
            pthread_create(&threads[i][j], NULL, multiply, data[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int *result;
            pthread_join(threads[i][j], (void **)&result);
            C[i][j] = *result;
            free(result);
            free(data[i][j]);
        }
    }

    printf("\nResultant Matrix C = A x B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}