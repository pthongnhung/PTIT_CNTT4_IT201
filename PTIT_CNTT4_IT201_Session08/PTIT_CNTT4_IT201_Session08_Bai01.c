#include<stdio.h>
int linear_search(int arr[],int search,int n)
{
    for (int i=0;i<n;i++)
    {
        if (arr[i]==search)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n<=0)
    {
        printf("Khong hop le");
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int search;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &search);
    if (linear_search(arr,search,n))
    {
        printf("Vi tri thu %d",linear_search(arr,search,n));
    }else
    {
        printf("Khong ton tai phan tu tim kiem");
    }
    return 0;
}
// Do phuc tap thoi gian 0(n)