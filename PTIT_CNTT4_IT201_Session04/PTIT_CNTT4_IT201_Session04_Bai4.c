#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Nhap vao so luong phan tu trong mang: ");
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
        int *numbers=(int*)malloc(n*sizeof(int));
        if (numbers==NULL)
        {
            printf("Khong du bo nho");
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            printf("arr[%d]=",i);
            scanf("%d",&numbers[i]);
        }
        int value;
        int index=0;
        printf("Nhap phan tu can tim kiem vi tri: ");
        scanf("%d",&value);
        for (int i=0;i<n;i++)
        {
            if (numbers[i]==value)
            {
                index=i;
            }
        }
        if (index==0)
        {
            printf("Khong tim thay phan tu");
            return 0;
        }
        printf("Vi tri can tim kiem la: %d",index);
        free(numbers);
    }
    return 0;
}