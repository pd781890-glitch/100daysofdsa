#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search function to find the index of a value in Inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(int in[], int post[], int inStrt, int inEnd, int* postIndex) {
    // Base case
    if (inStrt > inEnd) return NULL;

    // Pick current node from Postorder traversal using postIndex and decrement it
    struct Node* tNode = newNode(post[(*postIndex)--]);

    // If node has no children, return
    if (inStrt == inEnd) return tNode;

    // Find the index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Build Right subtree before Left subtree for Postorder logic
    tNode->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    tNode->left = buildTree(in, post, inStrt, inIndex - 1, postIndex);

    return tNode;
}

// Function to print preorder traversal
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printPreorder(root);
    printf("\n");

    return 0;
}