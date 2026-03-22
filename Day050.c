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

// Function to search a key in a BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's data
    if (root->data < key)
        return search(root->right, key);
 
    // Key is smaller than root's data
    return search(root->left, key);
}

int main() {
    int n, val, target;
    struct Node* root = NULL;

    // Input: Number of elements to build the tree
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: Target value to find
    scanf("%d", &target);

    struct Node* result = search(root, target);

    if (result != NULL)
        printf("Present\n");
    else
        printf("Not Present\n");

    return 0;
}