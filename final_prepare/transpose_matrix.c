#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value;
} term;

term A[MAX_TERMS];

void transpose(term a[], term b[]) {
	int n, currentb;
	n = a[0].value;
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].value = n;

	if (n > 0) {
		currentb = 1;
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[j].col == i) {
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}
