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


// C program for the implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

#define TEMP 100

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[TEMP], rightArr[TEMP];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}


// C Program for HeapSort
#include <stdio.h>

// Heapify function
void heapify(int arr[], int n, int i)
{
    int temp, maximum, left_index, right_index;

    // currently assuming i postion to
    // be holding the largest value
    maximum = i;

    // right child index
    right_index = 2 * i + 2;

    // left child index
    left_index = 2 * i + 1;

    // if left index value is grater than the current index
    // value
    if (left_index < n && arr[left_index] > arr[maximum])
        maximum = left_index;

    // if right index value is grater than the current index
    // value
    if (right_index < n && arr[right_index] > arr[maximum])
        maximum = right_index;

    // checking if we needed swaping the elements or not
    if (maximum != i) {
        temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr, n, maximum);
    }
}

// HeapSorting function
void heapsort(int arr[], int n)
{
    int i, temp;

    // performing heapify on the non leaf nodes so n/2 - 1
    // to 0 are the non leaf nodes
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // the current array is changed to max heap

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Driver code
int main()
{
    // initializing the array
    int arr[] = { 20, 18, 5, 15, 3, 2 };
    int n = 6;

    // Displaying original array
    printf("Original Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    heapsort(arr, n);

    // Displaying sorted array
    printf("Array after performing heap sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
