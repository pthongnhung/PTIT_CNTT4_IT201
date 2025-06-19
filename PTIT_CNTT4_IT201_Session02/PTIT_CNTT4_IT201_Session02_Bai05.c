#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int pos;
    do
    {
        printf("Moi ban nhap so phan tu trong mang (0<n<=100): ");
        scanf("%d",&n);
    }while (n<0 || n>100);
    int *numbers=(int*)malloc(n*sizeof(int*));
    if (numbers==NULL)
    {
        printf("Bo nho khong du");
        return 1;
    }
    for (int i=0;i<n;i++)
    {
        printf("Moi ban nhap phan tu thu %d: ", i+1);
        scanf("%d",&numbers[i]);
    }
    printf("Moi ban nhap vi tri muon xoa: ");
    scanf("%d",&pos);
    if (pos<0 || pos>n-1)
    {
        printf("Vi tri khong hop le");
        return 1;
    }else
    {
        for (int i=pos;i<n-1;i++)
        {
            numbers[i]=numbers[i+1];
        }
        n--;
    }
    printf("Mang sau khi xoa phan tu\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ",numbers[i]);
    }
    free(numbers);
    return 0;
}