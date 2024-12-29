// VERSION 1 - HOCA VERSION
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
} element;

typedef struct Node* node_pointer;
typedef struct Node {
	node_pointer leftlink;
	element item;
	node_pointer rightlink;
};

// insert into a doubly-linked circular list
// takes constant time to perform insertion operation O(1)
// node represents the head node of an empty list
void double_insert(node_pointer node, node_pointer newNode) {
	// insert a newnode to the right of node

	newNode->leftlink = node;
	newNode->rightlink = node->rightlink;
	node->rightlink->leftlink = newNode;
	node->rightlink = newNode;
}

// function deletes the node deleted from the list pointed to by node
// we only need to change the link fields of the nodes that precede 
//deleted->llink->rlink) and follow (deleted— > rlink— > Il ink] the node we want to delete.

void double_deleted(node_pointer node, node_pointer deleted) {
	if (node == deleted) {
		printf("deletion of head node not permitted.\n");
	}
	else {
		deleted->leftlink->rightlink = deleted->rightlink;
		deleted->rightlink->leftlink = deleted->leftlink;
		free(deleted);
	}
}



// VERSION 2
// more understandable version
// try drawing on paper if you don't understand

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* addToEmpty(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;

	return temp;
}

struct Node* addAtBeginning(struct Node* tail, int data) {
	struct Node* newP = addToEmpty(data);
	if (tail == NULL) { // empty list, so this will be the first node
		return newP;
	}
	else {
		struct Node* temp = tail->next;
		newP->prev = tail;
		newP->next = temp;
		temp->prev = newP;
		tail->next = newP;
		return tail;
	}
}

struct Node* addAtEnding(struct Node* tail, int data) {
	struct Node* newP = addToEmpty(data);
	if (tail == NULL) { // empty list, so this will be the first node
		return newP;
	}
	else {
		struct Node* temp = tail->next;
		newP->prev = tail;
		newP->next = temp;
		temp->prev = newP;
		tail->next = newP;
		tail = newP;  // the only line of code needed for adding at end
		
		return tail;
	}
}

// time of complexity O(N)
struct Node* addAtNthPosition(struct Node* tail, int data, int pos) {
	struct Node* newP = addToEmpty(data);

	if (tail == NULL) {
		return newP;
	}
	struct Node* temp = tail->next;
	while (pos > 1) {
		temp = temp->next;
		pos--;
	}
	newP->prev = temp; // newP->prev = tail; for insert at beg or end
	newP->next = temp->next; // newP->next = temp; for insert at beg or end
	temp->next->prev = newP; // temp->prev = newP; for insert at beg or end
	temp->next = newP; // tail->next = newP; for insert at beg or end
	if (temp == tail) {
		tail = tail->next;
	}
	return tail;

}

// time complexity O(1)
struct Node* delFirst(struct Node* tail) {
	if (tail == NULL) {
		return tail;
	}
	struct Node* temp = tail->next;
	if (temp == tail) { // only one node in list
		free(tail);
		tail = NULL;
		return tail;
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);

	return tail;
}

// time complexity O(1)
struct Node* delLast(struct Node* tail) {
	if (tail == NULL) {
		return tail;
	}
	struct Node* temp = tail->prev;
	if (temp == tail) { // only one node in list
		free(tail);
		tail = NULL;
		return tail;
	}
	temp->next = tail->next;
	tail->next->prev = temp;
	free(tail);
	tail = temp;
	return tail;
}
// time complexity O(N)
struct Node* delAtNthPosition(struct Node* tail, int pos) {
	struct Node* temp = tail->next; // points at first node
	
	while (pos > 1) {
		temp = temp->next; // in the end, temp will be the node we want to delete
		pos--;
	}

	struct Node* temp2 = temp->prev; // prev node of temp (node we want to delete)
	temp2->next = temp->next;
	temp->next->prev = temp2;
	free(temp);

	if (temp == tail) {
		tail = temp2;
	}
	return tail;
}


void print(struct Node* tail) {
	if (tail == NULL) {
		printf("No element in the list");
	}
	else {
		struct Node* temp = tail->next;
		do {
			printf("%d   ", temp->data);
			temp = temp->next;
		} while (temp != tail->next);
	}
	printf("\n");
}

int main() {
	struct Node* tail = NULL;
	tail = addToEmpty(45);
	tail = addAtBeginning(tail, 34);
	printf("Add to Beginning:\n");
	print(tail);

	printf("Add to Ending:\n");
	tail = addAtEnding(tail, 50);
	tail = addAtEnding(tail, 60);
	print(tail);

	printf("Add in Between, nth position:\n");
	tail = addAtNthPosition(tail, 15, 1);
	print(tail);

	printf("Deleting 1st Node:\n");
	tail = delFirst(tail);
	print(tail);

	printf("Deleting last Node:\n");
	tail = delLast(tail);
	print(tail);

	return 0;
}
