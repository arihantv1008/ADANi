#include <stdio.h>
#define MAX 50

int p[MAX], w[MAX];   // Profit and Weight arrays
double x[MAX];        // Solution vector (fraction of items taken)
double maxprofit = 0; // Total profit
int n, m, i;

// Greedy approach for fractional knapsack
void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX];

    // Step 1: Calculate profit-to-weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = (double)p[i] / w[i];
    }

    // Step 2: Sort items by ratio in non-increasing order
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weights
                int tempW = w[i];
                w[i] = w[j];
                w[j] = tempW;

                // Swap profits
                int tempP = p[i];
                p[i] = p[j];
                p[j] = tempP;
            }
        }
    }

    int currentWeight = 0;
    maxprofit = 0.0;

    // Step 3: Add items to knapsack
    for (i = 0; i < n; i++) {
        if (currentWeight + w[i] <= m) {
            x[i] = 1.0; // Take full item
            currentWeight += w[i];
            maxprofit += p[i];
        } else {
            // Take fractional part
            x[i] = (double)(m - currentWeight) / w[i];
            maxprofit += x[i] * p[i];
            break; // Knapsack is full
        }
    }

    // Output results
    printf("\nOptimal profit for greedy method: %.2f\n", maxprofit);
    printf("Solution vector (fractions of items taken):\n");
    for (i = 0; i < n; i++)
        printf("%.2f\t", x[i]);
    printf("\n");
}

int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of the objects: ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of the objects: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the maximum knapsack capacity: ");
    scanf("%d", &m);

    greedyKnapsack(n, w, p, m);
    return 0;
}
