#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d",&n);
    int *numbers=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        printf("Nhap so thu %d: ",i+1);
        scanf("%d",&numbers[i]);
    }
    int flag=0;
    for (int i=0;i<n-1;i++)
    {
        int isLeader=0;;
        for (int j=i+1;j<n;j++)
        {
            if (numbers[i]<=numbers[j])
            {
                isLeader=1;
                break;
            }
        }
        if (isLeader==0)
        {
            printf("%d\t",numbers[i]);
            flag=1;
        }
    }
    if (n>0)
    {
        printf("%d",numbers[n-1]);
    }
    if (flag==0)
    {
        printf("Khong co so hop le");
    }
    free(numbers);
    return 0;
}