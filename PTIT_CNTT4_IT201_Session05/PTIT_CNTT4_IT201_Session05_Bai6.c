#include<stdio.h>
int sumArray(int arr[],int size)
{
    if (size==1)
    {
        return arr[0];
    }
    return arr[size-1]+sumArray(arr,size-1);
}
int main()
{
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    printf("Tong cac phan tu trong mang: %d",sumArray(arr,n));
    return 0;
}