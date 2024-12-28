#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct Node {
	int data; // 4 bytes
	struct Node* link; // 4 bytes || holds the address of the next node
};

struct Node* head; // knowing head is mandatory bc we can move forward, not backward 
					// in the single linked list. so to access all list from beginning to end 
					// we have to know the head, aka the first item or node

void insertBeginning(int data) { // inserting in the beginning of the linked list
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->link = head; // not temp->link = NULL, bc we lose the previous nodes
	head = temp;
}

void insertNthPosition(int data, int position) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->link = NULL;
	if (position == 1) {
		temp->link = head;
		head = temp;
		return;
	}

	struct Node* temp2 = head;
	for (int i = 1; i < position - 1; i++) {
		temp2 = temp2->link;
	}

	temp->link = temp2->link;
	temp2->link = temp;
}

void insertEnd(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->link = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}

	struct Node* temp2 = head;
	while (temp2->link != NULL) {
		temp2 = temp2->link;
	}

	temp2->link = temp;
	
}

void deleteNthPosition(int position) {
	struct Node* temp = head;
	if (position == 1) {
		head = temp->link;
		free(temp);
		return;
	}

	int count = 1; // Counter to check the position validity
	while (temp != NULL && count < position - 1) {
		temp = temp->link;
		count++;
	}

	if (temp == NULL || temp->link == NULL) {
		printf("Invalid position\n");
		return;
	}

	struct Node* temp2 = temp->link;
	temp->link = temp2->link;
	free(temp2);
}


void deleteEnd() {
	if (head == NULL) { // Empty list
		printf("List is empty. Nothing to delete.\n");
		return;
	}
	if (head->link == NULL) { // Only one node in the list
		free(head);
		head = NULL;
		return;
	}

	struct Node* temp = head;
	while (temp->link->link != NULL) {
		temp = temp->link; // Move to the second-to-last node
	}

	free(temp->link);     // Free the last node
	temp->link = NULL;    // Set the link of the second-to-last node to NULL
}


void Print() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->link;
	}
}

void PrintForwardRecursive(struct Node* head) {
	if (head == NULL) {
		return;
	}
	printf("%d\t", head->data);
	PrintForwardRecursive(head->link);
}

void PrintBackwardRecursive(struct Node* head) {
	if (head == NULL) {
		return;
	}

	PrintBackwardRecursive(head->link);
	printf("%d\t", head->data);
}

int main() {
	head = NULL;
	//int n;
	//printf("how many numbers: ");
	//scanf_s("%d", &n);

	//int data;
	/*for (int i = 0; i < n; i++) {
		printf("\nEnter data for %d node: ", i + 1);
		scanf_s("%d", &data);
		insertBeginning(data);
		Print();
	}*/

	insertBeginning(20);
	insertBeginning(15);
	insertNthPosition(23, 2);
	insertEnd(30);

	printf("\nbefore delete end\n");
	Print();
	deleteEnd();
	printf("\nafter delete end\n");
	Print();

	return 0;
	
}
