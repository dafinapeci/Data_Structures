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

void print(item list[]) {
	int sayac = 0;
	while (sayac != NULL) {
		printf("%d\t%s\t%d\n", sayac, list[sayac].name, list[sayac].link);
		sayac = list[sayac].link;
	}
}

int main() {
	
	item list[MAX_SIZE] = {
		{"Arzu", 1},
		{"Ayse", 2},
		{"Aziz", 3},
		{"Bora", 4},
		{"Kaan", 5},
		{"Muge", 6},
		{"Ugur", NULL}
	};

	print(list);
}
