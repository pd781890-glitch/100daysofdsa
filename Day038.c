#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Deque {
    struct Node *front, *rear;
    int count;
};

void initDeque(struct Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->count = 0;
}

void push_front(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (dq->front == NULL) dq->rear = newNode;
    else dq->front->prev = newNode;
    dq->front = newNode;
    dq->count++;
}

void push_back(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (dq->rear == NULL) dq->front = newNode;
    else dq->rear->next = newNode;
    dq->rear = newNode;
    dq->count++;
}

void pop_front(struct Deque* dq) {
    if (dq->front == NULL) return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
    dq->count--;
}

void pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
    dq->count--;
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initDeque(&dq);
    int n, val;
    char op[20];

    // Example sequence of operations
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_back") == 0) {
            scanf("%d", &val);
            push_back(&dq, val);
        } else if (strcmp(op, "push_front") == 0) {
            scanf("%d", &val);
            push_front(&dq, val);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back(&dq);
        }
    }

    display(&dq);
    return 0;
}