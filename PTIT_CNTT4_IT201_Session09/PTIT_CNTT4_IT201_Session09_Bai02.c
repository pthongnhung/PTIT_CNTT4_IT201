#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* printList(Node* head)
{
    Node* current=head;
    int index=1;
    while (current!=NULL)
    {
        printf("Node %d: %d\n",index,current->data);
        current=current->next;
        index++;
    }
}
int main()
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    printList(head);
    return 0;
}
