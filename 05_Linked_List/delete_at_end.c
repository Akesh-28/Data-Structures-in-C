#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node *next;
};

// Insert at end
void insert_at_end(struct node **head, int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Delete last node
struct node* del_last(struct node *head) {

    // Empty list
    if (head == NULL) {
        return NULL;
    }

    // Single node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Multiple nodes
    struct node *temp = head;
    struct node *temp2 = head;

    while (temp->next != NULL) {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = NULL;
    free(temp);

    return head;
}

// Display list
void display(struct node *head) {

    if (head == NULL) {
        printf("List is empty");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {

    struct node *head = NULL;
    int N, M, value;

    // Input number of tasks
    scanf("%d", &N);

    // Input task IDs
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insert_at_end(&head, value);
    }

    // Number of deletions
    scanf("%d", &M);

    // Perform M deletions
    for (int i = 0; i < M; i++) {
        head = del_last(head);
    }

    // Output updated list
    display(head);

    return 0;
}
