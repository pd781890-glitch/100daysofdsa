// Day 023 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

struct Node* merge(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void display(struct Node* head) {
    while (head) {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m, val;
    struct Node *list1 = NULL, *list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&list1, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insert(&list2, val);
    }

    struct Node* result = merge(list1, list2);
    display(result);

    return 0;
}