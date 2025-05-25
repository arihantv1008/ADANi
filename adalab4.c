#include <stdio.h>
#define INF 999  // Representing infinity

// Dijkstra's algorithm to find shortest paths from source 's'
void dijkstra(int c[10][10], int n, int s, int d[10]) {
    int v[10], min, u, i, j;

    // Initialize distance and visited arrays
    for(i = 1; i <= n; i++) {
        d[i] = c[s][i];  // Distance from source to each vertex
        v[i] = 0;        // 0 means not visited
    }

    v[s] = 1;  // Mark source as visited

    // Loop to find shortest path to remaining n-1 vertices
    for(i = 1; i < n; i++) {
        min = INF;

        // Find the unvisited vertex with the smallest distance
        for(j = 1; j <= n; j++) {
            if(v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;  // Mark vertex u as visited

        // Update distances of neighbors of u
        for(j = 1; j <= n; j++) {
            if(v[j] == 0 && (d[u] + c[u][j] < d[j])) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main() {
    int c[10][10], d[10], i, j, s, n;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the cost matrix (use 999 for no direct edge):\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);

    // Input source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &s);

    // Run Dijkstra's algorithm
    dijkstra(c, n, s, d);

    // Print shortest distances
    printf("\nShortest distances from node %d:\n", s);
    for(i = 1; i <= n; i++)
        printf("To node %d: %d\n", i, d[i]);

    return 0;
}
