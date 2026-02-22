#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node *link;
};

// Insert at end
void insert_at_end(struct node **head, int data) {

    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// Delete at specific position
void del_pos(struct node **head, int position) {

    struct node *current = *head;
    struct node *previous = *head;

    // Case 1: Empty list
    if (*head == NULL) {
        printf("List is empty");
        return;
    }

    // Case 2: Delete first node
    if (position == 1) {
        *head = current->link;
        free(current);
        current = NULL;
        return;
    }

    // Case 3: Traverse safely
    while (position != 1) {

        previous = current;
        current = current->link;
        position--;

        if (current == NULL) {
            printf("Position out of range");
            return;
        }
    }

    previous->link = current->link;
    free(current);
    current = NULL;
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
        ptr = ptr->link;
    }
}

int main() {

    struct node *head = NULL;
    int N, P, value;

    scanf("%d", &N);

    // Insert elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insert_at_end(&head, value);
    }

    scanf("%d", &P);

    // Delete at position
    del_pos(&head, P);

    // Print only if list exists
    if (head != NULL)
        display(head);

    return 0;
}
