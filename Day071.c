#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY || table[pos] == DELETED) {
            table[pos] = key;
            return;
        }
    }
}

int search(int table[], int m, int key) {
    int h = hash(key, m);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            return 0;
        }
        if (table[pos] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    int *table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);
    return 0;
}