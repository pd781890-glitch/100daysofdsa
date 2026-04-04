#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (Undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Recursive DFS Function
void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, startNode;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startNode);

    printf("DFS Traversal starting from %d: ", startNode);
    DFS(graph, startNode);
    printf("\n");

    return 0;
}