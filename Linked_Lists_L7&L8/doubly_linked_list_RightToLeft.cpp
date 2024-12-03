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
	temp->next = head;//bu yeni eklenmiş elemanın next null yapar yeni eleman eklenene kadar
	if (head!=NULL)
	{
		head->prev = temp;
	}
	head = temp;
	temp->prev = NULL;

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
	struct node* head3 = head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("\ndüz list: ");
	while (head3 != NULL) {
		printf("%d \t", head3->number);
		head3 = head3->next;
	}
	struct node* head2 = head;//bu ilk elemanı gösterir atama yapınca head 1 de orayı gösteriyor o elemanın  nexti sonuçta sonraki elemanı gösterir 
	printf("\ndüz list: \n");
	while (head2 != NULL) {
		printf("%d:index %d:number %d:next %d:prev\n",head2, head2->number,head2->next,head2->prev);
		head2 = head2->next;
	}
}

int main() {
	insert_item(6);
	insert_item(15);
	insert_item(30);
	insert_item(40);
	printf("head is:%d\n", head->number);
	print();
	free_list();
	
	return 0;
}
