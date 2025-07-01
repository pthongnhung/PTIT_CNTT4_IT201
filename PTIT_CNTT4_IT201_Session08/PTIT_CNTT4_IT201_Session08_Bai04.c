#include<stdio.h>
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
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
    selectionSort(arr, n);
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
// do phuc tap thoi gian O(n2)