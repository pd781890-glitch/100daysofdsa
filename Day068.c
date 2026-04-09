#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int count = 0;

    if (scanf("%d %d", &n, &e) != 2) return 0;

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo_order[MAX];
    int k = 0;

    while (front < rear) {
        int u = queue[front++];
        topo_order[k++] = u;
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != n) {
        printf("The graph contains a cycle.\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    return 0;
}