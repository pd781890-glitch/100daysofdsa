#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

char findFirstNonRepeating(char* s) {
    int count[MAX_CHAR] = {0};
    int i;
    int length = strlen(s);

    // Step 1: Count the frequency of each character
    for (i = 0; i < length; i++) {
        count[(unsigned char)s[i]]++;
    }

    // Step 2: Traverse the string again to find the first char with count 1
    for (i = 0; i < length; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return s[i];
        }
    }

    // Return '$' if no non-repeating character is found
    return '$';
}

int main() {
    char s[100001]; // Adjust size based on expected input constraints

    if (scanf("%s", s) == 1) {
        char result = findFirstNonRepeating(s);
        printf("%c\n", result);
    }

    return 0;
}