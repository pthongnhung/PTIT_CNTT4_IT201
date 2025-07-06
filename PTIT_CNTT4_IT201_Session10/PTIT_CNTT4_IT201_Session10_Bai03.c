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
Node* insertTail(Node* head,int data)
{
    if(head==NULL) return NULL;
    Node* newNode=createNode(data);
    Node* current=head;
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    return head;
}
void freeList(Node* head)
{
    Node* temp;
    while(head!=NULL)
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
    printfList(head);
    int n;
    printf("Nhap phan tu ban muon them: ");
    scanf("%d",&n);
    head=insertTail(head,n);
    printfList(head);
    freeList(head);
    return 0;
}