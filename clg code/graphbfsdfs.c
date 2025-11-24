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

void addEdge(struct Node *adjList[], int u, int v)
{
    struct Node *node1 = createNode(v);
    node1->next = adjList[u];
    adjList[u] = node1;

    struct Node *node2 = createNode(u);
    node2->next = adjList[v];
    adjList[v] = node2;
}

void printQueue(int queue[], int front, int rear)
{
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void printStack(int stack[], int top)
{
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void BFS(struct Node *adjList[], int n, int start)
{
    int visited[n];
    int queue[n];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nBFS Traversal:\n");
    printf("Start from %d\n", start);

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        int curr = queue[front++];

        printf("\nVisited: %d\n", curr);
        printQueue(queue, front, rear);

        struct Node *temp = adjList[curr];
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

void DFS_Recursive(struct Node *adjList[], int visited[], int node)
{
    visited[node] = 1;
    printf("Visited: %d\n", node);

    struct Node *temp = adjList[node];
    while (temp)
    {
        if (!visited[temp->vertex])
            DFS_Recursive(adjList, visited, temp->vertex);
        temp = temp->next;
    }
}

void DFS_Iterative(struct Node *adjList[], int n, int start)
{
    int visited[n];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Iterative:\n");
    printf("Start from %d\n", start);

    stack[++top] = start;

    while (top >= 0)
    {
        int curr = stack[top--];

        if (!visited[curr])
        {
            visited[curr] = 1;
            printf("\nVisited: %d\n", curr);
            printStack(stack, top);

            struct Node *temp = adjList[curr];
            while (temp)
            {
                if (!visited[temp->vertex])
                {
                    stack[++top] = temp->vertex;
                }
                temp = temp->next;
            }
        }
    }
}

int main()
{
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Node *adjList[n];
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    printf("Enter starting node for traversal: ");
    scanf("%d", &start);

    BFS(adjList, n, start);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Recursive:\n");
    DFS_Recursive(adjList, visited, start);

    DFS_Iterative(adjList, n, start);

    return 0;
}