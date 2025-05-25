#include <stdio.h>

int ne = 1, min_cost = 0;

void main() {
    int n, i, j, min, a, u, b, v;
    int cost[20][20], parent[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nThe edges of the spanning tree are:\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the root of u
        while (parent[u])
            u = parent[u];
        // Find the root of v
        while (parent[v])
            v = parent[v];

        // If they belong to different sets
        if (u != v) {
            printf("Edge %d: (%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;  // Union
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
