#include<stdio.h>

void printfToNum(int n)
{
    if (n==1)
    {
        printf("1 ");
        return;
    }
    printfToNum(n-1);
    printf("%d ",n);
}
int main()
{
    int n;
    printf("Nhap vao so nguyen duong bat ky: ");
    scanf("%d",&n);
    printfToNum(n);
    return 0;
}