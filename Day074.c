#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparison function for qsort to sort names alphabetically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for n strings
    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(100 * sizeof(char)); // Assuming max name length 100
        scanf("%s", votes[i]);
    }

    // Sort the names alphabetically
    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int max_votes = 0;
    
    int current_votes = 1;
    char *current_candidate = votes[0];

    for (int i = 1; i <= n; i++) {
        // If it's the same name as the previous one, increment count
        if (i < n && strcmp(votes[i], votes[i - 1]) == 0) {
            current_votes++;
        } else {
            // New name encountered or reached end: check if current candidate won
            // Since array is sorted, the first one we hit with the max count
            // is automatically the lexicographically smallest.
            if (current_votes > max_votes) {
                max_votes = current_votes;
                winner = votes[i - 1];
            }
            if (i < n) {
                current_votes = 1;
            }
        }
    }

    printf("%s %d\n", winner, max_votes);

    // Free allocated memory
    for (int i = 0; i < n; i++) free(votes[i]);
    free(votes);

    return 0;
}