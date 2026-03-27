#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void printRightView(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++) {
            struct Node* current = queue[head++];

            if (i == levelSize - 1) {
                printf("%d ", current->data);
            }

            if (current->left) queue[tail++] = current->left;
            if (current->right) queue[tail++] = current->right;
        }
    }
}

struct Node* buildTree(int n) {
    if (n <= 0) return NULL;

    int val;
    scanf("%d", &val);
    struct Node* root = newNode(val);
    if (!root) return NULL;

    struct Node* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;

    int count = 1;
    while (count < n && head < tail) {
        struct Node* current = queue[head++];

        if (count < n) {
            scanf("%d", &val);
            count++;
            if (val != -1) {
                current->left = newNode(val);
                queue[tail++] = current->left;
            }
        }

        if (count < n) {
            scanf("%d", &val);
            count++;
            if (val != -1) {
                current->right = newNode(val);
                queue[tail++] = current->right;
            }
        }
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* root = buildTree(n);
    printRightView(root);
    return 0;
}