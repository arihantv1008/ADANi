#include <stdio.h>

// Stores topological order
int temp[10], k = 0;

// Topological Sort Function using Indegree Method
void sort(int a[][10], int indegree[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        // Find node with 0 indegree
        if (indegree[i] == 0) {
            indegree[i] = -1; // Mark as visited
            temp[++k] = i;     // Add to result

            // Decrease indegree of adjacent nodes
            for (j = 1; j <= n; j++) {
                if (a[i][j] == 1 && indegree[j] != -1)
                    indegree[j]--;
            }

            i = 0; // Restart loop to find next 0 indegree node
        }
    }
}

int main()
{
    int a[10][10], indegree[10], n, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize indegree array
    for (i = 1; i <= n; i++)
        indegree[i] = 0;

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                indegree[j]++;
        }
    }

    // Call sort to compute topological ordering
    sort(a, indegree, n);

    // Check and print result
    if (k != n)
        printf("Topological ordering not possible (Graph has a cycle)\n");
    else {
        printf("Topological ordering is: ");
        for (i = 1; i <= k; i++)
            printf("%d ", temp[i]);
        printf("\n");
    }

    return 0;
}
