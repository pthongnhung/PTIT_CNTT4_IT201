#include<stdio.h>
int sumDigits(int n)
{
    if (n==0)
    {
        return 0;
    }
    return n%10 + sumDigits(n/10);
}
int main()
{
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d",&n);
    if (n<=0)
    {
        printf("So khong hop le");
        return 0;
    }
    printf("%d",sumDigits(n));
    return 0;
}