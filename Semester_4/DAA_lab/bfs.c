
#include <stdio.h>
#include <stdlib.h>

int matrix[20][20], q[20], isVisited[20] = {0}; 
int front = -1, rear = -1, n;

void enqueue(int x)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        q[front] = x;
        return;
    }
    q[++rear] = x;
}

int dequeue()
{
    return q[front++];
}

int qLength()
{
    return rear - front + 1;
}

void bfs(int node) // Node is the current root node
{
    int i;
    isVisited[node] = 1; // mark root as visited

    for (i = 0; i < n; i++)
        if (matrix[node][i] == 1 && !isVisited[i])
            enqueue(i); 

    if (qLength())
        bfs(dequeue());
}

int main()
{
    int i, j, node;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:-\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("Enter the starting node: ");
    scanf("%d", &node);

    bfs(node);

    printf("The nodes that can be visited are: ");
    for (i = 0; i < n; i++)
        if (isVisited[i] == 1)
            printf("%d ", i);

    printf("\n");
    return (0);
}