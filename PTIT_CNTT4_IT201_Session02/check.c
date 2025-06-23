#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Moi ban nhap vao so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *numbers=(int*)malloc(n*sizeof(int));
    int *arr=(int*)malloc(n*sizeof(int));
    if (numbers==NULL || arr==NULL)
    {
        printf("Khong du bo nho");
    }
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    int Max=numbers[n-1];
    int count=0;
    for (int i=n-1;i>=0;i--)
    {
        if (Max<numbers[i] || i==n-1)
        {
            Max=numbers[i];
            arr[count]=Max;
            count++;
        }
    }
    for (int i=count-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    free(numbers);
    return 0;
}
