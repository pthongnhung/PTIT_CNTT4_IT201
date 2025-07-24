#include <stdio.h>

#define SIZE 3

void initGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
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

    printf("Initial directed graph:\n");
    printGraph(graph);

    addEdge(graph, 1, 2);

    printf("\nGraph after adding edge from 1 to 2:\n");
    printGraph(graph);
    return 0;
}