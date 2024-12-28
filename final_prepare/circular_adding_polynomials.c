#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct poly_node {
    int coefficient;
    int exponent;
    struct poly_node* link;
} poly_node;

typedef struct poly_node* poly_pointer;

int COMPARE(int a, int b) {
    if (a < b) return -1;
    else if (a == b) return 0;
    else return 1;
}

poly_pointer avail = NULL; // avail a.k.a available

poly_pointer get_node() {
    // provide a node for use

    poly_pointer node;
    if (avail) {
        node = avail;
        avail = avail->link;
    }
    else {
        node = (poly_pointer)malloc(sizeof(poly_node));

    }
    return node;
}

void ret_node(poly_pointer ptr) {
    // return a node to the available list
    ptr->link = avail;
    avail = ptr;
}

void cerase(poly_pointer* ptr) {
    // erase the circular list ptr
    poly_pointer temp;
    if (*ptr) {
        temp = (*ptr)->link;
        (*ptr)->link = avail;
        avail = temp;
        *ptr = NULL;
    }
}

void attach(int coefficient, int exponent, poly_pointer* rear) {
    poly_pointer temp;
    temp = (poly_pointer)malloc(sizeof(poly_node));
    temp->coefficient = coefficient;
    temp->exponent = exponent;
    temp->link = NULL;
    (*rear)->link = temp;
    *rear = temp;
}

// Function to add two polynomials--circular
poly_pointer padd(poly_pointer a, poly_pointer b) {
    poly_pointer front, rear, temp;
    int sum;

    poly_pointer starta = a; // new variables
    poly_pointer startb = b; // new variables

    a = a->link; // assign a = a->link
    b = b->link;// assign b = b->link

    // Create a dummy node to start the result list
    rear = (poly_pointer)malloc(sizeof(poly_node));
    
    rear->link = NULL;
    front = rear;

    // Traverse through both polynomials and add them term by term
    while (a != starta && b != startb) { // changed from while (a & b)
        switch (COMPARE(a->exponent, b->exponent)) {
        case -1: // a->exponent < b->exponent
            attach(b->coefficient, b->exponent, &rear);
            b = b->link;
            break;
        case 0: // a->exponent == b->exponent
            sum = a->coefficient + b->coefficient;
            if (sum) { // Only attach if the sum is not zero
                attach(sum, a->exponent, &rear);
            }
            a = a->link;
            b = b->link;
            break;
        case 1: // a->exponent > b->exponent
            attach(a->coefficient, a->exponent, &rear);
            a = a->link;
            break;
        }
    }

    // Copy remaining terms from a or b
    for (; a != starta; a = a->link) { // not circular: for (; a; a = a->link)
        attach(a->coefficient, a->exponent, &rear);
    }
    for (; b != startb; b = b->link) { // not circular: for (; b; b = b->link)
        attach(b->coefficient, b->exponent, &rear);
    }

   

    rear->link = front; // circular
    /* not circular
    * temp = front;
    front = front->link;
    free(temp);
    */
    return front;
}
