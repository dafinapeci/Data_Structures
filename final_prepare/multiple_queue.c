#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_QUEUE 10

typedef struct {
	int data;
} item;

typedef struct queue {
	item value;
	struct queue* link;
};

typedef struct queue* front_pointer;
typedef struct queue* rear_pointer;

front_pointer front[MAX_QUEUE];
rear_pointer rear[MAX_QUEUE];

void Enqueue(front_pointer* front, rear_pointer* rear, int data) {
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
	temp->value.data = data;
	temp->link = NULL;
	if (*front == NULL && *rear == NULL) { // empty queue
		(*front) = temp;
		(*rear) = temp;
	}
	(*rear)->link = temp;
	(*rear) = temp;
	
}

void Dequeue(front_pointer* front, rear_pointer* rear) {
	if ((*front) == NULL && (*rear) == NULL) {
		return; // empty queue
	}
	(*front) = (*front)->link;

}

void print(front_pointer* front, rear_pointer* rear) {
	struct queue* current = *front;
	printf("List: ");
	while (current != NULL) {
		printf("%d -> ", current->value.data);
		current = current->link;
	}
	printf("NULL\n");
}

int main() {
	Enqueue(&front[0], &rear[0], 1);
	Enqueue(&front[0], &rear[0], 2);
	Enqueue(&front[0], &rear[0], 3);
	Enqueue(&front[0], &rear[0], 4);
	Enqueue(&front[0], &rear[0], 5);
	print(&front[0], &rear[0]);
	Dequeue(&front[0], &rear[0]);
	print(&front[0], &rear[0]);
}
