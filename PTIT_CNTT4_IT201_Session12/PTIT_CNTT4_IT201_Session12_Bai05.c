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
int length(Node* head)
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
Node* removeHead(Node* head)
{
    if (head==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    if (head!=NULL)
    {
        head->prev=NULL;
    }
    free(temp);
    return head;
}
Node* removeAtEnd(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* current=head;
    while(current->next->next!=NULL)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=NULL;
    free(temp);
    return head;
}
Node* removeAtPos(Node* head,int pos)
{
    if (head==NULL)
    {
        return NULL;
    }
    if (pos==0)
    {
        return removeHead(head);
    }
    if (pos==length(head)-1)
    {
        return removeAtEnd(head);
    }
    if (pos<0 || pos>length(head))
    {
        printf("Vi tri khong hop le");
        return head;
    }
    Node* current=head;
    for (int i=0;i<pos-1;i++)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=temp->next;
    temp->next->prev=current;
    free(temp);
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
    int pos;
    printf("Nhap vi tri can xoa: ");
    scanf("%d",&pos);
    head=removeAtPos(head,pos);
    printfList(head);
    return 0;
}