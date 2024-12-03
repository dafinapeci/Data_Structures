/* Print elements of a linked list in forward and 
 reverse order using recursion
*/
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
};

struct Node* head;

void Insert(int data);
void PrintForward(struct Node* head);
void PrintReverse(struct Node* head);

int main() {
	head = NULL;
	Insert(5);
	Insert(9);
	Insert(11);
	Insert(28);
	Insert(2);
	Insert(7);

	printf("Printing Forward List: ");
	PrintForward(head);
	PrintReverse(head);

}

void Insert(int data) {
	struct Node* temp = (Node*)malloc(sizeof(Node));

	temp->data = data;
	temp->link = head;
	head = temp;
}

void PrintForward(struct Node* head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	else {
		printf("%d   ", head->data);
		PrintForward(head->link);
	}
}

void PrintReverse(struct Node* head) {
	if (head == NULL) {
		printf("\n");
		return;
	}
	else {
		PrintForward(head->link);
		printf("%d   ", head->data);
	}
}
