#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
}Student;
void toLowerCase(char str[])
{
    for (int i=0;str[i]!='\0';i++)
    {
        str[i]=tolower(str[i]);
    }
}
int containsIgnoreCase(char str[],char strName[])
{
    char strcopy[50];
    char strNamecopy[50];
    strcpy(strcopy,str);
    strcpy(strNamecopy,strName);
    toLowerCase((strcopy));
    toLowerCase((strNamecopy));
    return strstr(strcopy,strNamecopy)!=NULL;
}
int main()
{
    Student student[5];
    for(int i=0;i<5;i++)
    {
        printf("Nhap thong tin cua sinh vien thu %d\n",i+1);
        student[i].id=i+1;
        printf("Nhap ten: ");
        fgets(student[i].name,sizeof(student[i].name),stdin);
        student[i].name[strcspn(student[i].name,"\n")]='\0';
        printf("Nhap tuoi: ");
        scanf("%d",&student[i].age);
        getchar();
    }
    char strName[50];
    printf("Nhap ten can tim kiem: ");
    getchar();
    fgets(strName,sizeof(strName),stdin);
    strName[strcspn(strName, "\n")] = '\0';

    int found=0;
    for (int i=0;i<5;i++)
    {
        if (containsIgnoreCase(student[i].name,strName))
        {
            printf("%d,%s,%d\n",student[i].id,student[i].name,student[i].age);
            found=1;
        }
    }
    if (!found)
    {
        printf("Khong ton tai sinh vien");
    }
    return 0;
}