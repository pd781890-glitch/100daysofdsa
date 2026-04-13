#include <stdio.h>
#include <string.h>

char find_first_repeated(char* input_str) {
    int char_tracker[26] = {0};

    for (int current_index = 0; input_str[current_index] != '\0'; current_index++) {
        int alphabet_index = input_str[current_index] - 'a';

        if (char_tracker[alphabet_index] > 0) {
            return input_str[current_index];
        }

        char_tracker[alphabet_index]++;
    }

    return '\0';
}

int main() {
    char user_input[100];

    if (scanf("%99s", user_input) == 1) {
        char repeated_char = find_first_repeated(user_input);

        if (repeated_char != '\0') {
            printf("%c\n", repeated_char);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}