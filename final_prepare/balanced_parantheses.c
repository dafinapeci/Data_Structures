#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

void push(char s) {
	stack[++top] = s;
}

void pop() {
	top--;
}

int isMatching(char ch, char top) {
	if (ch == ')' && top == '(') {
		return 0;
	}
	else if (ch == ']' && top == '[') {
		return 0;
	}
	else if (ch == '}' && top == '{') {
		return 0;
	}
	else {
		return -1;
	}
}

int checkBalanced(const char exp[]) {
	int n = strlen(exp);
	
	for (int i = 0; i < n; i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if (isMatching(exp[i], stack[top]) == 0) {
				pop();
			}
			else {
				return -1; // not balanced
			}
		}
	}

	if (top >= 0) {
		return -1;
	}
	else { return 0; }
}

int main() {
	char exp[] = "{[]}()";
	int result = checkBalanced(exp);

	char exp2[] = "{[]})";

	int result2 = checkBalanced(exp2);

	if (result == 0) {
		printf("balanced!\n");
	}
	else {
		printf("imbalanced\n");
	}
	if (result2 == 0) {
		printf("balanced!\n");
	}
	else {
		printf("imbalanced\n");
	}
}
