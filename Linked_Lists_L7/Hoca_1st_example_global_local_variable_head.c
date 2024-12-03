// Head is a global variable - version 1
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
	int data; //the value that we need or want is of integer type (it can be char, float etc.)
	struct Node* link;  //or Node* next; // stroes the address of the next node
};

struct Node* head;  //global variable

void Insert(int x);
void Print();

int main() {
	head = NULL; // empty list
	printf("How many values (numbers)?\n");
	int n, x;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the number \n");
		scanf_s("%d", &x);
		Insert(x);
		Print();
	}
}

void Insert(int x) {
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->link = NULL;
	if (head != NULL) {
		temp->link = head; 
	}
	head = temp;  //the new head is temp now, temp is the first item

}

void Print() {
	struct Node* temp = head;
	printf("List is: ");
	
	while (temp != NULL) {
		printf("%d   ", temp->data); //each new data is stored at the beginning of the list
		temp = temp->link;
	}

	printf("\n");
}

// Head is a local variable - version 2
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
	int data; //the value that we need or want is of integer type (it can be char, float etc.)
	struct Node* link;  //or Node* next; // stroes the address of the next node
};

void Insert(struct Node* head, int x);
void Print(struct Node* head);

int main() {
	struct Node* head = NULL; // empty list
	printf("How many values (numbers)?\n");
	int n, x;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the number \n");
		scanf_s("%d", &x);
		Insert(head, x);
		Print(head);
	}
}

void Insert(struct Node* head, int x) {
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->link = NULL;
	if (head != NULL) {
		temp->link = head;
	}
	head = temp;  //the new head is temp now, temp is the first item

}

void Print(struct Node* head) {
	
	printf("List is: ");

	while (head != NULL) {
		printf("%d   ", head->data); //each new data is stored at the beginning of the list
		head = head->link;
	}

	printf("\n");
}

