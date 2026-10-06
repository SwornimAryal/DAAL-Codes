#include <stdio.h>

// Check whether a color can be assigned to a vertex
int isSafe(int vertex, int color, int n, int graph[n][n], int colors[])
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && colors[i] == color)
        {
            return 0;
        }
    }

    return 1;
}

// Backtracking to find a valid coloring
int graphColoring(int vertex, int n, int m,
                  int graph[n][n], int colors[])
{
    int color;

    // All vertices are colored
    if (vertex == n)
    {
        return 1;
    }

    // Try every color
    for (color = 1; color <= m; color++)
    {
        if (isSafe(vertex, color, n, graph, colors))
        {
            // Assign color
            colors[vertex] = color;

            // Move to next vertex
            if (graphColoring(vertex + 1, n, m, graph, colors))
            {
                return 1;
            }

            // Backtrack
            colors[vertex] = 0;
        }
    }

    return 0;
}

int main()
{
    int n, i, j;
    int minColors = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int colors[n];

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize colors to 0
    for (i = 0; i < n; i++)
    {
        colors[i] = 0;
    }

    // Try 1, 2, 3 ... colors
    for (int m = 1; m <= n; m++)
    {
        // Reset colors
        for (i = 0; i < n; i++)
        {
            colors[i] = 0;
        }

        if (graphColoring(0, n, m, graph, colors))
        {
            minColors = m;
            break;
        }
    }

    printf("\nMinimum number of colors required: %d\n", minColors);

    printf("Valid color assignment:\n");

    for (i = 0; i < n; i++)
    {
        printf("Vertex %d -> Color %d\n", i + 1, colors[i]);
    }

    return 0;
}