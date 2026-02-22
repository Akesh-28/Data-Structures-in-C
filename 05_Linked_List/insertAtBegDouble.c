#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;

    // Diagram logic
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

void display(struct Node* head) {
    struct Node* ptr = head;
    printf("\nDoubly Linked List:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, value;
    printf("How many nodes do you want to insert? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        head = insertAtBeginning(head, value);
    }
    display(head);
    return 0;
}
