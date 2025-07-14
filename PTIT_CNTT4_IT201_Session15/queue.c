#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Job
{
    char name[20];
    int id;
}Job;
typedef struct Queue
{
    Job* jobs;
    int front;
    int rear;
    int cap;
}Queue;
Queue* createQueue(int capacity)
{
    Queue* newQueue=(Queue*)malloc(sizeof(Queue));
    newQueue->front=0;
    newQueue->rear=-1;
    newQueue->cap=capacity;
    newQueue->jobs=(Job*)malloc(newQueue->cap*sizeof(Job));
    return newQueue;
}
int isFull(Queue* queue)
{
    if(queue->rear==queue->cap-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(Queue* queue, Job job)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    queue->rear=queue->rear+1;
    queue->jobs[queue->rear]=job;
}
void printQueue(Queue* queue)
{
    if (queue->front>queue->rear)
    {
        printf("Hang doi rong");
        return ;
    }
    for (int i=queue->front;i<=queue->rear;i++)
    {
        printf("%d ",queue->jobs[i].id);
        printf("%s\n",queue->jobs[i].name);
    }
}
int isEmpty(Queue* queue)
{
    if (queue->front>queue->rear)
    {
        return 1;
    }
    return 0;
}
void dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    queue->front=queue->front+1;
}
int main()
{
    Queue* queue=createQueue(3);
    for (int i=0;i<3;i++)
    {
        printf("Nhap ten cong viec: ");
        fgets(queue->jobs[i].name,20,stdin);
        queue->jobs[i].name[strcspn(queue->jobs[i].name, "\n")] = '\0';
        queue->jobs[i].id=i+1;
        queue->rear=queue->rear+1;
    }
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}