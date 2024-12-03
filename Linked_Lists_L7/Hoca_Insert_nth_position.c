// Insert at n-th position func.
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* head;

void Insert(int data, int n) { // n is the location we want the new data to be located at
	struct Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->link = NULL; //first we have to set it to NULL
	
	if (n == 1) { // we want the new node to be in the 1st position, yani head position
		temp->link = head;
		head = temp;
		return;

	}
	else { // the position of new node isn't 1st, but somewhere else
		Node* temp2 = head; // we set the temp at head, and we will start accessing the items until the preferred location
		for (int i = 0; i < n - 2; i++) {// or for (int i = 1; i < n - 1; i++)
			temp2 = temp2->link;		 
		}

		temp->link = temp2->link;
		temp2->link = temp; //previous node at this location is connected to the new node
	}
}

void Print() {
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->link;
	}

	printf("\n");
}

int main() {
	head = NULL; //empty list
	Insert(2, 1);
	Insert(7, 2);
	Insert(4, 1);
	Insert(6, 3);
	Print();
}
