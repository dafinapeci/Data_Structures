// Linked List using Stack
// O(1) for Push and Pop since push and pop happens at the beginning of the list, and instead of head we call it top. so it is easy and not time consuming

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

struct Node* top = NULL;

void Push(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->link = top;

	top = temp;
}

void Pop() {
	struct Node* temp = top;
	if (top == NULL) {
		return; // empty stack
	}
	top = temp->link;
	free(temp);
	
}

void Print() {
	struct Node* temp = top;
	while (temp->link != NULL) {
		printf("Data: %d\tLink: %d\n", temp->data, temp->link);
		temp = temp->link;
	}
	printf("\nlast item link: %d, and data:%d\n", -1, temp->data);
}

int main() {
	
	Push(5);
	Push(15);
	Push(2);
	Push(20);

	printf("before deletion\n");
	Print();

	Pop();
	printf("after deletion\n");
	Print();
}
