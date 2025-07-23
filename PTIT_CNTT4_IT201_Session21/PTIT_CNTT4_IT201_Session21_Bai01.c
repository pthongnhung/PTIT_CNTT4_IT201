#include <stdio.h>

#define SIZE 3

void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE];

    initGraph(graph);

    printf("Initial graph:\n");
    printGraph(graph);

    int firstNode = 1;
    int secondNode = 2;

    addEdge(graph, firstNode, secondNode);

    printf("\nGraph after adding edge between %d and %d:\n", firstNode, secondNode);
    printGraph(graph);

    return 0;
}