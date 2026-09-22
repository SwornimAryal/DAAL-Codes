#include <stdio.h>
#define INF 999
void dijkstra(int n, int graph[10][10], int start)
{
    int dist[10];
    int visited[10];
    int parent[10];
    int i, v;
    /* Initialization */
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;
    printf("\nInitial Distance Table:\n");
    printf("Iteration\t");
    for (i = 0; i < n; i++)
        printf("S%d\t", i);
    printf("\n");
    printf("0\t\t");
    for (i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("INF\t");
        else
            printf("%d\t", dist[i]);
    }
    printf("\n");
    /* Dijkstra's Algorithm */
    for (int count = 0; count < n - 1; count++)
    {
        int minDist = INF;
        int minVertex = -1;
        /* Find unvisited vertex with minimum distance */
        for (v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                minVertex = v;
            }
        }
        /* No more reachable vertices */
        if (minVertex == -1)
            break;
        visited[minVertex] = 1;
        /* Relax adjacent vertices */
        for (v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[minVertex][v] != 0 &&
                dist[minVertex] + graph[minVertex][v] < dist[v])
            {
                dist[v] = dist[minVertex] + graph[minVertex][v];
                parent[v] = minVertex;
            }
        }
        /* Display distance table */
        printf("%d\t\t", count + 1);

        for (i = 0; i < n; i++)
        {
            if (dist[i] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i]);
        }
        printf("\n");
    }
    /* Final shortest distances */
    printf("\n========================================");
    printf("\nFinal Minimum Latency Table");
    printf("\n========================================\n");
    printf("Server\tMinimum Latency\tParent\n");
    for (i = 0; i < n; i++)
    {
        printf("S%d\t", i);
        if (dist[i] == INF)
            printf("INF\t\t");
        else
            printf("%d\t\t", dist[i]);

        if (parent[i] == -1)
            printf("-");
        else
            printf("S%d", parent[i]);
        printf("\n");
    }
    /* Construct shortest path tree */
    printf("\n========================================");
    printf("\nShortest Path Tree");
    printf("\n========================================\n");
    printf("Parent -> Child\n");
    for (i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            printf("S%d -> S%d\n", parent[i], i);
        }
    }
    /* Display paths */
    printf("\n========================================");
    printf("\nShortest Paths from Source S%d", start);
    printf("\n========================================\n");
    for (i = 0; i < n; i++)
    {
        if (i == start)
        {
            printf("S%d -> S%d : 0 ms\n", start, i);
        }
        else if (dist[i] == INF)
        {
            printf("S%d -> S%d : No path\n", start, i);
        }
        else
        {
            int path[10];
            int pathSize = 0;
            int current = i;
            /* Store path */
            while (current != -1)
            {
                path[pathSize] = current;
                pathSize++;
                current = parent[current];
            }
            printf("S%d -> S%d : ", start, i);
            /* Print path in reverse */
            for (int j = pathSize - 1; j >= 0; j--)
            {
                printf("S%d", path[j]);

                if (j != 0)
                    printf(" -> ");
            }
            printf("  (%d ms)\n", dist[i]);
        }
    }
    /* Time complexity */
    printf("\n========================================");
    printf("\nTime Complexity Analysis");
    printf("\n========================================\n");
    printf("Best Case    : O(V^2)\n");
    printf("Average Case : O(V^2)\n");
    printf("Worst Case   : O(V^2)\n");
    printf("\nSpace Complexity: O(V^2)\n");
}
int main()
{
    int n, start;
    int graph[10][10];
    printf("Enter number of servers: ");
    scanf("%d", &n);
    printf("\nEnter latency matrix:\n");
    printf("(0 means no direct network link)\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nEnter source server (0 to %d): ", n - 1);
    scanf("%d", &start);
    dijkstra(n, graph, start);
    return 0;
}