//Prism Algorithm
#include <iostream>
#include <climits>
using namespace std;
const int V = 5;
int minKey(int key[], bool inMST[])
{
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < V; i++)
    {
        if (!inMST[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool inMST[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, inMST);
        inMST[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !inMST[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[parent[i]][i] << endl;
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
    return 0;
}
