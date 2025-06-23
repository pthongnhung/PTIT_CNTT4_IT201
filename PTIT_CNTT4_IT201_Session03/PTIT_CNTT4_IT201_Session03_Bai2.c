#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu cua mang: ");
    scanf("%d",&n);
    if (n<=0 || n>100)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int *numbers=(int*)malloc(n*sizeof(int));
    if (numbers==NULL)
    {
        printf("Khong du bo nho");
    }
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu arr[%d]= ",i+1);
        scanf("%d",&numbers[i]);
    }
    int Max=numbers[0];
    for (int i=1;i<n;i++)
    {
        if (Max<numbers[i])
        {
            Max=numbers[i];
        }
    }
    printf("Max=%d",Max);
    free(numbers);
    return 0;
}