#include<stdio.h>

int totalNumber(int n)
{
    if (n==1)
    {
        return 1;
    }
    return n+totalNumber(n-1);
}

int main()
{
    int n,sum;
    printf("Nhap vao so nguyen bat ky: ");
    scanf("%d",&n);
    if (n<1)
    {
        printf("So khong hop le");
        return 0;
    }
    sum=totalNumber(n);
    printf("%d",sum);
    return 0;

}