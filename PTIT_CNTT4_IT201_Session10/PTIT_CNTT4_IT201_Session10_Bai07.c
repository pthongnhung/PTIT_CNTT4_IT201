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
void sortList(Node* head) {
    if (head == NULL) return;

    Node* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Hoán đổi giá trị (không đổi liên kết)
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    Node* head=createNode(1);
    head->next=createNode(5);
    head->next->next=createNode(3);
    head->next->next->next=createNode(9);
    head->next->next->next->next=createNode(2);
    printfList(head);
    sortList(head);
    printfList(head);
    return 0;
}