#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {

    // Step 1: Create new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    // Step 2: If list is empty
    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return head;
    }

    // Step 3: Traverse to last node
    struct Node* ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Step 4: Update pointers
    ptr->next = temp;
    temp->prev = ptr;

    return head;
}

void display(struct Node* head) {
    struct Node* ptr = head;

    printf("\nDoubly Linked List:\n");

    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node* head = NULL;
    int n, value;

    printf("How many nodes do you want to insert? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        head = insertAtEnd(head, value);
    }

    display(head);

    return 0;
}
