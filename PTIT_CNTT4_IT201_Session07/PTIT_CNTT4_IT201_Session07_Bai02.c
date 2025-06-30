#include<stdio.h>
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for (int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
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
    for (int i=0; i<n; i++)
    {
        printf("arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }
    selection_sort(arr,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

}