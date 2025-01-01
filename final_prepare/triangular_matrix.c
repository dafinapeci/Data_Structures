#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

void readTriangularMatrix(int alt[], int n) {
	int i, j, k;
	int current = 1;

	if (n * (n + 1) / 2 > MAX_SIZE) {
		printf("invalid array size\n");
		return;
	}
	else {
		for (i = 0; i < n; i++) {
			k = i * (i + 1) / 2;
			for (j = 0; j <= i; j++) {
				alt[k + j] = current;
				current++;
			}
		}
	}
}

int getTriangularMatrix(int i, int j, int n) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		printf("invalid index\n");
		return -2;
	}
	else if (i >= j) {
		return i * (i + 1) / 2 + j;
	}
	else {
		return -1;
	}
}

int main() {
	int alt[MAX_SIZE];
	int n = 5;
	readTriangularMatrix(alt, n);
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		printf("%d\t", alt[i]);
	}

	int m = getTriangularMatrix(3, 0, n);
	if (m == -2) {
		printf("invalid index\n");
	}
	else if (m == -1) {
		printf("upper triangular: 0 values");
	}
	else {
		printf("\nValue: %d, index: %d", alt[m], m);
	}
}
