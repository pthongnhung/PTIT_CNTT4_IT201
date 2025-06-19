#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int pos;
    int value;
    do
    {
        printf("Moi ban nhap so luong phan tu trong mang (0<n<=100): ");
        scanf("%d",&n);
    }while (n<0 || n>100);
    int *numbers=(int*)malloc(n*sizeof(int));
    if (numbers==NULL)
    {
        printf("Bo nho khong du");
        return 1;
    }
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d",&numbers[i]);
    }
    printf("Nhap vi tri muon them phan tu: ");
    scanf("%d",&pos);
    if (pos<0 || pos>n-1)
    {
        printf("Vi tri khong hop le");
        return 1;
    }
    printf("Nhap phan tu muon them: ");
    scanf("%d",&value);
    int temp;
    for (int i=n;i>pos;i--)
    {
        numbers[i]=numbers[i-1];
    }
    numbers[pos]=value;
    n++;
    printf("Mang sau khi duoc them phan tu: ");
    for (int i=0;i<n;i++)
    {
        printf("%d ",numbers[i]);
    }
    free(numbers);
    return 0;
}