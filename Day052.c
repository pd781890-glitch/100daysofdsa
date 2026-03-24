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

// Recursive function to find LCA in a Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If either n1 or n2 matches the root's key, report 
    // the presence by returning root
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca) return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

    // Build the tree from level-order
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

    struct Node* lca = findLCA(root, n1, n2);
    if (lca) printf("%d\n", lca->data);

    return 0;
}