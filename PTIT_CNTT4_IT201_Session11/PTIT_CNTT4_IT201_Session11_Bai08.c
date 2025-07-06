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
        printf("%d ",current->data);
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
Node* deleteAtPosition(Node* head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 0)
    {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    Node* current = head;
    int index = 0;
    while (current != NULL && index < position)
    {
        current = current->next;
        index++;
    }

    if (current == NULL)
        return head;

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
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
    int index;
    printfList(head);
    printf("Nhap vao vi tri muon xoa: ");
    scanf("%d",&index);

    head = deleteAtPosition(head, index);
    printfList(head);

    return 0;
}
