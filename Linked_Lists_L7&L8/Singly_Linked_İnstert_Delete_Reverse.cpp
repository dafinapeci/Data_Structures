//this one insert from right and left / this one delete from right and left / this one reverse iterative and recursive
#include <stdio.h>
#include <stdlib.h>

struct node{
	int item;
	node* next;
};

void insert_from_left(node** head,int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;
	temp->next = *head;
	*head = temp;
}
void delete_from_left(node** head) {
	node* temp = *head;
	*head = (*head)->next;
}

void insert_to_right(node** head, int item) {
	node* temp = (node*)malloc(sizeof(node));
	temp->item = item;	
	temp->next = NULL;
	if (*head==NULL)
	{
		*head = temp;
	}
	else
	{
		node* current = *head;
		while (current->next!=NULL) {
			current = current->next;
		}
		current->next = temp;
		current = temp;
	}
}
void delete_to_right(node** head) {
	node* temp = *head;
	while (temp->next->next!=NULL) {
		temp = temp->next;
	}
	temp->next = NULL;
	
}
void reverse_recursive(node* head) {
	if (head==NULL)
	{
		return;
	}
	reverse_recursive((head)->next);
	printf("%d -> ", head->item);
}
struct node* reverse_iterative(node* head) {
	node* current = head;
	node* prev = NULL;
	node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}


void print(node** head) {
	node* current = *head;
	printf("list: ");
	while (current != NULL) {
		printf("%d -> ", current->item);
		current = current->next;
	}
	printf("NULL\n");
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
	node* head = NULL;
	node* head2 = NULL;
	insert_from_left(&head,1);
	insert_from_left(&head, 2);
	insert_from_left(&head, 3);
	insert_from_left(&head, 4);
	printf("\n");
	print(&head);
	delete_from_left(&head);
	print(&head);
	//printf("\n");
	//reverse_recursive(head);
	//printf("\n");
	//node* head3= reverse_iterative(head);
	//print(&head3);

	printf("ikinci olan\n");
	insert_to_right(&head2, 1);
	insert_to_right(&head2, 2);
	insert_to_right(&head2, 3);
	insert_to_right(&head2, 4);
	printf("\n");
	print(&head2);
	delete_to_right(&head2);
	print(&head2);
	//printf("\n");
	//reverse_recursive(head2);
	//printf("\n");

	free_list(&head);
	free_list(&head2);

}
