#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d",&n);
    int *numbers=(int*)malloc(n*sizeof(int));
    int *countNum=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Moi ban nhap phan tu thu %d: ",i+1);
        scanf("%d",&numbers[i]);
        countNum[i]=1;
    }
    for (int i=0;i<n-1;i++)
    {
        if (countNum[i]==0) continue;
        for (int j=i+1;j<n;j++)
        {
            if (numbers[i]==numbers[j])
            {
                countNum[i]++;
                countNum[j]=0;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if (countNum[i]!=0)
        {
            printf("Phan tu %d xuat hien %d lan\n",numbers[i],countNum[i]);
        }
    }
    free(numbers);
    free(countNum);
    return 0;
}