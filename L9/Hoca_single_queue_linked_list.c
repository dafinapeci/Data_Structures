// Queue - Linked - List
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* front;
struct Node* rear;

void Enqueue(int x);
void Dequeue();
void Front();
bool isEmpty();

int main() {
	front = NULL;
	rear = NULL;
}

void Enqueue(int x) {
	struct Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = x;
	temp->link = NULL;

	if (front == NULL && rear == NULL) { // queue is empty 
		front = rear = temp;
		return;
	}
	else {
		rear->link = temp;
		rear = temp;
	}
}

void Dequeue() {
	struct Node* temp = front;
	if (front == NULL) { // queue is empty
		return; // no node is there to be deleted or dequeued
	}
	else if (front = rear) { // only one node in the queue 
		front = rear = NULL; // we deleted the only node, and now the queue is empty
	}
	else {
		front = front->link;
	}
	free(temp);
}

void Front() {
	printf("%d", front);
}
bool isEmpty() {
	if (front == NULL) {
		return true;
	}
	else {
		return false;
	}
}
