#include <stdio.h>

#define MAX 100

void displayMatrix(int matrix[MAX][MAX], int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, type;
    int adjMatrix[MAX][MAX] = {0}; // Initialize all elements to 0

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter graph type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &type);

    printf("Enter %d pairs of edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Standard check to prevent array overflow
        if (u < n && v < n) {
            adjMatrix[u][v] = 1;
            
            // If undirected, add the reverse edge as well
            if (type == 0) {
                adjMatrix[v][u] = 1;
            }
        } else {
            printf("Invalid edge! Vertices must be between 0 and %d\n", n - 1);
            i--; // Decrement to retry this edge input
        }
    }

    displayMatrix(adjMatrix, n);

    return 0;
}