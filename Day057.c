#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to swap left and right children recursively
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Standard swap using a temporary pointer
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse for both subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder Traversal to verify the result
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Level-order tree construction for the given input format
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    
    queue[tail++] = root;
    int i = 1;

    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        // Process Left Child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[tail++] = current->left;
        }
        i++;

        // Process Right Child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[tail++] = current->right;
        }
        i++;
    }
    free(queue);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    // Perform Mirroring
    mirror(root);
    
    // Output the Mirrored Inorder Traversal
    inorder(root);
    printf("\n");

    free(arr);
    return 0;
}