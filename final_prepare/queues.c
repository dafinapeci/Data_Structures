// array version

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// FIFO (First-In-First-Out)

#define MAX_SIZE 15

int A[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
	if (front == -1 && rear == -1) {
		return 0;
	}
	else {
		return 1;
	}
}

void enqueue(int data) {
	if (rear == MAX_SIZE - 1) {
		return; // full queue
	}
	else if (front == rear == -1) { // first item will be added to queue
		A[++front] = data;
		rear = front;
	}
	else {
		rear++;
		A[rear] = data;
	}
}

void dequeue() {
	if (front == rear == -1) {
		return; // empty queue
	}
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front++;
	}
}
