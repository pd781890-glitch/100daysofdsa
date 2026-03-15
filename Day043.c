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

// Inorder Traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* current = queue[front++];

        // Left Child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }

        // Right Child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }

    inorder(root);
    printf("\n");

    return 0;
}