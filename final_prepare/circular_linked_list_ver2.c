#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
typedef struct list_node {
    int data;
    struct list_node* link;
} list_node;

typedef list_node* list_pointer;
list_pointer concatenate_circular(list_pointer ptr1, list_pointer ptr2);

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

list_pointer searchInt(list_pointer ptr, int searchedValue) {
    list_pointer temp;
   
    if (ptr) {
        temp = ptr->link;
        do {
            if (temp->data == searchedValue) {
                return temp;
            }
            temp = temp->link;
        } while (temp != ptr->link);
    }

    return NULL;
    
}
/*
 Write a function that deletes a node containing a number, num, from a circularly
linked list. Your function should first search for num.
*/
void deleteNode(list_pointer* ptr, int wantedNumber) {
    if (*ptr) {
        list_pointer current = (*ptr)->link; // Start at the first node
        list_pointer prev = *ptr;           // Previous node starts as the last node

        do {
            if (current->data == wantedNumber) {
                if (current == *ptr && current->link == *ptr) {
                    // Case: Deleting the only node in the list
                    free(current);
                    *ptr = NULL;
                    return;
                }
                else if (current == *ptr) {
                    // Case: Deleting the last node
                    prev->link = current->link;
                    *ptr = prev; // Update the last node
                    free(current);
                    return;
                }
                else {
                    // General case: Deleting a middle or first node
                    prev->link = current->link;
                    free(current);
                    return;
                }
            }
            prev = current;
            current = current->link;
        } while (current != (*ptr)->link); // Traverse until we return to the start
    }
    printf("Number %d not found in the list.\n", wantedNumber);
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


    //int search_value = 60;
    int search_value = 30;
    list_pointer result = searchInt(circular_list, search_value);

    if (result) {
        printf("Value %d found in node with address %p\n", search_value, (void*)result);
    }
    else {
        printf("Value %d not found in the list.\n", search_value);
    }

    printf("\n\n**********************************************\n\n");
    // Create two circular lists
    list_pointer list11 = NULL;
    list_pointer list22 = NULL;

    insert_front(&list11, create_node(10));
    insert_front(&list11, create_node(20));
    insert_front(&list11, create_node(30));

    insert_front(&list22, create_node(40));
    insert_front(&list22, create_node(50));
    insert_front(&list22, create_node(60));

    printf("List 1: ");
    print_circular_list(list11);

    printf("List 2: ");
    print_circular_list(list22);

    // Concatenate the lists
    list_pointer concatenated = concatenate_circular(list11, list22);
    printf("Concatenated list: ");
    print_circular_list(concatenated);

    return 0;
}


// Function to concatenate two circular linked lists where each pointer points 
// to the last node of the respective list. The concatenated list merges the 
// two input lists, and the inputs no longer exist as separate lists. 
// Returns a pointer to the last node of the resulting list.

list_pointer concatenate_circular(list_pointer ptr1, list_pointer ptr2) {
    // If both lists are empty, the result is also empty
    if (!ptr1 && !ptr2) return NULL;

    // If only ptr1 is empty, return ptr2 as the result
    if (!ptr1) return ptr2;

    // If only ptr2 is empty, return ptr1 as the result
    if (!ptr2) return ptr1;

    // Both lists are non-empty, concatenate them
    list_pointer temp1 = ptr1->link; // First node of list 1
    list_pointer temp2 = ptr2->link; // First node of list 2

    // Connect the last node of list 1 to the first node of list 2
    ptr1->link = temp2;

    // Connect the last node of list 2 to the first node of list 1
    ptr2->link = temp1;

    // Return the new last node, which is ptr2
    return ptr2;
}


// Function to reverse the direction of pointers in a circular linked list
list_pointer reverseCircularList(list_pointer last) {
    if (last == NULL || last->link == last) {
        // Empty list or single-node list
        return last;
    }

    list_pointer prev = last, curr = last->link, next = NULL;

    do {
        next = curr->link; // Store the next node
        curr->link = prev; // Reverse the link
        prev = curr;       // Move prev forward
        curr = next;       // Move curr forward
    } while (curr != last->link); // Stop when we complete the circle

    last->link = prev; // Update the last node's link
    return prev;       // Return the new last node
}
