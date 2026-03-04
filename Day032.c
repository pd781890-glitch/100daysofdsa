#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int n, m, val;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        pop();
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    return 0;
}