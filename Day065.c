#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// Structure for Graph
struct Graph {
    struct Node* adj[MAX_NODES];
    bool visited[MAX_NODES];
    int numVertices;
};

// Function to create a new node
struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge (Undirected)
void addEdge(struct Graph* g, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = g->adj[src];
    g->adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adj[dest];
    g->adj[dest] = newNode;
}

// DFS function to detect cycle
bool isCyclicUtil(struct Graph* g, int v, int parent) {
    g->visited[v] = true;

    struct Node* temp = g->adj[v];
    while (temp != NULL) {
        int neighbor = temp->dest;

        // If neighbor is not visited, recurse
        if (!g->visited[neighbor]) {
            if (isCyclicUtil(g, neighbor, v))
                return true;
        }
        // If neighbor is visited and not the parent, cycle found
        else if (neighbor != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Main function to check all components of the graph
void detectCycle(struct Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        g->visited[i] = false;
    }

    for (int i = 0; i < g->numVertices; i++) {
        if (!g->visited[i]) {
            if (isCyclicUtil(g, i, -1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->numVertices = 5;

    for (int i = 0; i < 5; i++) g->adj[i] = NULL;

    // Example: A graph with a cycle (0-1, 1-2, 2-0)
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 3, 4);

    detectCycle(g);

    return 0;
}