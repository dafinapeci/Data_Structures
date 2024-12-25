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
		if (child != theSize && array[child + 1] < array[child]) {
			child++;
		}
		if (array[child] < tmp) {
			array[hole] = array[child];
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
		array[hole] = array[hole / 2];
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
