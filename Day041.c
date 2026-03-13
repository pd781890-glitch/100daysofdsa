#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = q->front;
    printf("%d\n", temp->data);
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int main() {
    struct Queue q = {NULL, NULL};
    int n, val;
    char op[20];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(&q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue(&q);
        }
    }

    return 0;
}