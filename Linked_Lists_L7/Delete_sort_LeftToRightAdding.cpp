#include <stdio.h>
#include <stdlib.h>

struct node {
	int number;
	struct node* next;
};

void insert_at_position(struct node** head, int item);
void free_list(struct node** head);
void print_list(struct node* head);
void print_recursive(struct node* head);
void print_recursive_reverse(struct node* head);

void insert_at_position(struct node** head, int item) {
	// Doğru bellek ayırma işlemi
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (temp == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	temp->number = item;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
	}
	else {
		struct node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}
void Delete(struct node** head,int n) {
	struct node* temp = *head;
	if (n==1)
	{
		*head = temp->next;
		return;
	}
	int i=1;
	while (temp->next!=NULL) {
		if (i+1!=n)
		{
			temp = temp->next;
		}
		else
		{
			break;
		}
		i++;
	}
	struct node* temp2 = temp->next;
	temp->next = temp2->next;

}

void print_list(struct node* head) {
	struct node* current = head;
	printf("List: ");
	while (current != NULL) {
		printf("%d -> ", current->number);
		current = current->next;
	}
	printf("NULL\n");
}

void print_recursive(struct node* head) {
	if (head == NULL) {
		return;
	}
	printf("%d -> ", head->number);
	print_recursive(head->next);
}

void print_recursive_reverse(struct node* head) {
	if (head == NULL) {
		return;
	}
	print_recursive_reverse(head->next);
	printf("%d -> ", head->number);
}

void free_list(struct node** head) {
	struct node* temp;
	while (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int main() {
	struct node* head = NULL;

	// Eleman ekleme
	insert_at_position(&head, 10);
	insert_at_position(&head, 21);
	insert_at_position(&head, 32);
	insert_at_position(&head, 73);
	insert_at_position(&head, 84);

	// Listeyi yazdırma
	print_list(head);
	printf("\nDizi (recursive): ");
	print_recursive(head);
	printf("\nDizi (reverse recursive): ");
	print_recursive_reverse(head);
	printf("NULL\n");

	Delete(&head,3);
	print_list(head);
	// Belleği serbest bırakma
	free_list(&head);

	return 0;
}
