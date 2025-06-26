#include<stdio.h>
int factorial(int n)
{
    if (n==1 || n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main()
{
    int n,result;
    printf("Nhap so nguyen n: ");
    scanf("%d",&n);
    if (n<1)
    {
        printf("So khong hop le");
        return 0;
    }
    result=factorial(n);
    printf("%d",result);
    return 0;

}