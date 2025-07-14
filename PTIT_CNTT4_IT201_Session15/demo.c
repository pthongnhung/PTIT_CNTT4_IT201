#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Student
{
    char name[20];
    int id;
}Student;
typedef struct Node
{
    Student student;
    struct Node *next;
}Node;
Node* createNode(char *name, int id)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    strcpy(newNode->student.name, name);
    newNode->student.id=id;
    return newNode;
}
void printfList(Node* head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    Node* current=head;
    while(current!=NULL)
    {
        printf("%s ",current->student.name);
        printf("%d\n",current->student.id);
        current=current->next;
    }
}
void editStudent(Node* head,int id)
{
    Node* current = head;
    while (current != NULL) {
        if (current->student.id == id) {
            printf("Ban muon sua ten thanh gi: ");
            fgets(current->student.name, 20, stdin);
            current->student.name[strcspn(current->student.name, "\n")] = '\0';
            break;
        }
        current = current->next;
    }

}
int main()
{
    Node* head=createNode("nhung",10);
    Node* node2=createNode("huyen",11);
    Node* node3=createNode("hong",12);
    head->next=node2;
    node2->next=node3;
    printfList(head);
    editStudent(head,10);
    printfList(head);
}