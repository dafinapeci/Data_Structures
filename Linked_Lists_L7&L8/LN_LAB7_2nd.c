#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define NULL -1

typedef struct {
	char name[10];
	int link;
} item;

void print(item list[], int first) {
	int sayac = first;
	printf("Original unordered list:\n");
	printf("Index\tName\tLink\n");
	for (int i = 0; i < MAX_SIZE - 1; i++) {
		printf("%d\t%s\t%d\n", i, list[i].name, list[i].link);
	}
	printf("Ordered list names: \n");
	while (sayac != NULL) {
		printf("%s\t", list[sayac].name);
		sayac = list[sayac].link;
	}
}

int main() {
	int first = 1;
	item list[MAX_SIZE] = {
		{"Eyup", 4},
		{"Ayse", 2},
		{"Aziz", 3},
		{"Bora", 0},
		{"Kaan", 7},
		{"Muge", 6},
		{"Ugur", -1},
		{"Leyla", 5}
	};

	print(list, first);
}
