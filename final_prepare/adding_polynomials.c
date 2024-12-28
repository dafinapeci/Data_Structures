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

void attach(int coefficient, int exponent, poly_pointer* rear) {
    poly_pointer temp;
    temp = (poly_pointer)malloc(sizeof(poly_node));
    temp->coefficient = coefficient;
    temp->exponent = exponent;
    temp->link = NULL;
    (*rear)->link = temp;
    *rear = temp;
}

poly_pointer addPolynomial(poly_pointer a, poly_pointer b) {
    poly_pointer front, rear, temp;
    int sum;

    rear = (poly_pointer)malloc(sizeof(poly_node));
    rear->link = NULL;
    front = rear;

    while (a && b) {
        switch (COMPARE(a->exponent, b->exponent)) {
        case -1: // a->exponent < b->exponent
            attach(b->coefficient, b->exponent, &rear);
            b = b->link;
            break;
        case 0: // a->exponent == b->exponent
            sum = a->coefficient + b->coefficient;
            if (sum) attach(sum, a->exponent, &rear);
            a = a->link;
            b = b->link;
            break;
        case 1: // a->exponent > b->exponent
            attach(a->coefficient, a->exponent, &rear);
            a = a->link;
            break;
        }
    }

    // Copy remaining terms
    while (a) {
        attach(a->coefficient, a->exponent, &rear);
        a = a->link;
    }
    while (b) {
        attach(b->coefficient, b->exponent, &rear);
        b = b->link;
    }

    temp = front;
    front = front->link;
    free(temp);

    return front;
}

void printPolynomial(poly_pointer poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->link;
        if (poly) printf(" + ");
    }
    printf("\n");
}

int main() {
    poly_pointer a, b, result, rear;

    // Initialize polynomial a: 3x^4 + 2x^3 + x
    a = (poly_pointer)malloc(sizeof(poly_node));
    a->link = NULL;
    rear = a;
    attach(3, 4, &rear);
    attach(2, 3, &rear);
    attach(1, 1, &rear);
    a = a->link; // Skip the dummy node

    // Initialize polynomial b: 4x^3 + 1x^2 + 5
    b = (poly_pointer)malloc(sizeof(poly_node));
    b->link = NULL;
    rear = b;
    attach(4, 3, &rear);
    attach(1, 2, &rear);
    attach(5, 0, &rear);
    b = b->link; // Skip the dummy node

    // Add polynomials
    result = addPolynomial(a, b);

    // Print polynomials
    printf("Polynomial A: ");
    printPolynomial(a);
    printf("Polynomial B: ");
    printPolynomial(b);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
