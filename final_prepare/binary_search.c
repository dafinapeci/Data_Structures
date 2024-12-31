#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void deleteNode(struct Node** root);
int processLeftMost(struct Node** root);

struct Node* search(int searchedValue, struct Node* root) {
    if (root != NULL) { // not empty
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
    return NULL;
}

void insert(int data, struct Node** root) {
    if (*root == NULL) {
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

void delete_(int data, struct Node** root) {
    if (*root == NULL) {
        return; 
    }
    if (data < (*root)->data) {
        delete_(data, &(*root)->left);
    }
    else if (data > (*root)->data) {
        delete_(data, &(*root)->right);
    }
    else {
        deleteNode(root); 
    }
}


void deleteNode(struct Node** root) {
    struct Node* deleted;

    // Case 1: The node is a leaf
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
    }
    // Case 2: The node has no left child
    else if ((*root)->left == NULL) {
        deleted = *root;
        *root = (*root)->right;
        free(deleted);
    }
    // Case 3: The node has no right child
    else if ((*root)->right == NULL) {
        deleted = *root;
        *root = (*root)->left;
        free(deleted);
    }
    // Case 4: The node has two children
    else {
        (*root)->data = processLeftMost(&(*root)->right);
    }
}

int processLeftMost(struct Node** root) {
    if ((*root)->left == NULL) {
        int data = (*root)->data;
        struct Node* deleted = *root;
        *root = (*root)->right;
        free(deleted);
        return data;
    }
    else {
        return processLeftMost(&(*root)->left);
    }
}

void printPreorder(struct Node* root) {
    if (root != NULL) {
        printf("%d   ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    struct Node* root = NULL; 
    insert(11, &root);
    insert(15, &root);
    insert(25, &root);
    insert(5, &root);
    insert(30, &root);

    printf("preorder traversal before deletion: ");
    printPreorder(root);
    printf("\n");

    delete_(15, &root);
    printf("preorder traversal after deletion 15: ");
    printPreorder(root);
    printf("\n");

    delete_(5, &root);
    printf("preorder traversal after deletion 5: ");
    printPreorder(root);
    printf("\n");

    return 0;
}
