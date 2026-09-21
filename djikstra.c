#include <stdio.h>
#define INF 999
int main()
{
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    int distance[V];
    int visited[V];
    // Take graph weights from user
    printf("\nEnter the weight of each edge:\n");
    printf("Enter 999 if there is no direct path.\n\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("Weight from %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("\nEnter source vertex: ");
    scanf("%d", &source);
    // Initialize
    for (int i = 0; i < V; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }
    // Source distance is 0
    distance[source] = 0;
    // Dijkstra Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF;
        int currentVertex = -1;
        // Find minimum distance unvisited vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                currentVertex = i;
            }
        }
        if (currentVertex == -1)
            break;
        // Mark current vertex as visited
        visited[currentVertex] = 1;
        printf("\nCurrent Vertex: %d", currentVertex);
        // Check new vertices
        for (int newVertex = 0; newVertex < V; newVertex++)
        {
            if (!visited[newVertex] &&
                graph[currentVertex][newVertex] != INF)
            {
                int weight = graph[currentVertex][newVertex];
                printf("\nNew Vertex: %d, Weight: %d",
                       newVertex, weight);
                // Update distance
                if (distance[currentVertex] + weight <
                    distance[newVertex])
                {
                    distance[newVertex] =
                        distance[currentVertex] + weight;
                    printf(" -> New Distance: %d",
                           distance[newVertex]);
                }
            }
        }
    }
    // Display shortest distances
    printf("\n\nShortest distances from vertex %d:\n",
           source);
    for (int i = 0; i < V; i++)
    {
        if (distance[i] == INF)
            printf("Vertex %d = INF\n", i);
        else
            printf("Vertex %d = %d\n", i, distance[i]);
    }
    return 0;
}