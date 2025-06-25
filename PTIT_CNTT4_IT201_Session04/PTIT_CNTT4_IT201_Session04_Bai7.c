#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d",&n);
    if (n<=0)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int *numbers=(int*)malloc(n*sizeof(int));
    if (numbers==NULL)
    {
        printf("khong du bo nho");
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        printf("numbers[%d]=",i);
        scanf("%d",&numbers[i]);
    }
    int found=0;
    for (int i=0;i<n/2;i++)
    {
        if (numbers[i]==numbers[n-i-1])
        {
            printf("Cap doi xung (%d,%d)\n",numbers[i],numbers[n-i-1]);
            found=1;
        }
    }
    if (found==0)
    {
        printf("khong ton tai cap doi xung");
    }
    free(numbers);
    return 0;
}