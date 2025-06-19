#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int sum;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *numbers=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    printf("Nhap tong cua 2 so can tim: ");
    scanf("%d",&sum);
    int flag=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (numbers[i]+numbers[j]==sum)
            {
                printf("%d + %d =%d\t",numbers[i],numbers[j],sum);
                flag=1;
            }
        }
    }
    if (flag==0)
    {
        printf("Khong co so nao hop le");
    }
    free(numbers);
    return 0;
}