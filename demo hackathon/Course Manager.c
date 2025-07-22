#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Course
{
    int id;
    char title[100];
    int credit;
}Course;
typedef struct singleList
{
    Course course;
    struct singleList *next;
}singleList;
typedef struct doubleList
{
    Course course;
    struct doubleList *next;
    struct doubleList *prev;
}doubleList;
singleList *createSingleList(Course course)
{
    singleList *newNode = (singleList *)malloc(sizeof(singleList));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}
doubleList *createDoubleList(Course course)
{
    doubleList *newNode = (doubleList *)malloc(sizeof(doubleList));
    newNode->course = course;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
singleList* insertAtEnd(singleList *singleHead, Course course)
{
    singleList *newNode = createSingleList(course);
    if(singleHead==NULL)
    {
        singleHead = newNode;
        return singleHead;
    }
    singleList* current=singleHead;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    return singleHead;
}
void printList(singleList* singleHead)
{
    singleList* current=singleHead;
    if (current==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(current!=NULL)
    {
        printf("Course ID: %d\n",current->course.id);
        printf("Title: %s\n",current->course.title);
        printf("Credit: %d\n",current->course.credit);
        current=current->next;
    }
}
singleList* deleteAtChoice(singleList *singleHead,int id)
{
    singleList* current=singleHead;
    singleList* prev=NULL;
    if (current==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while (current!=NULL && current->course.id!=id)
    {
        prev=current;
        current=current->next;
    }
    if (current==NULL)
    {
        printf("Can not find Id");
        return singleHead;
    }
    if (current==singleHead)
    {
        singleHead=singleHead->next;
        free(current);
        return singleHead;
    }
    prev->next=current->next;
    free(current);
    printf("Da xoa thanh cong khoa hoc");
    return singleHead;
}
singleList* updateCourse(singleList* singleHead,int id)
{
    singleList* current=singleHead;
    if (current==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while ( current!=NULL && current->course.id!=id)
    {
        current=current->next;
    }
    if (current==NULL)
    {
        printf("Can not find Id\n");
        return singleHead;
    }
    printf("Course ID: %d\n",current->course.id);
    printf("Title: %s\n",current->course.title);
    printf("Credit: %d\n",current->course.credit);
    fflush(stdin);
    printf("Vui long nhap ten khoa hoc muon sua: ");
    fgets(current->course.title,100,stdin);
    current->course.title[strcspn(current->course.title,"\n")]='\0';
    printf("Vui long nhap lai so tin chi: ");
    scanf("%d",&current->course.credit);
    printf("Da sua thanh cong");
    return singleHead;
}
doubleList *doubleInsertAtEnd(doubleList *doubleHead,Course finishCourse)
{
    doubleList *newNode = createDoubleList(finishCourse);
    if(doubleHead==NULL)
    {
        doubleHead = newNode;
        return doubleHead;
    }
    doubleList* current=doubleHead;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return doubleHead;
}
singleList* finishCourse(singleList *singleHead,int id)
{
    singleList* current=singleHead;
    while (current!=NULL)
    {
        if (current->course.id==id)
        {
            return current;
        }
        current=current->next;
        return NULL;
    }
}

singleList* creditSort(singleList* singleHead)
{
    singleList* i;
    singleList* j;
    for (i=singleHead;i->next!=NULL;i=i->next)
    {
        for (j=i->next;j !=NULL;j=j->next)
        {
            if (i->course.credit>j->course.credit)
            {
                Course temp=i->course;
                i->course=j->course;
                j->course=temp;
            }
        }
    }
    return singleHead;
}
singleList* findName(singleList* head,char* name)
{
    singleList* current=head;
    while (current!=NULL)
    {
        if (strstr(current->course.title,name))
        {
            return current;
        }
        current=current->next;
    }
    return NULL;
}

int main()
{
    int choice;
    singleList *singleHead=NULL;
    doubleList *doubleHead=NULL;
    srand(time(NULL));
    do
    {
        printf("1.Them khoa hoc\n");
        printf("2.Hien thi khoa hoc\n");
        printf("3.Xoa khoa hoc\n");
        printf("4.Cap nhat thong tin khoa hoc\n");
        printf("5.Danh dau khoa hoc da hoan thanh\n");
        printf("6.Sap xep khoa hoc theo tin chi\n");
        printf("7.Tim kiem khoa hoc theo ten\n");
        printf("8.Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
        case 1:
            Course course;
            course.id = rand() % 9000+ 1000;
            printf("Nhap ten khoa hoc: ");
            fgets(course.title,100,stdin);
            course.title[strcspn(course.title,"\n")]='\0';
            printf("Nhap so tin chi: ");
            scanf("%d",&course.credit);
            singleHead=doubleInsertAtEnd(singleHead,course);
            break;
        case 2:
            printList(singleHead);
            break;
        case 3:
            int id;
            printf("Nhap id khoa hoc ban muon xoa: ");
            scanf("%d",&id);
            singleHead=deleteAtChoice(singleHead,id);
            break;
        case 4:
            int updateID;
            printf("Nhap id khoa hoc ban muon xoa: ");
            scanf("%d",&updateID);
            singleHead=updateCourse(singleHead,updateID);
            break;
        case 5:
            int finishId;
            printf("Nhap id khoa hoc ban muon danh dau: ");
            scanf("%d",&finishId);
            singleList *finishNode=finishCourse(singleHead,finishId);
            if(finishNode==NULL)
            {
                printf("Can not find Id\n");
                break;
            }
            Course finishCourse=finishNode->course;
            doubleHead=insertAtEnd(doubleHead,finishCourse);
            singleHead=deleteAtChoice(singleHead,finishId);
            printf("Da danh dau thanh cong khoa hoc");
            break;
        case 6:
            singleHead=creditSort(singleHead);
            printf("Da sap xep thanh cong");
            break;
        case 7:
            char name[100];
            printf("Nhap ten khoa hoc can tim kiem: ");
            fgets(name,100,stdin);
            name[strcspn(name,"\n")]='\0';
            singleList* findNode=findName(singleHead,name);
            if(findNode==NULL)
            {
                printf("Can not find Name\n");
                break;
            }
            printf("id khoa hoc: %d\n ",findNode->course.id);
            printf("ten khoa hoc: %s\n",findNode->course.title);
            printf("so tin chi: %d\n",findNode->course.credit);
            break;
        case 8:
            printf("Cam on ban da dung chuong trinh");

            break;
        default:
            printf("Vui long nhap lua chon hop le");
        }
    }while (choice!=8);
    return 0;
}
