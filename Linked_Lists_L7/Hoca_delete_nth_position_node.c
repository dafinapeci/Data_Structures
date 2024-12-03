// Delete at n-th position func.
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* head;


void Delete(int n);
void Insert(int data);
void Print();

int main() {
	head = NULL;
	Insert(5);
	Print();
	Insert(6);
	Print();
	Delete(2);
	Print();
}

void Insert(int data) { //insert at beginning 
	struct Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->link = head;
	head = temp;
	
}

void Delete(int n) { //delete at n-th position
	struct Node* temp = head;

	if (n == 1) { // delete node at 1st position aka at head
		head = temp->link; // head is now at 2nd node
		free(temp);
		return;
	}
	else {
		struct Node* temp2 = head->link; // my idea
		for (int i = 0; i < n - 3; i++) {
			temp2 = temp2->link;
			temp = temp->link;
		}

		temp->link = temp2->link;

		free(temp2);
		/* hoca's version
		* for (int i = 0; i < n-2; i++){
			temp = temp->link;   
		}  // temp is at n-1 node
		struct Node* temp2 = temp->link; //nth node
		temp->link = temp2->link;  //n+1 node

		free(temp2);
		*/
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
