// Day 028 of #100daysofdsa
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) printf(" ");
    } while (temp != head);
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&head, val);
    }

    display(head);

    return 0;
}