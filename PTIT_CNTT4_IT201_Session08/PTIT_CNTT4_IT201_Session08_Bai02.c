#include<stdio.h>
int binary_search(int arr[],int search,int n)
{
    int left=0;
    int right=n-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (arr[mid]==search)
        {
            return mid;
        }else if (arr[mid]<search)
        {
            left=mid+1;
        }else
        {
            right=mid-1;
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
    if (binary_search(arr,search,n))
    {
        printf("Vi tri thu %d",binary_search(arr,search,n));
    }else
    {
        printf("Khong ton tai phan tu tim kiem");
    }
    return 0;
}
// do phuc tap thoi gian O(logn)
