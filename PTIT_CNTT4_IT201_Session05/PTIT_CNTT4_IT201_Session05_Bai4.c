#include<stdio.h>
int total(int firstNumber,int secondNumber)
{
    if (firstNumber>secondNumber)
    {
        return 0;
    }
    return firstNumber + total(firstNumber+1,secondNumber);
}
int main()
{
    int firstNumber,secondNumber;
    printf("Nhap so thu 1: ");
    scanf("%d",&firstNumber);
    printf("Nhap so thu 2: ");
    scanf("%d",&secondNumber);
    if (firstNumber<=0 || secondNumber<=0)
    {
        printf("So khong hop le");
        return 0;
    }
    int result=total(firstNumber,secondNumber);
    printf("%d",result);
    return 0;
}