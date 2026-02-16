#include <stdio.h>
#include <stdlib.h>
/* Problem: 
You are working on a real-time inventory management system where you need to maintain a list of product IDs 
in a linked list. As new products are added to the inventory, their IDs are appended at the end of the list. 
You have been tasked with writing a program to handle this operation.
Write a program to insert a new product ID at the end of the linked list. After the completion of insertion, 
print the entire linked list to confirm that the new ID has been added.
*/
// Insert at the End
struct node{
    int data;
    struct node *next;
};

void insert_at_end(struct node **head, int data){
    struct node *temp, *ptr;
    // create a node
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    // Check if list is empty
    if(*head == NULL){
        *head = temp;
        return;
    }
    // Traverse to the last
    ptr = *head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    // Attach new node
    ptr->next = temp;
}

// Function to print linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int N;
    int id;
    struct node *head = NULL;
    scanf("%d", &N);    // input no of product ids
    
    for(int i=0; i<N; i++){ // input all product ids & insert at end
        scanf("%d", &id);
        insert_at_end(&head, id);
    }

    print_list(head);   //output list
    return 0;

}
