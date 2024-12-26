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
void percolateDown(int hole) {
	int child;

	int tmp = array[hole];

	for (; hole * 2 <= theSize; hole = child) {
	child = hole * 2;
	if (child != theSize && array[child + 1] < array[child]) { // child != theSize :: to check if we are seeing the last item of the array. 
								// if we see the last item it means there is no right child to compare
		child++;
	}
	if (array[child] < tmp) {
		array[hole] = array[child];
		// If the smaller child is less than tmp (the value at the current hole), 
		// move the smaller child up to maintain the min-heap property and continue percolating down. 
		// If tmp is already smaller than or equal to the smaller child, 
		// the heap property is satisfied at this level, so we exit the loop.

	}
	else {
		break;
	}
}

	array[hole] = tmp;
}

// insert function, maintain heap order ( P >= x ) P: parent, x: child
// duplicates allowed

void insert (int x) {
	int hole; // creating a new hole

	if (theSize + 1 == MAX_SIZE) { // heap is full
		return;
	}

	// else percolate up
	hole = ++theSize;

	for (; x < array[hole / 2]; hole /= 2) { // hole/2 is formula i/2 or parent 
		array[hole] = array[hole / 2];  // swap parent and child
	}
	array[hole] = x;
}

// deleteMin 
// removes the smallest item from the priority queue

void deleteMin() {
	if (isEmpty()) {
		return;
	}

	array[1] = array[theSize--]; // take the last element and put in root
	percolateDown(1); // checks if heap order is broken
}



// build heap, having the heap-order property 
// runs in linear time O(N)
void buildHeap() {
	for (int i = theSize / 2; i > 0; i--) {
		percolateDown(i);
	}
}

void printHeap() {
	printf("Heap: ");
	for (int i = 1; i <= theSize; i++) {
		printf("%d    ", array[i]);
	}
	printf("\n");
}

int main() {

	insert(10);
	insert(8);
	insert(15);
	insert(12);
	insert(20);

	printHeap();
}
