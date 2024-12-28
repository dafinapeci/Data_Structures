#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_STACK 10

typedef struct {
	int value;
} item;

typedef struct stack {
	item x;
	struct stack* next;
};

typedef struct stack* stack_pointer;

stack_pointer top[MAX_STACK];

void push(stack_pointer* top, item x) {
	stack_pointer temp = (stack*)malloc(sizeof(stack));

	temp->x = x;
	temp->next = *top;
	*top = temp;
	
}


void pop(stack_pointer* top) {
	if (*top == NULL) {
		return;
	}
	stack_pointer temp = *top;
	*top = (*top)->next;
	free(temp);
}
void print(stack_pointer* top) {
	stack_pointer temp = *top;
	printf("multiple stack list: ");
	while (temp != NULL) {
		printf("%d -> ", temp->x.value);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
    // Initialize all stack pointers in the array to NULL
    // This ensures that all stacks (top[0], top[1], ..., top[MAX_STACK-1]) start as empty.
    for (int i = 0; i < MAX_STACK; i++) {
        top[i] = NULL;
    }

    // Create items to push onto the first stack (top[0])
    item nr;
    nr.value = 10;
    item nr1;
    nr1.value = 20;
    item nr2;
    nr2.value = 30;

    // Add items to the first stack (top[0])
    push(&top[0], nr);
    push(&top[0], nr1);
    push(&top[0], nr2);

    // Print the contents of the first stack (top[0])
    print(&top[0]);

    // Pop an item from the first stack (top[0])
    pop(&top[0]);

    // Print the contents of the first stack again after popping
    print(&top[0]);

    // At this point, top[1] is still empty because we haven't pushed anything onto it.
    // The following print will show an empty stack.
    print(&top[1]); // Will print "NULL"

    // To add elements to the second stack (top[1]), create new items
    item nr3;
    nr3.value = 40;
    item nr4;
    nr4.value = 50;

    // Push items onto the second stack (top[1])
    push(&top[1], nr3);
    push(&top[1], nr4);

    // Now, top[1] contains elements, so printing it will show its contents.
    print(&top[1]); // Will print the list for top[1]

    return 0;
}
