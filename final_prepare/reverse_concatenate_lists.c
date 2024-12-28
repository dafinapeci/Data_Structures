#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
typedef struct list_node {
    char data;
    struct list_node* link;
} list_node;

typedef list_node* list_pointer;

// Function to create a new node with given data
list_pointer get_node(char data) {
    list_pointer new_node = (list_pointer)malloc(sizeof(list_node));
    if (new_node != NULL) {
        new_node->data = data;
        new_node->link = NULL;
    }
    return new_node;
}

// Function to print the linked list
void print_list(list_pointer head) {
    list_pointer current = head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverse_list(list_pointer* head) {
    list_pointer prev = NULL;
    list_pointer current = *head;
    list_pointer next = NULL;

    while (current != NULL) {
        next = current->link;  // Store the next node
        current->link = prev;  // Reverse the link
        prev = current;        // Move prev and current one step forward
        current = next;
    }
    *head = prev;  // Update the head to point to the new first node
}

// Function to concatenate two linked lists
void concatenate_lists(list_pointer* head1, list_pointer head2) {
    if (*head1 == NULL) {
        *head1 = head2;  // If first list is empty, just set head1 to head2
    }
    else {
        list_pointer current = *head1;
        while (current->link != NULL) {
            current = current->link;  // Traverse to the last node of list1
        }
        current->link = head2;  // Link the last node of list1 to head2
    }
}

// Main function to test the operations
int main() {
    // Test for reversing a linked list
    list_pointer list1 = get_node('A');
    list1->link = get_node('B');
    list1->link->link = get_node('C');

    printf("Original list 1: ");
    print_list(list1);

    reverse_list(&list1);

    printf("Reversed list 1: ");
    print_list(list1);

    // Test for concatenating two linked lists
    list_pointer list2 = get_node('X');
    list2->link = get_node('Y');
    list2->link->link = get_node('Z');

    printf("Original list 2: ");
    print_list(list2);

    concatenate_lists(&list1, list2);

    printf("Concatenated list: ");
    print_list(list1);

    return 0;
}
