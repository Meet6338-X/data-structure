#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, e;
    int i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int adjMatrix[n][n];

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    struct Node *adjList[n];
    for (i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        struct Node *newNode1 = createNode(v);
        newNode1->next = adjList[u];
        adjList[u] = newNode1;

        struct Node *newNode2 = createNode(u);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++)
    {
        struct Node *temp = adjList[i];
        printf("%d -> ", i);
        while (temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}