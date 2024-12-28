#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 15
#define EMPTY -1
#define TRUE 0
#define FALSE 1

typedef struct {
	char name[10];
	int link;
} item;

item linkedList[MAX_SIZE];
int first;
int free_;

void make_empty_list() {
	for (int i = 0; i < MAX_SIZE - 1; i++) {
		linkedList[i].link = i + 1;
	}

	linkedList[MAX_SIZE - 1].link = EMPTY; // last element points to NULL to let know the end of list
	free_ = 0;  // the list is empty and the first free element is at 0'th index
	first = EMPTY; // first element is yet to be inserted
}

int get_item(int* r) { // returns a free item from list
	if (free_ == EMPTY) { // the list is full and no free item is left
		return FALSE;
	}
	else {
		*r = free_;
		free_ = linkedList[free_].link; // the next free item is the item that free was previously pointing by link
		return TRUE;
	}
}

void return_item(int r) {
	linkedList[r].link = free_;  
	free_ = r;  // now r is free and it shows as a free item too
}

void insert_item(const char name[], int* list) {
	int r, q, p;
	if (get_item(&r)) {
		strcpy(linkedList[r].name, name);
		q = EMPTY;
		p = *list;

		while (p != EMPTY && strcmp(linkedList[p].name, name) < 0) { // finding the right position
			q = p;
			p = linkedList[p].link;
		}

		if (q == EMPTY) { // the item will be inserted at front
			*list = r;
			linkedList[r].link = p;
		}

		else {
			linkedList[q].link = r;
			linkedList[r].link = p;
		}
	}
}

void delete_item(const char name[], int* list) {
	int q, p;
	q = EMPTY;
	p = *list;
	int l;

	while (p != EMPTY && (l = strcmp(linkedList[p].name, name)) < 0) {
		q = p;
		p = linkedList[p].link;
	}
	if (p == EMPTY) { // item not found
		printf("\nnot found: %s\n", name);
		return;
	}
	else if (q == EMPTY) { // first item to be deleted
		*list = linkedList[p].link;
		return_item(p);
	}
	else { // middle item to be deleted
		linkedList[q].link = linkedList[p].link;
		return_item(p);
	}
}

void printList() {
/*	int i = first;
	while (i != EMPTY) {
		printf("Name: %s\t Link: %d\n", linkedList[i].name, linkedList[i].link);
		i = linkedList[i].link;
	}*/

	for (int i = 0; i < MAX_SIZE; i++) {
		printf("Name: %s\t Link: %d\n", linkedList[i].name, linkedList[i].link);
	}
}

int main() {
	make_empty_list();

	char namee[10] = "dafina";
	insert_item("dafina", &first);
	printList();

	return 0;
}
