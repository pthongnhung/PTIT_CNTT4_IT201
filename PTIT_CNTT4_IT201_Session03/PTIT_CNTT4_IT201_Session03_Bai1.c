#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu trong mang: ");
    scanf("%d",&n);

    if (n<0)
    {
        printf("So luong phan tu khong duoc am");
        return 0;
    }
    else if (n==0){
        printf("So luong phan tu phai lon hon khong");
        return 0;
    }
    else
    {
        int *numbers;
        numbers=(int*)malloc(n*sizeof(int));
        if (numbers==NULL)
        {
            printf("Khong du bo nho");
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            printf("Moi ban nhap phan thu %d:  ",i+1);
            scanf("%d",&numbers[i]);
        }
        for (int i=0;i<n;i++)
        {
            printf("So thu %d = %d\n",i+1,numbers[i]);
        }
        free(numbers);

    }
    return 0;

}
