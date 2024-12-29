#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
typedef struct list_node {
    int data;
    struct list_node* link;
} list_node;

typedef list_node* list_pointer;

// Function to reverse a singly linked list
list_pointer reverse(list_pointer lead) {
    list_pointer middle = NULL, trail;
    while (lead) {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

// Function to concatenate two singly linked lists
list_pointer concatenate(list_pointer ptr1, list_pointer ptr2) {
    if (ptr1 == NULL) return ptr2; // If ptr1 is empty, return ptr2
    list_pointer temp = ptr1;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = ptr2; // Attach ptr2 to the last node of ptr1
    return ptr1;
}

// Function to insert a node at the front of a circular linked list
void insert_front(list_pointer* ptr, list_pointer node) {
    if (*ptr == NULL) {
        *ptr = node;
        node->link = node;
    }
    else {
        node->link = (*ptr)->link;
        (*ptr)->link = node;
    }
}

// Function to calculate the length of a circular linked list
int length(list_pointer ptr) {
    list_pointer temp;
    int count = 0;
    if (ptr) {
        temp = ptr->link;
        do {
            count++;
            temp = temp->link;
        } while (temp != ptr->link);
    }
    return count;
}

// Function to create a new node
list_pointer create_node(int data) {
    list_pointer new_node = (list_pointer)malloc(sizeof(list_node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to print a singly linked list
void print_list(list_pointer ptr) {
    while (ptr) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Function to print a circular linked list
void print_circular_list(list_pointer ptr) {
    if (ptr == NULL) {
        printf("Circular list is empty.\n");
        return;
    }
    list_pointer temp = ptr->link; // Start at the first node
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != ptr->link);
    printf("(back to start)\n");
}

int main() {
    // Example 1: Reverse a singly linked list
    printf("Example 1: Reverse a singly linked list\n");
    list_pointer list1 = create_node(10);
    list1->link = create_node(20);
    list1->link->link = create_node(30);
    printf("Original list: ");
    print_list(list1);

    list1 = reverse(list1);
    printf("Reversed list: ");
    print_list(list1);

    // Example 2: Concatenate two singly linked lists
    printf("\nExample 2: Concatenate two singly linked lists\n");
    list_pointer list2 = create_node(40);
    list2->link = create_node(50);
    printf("First list: ");
    print_list(list1);
    printf("Second list: ");
    print_list(list2);

    list1 = concatenate(list1, list2);
    printf("Concatenated list: ");
    print_list(list1);

    // Example 3: Insert nodes at the front of a circular linked list
    printf("\nExample 3: Insert nodes at the front of a circular linked list\n");
    list_pointer circular_list = NULL;
    insert_front(&circular_list, create_node(60));
    insert_front(&circular_list, create_node(70));
    insert_front(&circular_list, create_node(80));
    printf("Circular list: ");
    print_circular_list(circular_list);

    // Example 4: Find the length of a circular linked list
    printf("\nExample 4: Find the length of a circular linked list\n");
    printf("Length of circular list: %d\n", length(circular_list));

    return 0;
}
