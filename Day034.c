#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    struct Node* stack = NULL;
    char exp[100];
    scanf("%[^\n]s", exp);

    char* token = strtok(exp, " ");
    while (token != NULL) {
        // If token is a number (handles negative numbers too)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            
            switch (token[0]) {
                case '+': push(&stack, op1 + op2); break;
                case '-': push(&stack, op1 - op2); break;
                case '*': push(&stack, op1 * op2); break;
                case '/': push(&stack, op1 / op2); break;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", pop(&stack));
    return 0;
}