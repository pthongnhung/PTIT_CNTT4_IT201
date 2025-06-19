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
    int MAX_NUM=numbers[0];
        for (int i=0;i<n;i++)
        {
            if (MAX_NUM<numbers[i]);
            {
                MAX_NUM=numbers[i];
            }
        }
    printf("Phan tu lon nhat trong mang la %d",MAX_NUM);
    free(numbers);

    return 0;
}