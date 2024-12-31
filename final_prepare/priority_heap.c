#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int array[MAX_SIZE]; 
int theSize = 0; // current item count of heap. Initially no items in heap

void percolateDown(int hole);

int isEmpty() {
	if (theSize <= 0) {
		return 1; // false
	}
	else {
		return 0; // true
	}
}

// insert function, maintaining heap order. P <= x for min heap
// duplicates allowed
// left child 2i, right child 2i + 1, parent i/2

void insert(int data) {
	int hole; 

	if (theSize + 1 == MAX_SIZE) {
		return;  // full heap
	}

	// percolate up
	hole = ++theSize; // creates a hole in the leftmost free place. order is checked. if not in order, then percolate up
	for (; data < array[hole / 2]; hole /= 2) { 
		array[hole] = array[hole / 2];
	}

	/*
	for MAX HEAP

	for (; data > array[hole / 2] && hole > 1; hole /= 2) {
		array[hole] = array[hole / 2];
	}
	*/
	array[hole] = data;
}

void insert_recursive(int data, int hole) {
	if (!(data < array[hole / 2]))  // or if (data > array[hole / 2])  
	{
		array[hole] = data;
		return;
	}

	// for MAX HEAP

	/*if (!(data > array[hole / 2] && hole > 1)) {
		array[hole] = data;
		return;
	}*/

	array[hole] = array[hole / 2];
	insert_recursive(data, hole / 2);

}

// remove the smallest item from binary heap

void deleteMin() {
	if (isEmpty()) {
		return;
	}
	else {
		array[1] = array[theSize--];
		percolateDown(1);
		// percolateDown_recursive (1, array[1]);
	}
}

// hole is the index at which the percolate begins
void percolateDown(int hole) { // checks if order is broken
	int child;
	int tmp = array[hole];

	for (; hole * 2 <= theSize; hole = child) { // for MAX HEAP :: hole <= theSize/2
		child = hole * 2;
		if (child != theSize && array[child + 1] < array[child]) { // for MAX HEAP :: array[child+1] >= array[child]
			child++;
		}
		if (array[child] < tmp) { // for MAX HEAP :: array[child] >= tmp
			array[hole] = array[child];
		}
		else {
			break;
		}
	}
	array[hole] = tmp;
}

void percolateDown_recursive(int hole, int tmp) {
	if (hole * 2 > theSize) { // for MAX HEAP :: hole > theSize / 2
		array[hole] = tmp;
		return;
	}

	int child;
	child = hole * 2;

	if (child != theSize && array[child + 1] < array[child]) { // for MAX HEAP :: array[child+1] >= array[child]
		child++;
	}

	if (array[child] < tmp) { // for MAX HEAP :: array[child] >= tmp
		array[hole] = array[child];
	}

	percolateDown_recursive(child, tmp);
}

void printHeap() {
	printf("Heap: ");
	for (int i = 1; i <= theSize; i++) {
		printf("%d    ", array[i]);
	}
	printf("\n");
}

// build heap, linear time O(N)

void buildHeap() {
	int i;
	for (i = theSize / 2; i > 0; i--) {  // thesize/2 is the last element's parent
		percolateDown(i);
	}
}
