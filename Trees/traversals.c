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

struct Node* createNode(int data) {
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void preorder(struct Node* root) {
	if (root != NULL) {
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node* root) {
	if (root != NULL) {	
		preorder(root->left);
		preorder(root->right);
		printf("%d\t", root->data);
	}
}
void inorder(struct Node* root) {
	if (root != NULL) {
		
		preorder(root->left);
		printf("%d\t", root->data);
		preorder(root->right);
	}
}

struct Node* preorderSearch(struct Node* root, int searchedValue);

struct Node* inorderSearch(struct Node* root, int searchedValue);

struct Node* postorderSearch(struct Node* root, int searchedValue);

int main() {
	struct Node* root = createNode(10);
	root->left = createNode(20);
	root->left->left = createNode(30);
	root->right = createNode(40);
	root->right->right = createNode(50);
	root->right->right->right = createNode(60);

	printf("\npreorder\n");
	preorder(root);

	printf("\npostorder\n");
	postorder(root);

	printf("\ninorder\n");
	inorder(root);

	preorderSearch(root, 22);

	
	postorderSearch(root, 30);
	preorderSearch(root, 50);

}

struct Node* preorderSearch(struct Node* root, int searchedValue) {

	if (root == NULL) {
		return NULL;
	}
	else if (root != NULL) {
		struct Node* temp = root;
		if (temp->data == searchedValue) {
			printf("\n\nvalue found!\n");
			return temp;
		}
		else {
			preorderSearch(temp->left, searchedValue);
			preorderSearch(temp->right, searchedValue);
		}
	}
}

struct Node* postorderSearch(struct Node* root, int searchedValue) {

	if (root == NULL) {
		return NULL;
	}
	else if (root != NULL) {
		struct Node* temp = root;
		
		postorderSearch(temp->left, searchedValue);
		postorderSearch(temp->right, searchedValue);

		if (temp->data == searchedValue) {
			printf("\n\nvalue found!\n");
			return temp;
		}
		
	}
}

struct Node* inorderSearch(struct Node* root, int searchedValue) {

	if (root == NULL) {
		return NULL;
	}
	else if (root != NULL) {
		struct Node* temp = root;
		
		inorderSearch(temp->left, searchedValue);
		if (temp->data == searchedValue) {
			printf("\n\nvalue found!\n");
			return temp;
		}
		inorderSearch(temp->right, searchedValue);
		
	}
}

