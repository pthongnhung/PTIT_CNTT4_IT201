#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int id;
    char name[50];
    int age;
}Student;
int main()
{
    Student student[5];
    for (int i=0;i<5;i++)
    {

        printf("Nhap thong tin cua sinh vien thu %d\n", i + 1);
        student[i].id=i+1;
        printf("Nhap ten: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0'; // xóa '\n'

        printf("Nhap tuoi: ");
        scanf("%d", &student[i].age);
        getchar();


    }
    int searchId;
    printf("Nhap id can tim kiem: ");
    scanf("%d",&searchId);
    getchar();
    int found=0;
    for (int i=0;i<5;i++)
    {
        if (searchId==student[i].id)
        {
            printf("%d, ",student[i].id);
            printf("%s, ",student[i].name);
            printf("%d",student[i].age);
            found=1;
            break;
        }
    }
    if (!found)
    {
        printf("Khong tim thay sinh vien");
        return 0;
    }
    return 0;
}