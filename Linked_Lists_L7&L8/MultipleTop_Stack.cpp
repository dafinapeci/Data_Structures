#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1
#define MAX_STACK 10

typedef struct {
	int value; // Diğer alanlar eklenebilir
} item;

typedef struct stack {
	item x;
	struct stack* next;
} stack;

typedef stack* stack_pointer;

#define ISFULL(p) (!(p))
#define ISEMPTY(p) ((p) == NULL)

void add_stack(stack_pointer* top, item x) {
	stack_pointer p = (stack*)malloc(sizeof(stack));
	if (ISFULL(p)) {
		printf("\n Memory allocation failed");
		exit(1);
	}
	p->x = x;
	p->next = *top;
	*top = p;
}

item remove_stack(stack_pointer* top) {
	stack_pointer p = *top;
	item x;
	if (ISEMPTY(p)) {
		printf("\n Stack is empty!");
		exit(1);
	}
	x = p->x;
	*top = p->next;
	return x;
}
void print_stack(stack_pointer top) {
	printf("Stack: ");
	while (top != NULL) {
		printf("%d -> ", top->x.value);
		top = top->next;
	}
	printf("NULL\n");
}
void free_stack(stack_pointer* top) {
	stack_pointer temp;
	while (*top != NULL) {
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

int main() {
	stack_pointer top[MAX_STACK] = {NULL};
	item x1 = { 10 };
	item x2 = { 20 };
	item x3 = { 30 };
	item x4 = { 11 };
	item x5 = { 22 };
	item x6 = { 33 };

	add_stack(&top[0], x1);
	add_stack(&top[0], x2);
	add_stack(&top[0], x3);
	add_stack(&top[1], x4);
	add_stack(&top[1], x5);
	add_stack(&top[1], x6);

	print_stack(top[0]);
	print_stack(top[1]);

	item popped_item = remove_stack(&top[0]);
	printf("Popped item: %d\n", popped_item.value);
	print_stack(top[0]);
	free_stack(&top[0]);
	free_stack(&top[1]);
	return 0;
}
