#include<stdio.h>
int fibonaci(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    return fibonaci(n-1)+fibonaci(n-2);
}
int main()
{
    int n;
    printf("Nhap vao so nguyen duong n: ");
    scanf("%d",&n);
    if (n<=0)
    {
        return 0;
    }
    int result[n];
    for (int i=0;i<n;i++)
    {
        result[i]=fibonaci(i);
    }
    for (int i=n-1;i>=0;i--)
    {
        printf("%d ",result[i]);
    }
    return 0;
}