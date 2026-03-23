#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Function to find the LCA in a BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, LCA is in left
    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);

    // If both n1 and n2 are larger than root, LCA is in right
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    // We have found the split point
    return root;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) printf("%d\n", lca->data);

    return 0;
}