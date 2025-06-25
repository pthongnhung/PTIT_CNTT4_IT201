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
        int maxNum=numbers[0];
        int index=0;
        for (int i=0;i<n;i++)
        {
            if (maxNum<numbers[i])
            {
                maxNum=numbers[i];
            }
        }
        for (int i=0;i<n;i++)
        {
            if (numbers[i]==maxNum)
            {
                index=i;
                break;
            }
        }
        printf("Vi tri can tim kiem cua phan tu lon nhat dau tien la: %d",index);
        free(numbers);
    }
    return 0;
}