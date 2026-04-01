#include <stdio.h>
#include <stdbool.h>

/**
 * Function to check the Min-Heap property.
 * Logic: For every internal node, compare it with its children.
 */
bool isMinHeap(int arr[], int n) {
    // We only need to check nodes that have at least one child.
    // Last internal node is at index (n-2)/2.
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check left child: index 2*i + 1
        if (arr[i] > arr[2 * i + 1]) {
            return false;
        }

        // Check right child: index 2*i + 2 (ensure it exists)
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}