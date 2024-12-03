#define _CRT_SECURE_NO_WARNINGS // Visual Studio kullanıyorsanız bu satır gereklidir.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
	int number;
	node* next;
	node* prev;
};
node* head = NULL;
node* tail = NULL;
node* temp;
void insert_item(int item) {
	struct node* temp = (node*)malloc(sizeof(node));//temp tüm iki kutucuğu ifade eder

	temp->number = item;//yeni elemanı ekler
	temp->next = NULL;//bu yeni eklenmiş elemanın next null yapar yeni eleman eklenene kadar
	
	if (head == NULL)
	{
		head = temp;//başlangıç durumudur head e ekleme bir kez yapılır
		temp->prev = NULL;
	}
	else
	{
		struct node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->prev = current;
		current = temp;
	}
}
void free_list() {
	struct node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}
void print() {
	struct node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	struct node* head1 = current;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("ters list: ");
	while (head1 != NULL) {
		printf("%d\t", head1->number);
		head1 = head1->prev;
	}
	struct node* head2 = head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("düz list: ");
	while (head2 != NULL) {
		printf("%d\t", head2->number);
		head2 = head2->next;
	}
}

int main() {
	insert_item(6);
	insert_item(15);
	insert_item(30);
	insert_item(40);
	print();
	free_list();
	return 0;
}
