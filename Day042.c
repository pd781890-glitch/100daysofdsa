#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int dequeue() {
    return queue[front++];
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    // Step 1: Input into Queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    // Step 2: Queue -> Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 3: Stack -> Queue (Reset pointers for clarity)
    front = 0; rear = -1;
    while (top != -1) {
        enqueue(pop());
    }

    // Step 4: Display Reversed Queue
    for (int i = front; i <= rear; i++) {
        printf("%d%s", queue[i], (i == rear) ? "" : " ");
    }
    printf("\n");

    return 0;
}