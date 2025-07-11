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
Node* removeHead(Node* head)
{
    if (head==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* removeTail(Node* head)
{
    if (head == NULL) return NULL;
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = NULL;
    free(temp);
    return head;
}
Node* removeAt(Node* head,int index)
{
    Node* current=head;
    if (index==0) removeHead(head);
    else if (index==length(head)-1) removeTail(head);
    for (int i=0;i<index-1;i++)
    {
        current=current->next;
    }
    Node* temp=current->next;
    current->next=temp->next;
    free(temp);
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
    int index;
    printList(head);
    printf("ban muon xoa phan tu vao vi tri nao: ");
    scanf("%d",&index);
    if (index<0 || index>length(head))
    {
        printf("Vi tri khong hop le");
        return 0;
    }
    head=removeAt(head,index);
    printList(head);
    return 0;
}
