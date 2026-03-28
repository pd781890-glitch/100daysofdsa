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

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->data == t2->data) && 
           isMirror(t1->left, t2->right) && 
           isMirror(t1->right, t2->left);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n == 0) {
        printf("YES\n");
        return 0;
    }
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = buildTree(arr, n);
    if (isMirror(root, root)) printf("YES\n");
    else printf("NO\n");
    
    free(arr);
    return 0;
}