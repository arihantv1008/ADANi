#include <stdio.h>
#define INF 999  // Representation of no connection or infinite cost

// Utility function to return minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Floyd–Warshall algorithm to update all-pairs shortest path matrix
void floyd(int p[][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++)       // Intermediate vertex
        for (i = 1; i <= n; i++)   // Source vertex
            for (j = 1; j <= n; j++) // Destination vertex
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int a[10][10], n, i, j;

    // Input number of vertices
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix (use 999 for no edge):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // Apply Floyd–Warshall algorithm
    floyd(a, n);

    // Output the shortest path matrix
    printf("\nShortest path matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
