#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
void insertAtEnd(struct Node **head, int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (*head == NULL) {
        temp->prev = NULL;
        *head = temp;
        return;
    }
    struct Node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}
void deleteAtEnd(struct Node **head) {
    // Case 1: Empty List
    if (*head == NULL) {
        return;
    }
    // Case 2: Only One Node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    // Case 3: Multiple Nodes
    struct Node *temp = *head;
    struct Node *temp2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
}
void display(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main() {
    struct Node *head = NULL;
    int N, bookID;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &bookID);
        insertAtEnd(&head, bookID);
    }
    deleteAtEnd(&head);
    if (head == NULL) {
        printf("List is empty");
    } else {
        display(head);
    }
    return 0;
}
