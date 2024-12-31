#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

void deleteNode(struct Node** root);
int processLeftMost(struct Node** root);

struct Node* search(int searchedValue, struct Node* root) {
	if (root != 0) { // not empty
		if (searchedValue == root->data) {
			return root;
		}
		else if (searchedValue < root->data) {
			return search(searchedValue, root->left);
		}
		else {
			return search(searchedValue, root->right);
		}
	}
	else {
		return 0;
	}
}

// For deletion: average case is O(logN) and worst case is O(N)
void insert(int data, struct Node** root) {
	if (*root == 0) {
		*root = (struct Node*)malloc(sizeof(struct Node));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (data < (*root)->data) {
		insert(data, &(*root)->left);
	}
	else if (data > (*root)->data) {
		insert(data, &(*root)->right);
	}
}

/*
For the deletion, we need to think of 3 cases:
	1. Case: A leaf node (the leaf has no children of its own)
	2. Case: A node with only one child (left or right child)
	3. Case: A node with two children
*/

// For removal: average case is O(logN) and worst case is O(N)
void delete_(int data, struct Node** root) {
	if (*root == 0) {
		return;
	}
	else if (data == (*root)->data) {
		deleteNode(&(*root));
	}
	else if (data < (*root)->data) {
		delete_(data, &(*root)->left);
	}
	else if (data > (*root)->data) {
		delete_(data, &(*root)->right);
	}
}

void deleteNode(struct Node** root) {
	struct Node* deleted;

	// 1. Case: Test for a leaf
	if ((*root)->left == NULL && (*root)->right == NULL) {
		free(*root);
		*root = NULL;
	}

	// 2. Case: Test for no left child
	else if ((*root)->left == NULL) {
		deleted = *root;
		*root = (*root)->right;
		deleted->right = NULL;
		free(deleted);
	}

	// 3. Case: Test for no right child
	else if ((*root)->right == NULL) {
		deleted = *root;
		*root = (*root)->left;
		deleted->left = NULL;
		free(deleted);
	}

	// 4. Case: There are two children
	// Retrieve and delete the inorder successor
	else {
		(*root)->data = processLeftMost(&(*root)->right);
	}
}

int processLeftMost(struct Node** root) {
	if ((*root)->left == NULL) {
		int data = (*root)->data;
		struct Node* deleted = *root;
		*root = (*root)->right;
		deleted->right = NULL;
		free(deleted);
		return data;
	}

	else {
		return processLeftMost(&(*root)->left);
	}
}
