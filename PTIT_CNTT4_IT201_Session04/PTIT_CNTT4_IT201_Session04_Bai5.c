#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu trong mang: ");
    scanf("%d",&n);

    if (n<0)
    {
        printf("So luong phan tu khong duoc am");
        return 0;
    }
    else if (n==0){
        printf("So luong phan tu phai lon hon khong");
        return 0;
    }
    else
    {
        int *numbers;
        numbers=(int*)malloc(n*sizeof(int));
        if (numbers==NULL)
        {
            printf("Khong du bo nho");
            return 0;
        }
        for (int i=0;i<n;i++)
        {
            printf("arr[%d]=",i);
            scanf("%d",&numbers[i]);
        }
        for (int i=0;i<n-1;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (numbers[i]>numbers[j])
                {
                    int temp=numbers[i];
                    numbers[i]=numbers[j];
                    numbers[j]=temp;
                }
            }
        }
        int left=0;
        int right=n-1;
        int target;
        printf("Nhap phan tu can tim kiem: ");
        scanf("%d",&target);
        int found=0;
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (numbers[mid]==target)
            {
                found=mid;
                break;
            }else if (target>mid)
            {
                left=mid+1;
            }else
            {
                right=mid-1;
            }
        }
        if (found==0)
        {
            printf("Khong ton tai phan tu tim kiem");
            return 0;
        }
        printf("Phan tu co trong mang");
        free(numbers);
    }
}