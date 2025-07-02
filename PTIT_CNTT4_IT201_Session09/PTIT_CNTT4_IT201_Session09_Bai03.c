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
void printList(Node* head)
{
    Node* current=head;
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL");
}
int findItem(Node* head,int search)
{
    Node* current=head;
    while (current!=NULL)
    {
        if (current->data==search)
        {
            return 1;
        }
        current=current->next;
    }
    return 0;
}
int main()
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    printList(head);
    int search;
    printf("\nNhap phan tu can tim kiem: ");
    scanf("%d",&search);
    if (findItem(head,search))
    {
        printf("TRUE");
    }else
    {
        printf("FALSE");
    }
    return 0;
}
