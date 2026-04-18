#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e18

typedef struct Edge { 
    int to;
    int weight; 
    struct Edge* next;
} Edge;

typedef struct {
    int node;
    long long dist; 
} HeapNode;

// Global adjacency list
Edge* adj[200005];
long long dist[200005];
bool visited[200005];

void add_edge(int u, int v, int w) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->to = v;
    new_edge->weight = w;
    new_edge->next = adj[u];
    adj[u] = new_edge;
}

// Simple Min-Heap Implementation
HeapNode heap[1000005];
int heapSize = 0;

void push(int node, long long d) {
    heap[++heapSize] = (HeapNode){node, d};
    int cur = heapSize;
    while (cur > 1 && heap[cur].dist < heap[cur / 2].dist) {
        HeapNode temp = heap[cur];
        heap[cur] = heap[cur / 2];
        heap[cur / 2] = temp;
        cur /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];
    int cur = 1;
    while (cur * 2 <= heapSize) {
        int next = cur * 2;
        if (next + 1 <= heapSize && heap[next + 1].dist < heap[next].dist) next++;
        if (heap[cur].dist <= heap[next].dist) break;
        HeapNode temp = heap[cur];
        heap[cur] = heap[next];
        heap[next] = temp;
        cur = next;
    }
    return top;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    for (int i = 1; i <= n; i++) dist[i] = INF;

    long long mst_weight = 0;
    int nodes_count = 0;

    // Start from node 1
    dist[1] = 0;
    push(1, 0);

    while (heapSize > 0) {
        HeapNode current = pop();
        int u = current.node;

        if (visited[u]) continue;
        
        visited[u] = true;
        mst_weight += current.dist;
        nodes_count++;

        for (Edge* e = adj[u]; e != NULL; e = e->next) {
            if (!visited[e->to] && e->weight < dist[e->to]) {
                dist[e->to] = e->weight;
                push(e->to, dist[e->to]);
            }
        }
    }

    printf("%lld\n", mst_weight);

    return 0;
}