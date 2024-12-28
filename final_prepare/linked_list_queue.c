// Linked List using Queue
// FIFO (First-In-First-Out). so basically first node to be inserted or enqueued will be the first to be removed or dequeued
// Dequeue takes O(1) whereas Enqueue takes O(N), since we have to go to the end of list to insert a new node
// so to not have O(N) for Enqueue we save a pointer variable named rear that points to the last node of the list
// now both enqueue and dequeue take O(1) time complexity

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = NULL;
	if (front == NULL && rear == NULL) {
		front = temp;
		rear = temp;
		return;
	}
	else {
		rear->link = temp;
		rear = temp;
	}
}

void Dequeue() {
	struct Node* temp = front->link;
	if (front == NULL) {
		return; // queue is empty
	}
	if (front == rear) { // one node only in queue
		front = NULL;
		rear = NULL;
		return;
	}
	else {
		front = temp;
	}
	free(temp);
}

void Print() {
	struct Node* temp = front;
	while (temp->link != NULL) {
		printf("Data: %d\tLink: %d\n", temp->data, temp->link);
		temp = temp->link;
	}
	printf("\nlast item link: %d, and data:%d\n", -1, temp->data);
}

int main() {

	Enqueue(5);
	Enqueue(15);
	Enqueue(2);
	Enqueue(20);

	printf("before deletion\n");
	Print();

	Dequeue();
	printf("after deletion\n");
	Print();
}
