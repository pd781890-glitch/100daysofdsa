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

// Recursive function to find the height
int getHeight(struct Node* node) {
    if (node == NULL) return 0;
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

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

    printf("%d\n", getHeight(root));

    return 0;
}