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
