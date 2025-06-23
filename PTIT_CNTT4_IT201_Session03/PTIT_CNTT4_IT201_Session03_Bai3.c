#include<stdio.h>
#include<stdlib.h>
float averageEvent(int arr[],int n)
{
    int sum=0;
    int count=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]%2==0)
        {

            sum+=arr[i];
            count++;
        }

    }
    return (float)sum/count;
}
int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu cua mang: ");
    scanf("%d",&n);
    if (n<=0 || n>100)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int *numbers=(int*)malloc(n*sizeof(int));
    if (numbers==NULL)
    {
        printf("Khong du bo nho");
    }
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu arr[%d]= ",i+1);
        scanf("%d",&numbers[i]);
    }
    printf("average=%.2f",averageEvent(numbers,n));
    free(numbers);
    return 0;
}