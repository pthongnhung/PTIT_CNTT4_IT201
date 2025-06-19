#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    do
    {
        printf("Moi ban nhap so phan tu trong mang (0<n<=100): ");
        scanf("%d",&n);
    }while (n<0 || n>100);
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
    int temp;
    for (int i=0;i<n/2;i++)
    {
        temp=numbers[i];
        numbers[i]=numbers[n-i-1];
        numbers[n-i-1]=temp;
    }
    printf("Mang sau khi duoc dao nguoc");
    for (int i=0;i<n;i++)
    {
        printf("%d",numbers[i]);
    }

    free(numbers);
    return 0;
}