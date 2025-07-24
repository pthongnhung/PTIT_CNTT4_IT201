#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node** createGraph(int n) {
    Node** adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }
    return adjList;
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** graph, int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}

void printGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Đỉnh %d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Node** graph, int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int main() {
    int n;
    scanf("%d", &n);

    Node** graph = createGraph(n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    printGraph(graph, n);

    freeGraph(graph, n);
    return 0;
}