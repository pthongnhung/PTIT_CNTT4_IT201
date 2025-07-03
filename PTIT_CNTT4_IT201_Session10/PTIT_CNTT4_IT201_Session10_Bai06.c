#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void printfList(Node* head)
{
    Node* current=head;
    while(current!=NULL)
    {
        printf("%d-> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int length(Node* head)
{
    int count=0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
Node* middle(Node* head,int length)
{
    if (head == NULL || length <= 0) return NULL;
    Node* current=head;
    int mid=length/2;
    for(int i=0;i<mid;i++)
    {
        current=current->next;
    }
    return current;
}
int main()
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    printfList(head);
    int len=length(head);
    Node* mid=middle(head,len);
    printf("%d",mid->data);
    return 0;
}