#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

void inorder(struct Node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}

void preorder(struct Node* root) {
	if (root != NULL) {
		printf("%d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d  ", root->data);
	}
}



