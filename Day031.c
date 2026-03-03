#include <stdio.h>
#define MAX 1000

int main() {
    int n, top = -1, stack[MAX], op, val;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &val);
            if (top < MAX - 1) stack[++top] = val;
        } else if (op == 2) {
            if (top == -1) printf("Stack Underflow\n");
            else printf("%d\n", stack[top--]);
        } else if (op == 3) {
            for (int i = top; i >= 0; i--) 
                printf("%d%s", stack[i], (i == 0 ? "" : " "));
            printf("\n");
        }
    }
    return 0;
}