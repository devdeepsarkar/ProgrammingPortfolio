#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];

int min_dist(int size)
{
    int min_distance = INT_MAX, min_index;
    for (int i = 0; i < size; i++)
    {
        if (!visited[i] && dist[i] < min_distance)
        {
            min_distance = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int ivertex, int size)
{
    for (int i = 0; i < size; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[ivertex] = 0;

    for (int count = 0; count < size - 1; count++)
    {
        int u = min_dist(size);
        visited[u] = 1;
        for (int v = 0; v < size; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main()
{
    int size, ivertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);

    printf("Enter the weighted adjacency matrix of the graph:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int cost = 0;
    printf("Enter the starting vertex: ");
    scanf("%d", &ivertex);

    dijkstra(ivertex, size);

    printf("Minimum costs from vertex %d:\n", ivertex);
    for (int i = 0; i < size; i++)
    {
        printf("Vertex %d: %d\n", i, dist[i]);
        cost = dist[i];
    }
    printf("\n");
    printf("Total minimum cost= %d\n", cost);
    return 0;
}

/*
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
*/