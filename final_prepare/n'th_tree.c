#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	int childCount;
	struct Node** children;
};

struct Node* createNode(int data, int maxChildren) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->childCount = 0;
	newNode->children = (struct Node**)malloc(maxChildren * sizeof(struct Node*));
	for (int i = 0; i < maxChildren; i++) {
		newNode->children[i] = NULL;
	}

	return newNode;
}

void insertChild(struct Node* parent, int data, int maxChildren) {
	if (parent->childCount < maxChildren) {
		parent->children[parent->childCount] = createNode(data, maxChildren);
		parent->childCount++;
	}
	else {
		printf("Cannot add child to node %d, max children reached.\n", parent->data);
	}
}

void printTree(struct Node* root, int level) {
	if (root == NULL) {
		return;
	}

	for (int i = 0; i < level; i++) {
		printf("  ");
	}
	printf("%d\n", root->data);

	for (int i = 0; i < root->childCount; i++) {
		printTree(root->children[i], level + 1);
	}
}

void freeTree(struct Node* root, int maxChildren) {
	if (root == NULL) {
		return;
	}

	// Recursively free all children
	for (int i = 0; i < root->childCount; i++) {
		freeTree(root->children[i], maxChildren);
	}

	// Free the node's children array and the node itself
	free(root->children);
	free(root);
}

int main() {
	int maxChildren = 3; // Define maximum number of children per node (N)

	// Create the root node
	struct Node* root = createNode(1, maxChildren);

	// Add children to the root node
	insertChild(root, 2, maxChildren);
	insertChild(root, 3, maxChildren);
	insertChild(root, 4, maxChildren);

	// Add children to one of the root's children
	insertChild(root->children[0], 5, maxChildren);
	insertChild(root->children[0], 6, maxChildren);

	// Add more children
	insertChild(root->children[1], 7, maxChildren);
	insertChild(root->children[2], 8, maxChildren);

	// Print the N-ary tree
	printf("N-ary Tree:\n");
	printTree(root, 0);

	// Free the allocated memory
	freeTree(root, maxChildren);

	return 0;
}
