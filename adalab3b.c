#include <stdio.h>

// Warshall's algorithm for transitive closure
void warshall(int p[][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main() {
    int a[10][10], n, i, j;

    // Input: number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input: adjacency matrix
    printf("\nEnter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // Apply Warshall's algorithm
    warshall(a, n);

    // Output: Transitive closure matrix (path matrix)
    printf("\nTransitive Closure (Path Matrix):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
