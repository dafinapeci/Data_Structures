#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// LIFO (Last-In-First-Out)

#define MAX_SIZE 15

int A[MAX_SIZE];
int top = -1;

int isEmpty() {
	if (top < 0) {
		return 0;
	}
	else {
		return 1;
	}
}

void push(int data) {
	if (top == MAX_SIZE - 1) {
		return;  // full stack
	}
	else {
		A[++top] = data;
	}
}

void pop() {
	if (top < 0) {
		return; // empty stack
	}
	else {
		top--;
	}
}

int Top() {
	return A[top];
}

void Print() {
	printf("Stack:  ");
	for (int i = 0; i <= top; i++) {
		printf("%d  ", A[i]);
	}
	printf("\n");
}

int main() {
	push(2); Print();
	push(5); Print();
	push(10); Print();
	pop(); Print();
	push(12); Print();
}
