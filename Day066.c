#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

int isCyclicUtil(int v, int visited[], int recStack[], struct Graph* graph) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;

        struct Node* temp = graph->adj[v];
        while (temp != NULL) {
            if (!visited[temp->dest] && isCyclicUtil(temp->dest, visited, recStack, graph))
                return 1;
            else if (recStack[temp->dest])
                return 1;
            temp = temp->next;
        }
    }
    recStack[v] = 0;
    return 0;
}

int isCyclic(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* recStack = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < graph->V; i++) {
        if (isCyclicUtil(i, visited, recStack, graph))
            return 1;
    }
    return 0;
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    if (isCyclic(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}