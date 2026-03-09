#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if (size == MAX) return;
    
    // Find position to insert (maintaining descending order)
    // Smallest element will be at pq[size-1]
    int i;
    for (i = size - 1; i >= 0 && pq[i] < x; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = x;
    size++;
}

void delete() {
    if (size == 0) {
        printf("-1\n");
    } else {
        // The smallest element is at the end (highest priority)
        printf("%d\n", pq[--size]);
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[size - 1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char op[10];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    
    return 0;
}