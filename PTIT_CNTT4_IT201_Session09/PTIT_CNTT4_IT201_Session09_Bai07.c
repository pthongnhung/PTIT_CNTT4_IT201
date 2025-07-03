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
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int length(Node*head)
{
    int count=0;
    Node* current=head;
    while (current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
Node* insertHead(Node* head,int value)
{
    Node* newNode=createNode(value);
    newNode->next=head;
    return newNode;
}
Node* insertTail(Node* head,int value)
{
    Node* newNode=createNode(value);
    Node* current=head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    return head;
}
Node* insertAt(Node* head,int value,int index)
{
    Node* newNode=createNode(value);
    Node* current=head;
    if (index==0) insertHead(newNode,value);
    else if (index==length(head)-1)insertTail(newNode,value);
    for (int i=0;i<index-1;i++)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=newNode;
    newNode->next=temp;
    return head;
}
void freeList(Node* head)
{
    Node* temp;
    while (head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
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
    int index,value;
    printf("ban muon them phan tu vao vi tri nao: ");
    scanf("%d",&index);
    if (index<0 || index>length(head))
    {
        printf("Vi tri khong hop le");
        return 0;
    }
    printf("ban muon them phan tu co gia tri la: ");
    scanf("%d",&value);
    head=insertAt(head,value,index);
    printList(head);
    freeList(head);
    return 0;
}
