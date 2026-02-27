// Day 027 of #100daysofdsa
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

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void findIntersection(struct Node* h1, struct Node* h2) {
    int l1 = getLength(h1);
    int l2 = getLength(h2);
    int diff = abs(l1 - l2);

    struct Node *temp1 = h1, *temp2 = h2;

    if (l1 > l2) {
        for (int i = 0; i < diff; i++) temp1 = temp1->next;
    } else {
        for (int i = 0; i < diff; i++) temp2 = temp2->next;
    }

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            printf("%d\n", temp1->data);
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    printf("No Intersection\n");
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

    findIntersection(list1, list2);

    return 0;
}