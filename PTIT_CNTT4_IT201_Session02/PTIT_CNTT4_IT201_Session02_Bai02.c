#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int number;
    printf("Moi ban nhap so phan tu cua mang (0<n<=100): \n");
    scanf("%d",&n);
    if (n<0 || n>=100)
    {
        printf("Vui long nhap lai n: \n");
    }
    printf("Moi ban nhap so can tim so lan xuat hien: \n");
    scanf("%d",&number);
    int *numbers=(int*)malloc(n*sizeof(int));
    if (numbers==NULL)
    {
        printf("Khong du bo nho.\n");
        return 1;
    }
    for (int i=0;i<n;i++)
    {
        printf("Moi ban nhap phan tu thu %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    int count=0;
    int flag=0;
    for (int i=0;i<n;i++)
    {
        if (numbers[i]==number)
        {
            count++;
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("Khong ton tai phan tu %d.\n",number);
        return 1;
    }
    printf("So lan xuat hien cua phan tu %d la %d", number,count);
    free(numbers);
    return 0;
}