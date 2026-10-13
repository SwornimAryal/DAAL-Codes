// Hamiltonian Cycle in a Graph
#include <stdio.h>

int n;
int graph[20][20];
int path[20];

int isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;
}

int hamCycle(int pos) {
    if (pos == n) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamCycle(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamCycle(1)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < n; i++)
            printf("%d -> ", path[i] + 1);
        printf("%d\n", path[0] + 1);
    } else {
        printf("No Hamiltonian Cycle exists.\n");
    }

    return 0;
}