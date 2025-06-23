#include<stdio.h>
#include<stdlib.h>
void printfArray(int array[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
}
int main()
{
    int n;
    int m;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d",&n);
    if (n<=0)
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
        printf("Nhap phan tu arr[%d]= ",i);
        scanf("%d",&numbers[i]);
    }
    printfArray(numbers,n);

    printf("\nBan muon them vao may phan tu: ");
    scanf("%d",&m);
    if (m==0)
    {
        printfArray(numbers,n);
    }else
    {
        numbers=(int*)realloc(numbers,(n+m)*sizeof(int));
        for (int i=n;i<n+m;i++)
        {
            printf("Nhap phan tu thu %d:  ",i);
            scanf("%d",&numbers[i]);
        }
        n+=m;
        printfArray(numbers,n);
        free(numbers);
        return 0;
    }
}