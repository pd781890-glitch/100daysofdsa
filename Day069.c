#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node heap[MAX * MAX];
    int size;
} PriorityQueue;

void push(PriorityQueue *pq, int v, int dist) {
    int i = pq->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq->heap[p].dist <= dist) break;
        pq->heap[i] = pq->heap[p];
        i = p;
    }
    pq->heap[i].v = v;
    pq->heap[i].dist = dist;
}

Node pop(PriorityQueue *pq) {
    Node res = pq->heap[0];
    Node last = pq->heap[--pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) {
        int a = i * 2 + 1, b = i * 2 + 2, c = a;
        if (b < pq->size && pq->heap[b].dist < pq->heap[a].dist) c = b;
        if (pq->heap[c].dist >= last.dist) break;
        pq->heap[i] = pq->heap[c];
        i = c;
    }
    pq->heap[i] = last;
    return res;
}

void dijkstra(int adj[MAX][MAX], int n, int start, int dist[MAX]) {
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[start] = 0;

    PriorityQueue pq = { .size = 0 };
    push(&pq, start, 0);

    while (pq.size > 0) {
        Node top = pop(&pq);
        int u = top.v;
        int d = top.dist;

        if (d > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(&pq, v, dist[v]);
                }
            }
        }
    }
}

int main() {
    int n, e, u, v, w, start;
    int adj[MAX][MAX] = {0};
    int dist[MAX];

    if (scanf("%d %d", &n, &e) != 2) return 0;

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; 
    }

    scanf("%d", &start);
    dijkstra(adj, n, start, dist);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d: INF\n", i);
        else printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}