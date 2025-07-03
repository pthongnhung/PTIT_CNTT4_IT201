#include<stdio.h>
//Khoi tao cau truc du lieu cua 1 phan tu
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//Ham tao node moi
Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
int length(Node* head)
{
    Node* current=head;
    int count=0;
    while (current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
void printList(Node*head)
{
    Node* current=head;
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main()
{
    Node* head=createNode(10);
    head->next=createNode(20);
    printList(head);
    return 0;
}