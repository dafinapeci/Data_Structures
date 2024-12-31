// Version 1 - from youtube
// depth first search

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
