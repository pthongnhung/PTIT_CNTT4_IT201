
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
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");

    if (q->rear != NULL) {
        printf("Rear: %d\n", q->rear->data);
    } else {
        printf("Rear: NULL\n");
    }
}
void dequeue(Queue* q)
{
    Node* temp = q->front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    q->front = temp->next;
}
int main() {
    Queue* queue = createQueue();

    int n;
    printf("Nhap so lan them vao hang doi: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        enqueue(queue);
        displayQueue(queue);
    }
    dequeue(queue);
    displayQueue(queue);

    return 0;
}
