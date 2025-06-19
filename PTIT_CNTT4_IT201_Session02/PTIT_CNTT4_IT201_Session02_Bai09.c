#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d",&n);
    int *numbers=(int*)malloc(n*sizeof(int));
    int *countNum=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&numbers[i]);
        countNum[i]=1;
    }

    int count=0;
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
    int Max_Index=0;
    for (int i=0;i<n;i++)
    {
        if (countNum[i]>countNum[Max_Index])
        {
            Max_Index=i;
        }
    }
    printf("So xuat hien nhieu nhat la: %d",numbers[Max_Index]);
    return 0;
    free(numbers);
    free(countNum);
}