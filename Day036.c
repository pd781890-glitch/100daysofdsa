#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node *front, *rear;
};

void enqueue(struct CircularQueue* q, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    if (q->front == NULL) {
        q->front = temp;
    } else {
        q->rear->next = temp;
    }
    q->rear = temp;
    q->rear->next = q->front; // Make it circular
}

void dequeue(struct CircularQueue* q) {
    if (q->front == NULL) return;
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular link
        free(temp);
    }
}

void display(struct CircularQueue* q) {
    if (q->front == NULL) return;
    struct Node* temp = q->front;
    do {
        printf("%d%s", temp->data, (temp->next == q->front) ? "" : " ");
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    struct CircularQueue q = {NULL, NULL};
    int n, m, val;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);
    return 0;
}