#include <stdio.h>

#define INF 999  // Represents infinity for unreachable paths

// Prim's Algorithm Function
int prim(int c[10][10], int n, int s) {
    int v[10], i, j, sum = 0, ver[10], d[10], min, u;

    // Initialization
    for (i = 1; i <= n; i++) {
        ver[i] = s;        // Initial parent of all vertices is source
        d[i] = c[s][i];    // Distance from source
        v[i] = 0;          // Mark all nodes as unvisited
    }
    v[s] = 1;  // Mark the source node as visited

    // Repeat to select n-1 edges
    for (i = 1; i <= n - 1; i++) {
        min = INF;

        // Find the minimum cost edge from visited to unvisited
        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;           // Mark selected vertex as visited
        sum += d[u];        // Add cost of this edge to total
        printf("\n%d -> %d  | Cost: %d", ver[u], u, d[u]);

        // Update distances for remaining vertices
        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
        }
    }

    return sum;  // Total cost of MST
}

int main() {
    int c[10][10], i, j, res, s, n;

    // Input: number of nodes
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    // Input: adjacency matrix
    printf("\nEnter the adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0)  // Replace 0s with INF
                c[i][j] = INF;
        }
    }

    // Input: source node
    printf("\nEnter the source node (1 to %d): ", n);
    scanf("%d", &s);

    // Call Prim’s algorithm
    res = prim(c, n, s);
    printf("\n\nTotal cost of Minimum Spanning Tree = %d\n", res);

    return 0;  // End of program
}
