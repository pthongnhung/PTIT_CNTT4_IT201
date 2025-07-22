#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Task
{
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;
typedef struct singleNode
{
    Task tasks;
    struct singleNode* next;
}singleNode;
typedef struct doubleNode
{
    Task tasks;
    struct doubleNode* next;
    struct doubleNode* prev;
}doubleNode;
singleNode* createSingleNode(Task tasks)
{
    singleNode* newNode=(singleNode*)malloc(sizeof(singleNode));
    newNode->tasks=tasks;
    newNode->next=NULL;
    return newNode;
}
doubleNode* createDoubleNode(Task tasks)
{
    doubleNode* newNode=(doubleNode*)malloc(sizeof(doubleNode));
    newNode->tasks=tasks;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
singleNode* insertSingleNodeAtEnd(singleNode* head,Task tasks)
{
    singleNode* newNode=createSingleNode(tasks);
    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    singleNode* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    return head;
}
void printList(singleNode* head)
{
    singleNode* current=head;
    while(current!=NULL)
    {
        printf("Id: %d\t",current->tasks.id);
        printf("Tennhiem vu: %s\t",current->tasks.title);
        printf("Muc do uu tien: %d\t",current->tasks.priority);
        printf("Thoi gian hoan thanh nhiem vu: %s\n",current->tasks.deadline);
        current=current->next;
    }
}
singleNode* deleteSingleNode(singleNode* head,int id)
{
    singleNode* current=head;
    if(head==NULL)
    {
        printf("Danh sach trong");
        return NULL;
    }
    singleNode* prev=NULL;
    while(current!=NULL && current->tasks.id!=id)
    {
        prev=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("khong tim thay id");
        return head;
    }
    if (current==head)
    {
        head=head->next;
        free(current);
        return head;
    }
    prev->next=current->next;
    return head;
}
void updateSingleNode(singleNode* head,int id)
{
    singleNode* current=head;
    if(head==NULL)
    {
        printf("Danh sach trong");
        return ;
    }
    while (current!=NULL && current->tasks.id!=id)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        printf("khong tim thay id");
        return ;
    }
        printf("Id: %d\t",current->tasks.id);
        printf("ten: %s\t",current->tasks.title);
        printf("thoi gian hoan thanh: %s\t",current->tasks.deadline);
        printf("muc do uu tien: %d\n",current->tasks.priority);
        fflush(stdin);
        printf("Nhap lai ten: ");
        fgets(current->tasks.title,100,stdin);
        current->tasks.title[strcspn(current->tasks.title,"\n")]='\0';

        printf("Nhap lai thoi gian hoan thanh nhiem vu: ");
        fgets(current->tasks.deadline,100,stdin);
        current->tasks.deadline[strcspn(current->tasks.deadline,"\n")]='\0';

        printf("Nhap lai muc do uu tien: ");
        scanf("%d",&current->tasks.priority);
        getchar();
}
doubleNode* insertDoubleNodeAtEnd(doubleNode* head,Task tasks)
{
    doubleNode* newNode=(doubleNode*)malloc(sizeof(doubleNode));
    newNode->tasks=tasks;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
singleNode* finishNode(singleNode* head,int finishId)
{
    singleNode* current=head;
    while (current!=NULL)
    {
        if(current->tasks.id==finishId)
        {
            return head;
        }
    }
    return NULL;
}
void sortByPriority(singleNode* head)
{
    singleNode* i;
    singleNode* j;
    for (i=head;i->next!=NULL;i=i->next)
    {
        for (j=i->next;j!=NULL;j=j->next)
        {
            if (i->tasks.priority>j->tasks.priority)
            {
                Task temp=i->tasks;
                i->tasks=j->tasks;
                j->tasks=temp;
            }
        }
    }
}
int main()
{
    int choice;
    singleNode* singleHead=NULL;
    doubleNode* doubleHead=NULL;
    srand(time(NULL));
   do
   {
       printf("1.Them nhiem vu\n");
       printf("2.Hien thi danh sach nhiem vu\n");
       printf("3.Xoa nhiem vu\n");
       printf("4.Cap nhat thong tin nhiem vu\n");
       printf("5.Danh dau nhiem vu da hoan thanh\n");
       printf("6.Sap xep nhiem vu\n");
       printf("7.Tim kiem nhiem vu\n");
       printf("8.Thoat chuong trinh\n");
       printf("Nhap lua chon cua ban: ");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
           Task tasks;
           fflush(stdin);
           tasks.id=rand() % 9000+ 1000;
           printf("Nhap ten nhiem vu: ");
           fgets(tasks.title,100,stdin);
           tasks.title[strcspn(tasks.title,"\n")]='\0';

           printf("Nhap muc do uu tien cua nhiem vu: ");
           scanf("%d",&tasks.priority);
           getchar();

           printf("Nhap thoi gian hoan thanh nhiem vu: ");
           fgets(tasks.deadline,100,stdin);
           tasks.deadline[strcspn(tasks.deadline,"\n")]='\0';

           singleHead=insertSingleNodeAtEnd(singleHead,tasks);
           printf("Da them nhiem vu thanh cong\n");
           break;
       case 2:
           printList(singleHead);
           break;
       case 3:
           int deleteId;
           printf("Nhap id can xoa: ");
           scanf("%d",&deleteId);
           singleHead=deleteSingleNode(singleHead,deleteId);
           printf("Da xoa nhiem vu thanh cong");
           break;
       case 4:
           int updateId;
           printf("Nhap id can xoa: ");
           scanf("%d",&updateId);
           updateSingleNode(singleHead,updateId);
           break;
       case 5:
           int finishId;
           printf("Nhap id can danh dau: ");
           scanf("%d",&finishId);
           singleNode* finish=finishNode(singleHead,finishId);
           if(finish==NULL)
           {
               printf("Khong tim thay Id");
               break;
           }
           Task finishTask=finish->tasks;
           doubleHead=insertDoubleNodeAtEnd(doubleHead,finishTask);
           singleHead=deleteSingleNode(singleHead,finishId);
           printf("Danh dau nhiem vu thanh cong");
           break;
       case 6:
           sortByPriority(singleHead);
           printf("Da sap xep thanh cong");
           break;
       case 7:
           break;
       case 8:
           break;
       default:
           printf("Nhap lua chon khong hop le");
       }
   }while (choice!=8);
    return 0;
}