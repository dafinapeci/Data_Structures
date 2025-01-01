// SELECTION SORT

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 101
void sort(int list[], int n);
void sort_recursive(int list[], int n, int temp);

void main() {
	int i;
	int list[MAX_SIZE];
	int array_size = 15;

	printf("original list: \n");
	for (i = 0; i < array_size; i++) {
		list[i] = rand() % 100;
		printf("%d\t", list[i]);
	}

	sort(list, array_size);
	printf("\nsorted list: \n");
	for (i = 0; i < array_size; i++) {
		printf("%d\t", list[i]);
	}
}

void sort(int list[], int n) {
	int min, temp;

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[i]) {
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}
}


int minIndex(int list[], int i, int j) {
	if (i == j) {
		return i;
	}

	int k = minIndex(list, i + 1, j);
	return (list[i] < list[k] ? i : k);
}

void sort_recursive(int list[], int index, int n) {
	if (index == n) {
		return;
	}

	// Find the minimum element's index in the subarray
	int k = minIndex(list, index, n - 1);
	if (k != index) {
		// Swap the minimum element with the current element
		int temp = list[k];
		list[k] = list[index];
		list[index] = temp;
	}

	// Recur for the remaining elements
	sort_recursive(list, index + 1, n);
}
