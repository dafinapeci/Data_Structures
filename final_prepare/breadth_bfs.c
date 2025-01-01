#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int V;             // No. of vertices
    Node** adjLists;   // Array of adjacency lists
} Graph;

// Structure to represent a queue
typedef struct Queue {
    int* items;        // Array to store queue elements
    int front;         // Front index
    int rear;          // Rear index
    int maxSize;       // Maximum size of the queue
} Queue;

// Function to create a queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->maxSize = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Enqueue an element
void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->maxSize - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = value;
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Function to create a new graph node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL; // Initialize adjacency list for each vertex
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to perform BFS traversal
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int)); // Array to keep track of visited vertices
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    Queue* queue = createQueue(graph->V); // Create a queue for BFS

    visited[startVertex] = 1; // Mark the start vertex as visited
    enqueue(queue, startVertex); // Enqueue the start vertex

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue); // Dequeue a vertex
        printf("%d ", currentVertex);      // Process the dequeued vertex

        Node* temp = graph->adjLists[currentVertex]; // Get all adjacent vertices
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) { // If an adjacent vertex has not been visited
                visited[adjVertex] = 1; // Mark it as visited
                enqueue(queue, adjVertex); // Enqueue the adjacent vertex
            }
            temp = temp->next;
        }
    }

    free(queue->items); // Free the queue
    free(queue);        // Free the queue structure
    free(visited);      // Free the visited array
}

// Main function
int main() {
    Graph* graph = createGraph(4); // Create a graph with 4 vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Following is Breadth First Traversal (starting from vertex 2):\n");
    BFS(graph, 2);

    return 0;
}
