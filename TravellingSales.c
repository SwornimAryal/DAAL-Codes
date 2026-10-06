#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];
int parent[1 << MAX][MAX];

/* TSP using Dynamic Programming */
int tsp(int mask, int pos)
{
    int city;

    /* All cities visited */
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    /* Already calculated */
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    dp[mask][pos] = INT_MAX;

    /* Try every unvisited city */
    for (city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newMask = mask | (1 << city);

            int cost = dist[pos][city]
                     + tsp(newMask, city);

            if (cost < dp[mask][pos])
            {
                dp[mask][pos] = cost;
                parent[mask][pos] = city;
            }
        }
    }

    return dp[mask][pos];
}

/* Print the optimal path */
void printPath()
{
    int mask = 1;
    int pos = 0;

    printf("\nOptimal Path: 1");

    while (mask != (1 << n) - 1)
    {
        int nextCity = parent[mask][pos];

        printf(" -> %d", nextCity + 1);

        mask = mask | (1 << nextCity);
        pos = nextCity;
    }

    printf(" -> 1\n");
}

int main()
{
    int i, j;
    int size;
    int minimumCost;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX)
    {
        printf("Enter cities between 2 and %d.\n", MAX);
        return 0;
    }

    printf("\nEnter distance matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    size = 1 << n;

    /* Initialize DP and parent arrays */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < n; j++)
        {
            dp[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    /* Start from city 1 */
    minimumCost = tsp(1, 0);

    printf("\nMinimum Travelling Cost = %d\n",
           minimumCost);

    printPath();

    return 0;
}