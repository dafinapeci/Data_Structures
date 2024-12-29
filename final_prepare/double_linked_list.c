// TO DO
// write functions: insert at nth position, delete at head, end and nth position

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* prev;
	Node* next;
};

struct Node* head;

struct Node* getNewNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}
void insertAtHead(int data) {
	struct Node* newNode = getNewNode(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void insertAtEnd(int data) {
	struct Node* newNode = getNewNode(data);
	if (head == NULL) {
		head = newNode;
		return;
	}

	struct Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;

}

void ForwardPrint() {
	struct Node* temp = head;

	if (temp == NULL) {
		return;
	}

	printf("forward:\n");
	while (temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint() {
	struct Node* temp = head;

	if (temp == NULL) {
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}

	printf("reverse:\n");
	while (temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->prev;
	}

	printf("\n");
}

int main() {
	head = NULL;
	insertAtHead(1);
	insertAtHead(2);
	ForwardPrint();
	insertAtEnd(4);
	ForwardPrint();
	ReversePrint();
}
