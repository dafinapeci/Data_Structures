//insert,height,depth(her bir istenilen eleman için),delete,inorder,levelprint,reverse
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_SIZE 100

struct node {
	int key;
	node* left;
	node* right;
};
void insert(int key,node** root) {
	if (*root==NULL)
	{
		*root = (node*)malloc(sizeof(node));
		(*root)->key = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (key < (*root)->key) {
		insert(key, &(*root)->left);
	}
	else if (key > (*root)->key) {
		insert(key, &(*root)->right);
	}
}
struct node* search(int key,node* root) {
	if (root!=NULL)
	{
		if (key==(root)->key)
		{
			return root;
		}
		else if (key<root->key) {
			search(key, root->left);
		}
		else if (key > root->key) {
			search(key, root->right);
		}
	}
	else
	{
		return NULL;
	}
}
void inorder(node* root) {
	if (root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d  ",root->key);
	inorder(root->right);
}
int treeLevel(struct node* root) {
	if (root == NULL) {
		return 0;
	}
	int leftlevel = treeLevel(root->left);
	int rightlevel = treeLevel(root->right);
	if (leftlevel>rightlevel)
	{
		return leftlevel + 1;
	}
	else
	{
		return rightlevel + 1;
	}
}
void printLevel(struct node* root, int level) {
	if (root == NULL) {
		return;
	}
	if (level == 1) {
		printf("%d ", root->key);  // Bu seviyedeki düğümü yazdır
	}
	else if (level > 1) {
		printLevel(root->left, level - 1);  // Sol alt ağacı işle
		printLevel(root->right, level - 1); // Sağ alt ağacı işle
	}
}
void levelOrderTraversal(struct node* root) {
	int level = treeLevel(root);  // Ağacın derinliğini al
	for (int i = 1; i <= level; i++) {
		printLevel(root, i);  // Her seviyedeki düğümleri yazdır
		printf("\n");
	}
}
int left_most(struct node** root) {
	if ((*root)->left == NULL)
	{
		int key = (*root)->key;
		node* deleted = *root;
		(*root) = (*root)->right;
		deleted->right = NULL;
		free(deleted);
		return key;
	}
	else
	{
		return left_most(&(*root)->left);
	}
}
void delete_node(node** root) {
	node* deleted = NULL;
	//case 1
	if ((*root)->left==NULL && (*root)->right==NULL)
	{
		free(*root);
		*root = NULL;
	}
	//case 2 only left
	else if ((*root)->left != NULL && (*root)->right == NULL)
	{
		deleted = *root;//eski değeri koru
		(*root) = (*root)->left;//soldakini atadık
		deleted->left = NULL;//eski değerin yerinin solunu boşalt
		free(deleted);	
	}
	else if ((*root)->left == NULL && (*root)->right != NULL)
	{
		deleted = *root;//eski değeri koru
		(*root) = (*root)->right;//soldakini atadık
		deleted->right = NULL;//eski değerin yerinin solunu boşalt
		free(deleted);
	}
	else
	{
		(*root)->key =left_most(&(*root)->right) ;
	}
}

void Delete(int key ,node** root) {
	if (*root==NULL)
	{
		return;
	}
	else if (key==(*root)->key) {
		delete_node(root);
	}
	else if (key < (*root)->key) {
		Delete(key, &(*root)->left);
	}
	else if (key > (*root)->key) {
		Delete(key, &(*root)->right);
	}
}

struct node* _mim_(node** root) {
	if ((*root)->left==NULL)
	{
		return *root;
	}
	_mim_(&(*root)->left);
}
struct node* _max_(node** root) {
	if ((*root)->right == NULL)
	{
		return *root;
	}
	_max_(&(*root)->right);
}
struct node* _from_last_second_(node** root) {
	if ((*root)->right->right == NULL)
	{
		return *root;
	}
	_from_last_second_(&(*root)->right);
}
int Height(node* root) {
	if (root==NULL)
	{
		return 0;
	}
	int left = Height((root)->left);
	int right = Height((root)->right);
	if (left>right)
	{
		return left +1;
	}
	else
	{
		return right +1;
	}
}
int depth(node* root,int key) {
	int left=0;
	int right=0;
	if (root == NULL)
	{
		return -1;
	}
	if (root->key==key)
	{
		return 0;
	}
	left = depth((root)->left,key);
	right = depth((root)->right,key);
	if (left !=-1)
	{
		return left + 1;
	}
	else if(right!=-1)
	{
		return right + 1;
	}
}
void reverse_tree(node* root) {
	if (root == NULL) {
		return;
	}

	node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	reverse_tree(root->left);
	reverse_tree(root->right);
}

int main() {
	struct node* root = NULL;
	insert(5,&root);
	insert(3, &root);
	insert(7, &root);
	insert(2, &root);
	insert(4, &root);
	insert(6, &root);
	insert(8, &root);
	inorder(root);
	printf("level order\n");//gerçek ağaç gibi bastırır
	levelOrderTraversal(root);
	//Delete(3, &root);
	printf("\n");
	//levelOrderTraversal(root);
	//printf("\n");
	
	inorder(root);
	printf("\n");
	
	node* mim = _mim_(&root);
	printf("mim == %d", mim->key);
	printf("\n");
	
	node* max = _max_(&root);
	printf("max == %d\n", max->key);

	int height = Height(root);
	printf("%d\n", height);
	
	int derinlik = depth(root,7);
	printf("%d\n", derinlik);

	node* last2nd = _from_last_second_(&root);
	printf("last 2nd :%d\n", last2nd->key);

	printf("ters çevrilmiş hali");
	reverse_tree(root);
	inorder(root);
	levelOrderTraversal(root);
	return 0;
}
