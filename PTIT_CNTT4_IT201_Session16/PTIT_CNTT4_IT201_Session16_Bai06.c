
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Hàm tạo node mới
Node* createNode() {
    int value;
    printf("Nhap so nguyen: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm vào hàng đợi
void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void displayQueue(Queue* q) {
    Node* temp = q->front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

}

int main() {
    Queue* queue = createQueue();

    int n;
    printf("Nhap so lan them vao hang doi: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        enqueue(queue);
    }
    displayQueue(queue);
    return 0;
}
