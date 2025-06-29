#include<stdio.h>
void binary(int n)
{
    if (n==0)
    {
        return;
    }
    binary(n/2);
    printf("%d",n%2);
}
int main()
{
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d",&n);
    if (n<=0)
    {
        return 0;
    }
    binary(n);
    return 0;
}