// Day 030 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void insert(struct Node** head, int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void display(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d", ptr->coeff);
        if (ptr->pow != 0) {
            printf("x");
            if (ptr->pow != 1) {
                printf("^%d", ptr->pow);
            }
        }
        ptr = ptr->next;
        if (ptr != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    int n, c, p;
    struct Node* poly = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &p);
        insert(&poly, c, p);
    }

    display(poly);

    return 0;
}