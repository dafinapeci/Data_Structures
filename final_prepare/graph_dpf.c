// Version 1 - from youtube
// depth first search
// RECURSIVE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// adjacency list
typedef struct Node {
	int vertex;
	struct Node* next;
};

typedef struct Graph {
	int V;
	struct Node** adjLists;
};

struct Node* createNode(int v) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = vertices;

	graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) { // src: source, dest: destination
	struct Node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
}

void DFSUtil(struct Graph* graph, int v, int* visited) {
	visited[v] = 1;
	printf("%d  ", v);

	struct Node* temp = graph->adjLists[v];
	while (temp) {
		int adjVertex = temp->vertex;
		if (!visited[adjVertex]) {
			DFSUtil(graph, adjVertex, visited);
		}
		temp = temp->next;
	}
}

void DFS(struct Graph* graph, int startVertex) {
	int* visited = (int*)malloc(graph->V * sizeof(int));

	for (int i = 0; i < graph->V; i++) {
		visited[i] = 0;
	}

	DFSUtil(graph, startVertex, visited);
	free(visited);
}

int main() {
	Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 0);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 3);

	printf("Following is Depth First Traversal (starting from vertex 1):\n");
	DFS(graph, 1);

	return 0;
}


// version 2
// ITERATIVE

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int V;
    Node** adjLists;
} Graph;

// Structure to represent a stack
typedef struct Stack {
    int* items;
    int top;
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->items[stack->top--];
}

// Function to create a node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Iterative DFS function
void DFSIterative(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    Stack* stack = createStack(graph->V);
    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int vertex = pop(stack);

        if (!visited[vertex]) {
            visited[vertex] = 1; // Mark as visited
            printf("%d ", vertex);
        }

        Node* temp = graph->adjLists[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                push(stack, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(stack->items);
    free(stack);
    free(visited);
}

// Main function
int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("DFS (Iterative) starting from vertex 2:\n");
    DFSIterative(graph, 2);

    return 0;
}
