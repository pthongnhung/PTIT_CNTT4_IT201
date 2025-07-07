#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printfList(Node* head)
{
    Node* current=head;
    int index=1;
    while (current!=NULL)
    {
        printf("data %d: %d\n",index,current->data);
        index++;
        current=current->next;
    }
}
int main()
{
    Node* head=createNode(1);
    Node* node2=createNode(2);
    Node* node3=createNode(3);
    Node* node4=createNode(4);
    Node* node5=createNode(5);
    head->next=node2;
    node2->prev=head;
    node2->next=node3;
    node3->prev=node2;
    node3->next=node4;
    node4->prev=node3;
    node4->next=node5;
    node5->prev=node4;
    printfList(head);
    return 0;
}