#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* createNewNode(int data) {
	struct Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

struct Node* search(int data, struct Node* root) {
	if (root != NULL) {
		if (data == root->data) {
			return root;
		}
		else if (data < root->data) {
			return search(data, root->left);
		}
		else {
			return search(data, root->right);
		}
	}
	else {
		return 0;
	}
}

struct Node* insert(int data, struct Node* root) {
	if (root == 0) {
		return createNewNode(data);
	}
	
	if (data < root->data) {
		root->left = insert(data, root->left);
	}
	else if (data > root->data) {
		root->right = insert(data, root->right);
	}

	return root;
}

void preorder(struct Node* root) {
	if (root != NULL) {
		printf("%d    ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct Node* root) {
	if (root != NULL) {
		
		inorder(root->left);
		printf("%d    ", root->data);
		inorder(root->right);
	}
}

void postorder(struct Node* root) {
	if (root != NULL) {
		preorder(root->left);
		preorder(root->right);
		printf("%d    ", root->data);
	}
}
void delete_ (int data, struct Node* root) {
	if (root == NULL) {
		return;
	}
	else if (data == root->data) {
		deleteNode(root);
	}
	else if (data < root->data) {
		delete_(data, root->left);
	}
	else if (data > root->data) {
		delete_(data, root->right);
	}
}

struct Node* deleteNode(struct Node* root) {
	struct Node* deleted;

	// 1. Test if the root we want to delete has no children
	if (root->left == NULL && root->right == NULL) {
		free(root);
		root = NULL;
	}
	// 2. Test if the root has no left child
	else if (root->left == NULL) {
		deleted = root;
		root = root->right;
		deleted->right = NULL;
		free(deleted);
	}
	// 3. Test if the root has no right child
	else if (root->right == NULL) {
		deleted = root;
		root = root->left;
		deleted->left = NULL;
		free(deleted);
	}
	// 4. There are 2 children
	//  inorder successor approach
	else {
		root->data = processLeftMost(root->right);
	}
	/*
	//  inorder predecessor approach
	else {
		root->data = processRightMost(root->right);
	}
	*/

	// To delete a node with two children in a BST, we can use:
	// 1. Successor: Smallest value in the right subtree.
	//    - Keeps changes to the left subtree minimal.
	//    - Good when the right subtree is smaller or simpler.
	// 2. Predecessor: Largest value in the left subtree.
	//    - Keeps changes to the right subtree minimal.
	//    - Good when the left subtree is smaller or simpler.
	// Both methods keep the BST rules. Choose based on the tree's structure.

}

int processLeftMost(struct Node* root) {
	if (root->left == NULL) { // Base case: Found the leftmost node
		int data = root->data; // Save the value of this node
		struct Node* deleted = root; // Save a reference to this node for deletion
		root = root->right; // Replace this node with its right child (may be NULL)
		deleted->right = NULL; // Detach it from the tree
		free(deleted); // Free the memory
		return data; // Return the smallest value
	}
	else { // Recursive case: Keep going left
		return processLeftMost(root->left);
	}
}

int processRightMost(struct Node* root) {
	if (root->right == NULL) { // Base case: Found the rightmost node
		int data = root->data; // Save the value of this node
		struct Node* deleted = root; // Save a reference to this node for deletion
		root = root->left; // Replace this node with its left child (may be NULL)
		deleted->left = NULL; // Detach it from the tree
		free(deleted); // Free the memory
		return data; // Return the largest value
	}
	else { // Recursive case: Keep going right
		return processRightMost(root->right);
	}
}

int main() {
	struct Node* root = NULL;
	root = insert(15, root);
	root = insert(25, root);
	root = insert(20, root);
	root = insert(22, root);
	root = insert(30, root);
	root = insert(5, root);

	printf("\npreorder:\n ");
	preorder(root);
	printf("\ninorder:\n ");
	inorder(root);
}
