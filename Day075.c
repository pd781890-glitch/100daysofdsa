#include <stdio.h>
#include <stdlib.h>

// Simple Hash Map Node
struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define HASH_SIZE 1000

int findLongestZeroSumSubarray(int arr[], int n) {
    struct Node* hashTable[HASH_SIZE] = {NULL};
    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        if (curr_sum == 0) {
            max_len = i + 1;
        } else {
            int hash = abs(curr_sum) % HASH_SIZE;
            struct Node* temp = hashTable[hash];
            int found = 0;
            
            while (temp != NULL) {
                if (temp->sum == curr_sum) {
                    if (i - temp->index > max_len)
                        max_len = i - temp->index;
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if (!found) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->sum = curr_sum;
                newNode->index = i;
                newNode->next = hashTable[hash];
                hashTable[hash] = newNode;
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", findLongestZeroSumSubarray(arr, n));
    return 0;
}