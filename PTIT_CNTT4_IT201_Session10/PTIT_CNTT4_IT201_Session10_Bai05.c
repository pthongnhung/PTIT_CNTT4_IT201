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
Node* removeHead(Node* head)
{
    if(head==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* removeTail(Node* head)
{
    if(head==NULL) return NULL;
    Node* current=head;
    while (current->next->next!=NULL)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=NULL;
    free(temp);
    return head;
}
Node* removeAt(Node* head,int index)
{
    if(head==NULL) return head;
    if (index==0) return removeHead(head);
    if (index==1) return removeTail(head);
    Node* current=head;
    for(int i=0;i<index-1;i++)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=temp->next;
    free(temp);
    return head;
}
int main()
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    printfList(head);
    int index;
    printf("Nhap vi tri can xoa: ");
    scanf("%d",&index);
    if (index<0 || index>length(head))
    {
        printf("Vi tri khong hop le");
        return 0;
    }
    head=removeAt(head,index);
    printfList(head);
    freeList(head);
    return 0;
}