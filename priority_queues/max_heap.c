#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int theSize = 0;  // initially there are no items in heap

void recursive_perculateDown(int hole, int tmp);

int isEmpty() {
	if (theSize <= 0) {
		return 1;
	}
	else return 0;
}

void insert(int data) {
	int hole;

	if (theSize > MAX_SIZE - 1) {
		return; // full heap
	}

	hole = ++theSize;
	/*for (; data < array[hole / 2]; hole /= 2) {   MIN HEAP
		array[hole] = array[hole / 2];
	}*/
	 // MAX HEAP
	for (; data > array[hole / 2] && hole > 1; hole /= 2) { // must be for MAX HEAP :: && hole > 1
		array[hole] = array[hole / 2];
	}

	array[hole] = data;
	
}

void insert_recursive(int data, int hole) {
	if (!(data > array[hole / 2] && hole > 1))  // in MIN HEAP is: if (!(data < array[hole / 2])) or if (data > array[hole / 2])
	{
		array[hole] = data;
		return;
	}
	array[hole] = array[hole / 2];
	insert_recursive(data, hole / 2);

}

void percolateDown(int hole) {
	int child;
	int tmp = array[hole];

	for (; hole <= theSize / 2; hole = child) {
		child = hole * 2;

		if (child != theSize && array[child + 1] >= array[child]) {  // for MIN HEAP ::  array[child + 1] < array[child]
			child++;
		}
		if (array[child] >= tmp) { // for MIN HEAP:: if (array[child] < tmp)
			array[hole] = array[child]; 
		}
		else {
			break;
		}
	}

	array[hole] = tmp;
}

void deleteMax() {
	if (isEmpty()) {
		return; // empty heap
	}

	array[1] = array[theSize--];
	 // percolateDown(1);
	recursive_perculateDown(1, array[1]);
}

void printHeap() {
	printf("Heap: ");
	for (int i = 1; i <= theSize; i++) {
		printf("%d    ", array[i]);
	}
	printf("\n");
}

int main() {
	//insert(10);
	//insert(5);
	//insert(20);
	//insert(1);

	insert_recursive(10, ++theSize);
	insert_recursive(5, ++theSize);
	insert_recursive(20, ++theSize);
	insert_recursive(1, ++theSize);

	printHeap();

	deleteMax();


	printHeap();
}

void recursive_perculateDown(int hole, int tmp) {
	if (hole > theSize / 2) {  // for MIN HEAP :: hole * 2 > theSize
		array[hole] = tmp; // Place tmp in the current hole.
		return;            // End the recursion.
	}

	int child;
	child = hole * 2; // Left child of the current hole.

	
	if (child != theSize && array[child + 1] >= array[child]) { //for MIN HEAP:: array[child + 1] < array[child]
		child++;
	}

	if (array[child] >= tmp) {  // //for MIN HEAP:: if (array[child] < tmp)
		array[hole] = array[child]; 
	}

	recursive_perculateDown(child, tmp);
}
