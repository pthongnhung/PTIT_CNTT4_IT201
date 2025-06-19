#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int position;
    int value;
    do
    {
        printf("Moi ban nhap so phan tu trong mang (0<n<=100): ");
        scanf("%d",&n);
    }while (n<0 || n>100);
    int *numbers=(int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Moi ban nhap phan tu thu %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    printf("Ban muon sua phan tu o vi tri thu: \n");
    scanf("%d",&position);
    printf("Gia tri sau khi sua la: ");
    scanf("%d",&value);
    if (position<0 || position>n-1)
    {
        printf("Vi tri can sua khong hop le");
        return 1;
    }else
    {
        for (int i=0;i<n;i++)
        {
            if (i==position)
            {
                numbers[i]=value;
            }
        }
    }
    printf("Mang sau khi sua ");
    for (int i=0;i<n;i++)
    {
        printf("%d ",numbers[i]);
    }
    free(numbers);
    return 0;
}