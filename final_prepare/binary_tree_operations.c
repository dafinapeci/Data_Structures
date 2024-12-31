#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* createNode(int data);
int isEmpty(struct Node* root);
int getHeight(struct Node* root);
int getNodeCount(struct Node* root);
int getRootData(struct Node* root);
void setRootData(struct Node** root, int data);
struct Node* addNode(struct Node* root, int data);
struct Node* removeNode(struct Node*, int data);
void removeAllNodes(struct Node** root);
struct Node* find(struct Node* root, int data);
int nodeDepth(Node* root, int value, int currentDepth);

int main() {
    struct Node* root = NULL;

    root = addNode(root, 10);
    root = addNode(root, 5);
    root = addNode(root, 15);

    printf("Tree Height: %d\n", getHeight(root));
    printf("Node Count: %d\n", getNodeCount(root));
    printf("Root Data: %d\n", getRootData(root));

    if (find(root, 15))
        printf("Tree contains 15\n");
    else
        printf("Tree does not contain 15\n");

    root = removeNode(root, 10);

    removeAllNodes(&root);

    if (root == NULL) {
        printf("Tree is empty.\n");
    }
    else {
        printf("Tree is not empty.\n");
    }
   
    return 0;
}



struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int isEmpty(struct Node* root) {
	return root == NULL;
}

int getHeight(struct Node* root) {
	if (!root) {
		return 0;
	}
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getNodeCount(struct Node* root) {
	if (!root) {
		return 0;
	}

	return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

int getRootData(struct Node* root) {
	if (!root) {
		printf("Tree is empty.\n");
		return -1;
	}

	return root->data;
}

void setRootData(struct Node** root, int data) {
	if (!(*root)) {
		*root = createNode(data);
	}
	else {
		(*root)->data = data;
	}
}

struct Node* addNode(struct Node* root, int data) {
	if (!root) {
		return createNode(data);
	}
	if (data < root->data) {
		root->left = addNode(root->left, data);
	}
	else {
		root->right = addNode(root->right, data);
	}

	return root;
}

struct Node* removeNode(struct Node* root, int data) {
    // Base case: If the root is NULL, the tree is empty or the node was not found
    if (!root) {
        return NULL;
    }

    // If the data to be deleted is smaller than the root's data,
    // move to the left subtree
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's data,
    // move to the right subtree
    else if (data > root->data) {
        root->right = removeNode(root->right, data);
    }
    // If the data matches the root's data, this is the node to delete
    else {
        // Case 1: The node has no left child
        if (!root->left) {
            struct Node* temp = root->right;  // Hold the right subtree
            free(root);                      // Free the current node
            return temp;                     // Return the right subtree to the parent
        }
        // Case 2: The node has no right child
        else if (!root->right) {
            struct Node* temp = root->left;  // Hold the left subtree
            free(root);                      // Free the current node
            return temp;                     // Return the left subtree to the parent
        }
        // Case 3: The node has two children
        else {
            // Find the in-order successor (smallest value in the right subtree)
            struct Node* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }

            // Replace the root's data with the in-order successor's data
            root->data = temp->data;

            // Delete the in-order successor from the right subtree
            root->right = removeNode(root->right, temp->data);
        }
    }

    // Return the updated root node to the parent
    return root;
}

void removeAllNodes(struct Node** root) {
    if (*root) {
        removeAllNodes(&(*root)->left);
        removeAllNodes(&(*root)->right);
        free(*root);
        *root = NULL;
    }
}

struct Node* find(struct Node* root, int data) {
    if (!root || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return find(root->left, data);
    }
    else if (data > root->data) {
        return find(root->right, data);
    }
}

int nodeDepth(Node* root, int value, int currentDepth) {
    if (root == NULL) {
        return -1; // Node not found
    }
    if (root->data == value) {
        return currentDepth;
    }
    else if (value < root->data) {
        return nodeDepth(root->left, value, currentDepth + 1);
    }
    else {
        return nodeDepth(root->right, value, currentDepth + 1);
    }
}
