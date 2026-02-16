#include <stdio.h>
#include <stdlib.h>
// Singly Linked List Implementation Steps:
// Step1. Define Node Structure
// Step2. Create Head Pointer
// Step3. Create New Nodes Dynamically
// Step4. Assign data to the new Node
// Step5. Connect Node to the list

// Step1: Define Node Structure
struct node{
    int data;
    struct node *next;
};

// Function to create a new node

struct node *createNode(int value){
struct node *newNode;

// allocate memory dynamically
newNode = (struct node*) malloc(sizeof(struct node));

if(newNode == NULL){
    printf("Memory allocation failed\n");
    return NULL;
}
// Assign Data
newNode->data = value;
newNode->next = NULL;
return newNode;
}

// Traversing a Singly Linked List: print data
    void print_data(struct node *head){
        if(head == NULL){
            printf("Linked List is empty"); 
            return;
        }    
        struct node *temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }    
    }

int main(){

    // Singly linked list with four nodes: 10, 34, 58, 78
    // step2: create head pointer
    struct node *head = NULL;
    struct node *first = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;

    // // step3: Create Nodes Dynamically (allocate memory)
    first = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    //step4: assign data and link nodes
    first->data = 10;
    first->next = second;
    
    second->data = 34;
    second->next = third;

    third->data = 58;
    third->next = fourth;

    fourth->data = 78;
    fourth->next = NULL;

    // Head points to first node
    head = first;

    //step5: print linked list
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return 0;
    // we can use any one of the above, step5 code or print_data function to print all linkedlist elements
    // print_data(head);
    
    
    // --------------------------------------------

    // Method 2: This is optimized version of above code, here we will use only two pointers
    
    // struct node *head = (struct node*) malloc(sizeof(struct node));
    // head->data = 40;
    // head->next = NULL;

    // struct node *current = (struct node*) malloc(sizeof(struct node));
    // current->data = 98;
    // current->next = NULL;
    // head->next = current;

    // //create node for 3
    // current = malloc(sizeof(struct node));
    // current->data = 3;
    // current->next = NULL;
    // head->next->next = current;

    // //create node for 20
    // current = malloc(sizeof(struct node));
    // current -> data = 20;
    // current->next = NULL;
    // head->next->next->next = current; 
     
    // print_data(head);
    // return 0;

    // --------------------------------------------


}
