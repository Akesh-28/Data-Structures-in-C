#include <stdio.h>
#include <stdlib.h>
/*
You are developing a simple task management application where tasks are represented by unique IDs. Users can 
add new tasks at the beginning of the task list for quick access. You need to write a program to handle the 
insertion of task IDs at the beginning of a linked list. After all insertions are completed, the final list of task IDs
should be printed to confirm the additions.
Write a program to insert new task IDs at the beginning of the linked list. 
After all insertions, print the entire linked list to show the updatedlist of task IDs.
*/
// Insert at the beginning
struct node{
    int data;
    struct node *next;
};

// Function to add at beginning
void add_at_beginning(struct node **head, int value){
    // create a new node
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    // assign data
    newNode->data = value;
    // link new node to current node
    newNode->next = *head;
    // update head to new node
    *head = newNode;
}

// Function to print linked list
void print_data(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int N, id;
    struct node *head = NULL;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &id);
        add_at_beginning(&head, id);
    }

    print_data(head);
    return 0;
}
