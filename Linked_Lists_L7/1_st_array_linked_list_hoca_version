#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0
#define NULL -1  //null pointer -1, indicating the end of list

typedef struct {
	char name[10]; // the data we want 
	int link;  //pointer, it points towards the next node
} item;

item linkedlist[MAX_SIZE];
int free_;
int first;

void make_empty_list(void) {
	for (int i = 0; i < MAX_SIZE - 1; i++) {
		linkedlist[i].link = i + 1; //the link points to the next index, meaning the next node

	}

	linkedlist[MAX_SIZE - 1].link = NULL; // last item of list
	free_ = 0;
	first = NULL; // empty linked list
}

int get_item(int* r) { //return a free_ item from list
	if (free_ == NULL) { //no item to get, empty
		return FALSE;
	}
	else {
		*r = free_; //get item pointed by free_
		free_ = linkedlist[free_].link; // points next free_ item
		return TRUE;
	}
}

void return_item(int r) { //free_ the item
	linkedlist[r].link = free_; // Link the current item to the list of free_ items
	free_ = r; //Update the head of the free_ list to this item
}

void insert_item(const char name[], int* list) { // *list is the front or head of the list (beginning)
	int r, q, p;
	if (get_item(&r)) {
		strcpy(linkedlist[r].name, name);
		q = NULL;
		p = *list;
		while (p != NULL && strcmp(linkedlist[p].name, name) < 0) { // search right position
			q = p;
			p = linkedlist[p].link;
		}

		if (q == NULL) { // list is empty, so we insert the new item at the front of list
			*list = r;
			linkedlist[r].link = p;
		}
		else { //new item inserted in the middle
			linkedlist[q].link = r;
			linkedlist[r].link = p;
		}
	}
	else {
		printf("\n not enough free_ space!! \n");
	}
}

void print() {
	printf("\nindex\tname\tlink\n");

	for (int i = 0; i < MAX_SIZE; i++) { // print the whole array evem with the empty rows
		printf("%d\t%s\t%d\n", i, linkedlist[i].name, linkedlist[i].link);
	}

	printf("\n only the non-empty part: \n");
	printf("\nindex\tname\tlink\n");

	int sayac = first;

	while (sayac != NULL) {
		printf("%d\t%s\t%d\n", sayac, linkedlist[sayac].name, linkedlist[sayac].link);
		sayac = linkedlist[sayac].link;
	}

	printf("\nfree:%d", free_);
	printf("\nfirst:%d", first);
}

void delete_item(char name[], int* list) {
	int q, p;
	q = NULL;
	p = *list;
	int l;

	while (p != NULL && (l = strcmp(linkedlist[p].name, name)) < 0) { //search for the item
		q = p;
		p = linkedlist[p].link;
	}

	if (p == NULL || l > 0) { // end of the list
		printf("\n %s cannot be found \n", name);
	}
	else if (q == NULL) { // the first item will be deleted
		*list = linkedlist[p].link;
		return_item(p);
	}
	else { //get item pointed by 'p'
		linkedlist[q].link = linkedlist[p].link;
		return_item(p);
	}
}

void locate(const char searchname[]) {
	int sayac = first; 
	while (sayac != NULL) {
		if (strcmp(linkedlist[sayac].name, searchname) == 0) {
			printf("\nLocation: %d\t%s\t%d\n", sayac, linkedlist[sayac].name, linkedlist[sayac].link);
			break;
		}
		sayac = linkedlist[sayac].link;
	}
}

int main() {
	make_empty_list();
	char name[100][100] = { "apple", "orange", "banana", "grape", "kiwi" };
	for (int i = 0; i < 5; i++)
	{
		insert_item(name[i], &first);
	}
	print();
	delete_item(name[0], &first);
	insert_item("heyla", &first);
	delete_item(name[1], &first);
	print();

	locate("kiwi");
	return 0;
}
