#include<stdio.h>
void bubble_sort(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int flag=0;
        for (int j=0;j<n-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if (flag!=1)
        {
            break;
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
    bubble_sort(arr, n);
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
// Do phuc tap thoi gian 0(n2)