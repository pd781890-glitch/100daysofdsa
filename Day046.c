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

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    // Queue for traversal
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Constructing the tree from input array
    struct Node* root = newNode(arr[0]);
    struct Node* q[n];
    int head = 0, tail = 0;
    q[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = q[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[tail++] = curr->right;
        }
    }

    // Perform traversal
    levelOrder(root);

    return 0;
}