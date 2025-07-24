#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

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

void DFS(Node** graph, int vertex, int* visited) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    Node* temp = graph[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int v, e;
    printf("Nhập số đỉnh (0 < v < 100): ");
    scanf("%d", &v);
    printf("Nhập số cạnh (0 < e < 100): ");
    scanf("%d", &e);

    if (v <= 0 || v >= 100 || e <= 0 || e >= 100) {
        printf("Giá trị không hợp lệ.\n");
        return 1;
    }

    Node** graph = (Node**)malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) {
        graph[i] = NULL;
    }

    printf("Nhập %d cạnh (mỗi cạnh: đỉnh1 đỉnh2):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(graph, u, w);
        } else {
            printf("Cạnh (%d, %d) không hợp lệ. Bỏ qua.\n", u, w);
        }
    }

    int start;
    printf("Nhập đỉnh bắt đầu duyệt DFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Đỉnh không hợp lệ.\n");
        return 1;
    }

    int visited[100] = {0};
    printf("Kết quả duyệt DFS từ đỉnh %d: ", start);
    DFS(graph, start, visited);
    printf("\n");

    for (int i = 0; i < v; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}