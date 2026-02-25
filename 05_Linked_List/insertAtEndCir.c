#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtEnd(struct node **tail, int value) {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    // Case 1: Empty List
    if (*tail == NULL) {
        *tail = ptr;
        ptr->next = ptr;
        return;
    }
    ptr->next = (*tail)->next;
    (*tail)->next = ptr;
    *tail = ptr;
}

void deleteAtEnd(struct node **tail) {
    // Case 1: Empty List
    if (*tail == NULL) {
        printf("\nList is empty");
        return;
    }
    // Case 2: Only One Node
    if ((*tail)->next == *tail) {
        free(*tail);
        *tail = NULL;
        return;
    }
    // Case 3: Multiple Nodes
    struct node *temp = (*tail)->next;
    while (temp->next != *tail) {
        temp = temp->next;
    }
    temp->next = (*tail)->next;
    free(*tail);
    *tail = temp;
}

void display(struct node *tail) {
    if (tail == NULL) {
        printf("\nList is empty");
        return;
    }
    struct node *temp = tail->next;
    printf("\nCircular Linked List:\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}

int main() {
    struct node *tail = NULL;
    int n, value;
    printf("How many nodes? ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        insertAtEnd(&tail, value);
    }
    display(tail);
    deleteAtEnd(&tail);
    printf("\nAfter Deletion at End:");
    display(tail);
    return 0;
}
