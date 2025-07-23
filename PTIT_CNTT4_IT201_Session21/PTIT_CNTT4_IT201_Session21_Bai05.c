#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initGraph(Node* graph[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        graph[i] = NULL;
    }
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[SIZE], int startNode, int endNode) {
    Node* newNode1 = createNode(endNode);
    newNode1->next = graph[startNode];
    graph[startNode] = newNode1;

    Node* newNode2 = createNode(startNode);
    newNode2->next = graph[endNode];
    graph[endNode] = newNode2;
}

void printGraph(Node* graph[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* graph[SIZE];

    initGraph(graph);

    printf("Initial graph:\n");
    printGraph(graph);

    addEdge(graph, 1, 2);
    printf("\nGraph after adding edge 1-2:\n");
    printGraph(graph);

    addEdge(graph, 0, 1);
    printf("\nGraph after adding edge 0-1:\n");
    printGraph(graph);

    return 0;
}