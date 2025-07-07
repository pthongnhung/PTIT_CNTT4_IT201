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
    printf("NULL<-");
    while (current!=NULL)
    {
        printf("%d",current->data);
       if (current->next==NULL)
       {
           printf("->");
       }else
       {
           printf("<->");
       }
        current=current->next;
    }
    printf("NULL\n");
}
Node* insertAtEnd(Node* head,int data)
{
    Node* newNode=createNode(data);
    Node* current=head;
    if (head==NULL)
    {
        return newNode;
    }
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
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
    int value;
    printf("Enter value to be inserted : ");
    scanf("%d",&value);
    head=insertAtEnd(head,value);
    printfList(head);
    return 0;
}