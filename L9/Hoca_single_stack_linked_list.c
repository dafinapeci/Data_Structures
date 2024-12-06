// Stack - Linked - List
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* top;

void Push(int x);
void Print();
void Pop();

int main() {
	top = NULL;
	Push(6);
	Push(9);
	Push(21);
	Print();
	Pop();
	Print();
}

void Push(int x) {
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop() {
	struct Node* temp = top;
	temp = temp->link;
	top = temp;
	free(temp);
}

void Print() {
	struct Node* temp = top;
	while (temp != NULL) {
		printf("%d    ", temp->data);
		temp = temp->link;
	}
}
