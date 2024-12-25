#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int array[MAX_SIZE];

int theSize = 0; // item count of heap

int isEmpty() {
	if (theSize > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

// method to percolate down in the heap
// hole is the index at which the percolate begins
void percolateDown_recursive(int hole, int tmp) {
	// Base case: If the current hole has no children (it's a leaf), stop recursion.
	if (hole * 2 > theSize) {
		array[hole] = tmp; // Place tmp in the current hole.
		return;            // End the recursion.
	}

	int child;
	child = hole * 2; // Left child of the current hole.

	// If there is a right child and it's smaller than the left child,
	// choose the right child as the smaller child to swap with.
	if (child != theSize && array[child + 1] < array[child]) {
		child++;
	}

	// If the smaller child is less than tmp, move the child up to the current hole.
	if (array[child] < tmp) {
		array[hole] = array[child]; // Move the smaller child up.
	}

	// Recur for the next hole (child index) to continue percolating down.
	percolateDown_recursive(child, tmp);
}

// insert function, maintain heap order ( P >= x ) P: parent, x: child
// duplicates allowed
// recursive function
void insert_recursive(int x, int hole) {
	// Base case: If x is greater than or equal to its parent, it's in the correct position.
	if (x > array[hole / 2]) {
		array[hole] = x; // Place x in the current hole.
		return;          // Stop the recursion.
	}

	// Recursive case: Move the parent value down to the current hole.
	array[hole] = array[hole / 2];

	// Recursively check and place x in the parent's position.
	insert_recursive(x, hole / 2);
}

// deleteMin 
// removes the smallest item from the priority queue

void deleteMin() {
	if (isEmpty()) {
		return;
	}

	array[1] = array[theSize--]; // take the last element and put in root
	percolateDown_recursive(1, array[1]); // checks if heap order is broken
}


void printHeap() {
	printf("Heap: ");
	for (int i = 1; i <= theSize; i++) {
		printf("%d    ", array[i]);
	}
	printf("\n");
}

int main() {

	insert_recursive(10, ++theSize);
	insert_recursive(8, ++theSize);
	insert_recursive(15, ++theSize);
	insert_recursive(12, ++theSize);
	insert_recursive(20, ++theSize);

	printHeap();
}
